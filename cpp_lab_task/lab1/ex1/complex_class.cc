#include "complex_class.h"

#include <stdio.h>

namespace complex_class{
Complex::Complex(){
	complex_={0.0,0.0};
}
Complex::Complex(const double re, const double im){
	complex_={re,im};
}
Complex Complex::Adding(const Complex &a, const Complex &b){
	return Complex(a.complex_.first+b.complex_.first,a.complex_.second+b.complex_.second);
}
Complex Complex::Subtracting(const Complex &a, const Complex &b){
	return Complex(a.complex_.first-b.complex_.first,a.complex_.second-b.complex_.second);
}
void Complex::Print(){
	if(complex_.second>=0)
		printf("%.2f+%.2fi\n",complex_.first,complex_.second);
	else
		printf("%.2f%.2fi\n",complex_.first,complex_.second);
}
Complex::~Complex(){};
} //namespace complex_class

int main()
{
	complex_class::Complex test1(1,7);
	complex_class::Complex test2(9,2);
	complex_class::Complex test3 = test1.Subtracting(test1, test2);
	test3.Print();
}
