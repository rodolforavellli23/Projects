#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* version(long int c) {
	
	char* ver_string;
	
	switch(c) {
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
		case 202000L:
			ver_string = "C23";
			break;
		default:
			ver_string = "C89/C90 (or non-compliant)";
	}
	return ver_string;
}

int main() {
  
    printf("\n%4cHello World! From C version: %s\n", ' ', version(__STDC_VERSION__) );
    
    //This Checks what number the macro is actually returning to the program
    //printf("%4c%ld\n", ' ', __STDC_VERSION__);

    return 0;
}
