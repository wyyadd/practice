#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int** ls=new int*[n];
	int* num=new int[n];
	for(int i=0;i<n;i++)
	{
		int sum;
		cin>>sum;
		num[i]=sum;
		int* arr=new int[sum];
	        ls[i]=arr;	
		int temp;
		for(int j=0;j<sum;j++)
		{
			cin>>temp;
			arr[j]=temp;
		}
                for(int k=0;k<sum-1;k++)
		{
			if(arr[k]>arr[k+1])
				swap(arr[k],arr[k+1]);
		}
	}
	for(int i=0;i<n;i++)
	{
		int* temp=ls[i];
		for(int j=0;j<num[i];j++)
		{
			cout<<temp[j]<<' ';
		}
		cout<<endl;
		delete [](ls[i]);
	}
}


