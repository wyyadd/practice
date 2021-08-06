#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;


int main()
{
	int num;
	cin>>num;
	if(num>=100||num<=0)
		exit(1);
        vector<int>* arr=new vector<int>[num];
	for(int i=0;i<num;i++)
	{
		int sum;
		cin>>sum;
	//	if(sum<=8||sum>=1000)
	//		exit(1);
		for(int j=0;j<sum;j++)
		{
			int temp;
			cin>>temp;
			arr[i].push_back(temp);
		}
		make_heap(arr[i].begin(),arr[i].end(),greater<int>());
	}
	for(int i=0;i<num;i++)
	{	
		for(int j=0;j<arr[i].size();j++)
			cout<<arr[i][j]<<' ';
		cout<<endl;
	}
	delete []arr;
}


