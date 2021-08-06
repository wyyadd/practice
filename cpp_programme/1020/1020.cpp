#include<iostream>

using namespace std;

int proved_max_price(int* row,int* col,int sum);

int main()
{
	int num;
	cin >> num;
	if(num>10)
		exit(1);
	int* count = new int[num];
	for (int i = 0; i < num; i++)
	{
		int sum;
		cin>>sum;
		int* row = new int[sum];
		int* col = new int[sum];
		for (int i = 0; i < sum; i++)
			cin >>row[i] >> col[i];
		count[i]=proved_max_price(row, col, sum);
		delete[]row;
		delete[]col;
	}
	for (int i = 0; i < num; i++)
		cout << count[i] << endl;
	delete[]count;
}

int proved_max_price(int* row,int* col,int sum)
{
	int arr[sum][sum];
	for(int i=0;i<sum;i++)
		arr[i][i]=0;
	for(int i=0;i<sum-1;i++)
	{
		for(int j=0;j<sum-i-1;j++)
		{
			int r=j;
			int l=j+i+1;
			int temp;
			int min=-1;
			for(int k=r;k<l;k++)
			{
				temp=arr[r][k]+arr[k+1][l]+row[r]*col[k]*col[l];
				if(min==-1)
					min=temp;
				if(temp<min)
					min=temp;
			}
			arr[r][l]=min;
		}
	}
	for(int i=0;i<sum;i++)
	{	
		for(int j=0;j<sum;j++)
			cout<<arr[i][j]<<'\t';
		cout<<endl;
	}
	return arr[0][sum-1];
}
