#include <stdlib.h>
#include <stdio.h>

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

int main(void){

	int size = 0;

	printf("\n%3cWhat is to be the size of the integer array? ", ' ');
	scanf("%i", &size);

	int *my_arr = return_int_arr(size);

	printf("\n%3cMy array = [", ' ');
	int_arr_printer(my_arr, size);
	printf("]\n");
	
	return 0;
}
