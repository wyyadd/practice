#include <iostream>
#include <stdio.h>

namespace{
typedef long long int lint;
class Solve{
 public:
	Solve(){};
	~Solve(){
		delete[] sum_;
	}
	void Initial(){
		scanf("%d %d",&n_,&k_);
		sum_ =  new lint[n_];

		lint temp;
		scanf("%lld",&temp);
		sum_[0] = temp;
		for(int i = 1;i < n_;++i){
			scanf("%lld",&temp);
			sum_[i] = sum_[i-1] + temp;
		}

		max_ = Get_Answer(n_-1, k_);
	}
	void Print(){
		printf("%lld\n",max_);
	}
	long long int Get_Answer(int po, int k){
		if(k == 0){
			return sum_[po];
		}
		lint max1 = 0;
		for(int x = 1; x<=po-k+1; ++x){
		max1 = std::max(max1, Get_Answer(po-x,k-1) * (sum_[po]-sum_[po-x]));
		}
		return max1;
	}
 private:
	int n_;
	int k_;
  lint max_ = 0;
	lint* sum_;
};
}//namespace

int main(){
	int num;
	scanf("%d",&num);
	Solve* foo = new Solve[num];
	for(int i = 0;i < num; ++i)
		foo[i].Initial();
	for(int i = 0; i < num; ++i)
		foo[i].Print();
	delete[] foo;
}
