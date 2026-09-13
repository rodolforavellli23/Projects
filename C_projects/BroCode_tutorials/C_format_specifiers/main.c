#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* C format specifier tutorial
 *
 * format specifier '%'   = defines and formats a type of data to be displayed
 *                  '%c'  = character
 *                  '%s'  = string (array of characters) 
 *                  '%f'  = float
 *                  '%lf' = double
 *                  '%d'  = integer
 *                  '%.1' = decimal precision
 *                  '%1'  = minimum field width
 *                  '%-'  = left align
 * */

char* pad(float larger_number, float smaller_number) {

	// Create the temporary strings that will hold the inputs as strings
	char str_larger_number[16], str_smaller_number[16];
	int size = 0;

	// Cast the inputs into the arrays
	(void)snprintf(str_larger_number , sizeof(str_larger_number), "%f", larger_number );
	(void)snprintf(str_smaller_number, sizeof(str_larger_number), "%f", smaller_number);

	// Calculate the size and make the declaration of the return padding string
	// Malloc has to be used to keep result in the Heap 
	size = strlen(str_larger_number) - strlen(str_smaller_number) + 1;
	char *result = malloc(size * sizeof(char));
	
	// malloc error checking
	if (result == NULL) {return NULL;}

	// Append to result using a loop
	for (int i = 0; i < size; i++) {
		result[i] = ' ';
	}

	// Make sure the result string is null terminated
	result[size] = '\0';

	return result;
}

int main(void) {

	// Variables
	float item1 =   5.75;
	float item2 =  10.00;
	float item3 = 100.99;

	char* line1_pad = pad(item3, item1);
	char* line2_pad = pad(item3, item2);
	char* line3_pad = pad(item3, item3);

	// Text Output
	printf("\n");
	printf("%4sPrice of item 1: $%s%.2f\n", " ", line1_pad, item1);
	printf("%4sPrice of item 2: $%s%.2f\n", " ", line2_pad, item2);
	printf("%4sPrice of item 3: $%s%.2f\n", " ", line3_pad, item3);
	printf("\n");

	// End Of Program
	free(line1_pad);
	free(line2_pad);
	free(line3_pad);
	return 0;
}
