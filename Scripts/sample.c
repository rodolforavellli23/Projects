#include<stdlib.h>
#include<stdio.h>

int main(void) {

int i = 0, j = 0, c = 0 ;

for( i; i < 7; i++) {
  for( j; j < 4; j++) {
	c++;
	if( c < 10){
	   printf(" 0%i", c);
	}else{
	   printf(" %i", c);
	}
      }
      if(j == 4) {
         j = 0;
         printf("\n");
      }
   }
 return 0;
}
