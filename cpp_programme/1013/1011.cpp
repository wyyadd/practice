#include <iostream>

using namespace std;

int find_ni(int* arr, int num);
int find();
int main()
{
	int sum;
	cin>>sum;
	int* ls=new int[sum];
	for(int i=0;i<sum;i++)
	{
		ls[i]=find();
	}
	for(int i=0;i<sum;i++)
		cout<<ls[i]<<endl;
	delete[]ls;
}

int find()
{
	int sum;
	cin>>sum;
	int* arr=new int[sum];
	for(int i=0;i<sum;i++)
		cin>>arr[i];
	return find_ni(arr,sum);
}

int find_ni(int* arr, int sum)
{
	int flag=0;
	for(int i=0;i<sum;i++)
	{
		for(int j=i+1;j<sum;j++)
		{
			if(arr[i]>arr[j])
				flag++;
		}
	}
	return flag;
}
