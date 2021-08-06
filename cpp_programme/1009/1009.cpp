#include<iostream>
#include<vector>

using namespace std;

void decrease(vector<int>arr,int max,int po);

int flag;

int main()
{
	int num;
	cin>>num;
	int* count=new int[num];
	for(int i=0;i<num;i++)
	{
		flag=0;
		int sum;
		cin>>sum;
		if(sum>=100)
			exit(1);
		vector<int>arr;
		for(int j=0;j<sum;j++)
		{
			int temp;
			cin>>temp;
			arr.push_back(temp);
		}
		decrease(arr,0,-1);
		count[i]=flag;
	}

	for(int i=0;i<num;i++)
	{	
		cout<<count[i]<<endl;
	}
	delete[]count;
}

void decrease(vector<int>arr,int max,int po)
{
	int n=arr.size();
	if(po>=n-1)
	{
		if(max>=flag)
			flag=max;
		return;
	}
	int i;
	for(i=po+1;i<n;i++)
	{
		if(po==-1)
		{
			decrease(arr,max+1,i);
			continue;
		}
		if(arr[po]<arr[i])
			continue;
		decrease(arr,max+1,i);
	}
	if(i==n)
	{
		if(max>=flag)
			flag=max;
		return;
	}
}
