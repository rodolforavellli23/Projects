#include <stdio.h>
#include <stdlib.h>

int* generate_fibonacci(int n) {
    if (n <= 0) return NULL;  // Invalid input
    
    // Allocate memory for 'n' integers
    int* fib_sequence = (int*)malloc(n * sizeof(int));
    
    if (fib_sequence == NULL) {
        printf("\n\tMemory allocation failed!\n\n");
        return NULL;
    }
    
    fib_sequence[0] = 0;  // First Fibonacci number
    if (n > 1) fib_sequence[1] = 1;  // Second Fibonacci number
    
    for (int i = 2; i < n; i++) {
        fib_sequence[i] = fib_sequence[i-1] + fib_sequence[i-2];
    }
    
    return fib_sequence;  // Return the dynamically allocated array
}

int main() {
    int n;
    printf("\n\tEnter how many Fibonacci numbers to generate: \n\n\t");
    scanf("%d", &n);
    
    int* fib_numbers = generate_fibonacci(n);
    
    if (fib_numbers == NULL) {
        printf("\n\nError generating Fibonacci sequence.\n\n");
        return 1;
    }
    
    printf("\n\tFibonacci sequence: \n\n\t");
    for (int i = 0; i < n; i++) {
        if (i < n-1) {
			printf("%d, ", fib_numbers[i]);
		} else {
			printf("%d ", fib_numbers[i]);
		}
    }
    printf("\n\n");
    
    free(fib_numbers);  // Release memory to avoid leaks
    return 0;
}