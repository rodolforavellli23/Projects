#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char product_code[11];
} Product;

int main(void) {

	Product A = {"0123456789"};
	Product B;
	
	B = A;

	printf("\n\tOriginal Array: %s\n\t    Copy Array: %s\n\n", A.product_code, B.product_code);
	
	return 0;
}
