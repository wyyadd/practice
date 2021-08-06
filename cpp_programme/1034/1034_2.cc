#include <iostream>
#include <stdio.h>
#include <vector>

namespace {
	using std::vector;

	struct Edge {
		bool flag = false;
		vector<int> next_;
	};

	class Tree {
	public:
		Tree() {}
		~Tree() {
			delete[] head_;
			delete[] dp[0];
			delete[] dp[1];
		}

		void Initial() {
			scanf("%d", &num_);
			head_ = new Edge[num_+1];
			dp = new int*[2];
			dp[0] = new int[num_+1];
			dp[1] = new int[num_+1];
			for(int i = 0; i<2; ++i)
				for(int j = 0; j<num_+1; ++j)
					dp[i][j] = 0;
			for (int i = 1; i < num_; ++i) {
				int a, b;
				scanf("%d %d", &a, &b);
				head_[a].next_.push_back(b);
				head_[b].next_.push_back(a);
			}
			max_ = std::max(Get_Answer(1,0,dp),Get_Answer(1,1,dp));
		}

//wb means colour w=white=0 b=black=1
		int Get_Answer(int po, bool wb, int** dp) {
			if (head_[po].flag)
				return 0;
			if (head_[po].next_.size() == 1 && po != 1 && wb)
				return 1;
			if (head_[po].next_.size() == 1 && po != 1 && !wb)
				return 0;
			head_[po].flag = true;
			if(!wb){
				int temp_max_1 = 0;
				for(int i = 0; i < (int)head_[po].next_.size(); ++i){
					int new_po = head_[po].next_[i];
					if (head_[new_po].flag)
						continue;
					int max_0 = dp[0][new_po];
					int max_1 = dp[1][new_po];
					if(!max_0){
						max_0 = Get_Answer(new_po,0,dp);
						dp[0][new_po] = max_0;
					}
					if(!max_1){
						max_1 = Get_Answer(new_po,1,dp);
						dp[1][new_po] = max_1;
					}
					temp_max_1 += std::max(max_0,max_1);
				}
				dp[0][po] = temp_max_1;
				head_[po].flag = false;
				return temp_max_1;
			}
			else{
				int	temp_max_2 = 1;
				for(int i = 0; i < (int)head_[po].next_.size(); ++i){
					int new_po = head_[po].next_[i];
					if (head_[new_po].flag)
						continue;
					int max_0 = dp[0][new_po];
					if(!max_0){
						max_0 = Get_Answer(new_po,0,dp);
						dp[0][new_po] = max_0;
					}
					temp_max_2 += max_0; 
				}
				dp[1][po] = temp_max_2;
				head_[po].flag = false;
				return temp_max_2;
			}
		}

		void Print() {
			printf("%d\n", max_);
			/*
			for(int i = 0; i<2; ++i){
				for(int j=1; j<=num_; ++j)
					std::cout<<dp[i][j]<<'\t';
				std::cout<<std::endl;
			}
			*/
		}
	int Get_max(){
		return max_;
	}
	private:
		int num_;
		Edge* head_;
		int max_;
		int** dp;
	};
}//namespace

int main() {
	int t;
	scanf("%d", &t);
	vector<int> result;
	for (int i = 0; i < t; ++i){
		Tree foo;
		foo.Initial();
		result.push_back(foo.Get_max());
	}
	for (int i = 0; i < t; ++i)
		printf("%d\n",result[i]);
}

