#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* gen_str(char *c, int size) {

	// How to initialize an empty buffer in C
	size_t   c_size = strlen(c);              // Get the size of the string to be repeated;
	size_t result_t = (strlen(c) * size) + 1; // Set the buffer size;
	char    *result = malloc(result_t)      ; // Allocate the memory for it on the Heap.
                                              //
                                              // Note that every time you call malloc,
                                              // you must free the pointer you allocated.
	if(result == NULL) {
		return NULL;
	} // Error checking before initializing the string

	size_t current_index = 0; // Track the current array index

	for (int i = 0; i < size; i++) {
		strncpy(&result[current_index], c, c_size); // Copy to the position on the array
		current_index += c_size;                    // Advance pointer
	}

	return result;
}

int main(void) {

	// Variables
	char *my_c = "*";
	char *my_str = gen_str(my_c, 15);

	// Error checking
	if (my_str == NULL) {
		fprintf(stderr, "\n%4cFailed Buffer Initialization!\n\n", ' ');
		return 1;
	}

	// Text Output
	printf("\n%4c|%s|\n\n%4c|%.*s|\n\n", ' ', my_str, ' ', 4, my_str);

	// Using the %.*s format specifier is one way to slice C strings

	// Free pointer and end program
	free(my_str);
	return 0;
}
