#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	int reverse(int x) {
		string s = to_string(x);
		if(x < 0)
			std::reverse(s.begin()+1,s.end());
		else
			std::reverse(s.begin(),s.end());
		auto ans = stol(s);
		if(INT32_MIN <= ans && ans <= INT32_MAX)
			return ans;
		return 0;
	}
};

int main(){
	auto s= new Solution;
	cout << s->reverse(1534236469);
}
