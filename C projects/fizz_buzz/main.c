#include <stdlib.h>
#include <stdio.h>

int main () {

	int limit = 0;

	printf("\n\n\tWhat is to be the limit for FizzBuzz? ");
	scanf("%i", &limit);

	for(int i = 1; i <= (limit); i++) {
		if(i % 3 == 0 && i % 5 == 0) {
			printf("\n\tFizzBuzz");
		} else if(i % 5 == 0) {
			printf("\n\tBuzz");
		} else if(i % 3 == 0) {
			printf("\n\tFizz");
		} else {
			printf("\n\t%i", i);
		}
	}
	
	printf("\n\n");
	return 0;
}
