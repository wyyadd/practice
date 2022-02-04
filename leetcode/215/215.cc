#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		//sort(nums.begin(),nums.end(),greater<int>());
		//return nums[k-1];
		priority_queue<int> q(less<int>(), nums);
		for(int i = 0; i < k-1; ++i)
			q.pop();
		return q.top();
	}
};
