// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <vector>
#include <iostream>
using namespace std;

int solution(int N, vector<int> &A, vector<int> &B, vector<int> &H) {
    // longest dist 
    vector<vector<int>> dist(N, vector<int>(N,100000));
    // dist itselves is 0
    for(int i = 0; i < N; ++i){
        dist[i][i] = 0;
    }
    // generate street dist
    for(auto i = 0; i < (int)A.size(); ++i){
        dist[A[i]][B[i]] = 1;
        dist[B[i]][A[i]] = 1;
    }
    // get longest dit between every two district
    for(int m = 0;m < N; ++m){
        for(int i = 0;i < N;++i){
            for(int j = 0;j < N;++j){
                if(dist[i][j]>dist[i][m]+dist[m][j])
                    dist[i][j] = dist[i][m]+dist[m][j];
            }
        }
    }
    int max_dist=0;
    for(int i=0;i<N;i++){
        int temp=100000;
        // temp = mindist from one district to every hospital
        for(auto h = 0;h < (int)H.size();++h){
            temp = min(dist[i][H[h]], temp);
        }
        max_dist = max(temp, max_dist);
    }
    if(max_dist>=100000) 
        return -1;
    return max_dist;
}