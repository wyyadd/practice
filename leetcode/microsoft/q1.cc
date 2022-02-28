// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int dfs(int x, int y, int po, vector<vector<int>>& Board, vector<vector<bool>>& flag){
    if(po == -1 || x == Board.size() || x == -1 || y == Board[0].size() || y == -1 || flag[x][y])
        return 0;
    flag[x][y] = true; 
    auto ans = pow(10,po)*Board[x][y]+max(dfs(x-1,y,po-1,Board,flag),
                                            max(dfs(x+1,y,po-1,Board,flag),
                                                max(dfs(x,y-1,po-1,Board,flag),dfs(x,y+1,po-1,Board,flag))));
    flag[x][y] = false;
    return ans;
}
int solution(vector< vector<int> > &Board) {
    vector<vector<bool>> flag(Board.size(), vector<bool>(Board[0].size(), false));
    int ans = INT32_MIN;
    int max_val = ans;
    if(Board.size()==1){
        for(int i=0; i+3<Board[0].size(); i++)
            ans = max(ans, Board[0][i]*1000 + Board[0][i+1]*100 + Board[0][i+2]*10 + Board[0][i+3]);
        for(int i=Board[0].size()-1; i>=3; i--)
            ans = max(ans, Board[0][i]*1000 + Board[0][i-1]*100 + Board[0][i-2]*10 + Board[0][i-3]);
	    return ans;
	 }
	 if(Board[0].size()==1){
	     for(int i=0; i+3<Board.size(); i++)
	        ans = max(ans, Board[i][0]*1000 + Board[i+1][0]*100 + Board[i+2][0]*10 + Board[i+3][0]);
	     for(int i=Board.size()-1; i>=3; i--)
	        ans = max(ans, Board[i][0]*1000 + Board[i-1][0]*100 + Board[i-2][0]*10 + Board[i-3][0]);
	     return ans;
	 }
    for(int i = 0; i < Board.size(); ++i){
        for(int j = 0; j < Board[0].size(); ++j){
            max_val = max(max_val,Board[i][j]);
        }
    }
    for(int i = 0; i < Board.size(); ++i){
        for(int j = 0; j < Board[0].size(); ++j){
            if(Board[i][j]==max_val)
                ans = max(ans,dfs(i,j,3,Board,flag));
        }
    }
    return ans;
}

int main(){
    vector<vector<int>> brid{{9,1,1,0,7},{1,0,2,1,0},{1,9,1,1,0}};
    // vector<vector<int>> brid{{1,1,1},{1,3,4},{1,4,3}};
    // vector<vector<int>> brid{{0,1,5,0,0}};
    cout << solution(brid);
}