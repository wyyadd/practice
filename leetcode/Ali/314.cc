#include <iostream>
#include <vector>
using namespace std;

struct flag{
	bool up = false;
	bool down = false;
	bool left = false;
	bool right = false;

};

int solve(vector<vector<int>> grid, int n, int m){
	vector<vector<flag>> f(n, vector<flag>(m));
	// left
	for(int i = 0; i < n; ++i){
		for(int j = 1; j < m; ++j){
			if(grid[i][j] == 0 && (grid[i][j-1] == 1 || f[i][j-1].left))
				f[i][j].left= true;
		}
	}
	// right
	for(int i = 0; i < n; ++i){
		for(int j = m-2; j >= 0; --j){
			if(grid[i][j] == 0 && (grid[i][j+1] == 1 || f[i][j+1].right))
				f[i][j].right = true;
		}
	}
	for(int j = 0; j < m; ++j){
		for(int i = 1; i < n; ++i){
			if(grid[i][j] == 0 && (grid[i-1][j] == 1 || f[i-1][j].up))
				f[i][j].up= true;
		}
	}
	for(int j = 0; j < m; ++j){
		for(int i = n-2; i >= 0; --i){
			if(grid[i][j] == 0 && (grid[i+1][j] == 1 || f[i+1][j].down))
				f[i][j].down= true;
		}
	}

	int ans = 0;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			if(grid[i][j] == 0){
				ans += f[i][j].up + f[i][j].down + f[i][j].left + f[i][j].right;
			}
		}
	}
	return ans;
}

int main(){
	vector<vector<int>> arr{{0,1,0,0},{1,0,1,0}};
	cout << solve(arr, 2, 4);
}
