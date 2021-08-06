#include <iostream>
#include <stdio.h>
#include <vector>

using std::ostream;
using std::istream;

template<class T>
class Vector{
 public:
	Vector(){};
	~Vector(){};
	friend ostream &operator <<(ostream& os, Vector<T> &v){
		for(size_t i = 0; i < v.arr.size(); ++i)
			os<<v.arr[i];
		return os;
	}
	friend istream &operator >>(istream& is, Vector<T>  &v){
		T temp;
		is>>temp;
		v.arr.push_back(temp);
		return is;
	}
 private:
	std::vector<T> arr;	
};
/*
template<class T>
ostream &Vector<T>::operator <<(ostream &os, Vector<T> &v){
	for(size_t i = 0; i < v.arr.size(); ++i)
		os<<v.arr[i];
	return os;
}

template<class T>
istream &Vector<T>::operator >>(istream &is, Vector<T> &v){
	T temp;
	is>>temp;
	v.arr.push_back(temp);
	return is;
}
*/

int main(){
	Vector<int> test;
	for(int i = 0; i < 3; ++i)
		std::cin>>test;
	std::cout<<test;
}
