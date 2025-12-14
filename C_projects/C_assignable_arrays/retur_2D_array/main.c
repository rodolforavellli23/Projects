#include <stdio.h>
#include <stdlib.h>

int** arr_2D_int(int rows, int cols) {
	
	// Counter variable
	int count = 1;

	// You called malloc, you'll have to free this later

	// Create an array of arrays, wherein each row is itself an array
	int **arr = (int **)malloc(rows * sizeof(int *));

	// Initialize each row
	for(int i = 0; i < rows; i++) {
		arr[i] = (int *)malloc(cols * sizeof(int));
	}

	// Populate 2D array with values
	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < cols; j++) {
			arr[i][j] = count;
			count++;
		}
	}
	return arr;
}

void print_2D_arr_int(int **arr, int rows, int cols) {
	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < cols; j++) {
			if(arr[i][j] <= 9) {
				if(i == (rows - 1) && j == (cols - 1)) {
					printf(" %i", arr[i][j]);
				} else if(j == (cols - 1)) {
					printf(" %i\n%14c", arr[i][j], ' ');
				} else {
					printf(" %i, ", arr[i][j]);
				}
			} else 	if(i == (rows - 1) && j == (cols - 1)) {
				printf("%i", arr[i][j]);
			} else if(j == (cols - 1)) {
				printf("%i\n%14c", arr[i][j], ' ');
			} else {
				printf("%i, ", arr[i][j]);
			}
		}
	}
}

void free_2D_arr_int(int **arr, int rows) {
	for(int i = 0; i < rows; i++) {
		free(arr[i]); // Free each row array first
	}
	free(arr); // Then free the array of arrays
}

int main(void) {
	
	// Variable Declaration
	int rows = 5;
	int cols = 5;
	int **myarr;

	// Making The Array Object
	myarr = arr_2D_int(rows, cols);
	
	// Printing Result
	printf("\n%2cMy Array: [ ", ' ');
	print_2D_arr_int(myarr, rows, cols);
	printf(" ]\n");

	// End of Program, freeing pointers
	free_2D_arr_int(myarr, rows);
	return 0;
}
