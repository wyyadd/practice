class Solution {
public:
	string longestPalindrome(string s) {
		int pos, max = 1;
		bool dp[s.length()][s.length()];
		for (int i = 0; i < s.length() - 1; ++i){
			dp[i][i] = true;
			dp[i][i+1] = (s[i] == s[i+1]);
			if(s[i] == s[i+1]){
				pos = 1;
				max = 2;
			}
		}
		dp[s.length()-1][s.length()-1] =true;
		for(int i = s.length() - 3; i >= 0; --i){
			for(int j = i + 2; j < s.length(); ++j){
				dp[i][j] = (dp[i+1][j-1] && s[i] == s[j]);	
				if(dp[i][j] && j - i + 1 > max){
					max = j - i + 1;
					pos = i;
				}
			}
		}
		return s.substr(pos,max);
	}
};
