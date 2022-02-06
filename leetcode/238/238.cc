class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		vector<int> ans(nums.size());			
		ans[0] = 1;
		for(auto i = 1; i < nums.size(); ++i){
			ans[i] = ans[i-1] * nums[i-1];
		}
		int R = 1;
		for(auto i = nums.size()-1; i != -1; --i){
			ans[i] = ans[i]*R;
			R*=nums[i];
		}
		return ans;
	}
};
