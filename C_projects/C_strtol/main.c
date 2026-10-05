#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main() {
    const char *str = "   -12345extra_garbage";
    char *endptr;
    
    // Reset errno before the call
    errno = 0; 
    
    long value = strtol(str, &endptr, 10);

    // 1. Check for underflow/overflow errors
    if (errno == ERANGE) {
        printf("Error: The number overflows or underflows a long int.\n");
    }
    // 2. Check if absolutely no numbers were parsed
    else if (str == endptr) {
        printf("Error: No valid digits could be found.\n");
    }
    // 3. Success (though potentially with trailing garbage)
    else {
        printf("Successfully converted: %ld\n", value);
        
        // If *endptr is '\0', it means the entire string was a clean number
        if (*endptr != '\0') {
            printf("Leftover unparsed text: \"%s\"\n", endptr);
        }
    }

    return 0;
}

