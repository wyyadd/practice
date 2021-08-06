#include <iostream>
using namespace std;

void quick_sort(int left,int right, int* arr);

int main()
{
	int num;
	cin>>num;
	if(num>=100||num<=0)
		exit(1);
        int** ls=new int*[num];
	int* count=new int[num];
        for(int i=0;i<num;i++)
	{
		int sum;
		cin>>sum;
		if(sum<=8||sum>=1000)
			exit(1);
		int* arr=new int[sum];
		count[i]=sum;
		ls[i]=arr;
		for(int j=0;j<sum;j++)
			cin>>arr[j];
                quick_sort(0,sum-1,arr);
	}
	for(int i=0;i<num;i++)
	{
	        int *temp=ls[i];	
		for(int j=0;j<count[i];j++)
			cout<<temp[j]<<' ';
		cout<<endl;
		delete[] temp;
	}
	delete []count;
	delete []ls;
}

void quick_sort(int left,int right,int* arr)
{//normal: while(left<right)
	while(left<right)
	{

		if(left==right-1)
			return;
		int flag=left+1;
		for(int i=left+1;i<=right;i++)
		{
			if(arr[left]>arr[i])
				swap(arr[flag++],arr[i]);
		}
		swap(arr[--flag],arr[left]);
		quick_sort(left,flag-1,arr);
		quick_sort(flag+1,right,arr);
		return;
	}
}

