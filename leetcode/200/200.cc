class Solution {
public:
	int numIslands(vector<vector<char>>& grid) {
		int result = 0;
		for(auto i = 0; i < grid.size(); ++i){
			for(auto j = 0; j < grid[0].size(); ++j){
				if(grid[i][j] == '1'){
					walk(grid,i,j);
					++result;
				}
			}
		}
		return result;
	}

	void walk(vector<vector<char>>& grid, unsigned int x, unsigned int y){
		if(x == -1 || y == -1 || x == grid.size() || y == grid[0].size() || grid[x][y] == '*' || grid[x][y] == '0')
			return;
		grid[x][y] = '*';
		walk(grid,x+1,y);
		walk(grid,x-1,y);
		walk(grid,x,y+1);
		walk(grid,x,y-1);
	}
};
