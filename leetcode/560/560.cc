class Solution {
public:
	int subarraySum(vector<int>& nums, int k) {
		vector<int> arr(nums.size()+1,0);
		for(int i = 0; i < (int)nums.size(); ++i){
			arr[i+1] = arr[i]+nums[i];
		}
		int ans = 0;
		for(int i = 1; i <= (int)nums.size(); ++i){
			for(int j = 0; j < i; ++j){
				if(arr[i]-arr[j] == k)
					++ans;
			}
		}
		return ans;
	}
};
