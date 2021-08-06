#include <iostream>
#include <stdio.h>

namespace{
class Solve{
 public:
	Solve(){};
	~Solve(){};
	void Get_Answer(){};
	void Print(){};
 private:

};
}//namespace


int main(){
	int num;
	scanf("%d", &num);
	Solve *foo = new Solve[num];
	for(int i = 0; i < num; ++i)
		foo.Print();
	delete foo;
}
