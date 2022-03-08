#include <iostream>
#include <vector>

using namespace std;

int main(){
    // 1 face same, two differ: move 1---- two same, one reverse
    // move 3 ---- one same, two reverse
    int T;
    cin >> T;
    for(int i = 0; i < T; ++i){
        vector<pair<int,int>> a(3);
        vector<pair<int,int>> b(3);
        for(int j = 0; j < 3; ++j){
            int x, y;
            cin >> x >> y;
            a[j] = make_pair(x,y);
        }
        for(int j = 0; j < 3; ++j){
            int x, y;
            cin >> x >> y;
            b[j] = make_pair(x,y);
        }
        int same = -1; 
        int count = 0; 
        for(int p = 0; p < 3; ++p){
            if(a[p].first == b[p].first && a[p].second == b[p].second){
                same = p;
                ++count;
            }
        }
        if(count == 3){
            cout << "0" << endl;
            return 0;
        }
        if(same == -1){
            cout << "-1" << endl;
            return 0;
        }
        if(same = 1 || same == 2){
            cout << "1" << endl;
            continue;
        }
        else{
            cout << "3" << endl;
            continue;
        }
    }
}