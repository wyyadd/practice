#include <iostream>
#include <stdio.h>
#include <unordered_set>
#include <vector>

std::unordered_set<int> prime_set;
std::vector<int> prime_vector;


void Initial_prime_list(){
	bool prime[1024]; 
	std::fill_n(prime,1024,true);
	printf("The prime numbers in the range 2 to 1023 are:\n");
	for(int i = 2; i < 1024; ++i){
		if(prime[i]){
			prime_set.insert(i);
			prime_vector.push_back(i);
			printf("%d ", i);
			int j = 2 * i;
			while(j < 1024){
				prime[j] = false;
				j += i;
			}
		}
	}
	printf("\n");
}

void Find_factors(int key){
	const auto pl = &prime_set;
	const auto pv = &prime_vector;
	if(pl->find(key) != pl->end()){
		printf("%d is a prime number\n", key);
		return;
	}
	printf("The unique prime fractorization of %d is :", key);
	int i = 0;
	while(true){
		if(pl->find(key) != pl->end()){
			printf("%d",key);
			break;
		}
		if(key % (*pv)[i] == 0){
			key = key/(*pv)[i];
			printf("%d*",(*pv)[i]);
			i = 0;
		}
		else
			++i;
	}
	printf("\n");
	return;
}


int main(){
	Initial_prime_list();
	Find_factors(331);
	Find_factors(659);
	Find_factors(688);
}
