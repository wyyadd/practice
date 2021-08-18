//because order in word may different, after sort, it will be same
//so sort every word in strs, and then insert it into a hashmap
class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		unordered_map<string, vector<string>>	map;
		for(auto &s : strs) {
			string key = s;
			sort(key.begin(), key.end());
			map[key].push_back(s);
		}
		vector<vector<string>> ans;
		for(auto &m : map)
			ans.push_back(m.second);
		return ans;
	}
};

//beacuse order in word may different, if we count every letter frequency, it will be same
//so sort every word frequency, and then insert it into a hashmap
class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		unordered_map<string, vector<string>> map;
		for(auto &s : strs){
			string key = string(26, '0');
			for(auto &i : s)
				++ key[i-'a'];
			map[key].push_back(s);
		}
		vector<vector<string>> ans;
		for(auto &m : map)
			ans.push_back(m.second);
		return ans;
	}
};
