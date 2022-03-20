#include <iostream>
using namespace std;

class A{
public:
    virtual void fun(int i){
        cout << "A" << i << endl;
    }
};

class B: public A{
public:
    void fun(int i){
        cout << "B"  << i << endl;
    }
};

int main(){
    A *a = new B;
    a->fun(1);
    a->A::fun(1);
}