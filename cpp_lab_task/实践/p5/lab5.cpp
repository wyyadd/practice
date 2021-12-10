#include <iostream>
#include <algorithm>
#include <queue>
#include <fstream>
#include <time.h>
#include <thread>
#include <future>
#include <parallel/losertree.h> 
#include <assert.h>


namespace lab5{
using std::string;

int feedInput(std::ifstream *infile, int *arr, int input_size){
    int i = 0;
    while (!infile->eof()&&i<input_size)
    {
        *infile >> arr[i++];
    }
    if(infile->eof())
        return i-1;
    return i;
}

void writeDisk(string name, int *arr, int size){
    std::ofstream outfile(name, std::ios::app);
    for(int i = 0; i < size; ++i)
        outfile << arr[i] << std::endl;
    outfile.close();
}

// 使用merge sort， 生成runs， 并生成到临时的输出文件中
void createInitialRuns(string input_file, int run_size, int num_ways){
    // 打开输入文件
    std::ifstream infile(input_file, std::ios::in);
 
    // 输出临时文件array
    std::ofstream outfile[num_ways];
    for (int i = 0; i < num_ways; i++)
    {
        // 输出临时文件
        outfile[i].open("epoch_0_run_"+std::to_string(i), std::ios::out);
    }
 
    // 创建三个缓存
    int *treeBuffer = new int[run_size];
    int *diskBuffer_input = new int[run_size];
    int *diskBuffer_output= new int[run_size];

    /**
    // loser tree
    constexpr int num_nodes = 10;
    std::less<int> compare;
    __gnu_parallel::_LoserTree<true, int, std::less<int>> loser_tree(num_nodes, compare);
    int treenodes[num_nodes]; 
    // init loser tree
    for(int i = 0; i < num_nodes; ++i){
        int key;
        infile >> key;
        treenodes[i] = key;
        loser_tree.__insert_start(key, i, false);
    }
    loser_tree.__init();
    */
 
    // flag
    int next_output_file = 0;
 
    int num = feedInput(&infile, treeBuffer, run_size);
    while (true)
    {
        // init diskBuffer_input
        // num = num of readed numbers

        std::future<int> t_read = std::async(feedInput, &infile, diskBuffer_input, run_size);

        // exchange treeBuffer and diskBuffer_input
        // std::swap(treeBuffer,diskBuffer_input);

        // use loser tree to feed diskBuffer_output
        /**
        for(int i = 0; i < num; ++i){
            int index = loser_tree.__get_min_source();
            loser_tree.__delete_min_insert(treeBuffer[i], false);
            std::swap(treeBuffer[i],treenodes[index]);
        }
        */

        // sort treeBuffer
        std::thread t_sort([&](){std::sort(treeBuffer,treeBuffer+run_size);});
        // std::sort(treeBuffer,treeBuffer + run_size);

        t_sort.join();
        // exchange treeBuffer and diskBuffer_output
        std::swap(treeBuffer,diskBuffer_output);

        // write to disk
        std::thread t_write([&](){
            for(int i = 0; i < num; ++i)
                outfile[next_output_file] << diskBuffer_output[i] << std::endl;
        });
        t_write.join();
        num = t_read.get();
        std::swap(treeBuffer, diskBuffer_input);
        // for(int i = 0; i < num; ++i){
        //     outfile[next_output_file] << diskBuffer_output[i] << std::endl;
        // }

        if(num != run_size){
            assert(infile.eof());
            std::sort(treeBuffer,treeBuffer+run_size);
            std::swap(treeBuffer,diskBuffer_output);
            for(int i = 0; i < num; ++i)
                outfile[next_output_file] << diskBuffer_output[i] << std::endl;
            break;
        }
        next_output_file++;
    }

    // for(int i = 0; i < num_nodes; ++i){
    //     outfile[next_output_file] << treenodes[loser_tree.__get_min_source()] << std::endl;
    //     loser_tree.__delete_min_insert(INT32_MAX,false);
    // }
 
    // close the input and output files
    for (int i = 0; i < num_ways; i++) {
        outfile[i].close();
    }

    infile.close();
    delete []diskBuffer_output;
    delete []diskBuffer_input;
    delete []treeBuffer;
}

// num = num of runs
// k = k way merge
void mergeFiles(int num, int k, int epoch, int input_size, int output_size){
    // end condition
    if(num == 1){
        return;
    }
    string prefix = "epoch_" + std::to_string(epoch) + "_run_";
    ++epoch;

    // k-way merge
    int i;
    for(i = 0; i < num; i+=k){   
        // input buffer
        int** input_buffer = new int* [k];
        for(int j = 0; j < k; ++j)
            input_buffer[j] = new int[input_size];
        // int input_buffer[k][input_size];
        int input_pos[input_size];
        std::fill(input_pos, input_pos+input_size, 0);
        // output buffer
        int *output_buffer_tree = new int[output_size];
        int *output_buffer_disk = new int[output_size];
        int output_po = 0;
        string new_name= "epoch_" + std::to_string(epoch) + "_run_" + std::to_string(i/k);
        // num_of_remain runs means in this loop, the number of runs to merge
        int num_of_reamin_runs =  std::min(num-i,k);
        // loser tree
        std::less<int> compare;
        __gnu_parallel::_LoserTree<true, int, std::less<int>> loser_tree(num_of_reamin_runs, compare);
        // create infile stream
        std::ifstream infile[num_of_reamin_runs];
        for(int j = 0; j < std::min(num_of_reamin_runs,k); ++j){
            infile[j].open(prefix+std::to_string(i+j), std::ios::in);
        }
        // create init buffer thread and feed input buffer
        std::thread t_writeDisk;
        std::thread t_init_inputBuffer[num_of_reamin_runs];
        for(int j = 0; j < num_of_reamin_runs; ++j){
            t_init_inputBuffer[j] = std::thread(feedInput, &infile[j], input_buffer[j], input_size);
        }
        for(int j = 0; j < num_of_reamin_runs; ++j){
            t_init_inputBuffer[j].join();
        }
        // init loser tree
        for(int j = 0; j < num_of_reamin_runs; ++j){
            // feedInput(&infile[j], input_buffer[j],input_size);
            loser_tree.__insert_start(input_buffer[j][0],j,false);
        }
        loser_tree.__init();
        // flag is the number of run which reach end
        int flag = 0;
        // loop to feed loser tree and output buffer 
        while(flag != num_of_reamin_runs) 
        {
            // min number index
            int index = loser_tree.__get_min_source();
            // put it into output buffer 
            output_buffer_tree[output_po++] = input_buffer[index][input_pos[index]++];
            // check if input buffer is empty 
            if(input_pos[index] == input_size){
                // feed buffer
                int size = feedInput(&infile[index],input_buffer[index], input_size);
                if(size == 0){
                    assert(infile[index].eof());
                    std::fill(input_buffer[index], input_buffer[index]+input_size, INT32_MAX);
                    input_pos[index] = 0;
                    ++flag;
                }
                else{
                    if(size != input_size){
                        // if cannot fill up buffer
                        // move fisrt valid numbers to the end of array which means shrink the buffer size
                        int start = input_size - size;
                        for(int j = 0; j < size; ++j){
                            input_buffer[index][start+j] = input_buffer[index][j];
                        }
                        input_pos[index] = start;
                    }
                    else
                        input_pos[index] = 0;
                }
            }
            // delete min and put new
            loser_tree.__delete_min_insert(input_buffer[index][input_pos[index]], false);
            // check if outputbuffer full
            if(output_po == output_size){
                std::swap(output_buffer_tree, output_buffer_disk);
                // write to disk 
                if(t_writeDisk.joinable())
                    t_writeDisk.join();
                t_writeDisk = std::thread(writeDisk, new_name, output_buffer_disk, output_size);
                // writeDisk(new_name, output_buffer_disk, output_size);
                output_po = 0;
            }
        } 
        if(t_writeDisk.joinable())
            t_writeDisk.join();
        // final writeDisk
        std::swap(output_buffer_tree, output_buffer_disk);
        writeDisk(new_name,output_buffer_disk, output_po);

        // close file
        for(int j = 0; j < num_of_reamin_runs; ++j){
            infile[j].close();
        }
        // gc
        delete []output_buffer_tree;
        delete []output_buffer_disk;
        for(int j = 0; j < k; ++j){
            delete[] input_buffer[j];
        }
        delete[] input_buffer;
    } 

    return mergeFiles(i/k, k, epoch, input_size, output_size);
}

} // namespace lab5

int main()
{
    // input file的分块数量
    constexpr int num_ways = 10;
 
    // 每块的大小
    constexpr int run_size = 2000;

    // input size
    constexpr int input_size = 50;

    // output_size
    constexpr int output_size = 500;

    // k-way merge
    constexpr int num_of_way_merge = 8;
 
    std::string input_file = "input.txt";
 
    std::ofstream outfile(input_file, std::ios::trunc|std::ios::out);
 
    std::srand(time(NULL));
 
    // 生成输入文件
    for (int i = 0; i < num_ways * run_size; i++) {
        outfile << rand() << std::endl;
    }
 
    outfile.close();
 
    clock_t start = clock();
    // 读输入文件， 生成初始的runs
    // 分配每个run临时的输出文件
    lab5::createInitialRuns(input_file, run_size, num_ways);
 
    // Merge the runs using the k–way merging
    lab5::mergeFiles(num_ways, num_of_way_merge, 0, input_size, output_size);
    
    printf("Time taken: %.2fs\n", (double)(clock() - start)/CLOCKS_PER_SEC);
    return 0;
}