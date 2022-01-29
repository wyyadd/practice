class Solution {
public:
    int majorityElement(vector<int>& nums) {
			unordered_map<int,int> map;
			for(auto& i: nums){
				if(map.find(i) != map.end())
					++map[i];
				else
					map.insert(make_pair(i,1));
			}
			int criterion = nums.size()/2;
			for(auto& i : map){
				if(i.second > criterion)
					return i.first;
			}
			return NULL;
    }
};
