#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* pad(int size, char c) {

	char *result = malloc(size * sizeof(char));

	// malloc error checking
	if (result == NULL) {
		return NULL;
	}

	// Append to result using a loop
	for (int i = 0; i < size; i++) {
		result[i] = c;
	}

	// Make sure the result string is null terminated
	result[size] = '\0';

	return result;
}

char* version(long int c) {

	char* ver_string;

	switch(c) {
		case 199409L:
			ver_string = "C95";
			break;
		case 199901L:
			ver_string = "C99";
			break;
		case 201112L:
			ver_string = "C11";
			break;
		case 201710L:
			ver_string = "C17";
			break;
		case 202000L:
			ver_string = "C23";
			break;
		default:
			ver_string = "C89/C90 (or non-compliant)";
			break;
	}

	return ver_string;
}

int main(void) {
	// Variables
	char* message   = "Hello World! From C version: ";
	char* pad_star  = pad(5, '*');
	char* pad_space = pad(1, ' ');
	char* newl_pad  = pad(4, ' ');

	char start_pad[8], end_pad[8], f_message[64];

	(void)snprintf(start_pad   , sizeof(start_pad), "%s%s", pad_star , pad_space);
	(void)snprintf(end_pad     , sizeof(end_pad)  , "%s%s", pad_space, pad_star );
	(void)snprintf(f_message   , sizeof(f_message), \
			"\n%s%s%s%s%s\n\n",             \
			newl_pad,                       \
			start_pad,                      \
			message,                        \
			version(__STDC_VERSION__),      \
			end_pad);

	// Text Output
	printf("%s", f_message);

	// End of Program
	free(pad_star);
	free(pad_space);
	free(newl_pad);
	return 0;
}
