#include<iostream>
#include<unordered_map>
using namespace std;

int proved_max_price(unordered_map<int,int> p_table,int length);

int main()
{
	int num;
	cin >> num;
	if(num>10)
		exit(1);
	int* count = new int[num];
	for (int i = 0; i < num; i++)
	{
		int length,amount;
		cin>>length>>amount;
		unordered_map<int,int>p_table;
		//map<int,int>p_table;
	for (int i = 0; i < amount; i++)
		{
			int len,price;
			cin>>len>>price;
			p_table[len]=price;
		}
		count[i]=proved_max_price(p_table,length);
	}
	for (int i = 0; i < num; i++)
		cout << count[i] << endl;
	delete[]count;
}


int proved_max_price(unordered_map<int,int> p_table,int length)
{
	int* arr=new int[length+1];
	arr[0]=0;	
	for(int l=1;l<=length;l++)
	{
		int max0=-1;
		if(p_table.find(l)==p_table.end())
			max0=0;
		else
			max0=p_table[l];
		for(int i=1;i<=l/2;i++)
		{
			max0=max(max0,arr[i]+arr[l-i]);
		}
		arr[l]=max0;
	}
/*	for(int i=1;i<=length;i++)
	{
		cout<<arr[i]<<'\t';
		if((i+1)%10==0)
			cout<<endl;
		
	}*/
	int temp=arr[length];
	delete[] arr;
	return temp;
}
