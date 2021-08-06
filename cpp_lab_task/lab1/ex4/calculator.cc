#include "calculator.h"
#include <iostream>
#include <stdio.h>

namespace calculator{
Calculator::Calculator(){};
Calculator::~Calculator(){};
double Calculator::Add(const double &a, const double &b) const{
	return a+b;
}
double Calculator::Subtract(const double &a, const double &b) const{
	return a-b;
}
double Calculator::Multiply(const double &a, const double &b) const{
	return a*b;
}
double Calculator::Divide(const double &a, const double &b) const{
	return a/b;
}

}//namespace calculator

int main(){
	calculator::Calculator test;
	printf("%.2f\n",test.Divide(1,2));
}
