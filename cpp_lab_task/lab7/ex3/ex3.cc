#include <iostream>
#include <stdexcept>
using namespace std;
class TestException: public runtime_error
{
public:
	TestException()
		:runtime_error("")
	{
	}
private:

};
void g()
{
	try
	{
		throw TestException();
	}
	catch(...)
	{
		cout<<"Exception caught in function g(). Rethrowing... "<<endl;
		throw TestException();
	}
}
int main()
{
	try
	{
		g();
	}
	catch(TestException &)
	{
		cout<<"Exception caught in function main() "<<endl;
	}
}

