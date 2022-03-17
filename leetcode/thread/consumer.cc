#include <iostream>                // std::cout
#include <thread>                // std::thread, std::this_thread::yield
#include <mutex>                // std::mutex, std::unique_lock
#include <condition_variable>    // std::condition_variable
using namespace std;
std::mutex mtx;
std::condition_variable cv;

int n = 10;
int food = 10;

// 消费者线程.
void consume(){
    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::unique_lock <std::mutex> lck(mtx);
        if(food == 0)
            cv.wait(lck, [](){return food != 0;});
        std::cout << "consume food: " << --food << std::endl;
        cv.notify_one();
    }
}

// 生产者线程, 生产 n 个物品.
void produce(){
    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::unique_lock <std::mutex> lck(mtx);
        if(food == n)
            cv.wait(lck, [](){return food != n;});
        std::cout << "produce food: " << ++food << std::endl;
        cv.notify_one();
    }
}

int main()
{
    std::thread consumer_thread1(consume); // 消费者线程.
    std::thread consumer_thread2(consume); // 消费者线程.
    std::thread consumer_thread3(consume); // 消费者线程.
    std::thread produce_thread1(produce); // produce thread
    std::thread produce_thread2(produce); // produce thread
    consumer_thread1.join();
    consumer_thread2.join();
    consumer_thread3.join();
    produce_thread1.join();
    produce_thread2.join();
    return 0;
}