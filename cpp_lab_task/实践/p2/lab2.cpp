#include <iostream>
#include <fstream>
#include <ctime>
#include <queue>
#include <limits.h>
#include <algorithm>

namespace lab2 {
    class QucikSort {
    public:
        QucikSort() {
            initDisk();
        }

        void sort(int left, int right) {
            // break
            if (right - left <= middleSize_) {
                // printf("right:%d, left:%d\n",right,left);
                int size = right - left;
                int arr[size];
                readFromDisk(left, right, size, arr);
                std::sort(arr, arr + size);
                writeDisk(left, true, size, arr);
                return;
            }
            // init array and read disk
            int total = right - left;
            int middle[middleSize_];
            int small[smallSize_];
            int smallPo = 0;
            int big[bigSize_];
            int bigPo = 0;
            int input[inputSize_];
            int inputPo = 0;
            readFromDisk(left, right, middleSize_, middle);
            readFromDisk(left + middleSize_ / 2, right - middleSize_ / 2, inputSize_, input);
            int diskpo = middleSize_ / 2 + inputSize_ / 2;
            int w_diskLeft = left;
            int w_diskRight = right;
            // init heap and min and max
            std::priority_queue<int> queue;
            int min = INT_MAX;
            for (int i = 0; i < middleSize_; ++i) {
                queue.emplace(middle[i]);
                if (middle[i] < min)
                    min = middle[i];
            }
            int max = queue.top();
            // recursive
            for (int i = 0; i < total - middleSize_; ++i) {
                // input is empty
                if (inputPo == inputSize_) {
                    readFromDisk(left + diskpo, right - diskpo, inputSize_, input);
                    diskpo += inputSize_ / 2;
                    inputPo = 0;
                }
                // if smaller than min
                if (input[inputPo] <= min) {
                    // small is full
                    if (smallPo == smallSize_) {
                        writeDisk(w_diskLeft, true, smallSize_, small);
                        w_diskLeft += smallSize_;
                        smallPo = 0;
                    }
                    small[smallPo++] = input[inputPo++];
                    continue;
                }
                // big is full
                if (bigPo == bigSize_) {
                    writeDisk(w_diskRight, false, bigSize_, big);
                    w_diskRight -= bigSize_;
                    bigPo = 0;
                }
                // if greater than max
                if (input[inputPo] >= max) {
                    big[bigPo++] = input[inputPo++];
                    continue;
                }
                // if between min and max
                big[bigPo++] = max;
                queue.pop();
                queue.emplace(input[inputPo++]);
                max = queue.top();
            }
            writeDisk(w_diskLeft, true, smallPo, small);
            writeDisk(w_diskRight, false, bigPo, big);
            // sort middle write to disk
            for (int i = middleSize_ - 1; i >= 0; --i) {
                middle[i] = queue.top();
                queue.pop();
            }
            w_diskLeft += smallPo;
            w_diskRight -= bigPo;
            writeDisk(w_diskLeft, true, middleSize_, middle);
            // recursive
            sort(left, w_diskLeft);
            sort(w_diskRight, right);
        }

        void readFromDisk(int left, int right, int size, int *arr) {
            readDisk_++;
            std::ifstream infile("disk", std::ios::binary | std::ios::in);
            if (!infile.is_open())
                throw std::runtime_error("cannot open memory file");
            infile.seekg(left * sizeof(int), std::ios::beg);
            for (int i = 0; i < size / 2; ++i) {
                int n;
                infile.read((char *) &n, sizeof(int));
                arr[i] = n;
            }
            infile.seekg((right - size / 2) * sizeof(int), std::ios::beg);
            for (int i = size / 2; i < size; ++i) {
                int n;
                infile.read((char *) &n, sizeof(int));
                arr[i] = n;
            }
            infile.close();
        }

        void writeDisk(int po, bool if_left, int size, int *arr) {
            writeDisk_++;
            if (size == 0)
                return;
            int memory[number_];
            readFromDisk(0, number_, number_, memory);
            if (if_left) {
                // printf("left:");
                for (int i = po; i < size + po; ++i) {
                    memory[i] = arr[i - po];
                    // printf("%d ",arr[i-po]);
                }
                // printf("\n");
            } else {
                // printf("right:");
                for (int i = po - size; i < po; ++i) {
                    memory[i] = arr[i + size - po];
                    // printf("%d ",arr[i+size-po]);
                }
                // printf("\n");
            }
            std::ofstream outfile("disk", std::ios::out | std::ios::binary | std::ios::trunc);
            for (int i = 0; i < number_; ++i) {
                int n = memory[i];
                outfile.write((char *) &n, sizeof(int));
            }
            // printf("\n");
            outfile.close();
        }

        void initDisk() {
            std::srand(std::time(nullptr));
            std::ofstream outfile("disk", std::ios::trunc | std::ios::binary);
            for (int i = 0; i < number_; ++i) {
                int ri = rand() % number_;
                outfile.write((char *) &ri, sizeof(int));
            }
            outfile.close();
        }

        void test() {
            std::ifstream infile("disk", std::ios::binary | std::ios::in);
            for (int i = 0; i < number_; ++i) {
                int n;
                infile.read((char *) &n, sizeof(int));
                printf("%d ", n);
            }
            printf("\nreadDisk:%d writeDisk:%d\n", readDisk_, writeDisk_);
        }

        const int number_ = 1000;
        int readDisk_ = 0;
        int writeDisk_ = 0;
    private:
        const int inputSize_ = 60;
        const int smallSize_ = 30;
        const int bigSize_ = 30;
        const int middleSize_ = 100;
    };
}// namespace lab2

int main() {
    lab2::QucikSort q;
    q.sort(0, q.number_);
    q.test();
}
