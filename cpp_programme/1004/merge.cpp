#include <iostream>
using namespace std;
void merge_sort(int *arr, int n);
void sort(int* arr, int left, int right, int* temp);
void merge(int* arr, int left, int mid, int right, int* temp);
int flag;
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
                merge_sort(arr,sum);
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

void merge_sort(int* arr,int n)
{
	flag=n;
	int* temp=new int[n];
	sort(arr,0,n-1,temp);
}

void sort(int* arr, int left, int right, int* temp)
{
	while(left<right)
	{
		int mid=(left+right)/2;
		sort(arr,left,mid,temp);
		sort(arr,mid+1,right,temp);
		if((right-left+1)>=flag/2)
			return;
		merge(arr,left,mid,right,temp);
		return;
	}
}

void merge(int* arr, int left, int mid, int right, int* temp)
{
	int i=left,j=mid+1,k=0;
	while(i<=mid&&j<=right)
	{
		if(arr[i]<arr[j])
			temp[k++]=arr[i++];
		else
			temp[k++]=arr[j++];
	}
	while(i<=mid)
	{
		temp[k++]=arr[i++];
	}
	while(j<=right)
	{
		temp[k++]=arr[j++];
	}
	k=0;
	while(left<=right)
	{
		arr[left++]=temp[k++];
	}
}
