#include <iostream>
#include <stdexcept>
using namespace std;
class Item
{
public:
	Item(int n=0)
	{
		cout<<"Item "<<n<<" constructor is called! "<<endl;
		setvalue(n);
	}
	~Item()
	{
		cout<<"Item "<<value<<" destructor is called! "<<endl;
	}
	void setvalue(int n=0)
	{
		if(n==3) throw runtime_error("An exception was thrown ");
		value=n;
	}
private:
	int value;
};
int main()
{
	try
	{
		Item test[3]={Item(1), Item(2), Item(3)};
		cout<<"Initialize successfully! "<<endl;
	}
	catch(runtime_error &a)
	{
		cout<<a.what()<<endl;
	}
}

