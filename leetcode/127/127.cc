#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;
class Solution {
private:
	int ans = INT32_MAX;
	unordered_set<string> set;
	unordered_map<string, bool> map;
public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		// dfs(beginWord,endWord,wordList,1);
		// return ans == INT32_MAX ? 0 : ans;
		return bfs(beginWord,endWord,wordList);
	}

	int bfs(const string& start, const string& end, const vector<string>& wordList){
		int ans = 1;
		queue<string> que;
		que.push(start);
		while (!que.empty())
		{
			int size = que.size();
			for(int i = 0; i < size; ++i){

				auto t = que.front();
				que.pop();
				if(t == end)
					return ans;
				for(auto w : wordList){
					if(set.find(w) == set.end() && differ(t,w)){
						que.push(w);
						set.insert(w);
					}
				}
			}
			++ans;
		}
		return 0;
	}

	void dfs(string& start, const string& end, const vector<string>& wordList, int depth){
		if(start == end){
			ans = min(ans,depth);
			return;
		}
		for(auto w : wordList){
			if(set.find(w) == set.end()){
				if(differ(start, w)){
					set.insert(w);
					dfs(w,end,wordList,depth+1);
					set.erase(w);
				}
			}
		}
	}

	bool differ(const string& word1, const string& word2){
		if(word1 == word2)
			return false;
		if(map.find(word1+word2) != map.end() || map.find(word2+word1) != map.end())
			return map[word1+word2];
		int ans = 0;
		for(int i  = 0; i < word1.size(); ++i){
			ans += word1[i] != word2[i] ? 1 : 0;
		}
		map[word1+word2] = ans == 1;
		map[word2+word1] = ans == 1;
		return ans == 1;
	}
};

int main(){
	auto s = new Solution;
	vector<string> map{"hot","dot","dog","lot","log","cog"};
	cout << s->ladderLength("hit","cog",map) << endl;
}