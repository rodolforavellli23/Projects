#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(void) {
	// Variable Declaration
	double x, root, cube;

	// User Input
	printf("\n%4cPlease type a number: ", ' ');
	scanf("%lf", &x);

	// Console Output
	printf("\n%4cRoot of %'.2lf ~= %'.2lf\n", ' ', x, sqrt(x));
	printf("\n%4c%'.2lf to the cube = %'.2lf", ' ', x, pow(x, 3));
	printf("\n");

	return 0;
}
