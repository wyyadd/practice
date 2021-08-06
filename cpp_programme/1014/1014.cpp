#include<iostream>
using namespace std;

void max_arr(int* arr, int* max, int len, int po = 0, int sum = 0);
void main_max_arr(int* arr, int* max, int len);
int proved_max_arr(int* arr,int len);
int main()
{
	int num;
	cin >> num;
	int* count = new int[num];
	for (int i = 0; i < num; i++)
	{
		int sum;
		cin >> sum;
		int* arr = new int[sum];
		for (int i = 0; i < sum; i++)
			cin >> arr[i];
		//count[i] = -9999;
		count[i]=proved_max_arr(arr, sum);
		//main_max_arr(arr, count + i, sum);
		delete[] arr;
	}
	for (int i = 0; i < num; i++)
		cout << count[i] << endl;
	delete[] count;
}


void main_max_arr(int* arr, int* max, int len)
{
	max_arr(arr, max, len);
	for (int i = 0; i < len; i++)
	{
		max_arr(arr + i, max, len - i);
	}
}

void max_arr(int* arr, int* max,int len, int po, int sum)
{
	int i = po + 1;
	while(i<=len)
	{
		sum += arr[po];
		max_arr(arr, max, len, i, sum);
		break;
	}
	if (sum > (*max))
		(*max) = sum;
}

int proved_max_arr(int* arr,int n)
{
	int ans = -1000000;
	int sum = 0;
	for (int i=0;i<n;i++)
	{
		sum += arr[i];
		if (sum>ans)
		{
			ans=sum;
		}
		if (sum<0)
		{
			sum = 0;
		}
	}
	return ans;
}