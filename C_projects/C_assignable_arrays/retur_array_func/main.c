#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h> // For strcspn()

// Function that returns a pointer to the start of an array.
// The array is created whe the function itself is called.
int *return_int_arr(int size) {

  int *arr = (int *)malloc(size * sizeof(int)); // Array initialization with type casting and dynamic size

  // Building the array
  for (int i = 0; i < size; i++) {
    arr[i] = (i + 1) * 2;
  }

  return arr;
}

// Pretty printer method for the array elements.
// Not necessary, I just like this honestly.
void int_arr_printer(int *a, int size) {

  for (int i = 0; i < size; i++) {
    if (i == (size - 1)) {
      printf("%i", a[i]);
    } else {
      printf("%i, ", a[i]);
    }
  }
}

int main(int argc, char *argv[]) {

  int *my_arr = NULL;

  if (argc == 1) {
    char input_buffer[100];

    printf("\n%3cEnter numbers separated by spaces (each will create an array): ", ' ');

    if (fgets(input_buffer, sizeof(input_buffer), stdin) == NULL) {
      printf("%3cError reading input.\n", ' ');
      return 1;
    }

    // Remove trailing newline
    input_buffer[strcspn(input_buffer, "\n")] = '\0';

    char *saveptr;  // Your own context pointer

    char *token = strtok_r(input_buffer, " ", &saveptr);
    // Tokenize the input by spaces using the thread safe version of strtok()

    while(token != NULL) {
      char *end_ptr;
      errno = 0;
      long size = strtol(token, &end_ptr, 10);

      if (end_ptr == token || *end_ptr != '\0' || errno == ERANGE || size <= 0) {
        printf("%3cSkipping invalid input: '%s'\n", ' ', token);
      } else {
        // If we get here, all arguments are valid
        my_arr = return_int_arr((int)size);
        printf("%3cArray for size %ld = [", ' ', size);
        int_arr_printer(my_arr, (int)size);
        printf("]\n");
        free(my_arr); // Pointer built with malloc must be freed after every loop
        my_arr = NULL;
      }

      token = strtok_r(NULL, " ", &saveptr);
    }

  } else {

    // Check ALL arguments, not just the first one
    for (int i = 1; i < argc; i++) {

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

      // If we get here, all arguments are valid

      int size = (int)strtol(argv[i], NULL, 10);

      int *my_arr = return_int_arr(size);
      printf("\n%3cMy array = [", ' ');
      int_arr_printer(my_arr, size);
      printf("]\n");
      free(my_arr); // Pointer built with malloc must be freed after every loop
      my_arr = NULL;
    }
  }

  free(my_arr);
  my_arr = NULL;
  return 0;
}
