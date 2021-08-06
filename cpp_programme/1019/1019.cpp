#include<iostream>

using namespace std;

void max_price(int* size, int* value, int* number, int* capcity, int* max, int price = 0, int weight = 0, int po = 0);

int proved_max_price(int* size,int* value,int number,int capcity);

int main()
{
	int num;
	cin >> num;
	if(num>10)
		exit(1);
	int* count = new int[num];
	for (int i = 0; i < num; i++)
	{
		int number;
		int capcity;
		cin >> number >> capcity;
		int* size = new int[number];
		int* value = new int[number];
		for (int i = 0; i < number; i++)
			cin >> size[i] >> value[i];
		count[i]=proved_max_price(size, value, number, capcity);
		delete[]size;
		delete[]value;
	}
	for (int i = 0; i < num; i++)
		cout << count[i] << endl;
	delete[]count;
}

void max_price(int* size, int* value, int* number, int* capcity, int* max, int price, int weight, int po)
{
	if (weight > *capcity)
		return;
	if (price > *max)
		*max = price;
	if (po == *number)
		return;
	max_price(size, value, number, capcity, max, price + value[po], weight + size[po], po + 1);
	max_price(size, value, number, capcity, max, price, weight, po + 1);
}

int proved_max_price(int* size,int* value,int number,int capcity)
{
	int arr[number+1][capcity+1];
	for(int i=0;i<capcity+1;i++)
		arr[0][i]=0;
	for(int i=0;i<number+1;i++)
		arr[i][0]=0;
	for(int i=1;i<number+1;i++)
	{
		for(int j=1;j<capcity+1;j++)
		{
			if(size[i-1]>j)
			{
				arr[i][j]=arr[i-1][j];
				continue;
			}
			else
			{
				arr[i][j]=max(arr[i-1][j],arr[i-1][j-size[i-1]]+value[i-1]);
				continue;
			}
			
		}
	}
	for(int i=0;i<number+1;i++)
	{
		for(int j=0;j<capcity+1;j++)
			cout<<arr[i][j]<<'\t';
		cout<<endl;
	}
	return arr[number][capcity];
}
