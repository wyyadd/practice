#include "integer_set.h"
#include <iostream>
#include <stdio.h>

namespace integer_set{

IntegerSet::IntegerSet(int* arr, int size){
	for(int i = 0; i < size; ++i){
		if(0 <= arr[i] && arr[i] <= 100)
			arr_[arr[i]] = true;
	}
}

void IntegerSet::Input(){
	while(true){
		int ele;
		printf("Enter an element (-1 to end): ");
		scanf("%d",&ele);
		if(ele == -1)
			break;
		if(ele < 0)
			printf("Element should be greater than 0\n");
		if(ele > 100)
			printf("Element should be less than 100\n");
		arr_[ele] = true;
	}
	printf("Entry complete\n");
}


void IntegerSet::Output(){
	for(int i = 0; i <= 100; ++i){
		if(arr_[i])
			printf("%d ", i);
	}
	printf("\n");
}

bool IntegerSet::IsEqualTo(const IntegerSet& x){
	for(int i = 0; i < 100; ++i){
		if(arr_[i] != x.arr_[i]){
			printf("Not equal\n");
			return false;
		}
	}
	printf("equal\n");
	return true;
}

void IntegerSet::Insert(int ele){
	if(ele < 0)
		printf("Element should be greater than 0\n");
	if(ele > 100)
		printf("Element should be less than 100\n");
	arr_[ele] = true;
}

void IntegerSet::Delete(int ele){
	if(ele < 0)
		printf("Element should be greater than 0\n");
	if(ele > 100)
		printf("Element should be less than 100\n");
	arr_[ele] = false;
}

IntegerSet IntegerSet::Union(const IntegerSet& a, const IntegerSet& b){
	IntegerSet c;
	for(int i = 0; i <= 100; ++i){
		if(a.arr_[i] || b.arr_[i])
			c.Insert(i);
	}
	return c;
}

IntegerSet IntegerSet::Intersection(const IntegerSet& a, const IntegerSet& b){
	IntegerSet c;
	for(int i = 0; i <= 100; ++i){
		if(a.arr_[i] && b.arr_[i])
			c.Insert(i);
	}
	return c;
}

}//namespcae integer_set

int main(){
	int arr1[8] = { 1,2,3,4,5,6,7,8};
	int arr2[8] = { 1,3,5,7,9,11,13,15};

	integer_set::IntegerSet test1(arr1,8);
	integer_set::IntegerSet test2(arr2,8);
	test1.IsEqualTo(test2);
	integer_set::IntegerSet test = integer_set::IntegerSet::Intersection(test1,test2);
	test.Output();
	test.Delete(1);
	test.Insert(99);
	test.Output();
}
