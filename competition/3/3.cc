#include <stdio.h>
#include <iostream>
#include <unordered_set>
#include <math.h>
namespace{
bool if_zhi(int key){
	if(key < 2)
		return 0;
	for(int i = 2; i <= sqrt(key); ++i)
		if(key%i == 0)
			return 0;
	return 1;
}

int solve(int key){
	if(if_zhi(key))
		return 1;
	if(key%2 == 0 || if_zhi(key-2))
		return 2;
	return 3;
}
}//namespcae

int main(){
	int num;
	scanf("%d",&num);
	int* key = new int[num];
	for(int i = 0; i < num; ++i)
		scanf("%d",key+i);
	for(int i = 0; i < num; ++i)
		printf("%d\n",key[i]-solve(key[i]));
	delete[] key;
}
