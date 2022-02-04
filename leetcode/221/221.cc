#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
	int maximalSquare(vector<vector<char>>& matrix) {
		vector<vector<int>> dp(matrix.size(),vector<int>(matrix[0].size(),0));
		int max_len = 0;
		for(auto i = 0; i < matrix.size(); ++i){
			for(auto j = 0; j < matrix[i].size(); ++j){
				if(matrix[i][j] == '1'){
					dp[i][j] = 1;
					max_len = max(getMaxLen(i,j,dp),max_len);
				}
			}
		}
		return max_len * max_len;
	}

	int getMaxLen(int x, int y, vector<vector<int>>& matrix){
		if(x == 0 || y == 0)
			return 1;
		matrix[x][y] = min(matrix[x-1][y-1],min(matrix[x][y-1],matrix[x-1][y]))+1; 
		return matrix[x][y];
	}
};

int main(){
	auto s = new Solution;
	vector<vector<char>> m {{'0','0','0','1'},{'1','1','0','1'},{'1','1','1','1'},{'0','1','1','1'},{'0','1','1','1'}};
	s->maximalSquare(m);
}
