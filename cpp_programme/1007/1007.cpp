#include<iostream>
#include<string>

int flag;

using namespace std;
void max_multiple(string ls,int part,int po=0,int multiple=1);
int main()
{
	int num;
	cin>>num;
	int* max =new int[num];
	for(int i=0;i<num;i++)
	{
		flag=0;
		int len;
		int part;
		cin>>len>>part;
		string temp;
		cin>>temp;
		max_multiple(temp,part+1);
		max[i]=flag;
	}
	for(int i=0;i<num;i++)
		cout<<max[i]<<endl;
	delete[]max;
}

void max_multiple(string ls,int part,int po,int multiple)
{
	if(part==1)
	{
		string temp=ls.substr(po,ls.length()-po);
		multiple*=stoi(temp);
		if(multiple>=flag)
			flag=multiple;
		return;
	}
	for(int i=po+1;i<=ls.length()-part+1;i++)
	{
		string temp=ls.substr(po,i-po);
		max_multiple(ls,part-1,i,multiple*stoi(temp));
	}
}
