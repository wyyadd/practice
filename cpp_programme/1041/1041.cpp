#include <stdio.h>
#include<iostream>

namespace{
class Solve{
 public:
	Solve(){};
	~Solve(){};
	void Initial(){

	}
	void Get_Answer(){
	}
	void Print(){
	}
 private:
	
};
}//namespace
//1 2 3 4 5 6
//7 8 9 10 11 12
//1 3 5 7 9 11 13
//2 4 6 8 10 12 14 16 18 19
int main(){
	int num;
	scanf("%d",&num);
	Solve* foo =new Solve[num];
	for(int i = 0; i < num; ++i)
		foo[i].Initial();
	for(int i = 0; i < num; ++i){
		printf("Case #%d: ", i+1);
		foo[i].Print();
	}
	delete []foo;
}

