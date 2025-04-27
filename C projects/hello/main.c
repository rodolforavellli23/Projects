#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
 
	char ver[16] = {};

	switch(__STDC_VERSION__){
		case 199409L:
			strcat(ver, "C95");
			break;
		case 199901L:
			strcat(ver, "C99");
			break;
		case 201112L:
			strcat(ver, "C11");
			break;
		case 201710L:
			strcat(ver, "C17");
			break;
		case 202311L:
			strcat(ver, "C23");
			break;
		default:
			strcat(ver, "C89/C90");	
		}

	printf("\n\tHello World! From C version: %s \n\n", ver);
	
	return 0;
}
