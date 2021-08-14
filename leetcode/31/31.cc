//Next Permutation
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;
				//from end to start to find a non decrease pair
        while (i >= 0 && nums[i] >= nums[i + 1])
            i--;
				//if i = -1, nums is max, skip
        if (i >= 0) {
            int j = nums.size() - 1;
						//i+1 to end is a decrease list
						//from this list to find a min num which is nums[j], bigger than nums[i]
            while (j >= 0 && nums[i] >= nums[j]) 
                j--;
            swap(nums[i], nums[j]);
        }
				//make list from decrease to increase, which is min
        reverse(nums.begin() + i + 1, nums.end());
    }
};
/*
 * example: 12385764
 * from end to start, find 5 < 7
 * then, from 764 find 6 > 5
 * swap 5,6
 * list: 12386754
 * 754 is a decrease list, reverse it
 * ans: 12385467
*/
