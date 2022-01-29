class Solution {
public:
    int rob(vector<int>& nums) {
			if(nums.empty())
				return 0;
			if(nums.size() == 1)
				return nums[0];
			int first = nums[0];
			int second = max(first,nums[1]);
			for(int i = 2; i < nums.size(); ++i){
					int temp = second;
					second = max(first+nums[i],second);
					first = temp;
			}
			return temp;
    }
};
