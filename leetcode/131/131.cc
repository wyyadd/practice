class Solution {
public:
    vector<vector<string>> partition(string s) {
			vector<vector<vector<string>>> dp{{{s.substr(0,1)}}};
			// dp[i]为有i+1个元素的组合
			for(auto i = 1; i < s.size(); ++i){
				vector<vector<string>> level;
				for(auto j = 0; j <= i; ++j){
					string candidates = s.substr(j, i-j+1);
					if(isPalindrome(candidates)){
						if(j == 0){
							level.push_back({candidates});
							continue;
						}
						for(auto l1 : dp[j-1]){
							vector<string> temp = l1;
							temp.push_back(candidates);
							level.push_back(temp);
						}
					}
				}
				dp.push_back(level);
			}
			return dp.back();
    }

		bool isPalindrome(string s) {
			auto len = s.size()-1;
			for(auto i = 0; i < s.size()/2; ++i){
				if(s[i] != s[len-i])
					return false;
			}
			return true;
		}
};
