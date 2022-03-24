#include <iostream>
using namespace std;

class A{
public:
    virtual void fun(int i){
        cout << "A" << i << endl;
    }

    void foo(int i){
        cout << "fooA" << i << endl;
    }
};

class B: public A{
public:
    void fun(int i){
        cout << "B"  << i << endl;
    }

    void foo(int i){
        cout << "fooB" << i << endl;
    }
};

int main(){
    A *a = new B;
    a->fun(1);
    a->A::fun(1);
    a->foo(1);
}