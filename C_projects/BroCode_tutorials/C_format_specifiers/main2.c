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

int main(void) {

	// Variables
	float item1 =   5.75;
	float item2 =  10.00;
	float item3 = 100.99;

	// Text Output
	printf("\n");
	printf("%4sPrice of item 1: $%7.2f\n", " ", item1);
	printf("%4sPrice of item 2: $%7.2f\n", " ", item2);
	printf("%4sPrice of item 3: $%7.2f\n", " ", item3);
	printf("\n");

	// End Of Program
	return 0;
}
