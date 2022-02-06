class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		vector<int> v;
		for(auto& i : nums)
			if(i)
				v.push_back(i);
		int i = 0;
		while(i<v.size()){
			nums[i] = v[i];
			++i;
		}
		while(i<nums.size()){
			nums[i++] = 0;
		}
	}
};

class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		int left = 0;
		int right = 0;
		while(right < nums.size()){
			if(nums[right]){
				swap(nums[right],nums[left]);
				++left;
			}
			++right;
		}
	}
};
