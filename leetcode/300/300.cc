class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		vector<int> dp(nums.size());
		int ans = 0;
		for(int i = 0; i < nums.size(); ++i){
			int num = 1;
			for(int j = i-1; j != -1; --j){
				if(nums[i]>nums[j])
					num = max(1+dp[j],num);
			}
			dp[i] = num;
			ans = max(num,ans);
		}
		return ans;
	}
};
