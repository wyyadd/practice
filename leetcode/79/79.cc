class Solution {
public:
	bool exist(vector<vector<char>>& board, string word) {
		for(int i = 0; i < board.size(); ++i){
			for(int j = 0; j < board[i].size(); ++j){
				// 0-left, 1-right, 2-up, 3-down, -1-nowhere
				if(match(board, word, i, j, 0))
						return true;
			}
		}
		return false;
	}

	bool match(vector<vector<char>>& board, string& word, int i, int j, int po) {
		if(po == word.size())
			return true;
		if(j==-1 || j==board[0].size() || i==-1 || i==board.size() || board[i][j] == '*')
			return false;
		char t = board[i][j];
		board[i][j] = '*';

		bool result = false;
		if(t == word[po]){
			if(match(board, word, i, j-1, po+1)
					||match(board, word, i, j+1, po+1)
					||match(board, word, i-1, j, po+1)
					||match(board, word, i+1, j, po+1))
				result = true;
		}
		board[i][j] = t;
		return result;
	}
};
