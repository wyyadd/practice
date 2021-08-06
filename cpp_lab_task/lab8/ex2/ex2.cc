#include <iostream>
#include <stdio.h>

template <typename T>
bool isEqualTo(T a, T b){
	return a==b;
}

class Complex{
 public:
	Complex(float i,float r):im(i),re(r){};
	~Complex(){};
	bool operator == (const Complex& x) const{
		if(im == x.im && re == x.re)
			return true;
		else 
			return false;
	}
 private:
	float im;
	float re;
};
int main(){
	if(isEqualTo<int>(3,3))
		printf("true\n");
	else
		printf("false\n");

	Complex a(1,2);
	Complex b(2,2);
	if(isEqualTo<Complex>(a,b))
		printf("true\n");
	else
		printf("false\n");
}
