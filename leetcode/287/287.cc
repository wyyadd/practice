class Solution {
public:
	int findDuplicate(vector<int>& nums) {
		int slow = 0; int fast = 0;	
		// slow = a + b
		// fast = a + nL + b
		// 2(a+b) = a + nL +b ==> a = nL - b ==> a = (n-1)L + c
		do{
			slow = nums[slow];
			fast = nums[nums[fast]];
		}
		while(fast != slow);
		slow = 0;
		while(slow != fast){
			slow = nums[slow];
			fast = nums[fast];
		}
		return slow;
	}
};
