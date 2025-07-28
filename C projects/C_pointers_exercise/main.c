#include <stdlib.h>
#include <stdio.h>

// Pointers Exercise in C

// Example Method, by passing a pointer we can directly alter a value 
// stored inside a declared variable. Note that, when using pointers
// inside a method, we must reference the pointer in the following
// manner, so as to access the value inside the variable: 
// (*pointer)

void Increment(int *a){
	(*a)++;
}

int main(){

	int   Age =   25;
	int* pAge = &Age;

//	Using the '&' operator we can retrieve the value to the pointer to a variable.

	printf("\n\tExample pointer address: %p\n\n", &Age);

	printf("\tExample pointer address: %p\n\n", pAge);

	printf("\tOriginal Age: %i\n\n", Age);

	Increment(pAge);

	printf("\tAge incremented by 1: %i\n\n", Age);

	return 0;
}
