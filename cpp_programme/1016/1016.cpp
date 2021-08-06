#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
using namespace __gnu_cxx;
bool find_equ(vector<float>arr,int key);
int main()
{
	int num;
	std::cin>>num;
	bool* count=new bool[num];
	for(int i=0;i<num;i++)
	{
		int sum,key;
		std::cin>>sum>>key;
		vector<float>arr;
		for(int i=0;i<sum;i++)
		{
			int temp;
			std::cin>>temp;
			arr.push_back(temp);
		}
		count[i]=find_equ(arr,key);
	}
	for(int i=0;i<num;i++)
	{
		if(count[i])
			std::cout<<"YES"<<endl;
		else
			std::cout<<"NO"<<endl;
	}
	delete[] count;
}

bool find_equ(vector<float>arr, int key)
{
	int len=arr.size();
	unordered_set<float> map;
	for(int i=0;i<len;i++)
		map.insert(arr[i]);
	for(int i=0;i<len;i++)
	{
		float second_key=key/arr[i];
		if(map.find(second_key)!=map.end())
			return true;
	}
	return false;
}
