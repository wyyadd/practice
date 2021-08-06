#include <iostream>
#include <stdio.h>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

template<typename T>
bool palindrome(T arr){
	int num = arr.size();
	for(int i = 0; i < num/2; ++i){
		if(arr[i]!=arr[num-i-1]){
			cout<<"false"<<endl;
			return false;
		}
	}
	cout<<"true"<<endl;
	return true;
}

int main(){
	vector<int> test1 = {1,2,3,4,5};
	vector<int> test2 = {1,2,3,2,1};
	vector<int> test3 = {'a','b','c','b','a'};
	palindrome(test1);
	palindrome(test2);
	palindrome(test3);
}
