#include <stdio.h>
#include <string.h> // Required for strcspn if you want to remove the newline

int main() {
    char name[50];

    printf("\nEnter your name: ");
    fgets(name, sizeof(name), stdin);

    // Read up to 49 characters from standard input into 'name'
    if (name != NULL && name[0] != '\n') {

        // Optional: Remove the trailing newline character if it was read
        name[strcspn(name, "\n")] = '\0';

        printf("\nHello, %s\n", name);

    } else {

        printf("\nError reading input or end of input reached.\n");

    }

    return 0;
}
