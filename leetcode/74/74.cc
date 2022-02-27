#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int m  = matrix.size();
		int n = matrix[0].size();
		int left = 0;
		int right = m*n-1;
		while(left <= right){
			int mid = (left + right)/2;
			auto val = getValue(mid, matrix);
			if(target == val)
				return true;
			if(target < val){
				right = mid - 1;
			}else{
				left = mid + 1;
			}
		}
		return false;
	}

	int getValue(int po, vector<vector<int>>& matrix){
		int x = po / matrix[0].size();
		int y = po % matrix[0].size();
		return matrix[x][y];
	}
};

int main(){
	auto s = new Solution;
	vector<vector<int>> v{{1,1}};
	s->searchMatrix(v,2);
}