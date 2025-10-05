#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Using a for loop is the easiest way to copy an array

int main(void) {
	// Start
	// Variable declaration
	char num_arr_A[11] = "0123456789";
	char num_arr_B[11];

	int size_arr = sizeof(num_arr_A)/sizeof(num_arr_A[0]);

	// Copying element by element using a for loop
	for(int i = 0; i < size_arr; i++) {
		num_arr_B[i] = num_arr_A[i];
	}

	// Test to see if it was a deep copy by changing array B 
	num_arr_B[0] = 'Z';

	// Text Output
	printf("\n\tOriginal Array: %s\n\t    Copy Array: %s\n\n", num_arr_A, num_arr_B);

	// End
	return 0;
}
