#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    if(M > N){
        cout << "-1" << endl;
        return 0;
    }
    // first: attack, second: defend
    vector<pair<int,int>> duo(N);
    vector<pair<int,int>> pi(M);
    for(int i = 0; i < N; ++i){
        int x,y;
        cin >> x >> y;
        duo[i] = make_pair(x,y);
    }
    for(int i = 0; i < M; ++i){
        int x,y;
        cin >> x >> y;
        pi[i] = make_pair(x,y);
    }
    int ans = 0;
    // sort defend increase --- pipi
    sort(pi.begin(),pi.end(),[](pair<int,int>&a,pair<int,int>&b){return a.second < b.second;});
    // sort attack increase --- duoduo
    sort(duo.begin(),duo.end(),[](pair<int,int>&a,pair<int,int>&b){return a.first< b.first;});
    // dp[i][j] = dp
    int d_po = 0;
    for(int p = 0; p < pi.size(); ++p){
       bool flag = false;
       for(;d_po < duo.size(); ++d_po){
          if(duo[d_po].first >= pi[p].second) {
              if(duo[d_po].second > pi[p].first){
                ++ans;
                flag = true;
                break;
              }
          }
       } 
       if(!flag){
           cout << "-1" << endl;
           return 0;
       }
    }
    cout << ans << endl;
}