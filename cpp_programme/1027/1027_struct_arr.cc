#include <iostream>
#include <stdio.h>
#include <vector>
#include <climits>
namespace {
	using std::vector;
	struct tuple0 {
		int a;
		int b;
		int c;
	};
	class Solve {
	public:
		Solve() {};
		~Solve() {};
		void Initial() {
			scanf("%d", &num_);
			upper_bound_ = INT_MIN;
			lower_bound_ = INT_MAX;
			for (int i = 0; i < num_; ++i) {
				int a, b, c;
				scanf("%d %d %d", &a, &b, &c);
				if (a < lower_bound_)
					lower_bound_ = a;
				if (b > upper_bound_)
					upper_bound_ = b;
				tuple0 temp;
				temp.a = a;
				temp.b = b;
				temp.c = c;
				activity_.push_back(temp);
			}
			Get_Answer();
		}
		
		void Print() {
			printf("%d\n", max_);
		}

		int Get_Max() {
			return max_;
		}

		int Check(int* dp, vector<int>& marks, int k) {
			int check_flag = 1;
			auto act = activity_[k];
			int start = act.a - lower_bound_;
			int end = act.b - lower_bound_;
			for (int i = start; i < end; ++i) {
				if (dp[i] < 0) {
					check_flag = 0;
					int temp = i - 1;
					while (dp[temp] < 0)
						--temp;
					marks.push_back(dp[temp]);
					auto temp_act = activity_[dp[temp] - 1];
					i = temp + temp_act.b - temp_act.a;
					continue;
				}
				if (dp[i] > 0) {
					check_flag = 0;
					marks.push_back(dp[i]);
					auto temp_act = activity_[dp[i] - 1];
					i = i + temp_act.b - temp_act.a;
					continue;
				}
			}
			return check_flag;
		}

		void Make_Flag(int* dp, int k, int up) {
			auto act = activity_[k];
			int start = act.a - lower_bound_;
			int end = act.b - lower_bound_;
			for (int i = start + 1; i < end; ++i)
				dp[i] = -1;
			dp[start] = k + 1;
		}

		void Erace_Flag(int* dp, vector<int>& marks) {
			for (size_t i = 0; i < marks.size(); ++i) {
				auto act = activity_[marks[i] - 1];
				int start = act.a - lower_bound_;
				int end = act.b - lower_bound_;
				for (int j = start; j < end; ++j)
					dp[j] = 0;
			}
		}

		void Get_Answer() {
			int up = upper_bound_ - lower_bound_ + 1;
			int* dp = new int[up];
			for (int j = 0; j < up; ++j)
				dp[j] = 0;
			for (int k = 0; k < num_; ++k) {
				vector<int> marks;
				if (Check(dp, marks, k)) {
					Make_Flag(dp, k, up);
					dp[up - 1] = dp[up - 1] + activity_[k].c;
				}
				else {
					int temp = dp[up - 1];
					for (size_t i = 0; i < marks.size(); ++i)
						temp -= activity_[marks[i] - 1].c;
					temp += activity_[k].c;
					if (temp > dp[up - 1]) {
						Erace_Flag(dp, marks);
						Make_Flag(dp, k, up);
						dp[up - 1] = temp;
					}
					else {
						continue;
					}
				}
			}
			max_ = dp[up - 1];
			delete[] dp;
		}
	private:
		vector<tuple0> activity_;
		int num_;
		int max_;
		int upper_bound_, lower_bound_;
	};
}//namespace

int main() {
	int n;
	scanf("%d", &n);
	vector<int> result;
	for (int i = 0; i < n; ++i) {
		Solve foo;
		foo.Initial();
		result.push_back(foo.Get_Max());
	}
	for (int i = 0; i < n; ++i)
		printf("%d\n", result[i]);
}

