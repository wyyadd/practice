#include "huge_integer.h"
#include <iostream>
#include <stdio.h>
#include <string.h>

namespace huge_integer{

HugeInteger::HugeInteger(int x){
	int i = 0;
	while(x!=0){
		 integer[i++] = x % 10;
		 x = x / 10;
	}
	while(i < 40)
		integer[i++] = 0;
}

HugeInteger::HugeInteger( const char* str){
	int i = 0;
	int base = (int)'0';
	for(int j = strlen(str)-1; j>=0; --j)
		integer[j] = (int)str[i++] - base;
	while(i < 40)
		integer[i++] = 0;
}

HugeInteger HugeInteger::add( const HugeInteger &x){
	int i = 0;
	int flag = 0;
	HugeInteger temp;
	while(i < 40){
		if(integer[i] + x.integer[i] + flag > 9){
			temp.integer[i] = integer[i] + x.integer[i] + flag - 10;
			flag = 1;
		}
		else{
			temp.integer[i] = integer[i] + x.integer[i] + flag;
			flag = 0;
		}
		++i;
	}
	if(flag == 1){
		printf("exceed/n");
		std::exit(1);
	}
	return temp;	
}

HugeInteger HugeInteger::add( int x ){
	HugeInteger temp(x);
	return add(temp);
}

HugeInteger HugeInteger::add(const char* str){
	HugeInteger temp(str);
	return add(temp);
}

HugeInteger HugeInteger::subtract( const HugeInteger &x){
	int i = 0;
	int flag = 0;
	HugeInteger temp;
	while(i < 40){
		if(integer[i] - x.integer[i] - flag < 0){
			temp.integer[i] = integer[i] - x.integer[i] - flag + 10;
			flag = 1;
		}
		else{
			temp.integer[i] = integer[i] - x.integer[i] - flag;
			flag = 0;
		}
		++i;
	}
	if(flag == 1){
		printf("exceed/n");
		std::exit(1);
	}
	return temp;	
}

HugeInteger HugeInteger::subtract( int x ){
	HugeInteger temp(x);
	return subtract(temp);
}

HugeInteger HugeInteger::subtract(const char* str){
	HugeInteger temp(str);
	return subtract(temp);
}

bool HugeInteger::isEqualTo(HugeInteger &x){
	for(int i = 0; i < 40; ++i){
		if(integer[i] != x.integer[i])
			return 0;
	}
	return 1;
}

bool HugeInteger::isNotEqualTo(HugeInteger &x){
	return !isEqualTo(x);
}

bool HugeInteger::isGreaterThan(HugeInteger &x){
	for(int i = 39; i >= 0; --i){
		if(integer[i] > x.integer[i])
			return 1;
		else 
			if(integer[i] < x.integer[i])
				return 0;
	}
	return 0;
}

bool HugeInteger::isLessThan(HugeInteger &x){
	return !isGreaterThan(x);
}

bool HugeInteger::isGreaterThanOrEqualTo(HugeInteger &x){
	return isEqualTo(x)|isGreaterThan(x);
}

bool HugeInteger::isLessThanOrEqualTo(HugeInteger &x){
	return isEqualTo(x)|isLessThan(x);
}

bool HugeInteger::isZero(){
	for(int i = 0; i < 40; ++i)
		if(integer[i])
			return 0;
	return 1;
}

void HugeInteger::input(const char* str){
	int i = 0;
	int base = (int)'0';
	for(int j = strlen(str)-1; j>=0; --j)
		integer[j] = (int)str[i++] - base;
	while(i < 40)
		integer[i++] = 0;
}
void HugeInteger::output(){
	for(int i = 39; i>=0; --i)
		printf("%d", integer[i]);
	printf("\n");
}
}//namespace huge_integer


int main(){
	huge_integer::HugeInteger test;
	test.input("123");
	test.output();
}

