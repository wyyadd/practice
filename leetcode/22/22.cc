/*
 * 动态规划：
 *dp[i]表示i组括号的所有有效组合
 *dp[i] = "(dp[p]的所有有效组合)+【dp[q]的组合】"，其中 1 + p + q = i , p从0遍历到i-1, q则相应从i-1到0
*/
class solution {
public:
	vector<string> generateparenthesis(int n) {
		if (n == 0) return {};
		if (n == 1) return { "()" };
		vector<vector<string>> dp(n+1);
		dp[0] = { "" };
		dp[1] = { "()" };
		for (int i = 2; i <= n; i++) {
			for (int j = 0; j <i; j++) {
				for (string p : dp[j])
					for (string q : dp[i - j - 1]) {
						string str = "(" + p + ")" + q;
						dp[i].push_back(str);
					}
			}
		}
		return dp[n];
	}
};
