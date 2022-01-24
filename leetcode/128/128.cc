class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
			unordered_set<int> set;
			for(auto i : nums) {
				set.insert(i);
			}
			int longest = 0;
			for(auto i : nums) {
				if(set.find(i-1) == set.end()) {
					int temp_longgest = 1;
					int temp_po = i+1;
					while(set.find(temp_po) != set.end()) {
						++temp_po;
						++temp_longgest;
					}
					longest = max(longest, temp_longgest);
				}
			}
			return longest;
    }
};
