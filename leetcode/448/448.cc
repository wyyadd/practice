class Solution {
public:
	vector<int> findDisappearedNumbers(vector<int>& nums) {
		int n = nums.size();
		vector<int> ans(n+1,0);
		for(int i = 1; i <=n; ++i)
			ans[i] = i;
		for(auto i : nums)
			ans[i] = 0;
		ans.erase(ans.begin());
		int slow = 0;
		int fast = 0;
		while(fast != n){
			if(ans[fast]){
				swap(ans[fast],ans[slow]);
				++slow;
			}
			++fast;
		}
		ans.erase(ans.begin()+slow,ans.end());
		return ans;
	}
};
