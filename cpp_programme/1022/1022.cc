#include <iostream>
#include <string>

namespace{
using std::cout;
using std::cin;
using std::endl;
using std::string;
class Solve{
 public:
  Solve() {};
	~Solve() {};
	void Set_Str(){
		string first,second;
		cin>>first>>second;
		first_=first;
		second_=second;
		max_match_ = 0;
	}
	void Print(){
		cout<<max_match_<<endl;
	}
  void Find_Max_Match(){
		int dp[second_.length()+1][first_.length()+1];
		for(size_t i = 0; i < first_.length()+1; ++i)
			dp[0][i] = 0;
		for(size_t i = 0; i< second_.length()+1; ++i)
			dp[i][0] = 0;
		for(size_t i = 1; i< second_.length()+1; ++i){
			for(size_t j = 1; j < first_.length()+1; ++j){
				if(second_[i-1] == first_[j-1]){
					dp[i][j] = dp[i-1][j-1] + 1;
				}
				else{
					dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);
				}
			}
		}
		max_match_ = dp[second_.length()][first_.length()];
		for(size_t i = 0; i<= second_.length(); ++i){
			for(size_t j = 0; j <= first_.length(); j++){
				cout<<dp[i][j]<<'\t';
			}
			cout<<endl;
		}
	}
 private:
  string first_;
	string second_;
	int max_match_;
};
} //namespace

int main()
{	
	size_t number;
	cin>>number;
	Solve *strs = new Solve[number];
	for(size_t i = 0; i < number; ++i){
		strs[i].Set_Str();
		strs[i].Find_Max_Match();
	}
	for(size_t i = 0; i < number; ++i){
		strs[i].Print();
	}
}
