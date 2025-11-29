#include <stdio.h>
#include <string.h>
#include <limits.h>

int main() {
    const char *text = "programming";
    const char *vowels = "aeiouAEIOU";
    size_t length;

    // Calculate the length of the initial segment without any vowels
    length = strcspn(text, vowels);

    printf("\nOriginal string: %s\n", text);
    printf("Characters to avoid: %s\n", vowels);
    printf("The first vowel in \"%s\" is at index: %zu\n", text, length); // Use %zu for size_t
    printf("\nSize of size_t = %zu\n", sizeof(size_t));
    printf("Size of INT_MAX = %i\n", INT_MAX);

    return 0;
}
