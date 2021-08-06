#include <iostream>
#include <stdexcept>
using namespace std;
class TestException: public runtime_error
{
public:
	TestException()
		:runtime_error("Caught TestException ")
	{
	}
private:

};

void h()
{
	throw TestException();
}
void g()
{
	h();
}
void f()
{
	g();
}  //注意三个函数的先后定义!

int main()
{
	try
	{
		f();
	}
	catch(TestException &a)
	{
		cout<<"In main: "<<a.what()<<endl;
	}
}

