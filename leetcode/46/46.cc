//recursion
class Solution {
public:
	void Get_Answer(vector<vector<int>> &ans, vector<int> &nums, vector<int> &list){
		if(nums.size() == 1){
			list.push_back(nums[0]);
			ans.push_back(list);
			return;
		}
		for(int i = 0 ; i < nums.size(); ++i){
			vector<int> temp_list(list);
			temp_list.push_back(nums[i]);
			vector<int> temp_nums(nums);
			temp_nums.erase(temp_nums.begin() + i);
			Get_Answer(ans,temp_nums,temp_list);
		}
	}

	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> ans;       
		vector<int> list;
		Get_Answer(ans, nums, list);
		return ans;
	}
};
