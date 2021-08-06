#include<iostream>
using namespace std;

class MyBase31 {
int a, b, c;
public:
MyBase31(int x=0, int y=0, int z=0) :a(x), b(y), c(z)
{
cout << "…-BaseClass31 Object is created!"<< endl;
cout << a << " " << b << " " << c << endl;
}
 int get_a(){return a;}
    int get_b(){return b;}
    int get_c(){return c;}
 
~ MyBase31(){ cout << "…-BaseClass31 Object is destroyed!"<< endl; }
};
class MyBase32 {
int a, b, c;
public:
MyBase32(int x, int y, int z)
{
cout << "…-BaseClass32 Object is created!"<< endl;
cout << a << " " << b << " " << c << endl;
a=x, b=y, c=z;
cout << a << " " << b << " " << c << endl;
}
~ MyBase32(){ cout << "…-BaseClass32 Object is destroyed!"<< endl; }
};
class MyDerived1 : public MyBase31 {
MyBase31 a;
int c;
public:
MyDerived1(int x) : c(x),a(5,6,7), MyBase31(x,8,9)
{
cout << "…-Base Object has been created!" << endl;
cout << "…-Member Object has been created! " << a.get_a() << " " <<a.get_b() << " " 
<< a.get_c() << endl;
cout << "…-Derived Object is created! "<< c << endl;
} 
};
int main()
{
MyDerived1 b(88);
}
