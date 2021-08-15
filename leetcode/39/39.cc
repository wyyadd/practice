class Solution {
public:
		void FindAll(vector<int> &result ,vector<vector<int>> &ans, vector<int>& candidates, int var, int pos){
			if(var < 0)
				return;
			if(var == 0)
				ans.push_back(result);	
			for(int i = pos; i < candidates.size(); ++i){
				vector<int> temp = result;
				temp.push_back(candidates[i]);
				FindAll(temp, ans, candidates, var-candidates[i], pos);
				++pos;
			}
		}

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
			vector<vector<int>> ans;
			vector<int> result;
			FindAll(result, ans, candidates, target, 0);
			return ans;
    }
};
/*
 * 回溯法
class Solution {
public:
    void dfs(vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int>& combine, int idx) {
        if (idx == candidates.size()) {
            return;
        }
        if (target == 0) {
            ans.emplace_back(combine);
            return;
        }
        // 直接跳过
        dfs(candidates, target, ans, combine, idx + 1);
        // 选择当前数
        if (target - candidates[idx] >= 0) {
            combine.emplace_back(candidates[idx]);
            dfs(candidates, target - candidates[idx], ans, combine, idx);
            combine.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> combine;
        dfs(candidates, target, ans, combine, 0);
        return ans;
    }
};
*/
