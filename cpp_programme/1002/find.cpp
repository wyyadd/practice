#include<iostream>

using namespace std;

int main()
{
	int n;
	cin>>n;
	if(n>=100)
		exit(1);
	int* min=new int[n];
	for(int i=0;i<n;i++)
	{
		int sum;
		cin>>sum;
		if(sum<=0||sum>=1000)
			exit(1);
		int* arr=new int[sum];
		int temp;
		for(int x=0;x<sum;x++)//input
		{	
			cin>>temp;
			arr[x]=temp;
		}
		for(int j=0;j<2;j++)//bubble sort
		{
			for(int k=sum-1;k>j;k--)
			{
				if(arr[k]<arr[k-1])
					swap(arr[k],arr[k-1]);
			}
		}
		min[i]=arr[1];
		delete []arr;
	} 
	for(int i=0;i<n;i++)
	        cout<<min[i]<<endl;
	delete[] min;
}

