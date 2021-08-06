#include <iostream>
#include <string>
using namespace std;
class Date
{
public:
	Date(int y=2014, int m=1, int d=1)
		:year(y), month(m), day(d)
	{
	}
	void setDate(Date d)
	{
		year=d.year;
		month=d.month;
		day=d.day;
	}
	void print()
	{
		cout<<"Test Date: "<<year<<"-"<<month<<"-"<<day;
	}
private:
	int year, month, day;
};
class FinalTest
{
public:
	FinalTest(string t="NULL", Date d = NULL)
		:title(t), time(d)
	{
	}
	void setDate(Date d)
	{
		time.setDate(d);
	}
	void print()
	{
		cout<<"Title: "<<title<<endl;
		time.print();
		cout<<endl;
	}
private:
	string title;
	Date time;
};
int main()
{
	FinalTest item1("C++ Test", Date(2014,6,2));
	item1.print();
	FinalTest item2("Java");
	item2.print();
	item2.setDate(Date(2014,6,10));
	item2.print();
}

