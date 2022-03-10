#include <iostream>
#include <thread>
#include <condition_variable>
std::mutex mtx;
std::condition_variable cv;
char flag = 'A';
void PrintString_1()
{
        std::unique_lock<std::mutex> lk(mtx);
        int cnt = 0;
        while(cnt<10)
        {
                // while(flag != 'A')
                //         cv.wait(lk);
                std::cout<<'A'<<std::endl;
                // ++flag;
                cnt++;
                // cv.notify_all();
        }
}

void PrintString_2()
{
        std::unique_lock<std::mutex> lk(mtx);
        int cnt = 0;
        while(cnt<10)
        {
                // while(flag != 'B')
                //         cv.wait(lk);
                std::cout<<'B'<<std::endl;
                // ++flag;
                cnt++;
                // cv.notify_all();
        }
}

void PrintString_3()
{
        std::unique_lock<std::mutex> lk(mtx);
        int cnt = 0;
        while(cnt<10)
        {
                // while(flag != 'C')
                //         cv.wait(lk);
                std::cout<<'C'<<std::endl;
                // flag = 'A';
                cnt++;
                // cv.notify_all();
        }
}

int main()
{
        std::thread  t1(PrintString_1);
        std::thread  t2(PrintString_2);
        std::thread  t3(PrintString_3);
        t1.join();
        t2.join();
        t3.join();
        return 0;
}