#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
class Solution {
private:
	// first:numner, second: frequency
	unordered_map<int,int> kmap;
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		for(auto& i : nums)
			kmap[i]++;
		vector<pair<int,int>> list;
		for(auto& i : kmap){
			list.push_back(make_pair(i.first,i.second));
		}
		sort(list.begin(),list.end(),
				[](pair<int,int>a,pair<int,int>b){return a.second>b.second;});
		vector<int> ans(k);
		for(int i = 0; i < k; ++i)
			ans[i] = list[i].first;
		return ans;
	}
};

int main(){
	auto s = new Solution;
	vector<int> v{1,1,1,2,2,3};
	s->topKFrequent(v,2);
}
