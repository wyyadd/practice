#include <thread>
#include <mutex>
#include <iostream>
using namespace std;

std::mutex mtx;

void foo1(){
    for(int i = 0; i < 10; ++i){
        mtx.lock();
        cout << i << endl;
        mtx.unlock();
        this_thread::sleep_for(chrono::milliseconds(1));
    }
}

class basic
{
private:
public:
    void bar1(int n){
        cout << n << endl;
    }

    static void bar2(int n){
        cout << n << endl;
    }
};

int main(){
    thread t1(foo1);
    thread t2(foo1);
    t1.join();
    t2.join();
}