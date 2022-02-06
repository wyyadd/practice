class Solution {
public:
	// dp(n) = 1 + min(dp(n-j^2))
	int numSquares(int n) {
		vector<int> dp(n+1,0);
		for(int i = 1; i < n+1; ++i){
			int min_ = INT32_MAX;
			for(int j = 1; j <= sqrt(i); ++j){
				min_ = min(dp[i-j*j], min_);
			}
			dp[i] = 1 + min_;
		}
		return dp[n];
	}
};
