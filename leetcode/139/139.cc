class Solution {
private:
	unordered_set<string> set;
	// ifBreak[i] = from 0 to i, if can work break
	vector<int> ifBreak;
public:
    bool wordBreak(string s, vector<string>& wordDict) {
			 ifBreak.resize(s.size()+1, -1);
       for(auto i : wordDict){
					set.insert(i);
			 }
			 return dfs(s,s.size());
    }

		bool dfs(string& s, unsigned int num){
			if(num == 0)
				return true;
			if(ifBreak[num] == 1)
				return true;
			if(ifBreak[num] == 0)
				return false;
			for(auto i = 1; i <= num; ++i){
				if(set.find(s.substr(num-i,i)) != set.end() && dfs(s, num-i)){
						ifBreak[num] = 1;
						return true;
				}
			}
			ifBreak[num] = 0;
			return false;
		}
};
