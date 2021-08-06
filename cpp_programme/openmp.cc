#include <iostream>
#include <stdio.h>
#include <omp.h>

namespace{

double Calculate_Pi(){
	double pi = 0.0;
	int thread_num = 17;
	int n = 1000000;
	#pragma omp parallel num_threads(thread_num)
	{
		#pragma omp for ordered schedule(dynamic)
		for(int k = 0; k < n; ++k){
			double j = (k + 0.5) / n;
			double len = 4 / (j * j + 1);
			pi += len;
			printf("thread %d is executing, len = %f\n", omp_get_thread_num(), len);
		}
	}
	return pi/n;
}

}//namespace

int main(){
	printf("pi = %f\n", Calculate_Pi());
}

