#include <iostream>
#include <vector>
using namespace std;
class QucikSort{
private:
public:
	// 5 4 7 6 3 2 9
	void quickSort(vector<int>& arr, int left, int right){
		if(right <= left)
			return;
		auto mid = left;
		auto criteria = arr[left];	
		for(int i = left; i <= right; ++i){
			if(arr[i] <= criteria){
				swap(arr[mid++],arr[i]);
			}
		}
		--mid;
		swap(arr[left],arr[mid]);
		quickSort(arr, left, mid-1);
		quickSort(arr, mid+1,  right);
	}
};


int main(){
	vector<int> arr{5,4,7,6,3,2,9};
	// vector<int> arr{1,2};
	auto s = new QucikSort;
	s->quickSort(arr,0,arr.size()-1);
	for(auto i : arr)
		cout << i << '\t';
}
