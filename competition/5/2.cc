#include <stdio.h>
#include<iostream>

namespace{
typedef long long int ll;
class Solve{
 public:
	Solve(){};
	~Solve(){};
	void Initial(){
		scanf("%lld",&G);
		num = 1;
	}
	void Get_Answer(){
		ll K;
		ll foo = G/2;
		for(K = 1; K < G; ++K){
			while(--foo){
				int sum = 0;
				sum = (K+foo)*(foo-K+1)/2;
				if(sum==G){
					++num;
					break;
				}
				if(sum>G)
					break;
			}
		}
	}
	void Print(){
		Get_Answer();
		printf("%d\n",num);
	}
 private:
	ll G;	
	int num;
};
}//namespace

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

