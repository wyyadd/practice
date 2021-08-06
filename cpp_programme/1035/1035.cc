#include <stdio.h>
#include <iostream>

namespace{
typedef long long int ll;
class Solve{
 public:
 Solve(){}
 ~Solve(){
	delete[] need_;
	delete[] cost_;
 }
 void Initial(){
	scanf("%lld", &month_);
	need_ = new ll [month_];
	cost_ = new ll [month_];
	min_ = 0;
	for(ll i = 0; i < month_; ++i)
		scanf("%lld",cost_+i);
	for(ll i = 0; i < month_; ++i)
		scanf("%lld",need_+i);
 }
 void Get_Answer(){
	for(ll i = 0; i < month_; ++i){
		if(i > 0)
			cost_[i] = std::min(cost_[i], cost_[i-1]+1);
		min_ += cost_[i]*need_[i];
	}
 }
 void Prll(){
	Get_Answer();
	printf("%lld\n",min_);
 }
 private:
	ll min_;
	ll month_;
	ll* need_;
	ll* cost_; 
};
}// namespace

int main(){
	ll num;
	scanf("%lld",&num);
	Solve* foo = new Solve[num];
	for(ll i = 0; i < num; ++i)
		foo[i].Initial();
	for(ll i = 0; i < num; ++i)
		foo[i].Prll();	
	delete[] foo;
}
