class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int x = (int)matrix.size() - 1;
		int y = 0;
		// iterater
		while(x != -1 && y != matrix[0].size()){
			if(target == matrix[x][y])
				return true;
			if(target > matrix[x][y])
				++y;
			else
				--x;
		}
		return false;
	}

	// recursive
	bool walk(vector<vector<int>>& matrix, int x, int y, int& target){
		if(x == -1 || y == matrix[0].size())
			return false;
		if(target == matrix[x][y])
			return true;
		if(target > matrix[x][y])
			return walk(matrix, x, y+1, target);
		else
			return walk(matrix, x-1, y, target);
	}
};
