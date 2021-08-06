#include <iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	cin.ignore();
	int *count=new int[n];
	for(int i=0;i<n;i++)
	{
		string sen;
	 	getline(cin,sen);
		count[i]=0;
		for(int j=0;j<sen.length();j++)
		{
			if('0'<=sen[j]&&'9'>=sen[j])
				count[i]++;
		}
	}
	for(int i=0;i<n;i++)
		cout<<count[i]<<endl;
	delete[] count;
}


