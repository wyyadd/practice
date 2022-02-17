#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class MedianFinder {
private:
	vector<int> arr;
public:
	MedianFinder() {
			
	}
	
	void addNum(int num) {
		int left = 0;
		int right = (int)arr.size()-1;
		while(left <= right){
			int mid = (left + right) / 2;
			if(num > arr[mid])
				left = mid + 1;
			else
				right = mid - 1;
		}
		arr.insert(arr.begin()+left,num);
	}
	
	double findMedian() {
		auto size = arr.size();
		if(size % 2)
			return arr[size/2];
		else
			return (double)(arr[size/2]+arr[size/2-1])/2;
	}
};

int main(){
	auto s = new MedianFinder;
	vector<int> a{12,10,13,11,5,15,1,11,6,17,14,8,17,6,4,16,8,10,2,12,0};
	for(auto i : a)
		s->addNum(i);
	cout << s->findMedian();
}
/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
