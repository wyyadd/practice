#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
	vector<int> dailyTemperatures(vector<int>& temperatures) {
		vector<int> ans(temperatures.size(),0);
		auto cmp = [](pair<int,int>a,pair<int,int>b){return a.first>b.first;};
		priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> q(cmp);
		for(int i = 0; i < (int)temperatures.size(); ++i){
			while(!q.empty() && q.top().first < temperatures[i]){
				ans[q.top().second] = i - q.top().second;
				q.pop();
			}
			q.push(make_pair(temperatures[i],i));
		}
		return ans;
	}
};

int main(){
	auto s = new Solution;
	vector<int> v{73,74,75,71,69,72,76,73};
	for(auto i: s->dailyTemperatures(v))
		cout << i << endl;
}
