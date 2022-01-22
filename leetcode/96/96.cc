class Solution {
public:
    int numTrees(int n) {
			vector<int> dp(n+1, 0);
			dp[0] = 1;
			dp[1] = 1;
			// i = number to construct BST
			for(int i = 2; i < n+1; i++){
				for(int j = 0; j < i/2; ++j){
					dp[i] += dp[j] * dp[i-j-1];
				}
				dp[i] *= 2;
				// if odd
				if(i % 2 == 1)
					dp[i] += dp[i/2] * dp[i/2];
			}
			return dp[n];
    }
};
