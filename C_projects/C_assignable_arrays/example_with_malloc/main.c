#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// This function creates a padding string
char* repeat(const char *c, int size) {

	// Allocate memory to construct the padding array
	char *str_out = malloc(size * strlen(c) + 1);

	// Should memory allocation by malloc fail, return NULL
	if(str_out == NULL) {
		return NULL;
	}

	// Initialize the empty padding array
	str_out[0] = '\0';

	// build the padding array
	for(int i = 0; i < size; i++) {
		strcat(str_out, c);
	}

	return str_out;
}

// How to assign C arrays

int main(void) {

	// Start
	
	// Variable assignment -- Note: The size of a C string array must be: size + 1; 
	// so as to account for the null terminating charater

	char product_code_A[11] = "0123456789"; // Origin array A
	
	// char *product_code_B = product_code_A[11]; is not allowed by the C compiler
	// So we must take another route
	
	char product_code_B[11]; // Destination array B

	char *spaces_1 = repeat(" ", 10); // Padding array 1
	char *spaces_2 = repeat(" ", 14); // Padding array 2

	strcpy(product_code_B, product_code_A); // Copy A to B

	// Text output
	// If the variable 'spaces' is NULL, do nothing
	if (spaces_1 != NULL && spaces_2 != NULL) {

		// This is what is printed to the standard output
		printf("\n\n%sOriginal array: %s\n%sCopy array: %s\n\n", spaces_1, product_code_A, spaces_2, product_code_B);

		// Since 'spaces' was constructed using a function that called malloc, 
		// you must manually free the memory used by this variable
		free(spaces_1);
		free(spaces_2);
	}

	// After freeing memory, it's good practice to set the pointer to NULL,
	// this helps in preventing "dangling pointers" and potential use-after-free bug
	spaces_1 = NULL;
	spaces_2 = NULL;

	// End
	return 0;
}
