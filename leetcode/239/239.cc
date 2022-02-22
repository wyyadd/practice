class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		vector<int> ans;
		ans.reserve(nums.size() - k + 1);

		priority_queue<pair<int,int>> q;
		for(int i = 0; i < k; ++i)
			q.push(make_pair(nums[i],i));
		ans.push_back(q.top().first);
		for(int i = k; i < nums.size(); ++i){
			q.push(make_pair(nums[i],i));
			while(q.top().second <= i - k)
				q.pop();
			ans.push_back(q.top().first);
		}
		return ans;
	}
};
