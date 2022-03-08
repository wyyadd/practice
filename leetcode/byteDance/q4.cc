#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int getMoveTime(const int center, vector<int>& stu, const int& seats){
    int move = 0;
    int count = 1;
    int r_e = center + 1 == stu.size()? 0 : center + 1;
    int l_e = center - 1 < 0? stu.size() - 1 : center - 1;
    while(r_e != l_e){
        int r = stu[center] + count > seats ? 0 : stu[center]+count;
        int l = stu[center] - count == 0 ? seats : stu[center]-count;
        move += min(abs(stu[r_e]-r),seats-abs(stu[r_e]-r));
        move += min(abs(stu[l_e]-l),seats-abs(stu[l_e]-l));
        ++ count;
        r_e = center + count  == stu.size()? 0 : center + count;
        l_e = center - count < 0? stu.size() - 1 : center - count;
    }
    return move;
}

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> stu(n);
    for(int i =0; i < n; ++i){
        cin >> stu[i];
    }
    sort(stu.begin(),stu.end()); 
    int ans = INT32_MAX;
    for(int i = 0; i < n; ++i){
        ans = min(ans,getMoveTime(i,stu,m));
    }
    cout << ans;
}