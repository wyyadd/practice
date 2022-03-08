#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, T;
    cin >> n >> T;
    vector<int> pre(n+1,0);
    for(int i = 0; i < n; ++i){
        int val;
        cin >> val;
        pre[i+1] += pre[i]+val;
    }
    int ans = INT32_MIN;
    for(auto i = n; i > 0; --i){
        int j;
        for(j = 0; j < i; ++j){
            if(pre[i]-pre[j] <= T)
                break;
        }
        ans = max(ans,i-j);
    }
    cout << ans;
}


