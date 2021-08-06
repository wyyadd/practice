//解法， 滑动窗口
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
			//哈希集合，记录每个字符是否出现过
			unordered_set<char> set;
			//先插入第一个
			set.insert(s[0]);
			//最大的个数
			int ans = 0;
			//右指针
			int right = 1;
			for(int left = 0; left < s.length(); ++left) {
				//右指针不断右移，直到重复
				while(set.find(s[right]) == set.end() && right < s.length()){
					set.insert(s[right]);
					++right;
				}
				//更新最大个数
				ans = max(ans, (int)set.size());
				//删除左指针所指的
				set.erase(set.find(s[left]));	
			}
			return ans;
    }
};
