class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
			int n = nums.size();
			vector<vector<int>> ans;
			sort(nums.begin(), nums.end());       
			//枚举a
			for(int first = 0; first < n; ++first){
				//需要和上一次枚举的不相同
				if(first > 0 && nums[first] == nums[first - 1])
					continue;
				int target = -nums[first];
				//c 在最右端
				int third = n-1;
				//枚举b
				for(int second = first + 1; second < n; ++second){
					//需要和上一次枚举的不相同
					if(second > first + 1 && nums[second] == nums[second - 1])
						continue;
					// 需要保证 b 的指针在 c 的指针的左侧
					while(second < third && nums[second] + nums[third] > target)
						--third;
					// 如果指针重合，随着 b 后续的增加
					// 就不会有满足 a+b+c=0 并且 b<c 的 c 了，可以退出循环
					if(second == third)
						break;
					if(nums[second] + nums[third] == target)
						ans.push_back({nums[first],nums[second],nums[third]});
				}
			}
			return ans;
    }
};
