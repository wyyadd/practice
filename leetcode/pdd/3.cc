#include <iostream>

using namespace std;

bool huiwen(string& s){
    for(int i = 0; i < s.size()/2; ++i){
        if(s[i] != s[s.size()-i-1])
            return false;
    }
    return true;
}

int main(){
    int T;
    cin >> T;
    for(int i = 0; i < T; ++i){
        int K, L;
        cin >> K >> L;
        if(K == 0){
            cout << "1" << endl;
            continue;
        }
        string s;
        cin >> s;
        if(huiwen(s))
            cout << "1" << endl;
        else
            cout << "2" << endl;
    }
}