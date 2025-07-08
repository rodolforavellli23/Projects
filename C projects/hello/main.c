#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void version(char c[8]) {
#ifdef __STDC_VERSION__
    switch(__STDC_VERSION__) {
        case 199409L: 
			strcpy(c, "C95"); 
			break;
        case 199901L: 
			strcpy(c, "C99"); 
			break;
        case 201112L: 
			strcpy(c, "C11"); 
			break;
        case 201710L: 
			strcpy(c, "C17"); 
			break;
        case 202311L: 
			strcpy(c, "C23"); 
			break;
        default:      
			strcpy(c, "Unknown C standard");
    }
#else
    strcpy(c, "C89/C90 (or non-compliant)");
#endif
}

int main() {
    char ver[8] = {0};
    version(ver);
    
    printf("\n\tHello World! From C version: %s\n", ver);
#ifdef __STDC_VERSION__
    printf("\t__STDC_VERSION__ = %ld\n\n", __STDC_VERSION__);
#endif
    return 0;
}