#include <iostream>
#include <stdio.h>
#include <tuple>
#include <vector>
#include <climits>

namespace{
using std::vector;
using std::tuple;

class Solve{
 public:
	Solve(){};
	~Solve(){};
	void Initial(){
		scanf("%d",&num_);
		upper_bound_ = INT_MIN;
		lower_bound_ = INT_MAX;
		for(int i = 0; i < num_; ++i){
			int a,b,c;
			scanf("%d %d %d",&a,&b,&c);
			if(a < lower_bound_)
				lower_bound_ = a;
			if(b > upper_bound_)
				upper_bound_ = b;
			activity_.push_back(std::make_tuple(a,b,c));
		}
		Get_Answer();
	}
	void Print(){
		printf("%d\n",max_);
	}
	
	int Get_Max(){
		return max_;
	}

	int Check(int **pd, const int k, vector<int>& marks){
		int check_flag = 1;
		auto act = activity_[k-1];
		int start = std::get<0>(act) - lower_bound_;
		int end = std::get<1>(act) - lower_bound_;
		for(int i = start; i < end; ++i){
			if(pd[k-1][i] < 0){
				check_flag = 0;
				int temp = i - 1;
				while(pd[k-1][temp] < 0)
					--temp;
				marks.push_back(pd[k-1][temp]);
				auto temp_act = activity_[pd[k-1][temp]-1];
				i = temp +	std::get<1>(temp_act) - std::get<0>(temp_act); 
				continue;
			}
			if(pd[k-1][i] > 0){
				check_flag = 0;
				marks.push_back(pd[k-1][i]);
				auto temp_act = activity_[pd[k-1][i]];
				i = i +	std::get<1>(temp_act) - std::get<0>(temp_act); 
				continue;
			}
		}
		return check_flag;
	}

	void Make_Flag(int** dp, int k, int up){
		for(int i = 0; i < up; ++i)
			dp[k][i] = dp[k-1][i];
		auto act = activity_[k-1];
		int start = std::get<0>(act) - lower_bound_;
		int end = std::get<1>(act) - lower_bound_;
		for(int i = start + 1; i < end; ++i)
			dp[k][i] = -1;
		dp[k][start] = k;
		}

		void Erace_Flag(int** dp, vector<int>& marks, int k){
			for(size_t i = 0; i < marks.size(); ++i){
				auto act = activity_[marks[i]-1];
				int start = std::get<0>(act) - lower_bound_;
				int end = std::get<1>(act) - lower_bound_;
				for(int j = start; j < end; ++j)
					dp[k][j] = 0;
			}
		}
					
	
	void Get_Answer(){
		int up = upper_bound_ - lower_bound_ + 1;
		int **pd = new int* [num_+1];
		for(int i = 0; i < num_+1; ++i){
			pd[i] = new int [up];
		}
		for(int i = 0; i < num_+1; ++i)
			for(int j = 0; j < up; ++j)
				pd[i][j] = 0;
		//int pd[num_+1][up] = {0};
		for(int k = 1; k < num_+1; ++k){
			vector<int> marks;
			if(Check(pd,k,marks)){
				Make_Flag(pd,k,up);
				pd[k][up-1] = pd[k-1][up-1] + std::get<2>(activity_[k-1]);
			}
			else{
				int temp = pd[k-1][up-1];
				for(size_t i = 0; i < marks.size(); ++i)
					temp -= std::get<2>(activity_[marks[i]-1]);
				temp += std::get<2>(activity_[k-1]);
				if(temp > pd[k-1][up-1]){
					Erace_Flag(pd,marks,k);
					Make_Flag(pd,k,up);
					pd[k][up-1] = temp; 
				}
				else{
					for(int i = 0; i < up; ++i)
						pd[k][i] = pd[k-1][i];
					continue;
				}
			}
		}
		max_ = pd[num_][up-1];
		for(int i = 0; i < num_+1; ++i){
			for(int j = 0; j < up; ++j)
				std::cout<<pd[i][j]<<'\t';
			std::cout<<std::endl;
		}
		for(int i = 0; i < num_+1; ++i)
			delete[] pd[i];
	}
 private:
	vector<tuple<int,int,int>> activity_;
	int num_;
	int max_;
	int upper_bound_, lower_bound_;
};
}//namespace

int main(){
	int n;
	scanf("%d",&n);
/*	Solve *foo = new Solve[n];
	for(int i = 0; i < n; ++i){
		foo[i].Initial();
	}
	for(int i = 0; i < n; ++i){
		foo[i].Print();
	}
	delete[] foo;
	*/
	vector<int> result;
	for(int i = 0; i < n; ++i){
		Solve foo;
		foo.Initial();
		result.push_back(foo.Get_Max());
	}
	for(int i = 0; i < n; ++i)
		printf("%d\n",result[i]);
}
