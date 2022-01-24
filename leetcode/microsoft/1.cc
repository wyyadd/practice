// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <unordered_map>
#include <vector>
#include <cmath>
using namespace std;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    // number:frequence
    unordered_map<int,int> map;
    for(auto i : A){
        map[i]++;
    }
    int result = 0;
    for(auto i : map){
        int deleteALLTimes = i.second;
        int addTimes = i.first - i.second; 
        int deleteTimes = i.second - i.first;
        if(addTimes < 0)
            addTimes = INT32_MAX;
        if(deleteTimes < 0)
            deleteTimes = INT32_MAX;
        // get min of 3
        int min_value = min(deleteALLTimes, addTimes);
        min_value = min(deleteTimes,min_value);
        // add
        result += min_value;
    }
    return result;
}
