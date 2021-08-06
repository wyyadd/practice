#include <iostream>
#include <stdio.h>
#include <tuple>
#include <vector>
#include <algorithm>

namespace{
using std::vector;
using std::tuple;

class Solve{
 public:
	Solve(){};
	~Solve(){
		delete[] former_act_;
	}
	void Print(){
		printf("%d\n",max_);
	}
	int Get_Max(){
		return max_;
	}
	static bool compare(const tuple<int,int,int>& x, const tuple<int,int,int>& y){
		return std::get<1>(x) < std::get<1>(y);
	}

	void Initial(){
		scanf("%d",&num_);
		former_act_ = new int[num_];
		for(int i = 0; i < num_; ++i){
			int a,b,c;
			scanf("%d %d %d",&a,&b,&c);
			activity_.push_back(std::make_tuple(a,b,c));
		}
		Sort_Activity();
		Get_Answer();
	}
	
	void Sort_Activity(){
		std::sort(activity_.begin(),activity_.end(), compare);
		for(int i = 0; i < num_; ++i)
			former_act_[i] = 0;
		for(int i = (int)activity_.size() - 1; i >= 0; --i){
			int start_time = std::get<0>(activity_[i]);
			for(int j = i - 1; j >= 0; --j){
				if(std::get<1>(activity_[j]) <= start_time){
					former_act_[i] = j + 1;
					break;
				}
			}
		}
	}	

	void Get_Answer(){
		int max_value[num_+1] = {0};
		for(int i = 0; i < num_; ++i){
			max_value[i+1] = std::max(max_value[former_act_[i]] + std::get<2>(activity_[i]), max_value[i]);
		}
		max_ = max_value[num_];
	}
 private:
	vector<tuple<int,int,int>> activity_;
	int num_;
	int max_;
	int* former_act_;
};

}//namespace

int main(){
	int n;
	scanf("%d",&n);
	vector<int> result;
	for(int i = 0; i < n; ++i){
		Solve foo;
		foo.Initial();
		result.push_back(foo.Get_Max());
	}
	for(int i = 0; i < n; ++i)
		printf("%d\n",result[i]);
}
