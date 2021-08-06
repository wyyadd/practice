#include <iostream>

using namespace std;

int search_tree(int* arr,int key,int left,int right,int father,int* flag);
int main()
{
	int num;
	cin>>num;
	int* count=new int[num];
	int* flag=new int[num];
	for(int i=0;i<num;i++)
	{
		int sum;
		int key;
		cin>>sum>>key;
//		if(num<1000||num>20000)
//			exit(1);
		int* arr=new int[sum];
		for(int i=0;i<sum;i++)
		{
			cin>>arr[i];
		}
		flag[i]=0;
		count[i]=search_tree(arr,key,0,sum-1,key,flag+i);
		delete[] arr;
	}
	for(int i=0;i<num;i++)
	{
		if(flag[i]>0)
			cout<<"success, father is "<<count[i]<<endl;
		else
			cout<<"not found, father is "<<count[i]<<endl;
	}
	delete[]count;
	delete[]flag;
}

int search_tree(int* arr, int key, int left,int right,int father,int* flag)
{
	if(right<left)
	{
		(*flag)=-1;
		return father;
	}
	int mid=(left+right)/2;
	if(arr[mid]==key)
	{
		(*flag)=1;
		return father;
	}
	if(arr[mid]>key)
		return search_tree(arr,key,left,mid-1,arr[mid],flag);
	else
		return search_tree(arr,key,mid+1,right,arr[mid],flag);
}
