#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Sollution{
public:
    pair<int,int>getSameAndDiff(const vector<int>&a, const vector<int>& b){
        unordered_set<int> set;
        for(auto& i : a)
            set.insert(i);
        int same = 0;
        int diff = 0;
        for(auto& i : b){
            if(set.find(i) != set.end())
                ++same;
            else
                ++diff;
        }
        if(a.size() > b.size())
            diff += a.size() - b.size();
        return {same, diff};
    }
};

int main(){
    auto s = new Sollution;
    vector<int> a{1,3,4,5};
    vector<int> b{1,6};
    auto ans = s->getSameAndDiff(a,b);
    cout << ans.first << endl << ans.second;
}