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
       int* count=new int[num];
        for(int i=0;i<num;i++)
	{
		int sum;
		cin>>sum;
		if(sum>50000)
			exit(1);
		int* arr=new int[sum];
		for(int j=0;j<sum;j++)
			cin>>arr[j];
		flag=0;
                merge_sort(arr,sum);
		count[i]=flag;
	}	
	for(int i=0;i<num;i++)
	{
		cout<<count[i]<<endl;
	}
	delete []count;
}

void merge_sort(int* arr,int n)
{
	int* temp=new int[n];
	sort(arr,0,n-1,temp);
	delete[] temp;
}

void sort(int* arr, int left, int right, int* temp)
{
	while(left<right)
	{
		int mid=(left+right)/2;
		sort(arr,left,mid,temp);
		sort(arr,mid+1,right,temp);	
		merge(arr,left,mid,right,temp);
		return;
	}
}

void merge(int* arr, int left, int mid, int right, int* temp)
{
	int i=left,j=mid+1,k=0,w=-1;
	while(i<=mid&&j<=right)
	{
		if(arr[i]<=arr[j])
		{
			temp[k++]=arr[i++];
			if(w!=-1&&w!=i-1)
			{
				flag+=j-mid-1;
			}
		}
		else
		{
			temp[k++]=arr[j++];
		//	if(i<j-1)
		//		flag++;
			if(w==i||w==-1)
			{
				w=i;
				flag++;
				continue;
			}	
			flag+=j-mid-1;
			w=i;
		}	
	}
	if(i<=mid)
		flag-=j-mid-1;
	while(i<=mid)
	{
		temp[k++]=arr[i++];
		flag+=j-mid-1;
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
