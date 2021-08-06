#include <iostream>
#include <stdexcept>
using namespace std;
class TestException: public runtime_error
{
public:
	TestException()
		:runtime_error("Invalid number! ")
	{
	}
private:

};
int main()
{
	int a=0;
	while(cin>>a)
	{
		try
		{
			if(a==0) throw TestException();
			else cout<<"Yes, a!=0. "<<endl;
		}

		catch(TestException &a)
		{
			cout<<a.what()<<endl;
			throw TestException();
		}
	}
}

