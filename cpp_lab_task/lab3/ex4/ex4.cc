#include <iostream>
using namespace std;
class MyBase {
int x;
public:
MyBase(int a):x(a);
int getX(){ cout << "" << endl; return x; }
};
class MyDerived : public MyBase {
int y;
public:
MyDerived(int a):y(a),MyBase(a+4);
int getY(){ cout << ""<< endl; return Y; }
};
int main()
{
MyBase a(2), *p = a,;
MyDerived b(4), *q=b;
MyBase &c = a;
MyBase &d = b;
cout << a.getX() << " "<< p-> getX() << endl;
cout << b.getY() << " " << q-> getY() << b.getX() << " " << q-> getX() << endl;
a = b;
cout << a.getX() << " " << a.getY() << endl;
p = q;
cout << p->getX() << " " << p->getY() << endl;
cout << c.getX() << " " << d.getX() << " "<< d.getY() << endl;
b = a;
cout << b.getX() << " " << b.getY() << endl;
}
