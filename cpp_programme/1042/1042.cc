#include <stdio.h>
#include <iostream>

namespace{
class Solve{
 public:
	Solve(){
		scanf("%d",&num_of_days_);
		days_ = new int [num_of_days_];
		for(int i = 0; i < num_of_days_; ++i)
			scanf("%d",days_+i);
		for(int i = 0; i < 3; ++i)
			scanf("%d",cost_+i);
	}
	~Solve(){
		delete[] days_;
	}
	void Get_Answer(){
		int last_day = days_[num_of_days_-1];
		int* dp = new int[last_day + 1];
		dp[0] = 0;
		int po = 0;
		for(int i = 1; i <= last_day; ++i){
			if(i == days_[po]){
				int week = i - 7 > 0 ? i - 7 : 0;
				int month = i -30 > 0 ? i - 30 : 0;
				dp[i] = std::min(dp[i-1]+cost_[0], std::min(dp[week]+cost_[1], dp[month]+cost_[2]));
				++po;
			}
			else
				dp[i] = dp[i-1];
		}
		min_ = dp[last_day];
	}
	void Print(){
		Get_Answer();
		printf("%d\n",min_);
	}
 private:
	int min_;
	int cost_[3];
	int num_of_days_;
	int *days_;
};
}//namespace

int main(){
	int num;
	scanf("%d", &num);
	Solve* foo = new Solve[num];
	for(int i = 0; i < num; ++i){
		foo[i].Print();
	}
	delete[] foo;
}
