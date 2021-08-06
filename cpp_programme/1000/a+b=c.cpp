#include <iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int *arr=new int[n];
	int a,b;
	for(int i=0;i<n;i++)
	{
		cin>>a>>b;
		arr[i]=a+b;
	}
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<endl;
	}
	delete []arr;
	return 0;
}
