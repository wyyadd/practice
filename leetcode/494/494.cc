#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	int findTargetSumWays(vector<int>& nums, int target) {
		target = abs(target);
		// dp[i][j] = dp[i-1][abs(j-nums[i])] +  dp[i-1][abs(j+nums[i])]
		vector<vector<int>> dp(nums.size(), vector<int>(2000,0));		
		if(nums[0] == 0)
			dp[0][abs(nums[0])] = 2;
		else
			dp[0][abs(nums[0])] = 1;
		for(int i =	1; i < (int)nums.size(); ++i){
			for(int j = 0; j < 1001; ++j){
				dp[i][j] = dp[i-1][abs(j-nums[i])] + dp[i-1][abs(j+nums[i])];
			}
		}
		return dp[nums.size()-1][target];
	}
};