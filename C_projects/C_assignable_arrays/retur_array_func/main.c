#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <limits.h>

// Function that returns a pointer to the start of an array.
// The array is created whe the function itself is called.
int* return_int_arr(int size) {

	int *arr = (int *)malloc((size + 1) * sizeof(int)); // Array initialization with type casting and dynamic size

	// Building the array
	for(int i = 0; i < (size + 1); i++) {
		arr[i] = i * 2;
	}

	return arr;
}

// Pretty printer method for the array elements.
// Not necessary, I just like this honestly.
void int_arr_printer(int* a, int size){

	for(int i = 0; i < (size + 1); i++) {
		if(i == size) {
			printf("%i", a[i]);
		} else {
			printf("%i, ", a[i]);
		}
	}
}

int main(int argc, char *argv[]){

	if(argc == 1) {

		int size = 0;
        int input_success = 0;
        char input_buffer[100];

        printf("\n%3cWhat is to be the size of the integer array? ", ' ');

        while (!input_success) {
            if (fgets(input_buffer, sizeof(input_buffer), stdin) == NULL) {
                printf("%3cError reading input. Please try again: ", ' ');
                continue;
            }

            // Parse the input using strtol for consistent error handling
            char *end_ptr;
            errno = 0;
            long temp_size = strtol(input_buffer, &end_ptr, 10);

            // Check for conversion errors
            if (end_ptr == input_buffer) {
                printf("%3cError: Input is not a number. Please enter a valid integer: ", ' ');
            } else if (*end_ptr != '\n' && *end_ptr != '\0') {
                printf("%3cError: Input contains non-numeric characters. Please enter a valid integer: ", ' ');
            } else if (errno == ERANGE || temp_size < 0) {
                printf("%3cError: Size must be a non-negative integer. Please enter a valid size: ", ' ');
            } else if (temp_size > INT_MAX) {
                printf("%3cError: Size is too large. Please enter a smaller number: ", ' ');
            } else {
                size = (int)temp_size;
                input_success = 1;
            }
        }

        int *my_arr = return_int_arr(size);

        printf("\n%3cMy array = [", ' ');
        int_arr_printer(my_arr, size);
        printf("]\n");

        free(my_arr);
        my_arr = NULL;

	} else {

		// Check ALL arguments, not just the first one
        for(int i = 1; i < argc; i++) {

            char *end_ptr;
            errno = 0;

            long num_long = strtol(argv[i], &end_ptr, 10);

            // Correct error checking:
            // 1. Check if conversion happened at all (end_ptr didn't move)
            // 2. Check if there are leftover characters after conversion
            // 3. Check for range errors

            if (end_ptr == argv[i] || *end_ptr != '\0' || errno == ERANGE) {
                printf("\n%3cError: Argument '%s' is not a valid integer or out of range.\n\n", ' ', argv[i]);
                printf("%3cThis program only accepts numeric arguments.\n\n", ' ');
                return 1;
            }

            // Optional: Check if the value fits in an int
            if (num_long < -2147483647 || num_long > 2147483647) {
                printf("\n%3cError: Value %ld is out of range for int.\n", ' ', num_long);
                return 1;
            }
        }

        // If we get here, all arguments are valid
        // Use the first argument as the size
        int size = (int)strtol(argv[1], NULL, 10);

        int *my_arr = return_int_arr(size);
        printf("\n%3cMy array = [", ' ');
        int_arr_printer(my_arr, size);
        printf("]\n");

        free(my_arr);
        my_arr = NULL;
	}

	return 0;
}
