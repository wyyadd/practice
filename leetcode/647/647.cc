class Solution {
public:
	int countSubstrings(string s) {
		int ans = s.size();		
		vector<vector<bool>> dp(s.size(),vector<bool>(s.size(),true));
		for(int i = 0; i < (int)s.size(); ++i){
			dp[i][i] = true;
		}
		// dp[i][j] = dp[i+1][j-1] && string[i] == string[j]
		for(int n = 1; n < (int)s.size(); ++n){
			for(int i = 0; i < (int)s.size()-n; ++i){
				int j = i+n;
				dp[i][j] = dp[i+1][j-1] && s[i] == s[j];
				if(dp[i][j])
					++ans;
			}
		}
		return ans;
	}
};
