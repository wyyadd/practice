//recursion
/*
class Solution {
	int m,n;
public:
	void Walk(int x, int y, int &ans){
		if(x == m && y == n){
			++ans;
			return;
		}
		if(x != m)
			Walk(x+1,y,ans);
		if(y != n)
			Walk(x,y+1,ans);
	}
	int uniquePaths(int m, int n) {
		this->m = m;
		this->n = n;
		int ans = 0;		
		Walk(1,1,ans);
		return ans;
	}
};
*/
//dp[x][y] = dp[x-1][y] + dp[x][y-1]
class Solution {
public:
	int uniquePaths(int m, int n) {
		vector<vector<int>> dp(m,vector<int>(n));
		for(int i = 0; i < m; ++i)
			dp[i][0] = 1;
		for(int i = 0; i < n; ++i)
			dp[0][i] = 1;
		for(int i = 1; i < m; ++i)
			for(int j = 1; j < n; ++j)
				dp[i][j] = dp[i-1][j] + dp[i][j-1];
		return dp[m-1][n-1];
	}
};
