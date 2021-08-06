#include <stdio.h>
#include<iostream>
#include<string>
#include<math.h>
namespace{
using std::string;
typedef long long int ll;
class Solve{
 public:
	Solve(){};
	~Solve(){};
	void Initial(){
		scanf("%lld%lld",&N,&K);
		std::cin>>str;
		max_ = 0;
	}
	void Get_Answer(){
		ll half = (N-1)/2;
		ll count;
		int temp = 1;
		for(ll i = 0; i <= half; ++i){
			count = (int)str[i] - (int)'a' + 1;
			for(ll j = 1; j < count; ++j){
				temp = 1;	
				for(ll j1 = i; j1 < half; ++j1)
					temp*=K;
				if(temp!=1)
					max_+=temp;
			}
		}
		if(max_!=0)
			max_ += count-1;
		else
			max_ = count -1;
		if(N%2!=0){
			for(ll i = 1; i <= half; ++i){
				if(str[half+i]>str[half-i]){
					++max_;
					break;
				}
				else{
					if(str[half+i]<str[half-i])
						break;
				}
			}
		}
		else{
			for(ll i = 0; i <=half; ++i){
				if(str[half+i+1]>str[half-i]){
					++max_;
					break;
				}
				else{
					if(str[half+i+1]<str[half-i])
						break;
				}
			}
		}
	}
	void Print(){
		Get_Answer();
		ll temp = pow(10,9) + 7;
		max_ = max_% temp;
		printf("%lld\n",max_);
	}
private:
	ll N;
	ll K;
	ll max_;
	string str;
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
