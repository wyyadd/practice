#include <iostream>
#include <vector>
using namespace std;
class Heap{
private:
    static void adjustHeap(vector<int>& arr, int po, int size){
        int left_child = 2*po+1;
        int right_child = 2*po+2;
        if(left_child == size-1){
            if(arr[po] < arr[left_child])
                swap(arr[po],arr[left_child]);
            return;
        }
        if(right_child >= size || arr[po] >= arr[left_child] && arr[po] >= arr[right_child])
            return;
        int max_po = arr[left_child] >= arr[right_child] ? left_child : right_child;
        swap(arr[po],arr[max_po]);
        adjustHeap(arr, max_po, size);
    }

public:
   static void sort(vector<int>&& arr){
        for(int i = arr.size()/2-1; i >= 0; --i){
                adjustHeap(arr, i, arr.size());
        }

        for(int j = arr.size()-1; j>0; --j){
            swap(arr[0],arr[j]);
            adjustHeap(arr, 0, j);
        } 

        for(auto& i : arr)
            cout << i << endl;
   } 
};

int main(){
   Heap::sort({1,4,2,8,6,4,3,9,8,6});
}