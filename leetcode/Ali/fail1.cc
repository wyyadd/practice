#include <bits/stdc++.h>
using namespace std;
class A
{
public:
    A
    (/* args */){};
    virtual void fun1(){cout << "A";};
};

class B : public A
{
public:
    B(/* args */){};
    void fun1(){cout << "B";}
};
int main(){
    A* a = new B;
    a->fun1();
}