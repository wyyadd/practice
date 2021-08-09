//Longest palindromix substring
class Solution {
public:
	string longestPalindrome(string s) {
		//pos: longest palidrome start pos
		//max: longest palidrome length 
		int pos = 0, max = 1;
		//dp[i][i] = true, if substr i to j is palidrome 
		//					 false , otherwise
		bool dp[s.length()][s.length()];
		for (int i = 0; i < s.length() - 1; ++i){
			//base case, single char is palidrome 
			dp[i][i] = true;
			//same two char is palidrome  
			dp[i][i+1] = (s[i] == s[i+1]);
			if(s[i] == s[i+1]){
				pos = i;
				max = 2;
			}
		}
		dp[s.length()-1][s.length()-1] =true;
		for(int i = s.length() - 3; i >= 0; --i){
			for(int j = i + 2; j < s.length(); ++j){
				//dp[i][j] = (dp[i+1][j-1] && s[i] == s[j]
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
