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

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> q;
        for (int i = 0; i < k; ++i) {
            while (!q.empty() && nums[i] >= nums[q.back()]) {
                q.pop_back();
            }
            q.push_back(i);
        }

        vector<int> ans = {nums[q.front()]};
        for (int i = k; i < n; ++i) {
            while (!q.empty() && nums[i] >= nums[q.back()]) {
                q.pop_back();
            }
            q.push_back(i);
            while (q.front() <= i - k) {
                q.pop_front();
            }
            ans.push_back(nums[q.front()]);
        }
        return ans;
    }
};
