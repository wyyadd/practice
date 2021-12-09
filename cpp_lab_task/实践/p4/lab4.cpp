#include <iostream>
#include <algorithm>
#include <queue>
#include <fstream>
#include <vector>
#include <time.h>
#include <thread>
#include <future>
#include <parallel/losertree.h> 
#include <assert.h>


namespace lab4{
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

void writeDisk(string name, std::priority_queue<int, std::vector<int>, std::greater<int>> *heap, int heap_size){
    std::ofstream outfile(name, std::ios::app);
    while (!heap->empty())
    {
        outfile << heap->top() << std::endl;
        heap->pop();
    }
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
    bool more_input = true;
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
        // for(int i = 0; i < num; ++i){
        //     outfile[next_output_file] << diskBuffer_output[i] << std::endl;
        // }

        if(num != run_size){
            assert(infile.eof());
            std::swap(treeBuffer,diskBuffer_input);
            std::sort(treeBuffer,treeBuffer+run_size);
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
void mergeFiles(int num, int epoch, int input_size, int output_size){
    // end condition
    if(num == 1){
        return;
    }
    string prefix = "epoch_" + std::to_string(epoch) + "_run_";
    ++epoch;
    // input buffer
    int input_1[input_size]; int po_1 = 0;
    int input_2[input_size]; int po_2 = 0;
    // output buffer
    std::priority_queue<int, std::vector<int>, std::greater<int>> heap; int heap_size = 0;
    int i;
    for(i = 0; i < num-1; i+=2){
        string new_name= "epoch_" + std::to_string(epoch) + "_run_" + std::to_string(i/2);
        // read runs
        std::ifstream ifstream1(prefix+std::to_string(i), std::ios::in);
        std::ifstream ifstream2(prefix+std::to_string(i+1), std::ios::in);
        while (!ifstream1.eof() || !ifstream2.eof()){
            // po_1 = size of input buffer
            po_1 = feedInput(&ifstream1, input_1, input_size);
            po_2 = feedInput(&ifstream2, input_2, input_size);
            for(int k = 0; k < std::max(po_1, po_2); ++k){
                if(k < po_1){
                    heap.emplace(input_1[k]);
                    ++ heap_size;
                    if(heap_size == output_size){
                        // write to disk
                        writeDisk(new_name,&heap, heap_size);
                        heap_size = 0;
                    }
                }
                if(k < po_2){
                    heap.emplace(input_2[k]);
                    ++ heap_size;
                    if(heap_size == output_size){
                        // write to disk
                        writeDisk(new_name,&heap,heap_size);
                        heap_size = 0;
                    }
                }
            }
        }
        // write to disk
        writeDisk(new_name,&heap,heap_size);
        heap_size = 0;
        // close file
        ifstream1.close();
        ifstream2.close();
    } 
    if(i == num)
        return mergeFiles( num/2, epoch, input_size, output_size);
        // even
    else{
        // odd
        string new_name= "epoch_" + std::to_string(epoch) + "_run_" + std::to_string(i/2);
        // copy
        std::ofstream outfile(new_name, std::ios::out);
        std::ifstream infile(prefix+std::to_string(i), std::ios::in);
        outfile << infile.rdbuf();
        infile.close();
        outfile.close();
        return mergeFiles(num/2+1, epoch, input_size, output_size);
    }
}

} // namespace lab3

int main()
{
    // input file的分块数量
    int num_ways = 10;
 
    // 每块的大小
    int run_size = 2000;

    // input size
    int input_size = 100;

    // output_size
    int output_size = 1000;
 
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
    lab4::createInitialRuns(input_file, run_size, num_ways);
 
    // Merge the runs using the k–way merging
    //lab4::mergeFiles(num_ways, 0, input_size, output_size);
    
    printf("Time taken: %.2fs\n", (double)(clock() - start)/CLOCKS_PER_SEC);
    return 0;
}