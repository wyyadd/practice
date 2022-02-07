class Solution {
public:
	// dp[i] = 1 + min(dp[i-j]) i = amount
	int coinChange(vector<int>& coins, int amount) {
		vector<int> dp(amount+1,-1);	
		dp[0] = 0;
		for(int i = 1; i <= amount; ++i){
			int temp_min = INT32_MAX;
			for(auto& c : coins){
				auto new_amount = i - c;
				if(new_amount>=0 && dp[new_amount] != -1)
					temp_min = min(temp_min,dp[new_amount]);
			}
			if(temp_min != INT32_MAX)
				dp[i] = temp_min + 1;
		}
		return dp.back();
	}
};
