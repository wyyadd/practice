#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <string>
#include <ctime>
using namespace std;
int Month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
class IPv4
{
	friend bool cmp(IPv4 &a, IPv4 &b);
public:
	IPv4()
	{
		for(int i=0; i<=3; i++)
		{
			part[i]=rand()%256;
		}
		year=rand()%21+2000;
		month=rand()%12+1;
		day=rand()%Month[month]+1;
		hour=rand()%24;
		minute=rand()%60;
		second=rand()%60;
	}

	void print()
	{
		cout<<part[3];
		for(int i=0; i<=2; i++) cout<<"."<<part[i]; 
		cout<<"\t"<<year<<"-"<<month<<"-"<<day<<"\t"<<setfill('0')<<setw(2)<<hour<<":"<<setw(2)<<minute<<":"<<setw(2)<<second<<endl;
	}

	int year;
	int month;
	int day;
	int hour;
	int minute;
	int second;
	int part[4];
};
void reswap(IPv4 &a, IPv4 &b)
{
	IPv4 temp=a;
	a=b;
	b=temp;
}
bool cmp(IPv4 &a, IPv4 &b)
{
	if(a.year>b.year)  return true;
	else if(a.year==b.year && a.month>b.month)  return true;
	else if(a.year==b.year && a.month==b.month && a.day>b.day)  return true;
	else if(a.year==b.year && a.month==b.month && a.day==b.day && a.hour>b.hour)  return true;
	else if(a.year==b.year && a.month==b.month && a.day==b.day && a.hour==b.hour && a.minute>b.minute)  return true;
	else if(a.year==b.year && a.month==b.month && a.day==b.day && a.hour==b.hour && a.minute==b.minute && a.second>b.second) return true;
	else return false;
}

int main()
{
	srand(time(0));
	IPv4 temp[100];
	for(int i=0; i<=99; i++)
		for(int j=i+1; j<=99; j++)
		    if(cmp(temp[i], temp[j])) reswap(temp[i], temp[j]);
	for(int i=0; i<=99; i++) temp[i].print();

	ofstream visitors("visitors.txt", ios::out);
	if(!visitors)
	{
		cerr<<" Error! "<<endl;
		exit(1);
	}

	for(int i=0; i<=99; i++) visitors<<temp[i].part[3]<<'.'<<temp[i].part[2]<<'.'<<temp[i].part[1]<<'.'<<temp[i].part[0]
								 <<"\t"<<temp[i].year<<"-"<<temp[i].month<<"-"<<temp[i].day
								 <<"\t"<<setfill('0')<<setw(2)<<temp[i].hour<<":"<<setw(2)<<temp[i].minute<<":"<<setw(2)<<temp[i].second<<endl;
}

