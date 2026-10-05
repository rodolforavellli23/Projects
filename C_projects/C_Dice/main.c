#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <errno.h>
#include <time.h>

// Learning how to make a dice program in C

int get_safe_int(int *out_value, char* pad) {
	char buffer[32];
	char *endptr;

	// 1. Read input safely into a string buffer
	if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
		fprintf(stderr, "\n%sError: EOF or read failure\n", pad);
		return 0;
	}

	// 2. Clear errno before the conversion
	errno = 0;

	// 3. Convert string to a long integer
	long val = strtol(buffer, &endptr, 10);

	// 4. Check for parsing errors
	if (endptr == buffer) {
		fprintf(stderr, "\n%sError: No digits were found at all\n", pad);
		return 0;
	}

	if (*endptr != '\n' && *endptr != '\0') {
		fprintf(stderr, "\n%sError: Trailing invalid characters (e.g., \"12abc\")\n", pad);
		return 0; 
	}

	if ((errno == ERANGE && (val == LONG_MAX || val == LONG_MIN)) || (val > INT_MAX || val < INT_MIN)) {
		fprintf(stderr, "\n%sError: Number is out of range for a standard integer\n", pad);
		return 0; 
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
	int sides;

	// User response to continue rolling dice
	char cont[8];

	// Beginning of interactive execution
	while(1) {
		fprintf(stdout, "\n%sHello! What is the size of the dice you wish to roll? ", my_pad);
		while (!get_safe_int(&sides, my_pad)) {
			fprintf(stderr, "\n%sInvalid input. Please enter a valid integer number of sides: ", my_pad);
		}

		// Seed the random number generator using current time
		srand((unsigned int)time(NULL));

		// Generate a pseudo-random integer between "0" and "sides"
		int random_value = (rand() % (sides - 1));

		// Get the pointer to the number the user has rolled
		int *rvp = &random_value; 

		// Prevent a scenario where the user rolls a zero
		if (random_value == 0) {
			*rvp+=1;
		}

		// Print the number the user has rolled
		fprintf(stdout, "\n%sRolling dice D%d, result: %d\n", my_pad, sides, random_value);

		// Ask if user wishes to continue rolling dice
		fprintf(stdout, "\n%sContinue rolling dice? Type \"yes\" to continue, or \"no\" to exit: ", my_pad);

		if (fgets(cont, sizeof(cont), stdin) == NULL) {
			fprintf(stderr, "\n%sError: EOF or read failure\n", my_pad);
			break;
		}

		if (strncmp(cont, "yes", 3) == 0) {
			fprintf(stdout, "\n%sContinuing...\n", my_pad);
			continue;
		} else if (strncmp(cont, "no", 2) == 0) {
			fprintf(stdout, "\n%sExiting Program...\n\n", my_pad);
			break;
		} else {
			fprintf(stderr, "\n%sInvalid option, exiting program...\n\n", my_pad);
			break;
		}
	}

	// End of Program
	return 0;
}
