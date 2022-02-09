#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	vector<int> partitionLabels(string s) {
		vector<pair<int,int>> map(26, make_pair(-1,-1));
		for(int i = 0; i < (int)s.size(); ++i){
			int po = s[i]-'a';
			if(map[po].first != -1)
				map[po].second = i;
			else 
				map[po].first = i;
		}
		sort(map.begin(),map.end(),[](pair<int,int>a,pair<int,int>b){return a.first<b.first;});
		vector<int> ans;
		int left=0;
		int right=-1;
		for(int i = 0; i < 26; ++i){
			if(map[i].first!=-1){
				cout << map[i].first << '\t' << map[i].second << endl;
				int l = map[i].first;
				int r = map[i].second;
				if(l < right)
					right = max(right,r);
				else{
					ans.push_back(right-left+1);
					left = l;
					if(r != -1)
						right = r;
					else
						right = l;
				}
			}
		}
		ans.erase(ans.begin());
		ans.push_back(right-left+1);
		return ans;
	}
};

int main(){
	auto t = new Solution;
	string s = "e";
	t->partitionLabels(s);
}
