#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <errno.h>
#include <time.h>

// Learning how to make a dice program in C

int get_safe_int(int *out_value) {
	char buffer[32];
	char *endptr;

	// 1. Read input safely into a string buffer
	if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
		return 0; // Error: EOF or read failure
	}

	// 2. Clear errno before the conversion
	errno = 0;

	// 3. Convert string to a long integer
	long val = strtol(buffer, &endptr, 10);

	// 4. Check for parsing errors
	if (endptr == buffer) {
		return 0; // Error: No digits were found at all
	}

	if (*endptr != '\n' && *endptr != '\0') {
		return 0; // Error: Trailing invalid characters (e.g., "12abc")
	}

	if ((errno == ERANGE && (val == LONG_MAX || val == LONG_MIN)) ||
			(val > INT_MAX || val < INT_MIN)) {
		return 0; // Error: Number is out of range for a standard integer
	}

	// Success: Assign the value and return 1
	*out_value = (int)val;
	return 1;
}

int main(void) {
	// Variables
	
	// Padding for the text output in this program 
	char my_pad[8];
	size_t pad_size = sizeof(my_pad)/sizeof(my_pad[0]);
	(void)snprintf(my_pad, pad_size, "%4s", " ");

	// Number of dice sides
	int sides = 6;

	// Seed the random number generator using current time
	srand((unsigned int)time(NULL));

	// Generate a pseudo-random integer between 0 and RAND_MAX
	int random_value = (rand() % (sides - 1));
	printf("\n%sRandom raw value: %d\n", my_pad, random_value);

	// End of Program
	return 0;
}
