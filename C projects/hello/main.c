#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void version(char* c, size_t size) {
    const char* ver_string;
#ifdef __STDC_VERSION__
    switch(__STDC_VERSION__) {
        case 199409L: 
			ver_string = "C95";
			break;
        case 199901L: 
			ver_string = "C99";
			break;
        case 201112L: 
			ver_string = "C11";
			break;
        case 201710L: 
			ver_string = "C17";
			break;
        case 202311L: 
			ver_string = "C23";
			break;
        default:      
			ver_string = "Unknown C standard";
    }
#else
    ver_string = "C89/C90 (or non-compliant)";
#endif
    strncpy(c, ver_string, size - 1); // Prevent Buffer Overflow
    c[size - 1] = '\0'; // Ensure Null Termination
}

int main() {
    char ver[26] = {0};
    version(ver, sizeof(ver));    
    printf("\n\tHello World! From C version: %s\n", ver);
#ifdef __STDC_VERSION__
    printf("\t__STDC_VERSION__ = %ld\n\n", __STDC_VERSION__);
#endif
    return 0;
}