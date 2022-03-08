#include <iostream>
#include <vector>
using namespace std;

int main(){
    string s;
    cin >> s;
    string ans;
    int l=0;
    int r = 1;
    char pre = s[0];
    for(;r < (int)s.size(); ++r){
        if(s[r] != pre){
            ans += to_string(r-l) + pre;
            l = r;
            pre = s[r];
        }
    }
    ans += to_string(r-l) + pre;
    cout << ans;
}