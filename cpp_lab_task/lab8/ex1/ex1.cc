#include <iostream>
#include <stdio.h>

template <class T, int num>
class Array{
 public:
 T* GetArray(){
	return myarr_;
 }
 T& operator[](int index){
	return myarr_[index];
 }
 private:
	T myarr_[num];
};

int main(){
	Array<std::string ,3> test;
	test[0] = "hello,world";
	std::cout<<test[0]<<std::endl;
	//printf("%d\n",test[0]);
}
