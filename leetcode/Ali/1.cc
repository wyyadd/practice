#include <iostream>
#include <vector>
using namespace std;

class Sollution
{
public:
    vector<string> bracket(int n){
        vector<string> ans;
        string val = "(";
        dfs(ans,n-1,n, val);
        return ans;
    }

    void dfs(vector<string>& ans, int left, int right, string& val){
        if(left == 0 && right == 0){
            ans.push_back(val);
            return;
        }
        if(left != 0){
            val += "(";
            dfs(ans,left-1,right,val);
            val.pop_back();
        }
        if(right != 0 && left < right){
            val += ")";
            dfs(ans,left,right-1,val);
            val.pop_back();
        }
    }
};

int main(){
    auto s = new Sollution;
    for(auto i : s->bracket(4))
        cout << i << endl;
}