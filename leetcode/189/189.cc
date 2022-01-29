class Solution {
public:
    void rotate(vector<int>& nums, int k) {
			k = k % nums.size();
		// o(1) space, o(n2) time
		/*
			for(int i = 0; i < k; ++i){
				int back = nums.back();
				nums.pop_back();
				nums.insert(nums.begin(),back);
			}
		*/

		// o(n), o(n) space and time
		/*
			vector<int> k_arr(k);
			for(int i = 0; i < k; ++i){
				k_arr[k-i-1] = nums.back();
				nums.pop_back();
			}
			nums.insert(nums.begin(), k_arr.begin(),k_arr.end());
    }
		*/

		// o(n) time, o(n) space
		// -1 -1 -1 1 2 3 4 5 6 7 
		int start = nums.size();
		nums.insert(nums.begin(), k, -1);
		for(int i = 0; i < k; ++i){
			nums[i] = nums[start+i];
		}
		nums.erase(nums.begin()+start, nums.end());
	}
};
