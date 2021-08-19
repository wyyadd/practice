//idea: first sort every element in intervals, then travel the vector to combine
//time : o(nlgn)
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
		sort(intervals.begin(),
				intervals.end(), 
				[](vector<int>& a, vector<int>& b){return a[0] < b[0];});
		vector<vector<int>> ans;
		ans.push_back({intervals[0][0],intervals[0][1]});
		for(auto i = intervals.begin() + 1; i != intervals.end() ; ++i){
			auto j = ans.end() - 1;
			if((*i)[0] <= (*j)[1])
				(*j)[1] = max((*j)[1],(*i)[1]);
			else
				ans.push_back({(*i)[0],(*i)[1]});
		}
		return ans;
	}
};
