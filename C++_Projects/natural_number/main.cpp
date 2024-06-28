#include <iostream>
#include <math.h>

using namespace std;

int factorial(int a) {

	double result = 1;

	for (int i = 1; i <= a; ++i) {
        	result *= i;
	}
	
	return result;
}

int main(void){

	int i = 0;
	double count = 0.0;

	for ( i; i < 1000; i++){		
		count += 1.0 / factorial(i);		
	}
	
	printf("\n%.9f\n\n", count);
	
	return 0;
}
