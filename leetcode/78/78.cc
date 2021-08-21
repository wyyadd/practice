class Solution {
public:
	void Get_Answer(vector<vector<int>> &ans, vector<int> &result, vector<int> &nums, int pos){
		//stop
		if(pos == nums.size()){
			ans.push_back(result);
			return;
		}
		//add element
		result.push_back(nums[pos]);
		Get_Answer(ans,result,nums,pos+1);
		//skip
		result.pop_back();
		Get_Answer(ans,result,nums,pos+1);
	}
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> ans;
		vector<int> result;
		Get_Answer(ans, result, nums, 0);
		return ans;
	}
};
