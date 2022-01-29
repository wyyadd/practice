class Solution {
public:
    int maxProduct(vector<int>& nums) {
			int dp_min = nums[0];
			int dp_max = nums[0];
			int result = nums[0];
			for(int i = 1; i < nums.size(); ++i){
				int new_max = dp_max * nums[i];
				int new_min = dp_min * nums[i];
				dp_max = max({new_max,new_min,nums[i]});
				dp_min = min({new_max,new_min,nums[i]});
				result = max(dp_max,result);
			}
			return result;
		}
};
