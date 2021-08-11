//same as 15.cc
class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		int n = nums.size();
		int ans;
		int min = INT_MAX;
		sort(nums.begin(), nums.end());       
		for(int first = 0; first < n; ++first){
			if(first > 0 && nums[first] == nums[first - 1])
				continue;
			int key = target-nums[first];
			int third = n-1;
			for(int second = first + 1; second < n; ++second){
				if(second > first + 1 && nums[second] == nums[second-1])
					continue;
				while(second < third && nums[second] + nums[third] > key)
					--third;
				if(third != n-1 && abs(nums[second] + nums[third+1] - key) < min){
					ans = nums[second] + nums[third+1] + nums[first];
					min = abs(ans - target);		
				}
				if(second == third)
					break;
				if(abs(nums[second] + nums[third] - key) < min){
					ans = nums[second] + nums[third] + nums[first];
					min = abs(ans - target);		
				}
				if(ans == target)
					return ans;
			}
		}
		return ans;
	}
};
