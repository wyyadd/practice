//idea: greedy algorithim
//continuely increase maxPos
//if i == maxPos , then will not reach end
class Solution {
public:
	bool canJump(vector<int>& nums) {
		int maxPos = 0 ,i = 0;
		while(i < nums.size()) {
			maxPos = max(maxPos, i + nums[i]);
      if(maxPos >= nums.size()-1)
        return true;
			if(i == maxPos) 
				return false;
      ++i;
		}
		return true;
	}
};
