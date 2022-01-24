#include <vector>
#include <string>
using namespace std;

int result = 1;

// dir: right = 0, down = 1, left = 2, up = 3
void walk(vector<string> &R, int x, int y, int dir, vector<vector<vector<int>>>& dirmap){
    // quit
    if(dirmap[x][y][0] != -1){
        auto arr = dirmap[x][y];
        int po;
        for(po = 0; po < 4; ++po){
            // if dir are same in this grid , quit
            if(arr[po] == dir)
                return;
            if(arr[po] == -1){
                arr[po] = dir;
                break;
            }
        }
    }
    else{
        dirmap[x][y][0] = dir;
    }
    // walk
    int next_x = x, next_y = y;
    switch (dir)  {
    case 0: next_y++;
        break;
    case 1: next_x++; 
        break;
    case 2: next_y--;
        break;
    case 3: next_x--;
        break;
    } 
    if(next_x == -1 || next_y == -1 || next_x == (int)R.size() || next_y == (int)R[0].size() || R[next_x][next_y] == 'X')
        walk(R,x,y,(dir+1)%4,dirmap); // change dir
    else{
        if(R[next_x][next_y] != '0'){
            // 0 mean cleaned
            R[next_x][next_y] = '0';
            // cout << next_x << '\t' << next_y <<endl;
            result++;
        }
        walk(R,next_x,next_y,dir,dirmap);
    }
}

int solution(vector<string> &R) {
    // save every grid history directions
    vector<vector<vector<int>>> dirmap(R.size(), vector<vector<int>>(R[0].size(), vector<int>(4,-1)));
    // 0,0 has cleaned
    R[0][0] = '0';
    walk(R,0,0,0,dirmap);
    return result;
}
