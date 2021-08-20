//dp[n] = dp[n-1] + dp[n-2]
/*
class Solution {
public:
	int climbStairs(int n) {
		vector<int> dp(n+1);
		dp[0] = 1;
		dp[1] = 1;
		for(int i = 2; i <= n; ++i)
			dp[i] = dp[i-1] + dp[i-2];	
		return dp[n];
	}
};
*/
class Solution {
public:
	int climbStairs(int n) {
		int first = 1;
		int second = 1;
		for(int i = 2; i <= n; ++i){
			int temp = first + second;
			first = second;
			second = temp;
		}
		return second;
	}
};
