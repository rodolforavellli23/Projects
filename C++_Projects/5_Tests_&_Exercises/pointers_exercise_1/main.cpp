# include <iostream>

using namespace std;


/* A void function does not return a visible 
 * output to stdout, this is called a method
 * in Object Oriented Programming.
 *
 * */

void fn(int* pnArg) { // The '*' character tells the compiler we're dealing with pointers.

	*pnArg = 10; // By passing a value through a pointer we're intructing the compiler to store the given value into that memory location. 
} 

/* An function starting with a variable type
 * Must return a output to stdout. As well as
 * have a 'return' somewhere in it's body.
 *
 * */

int main(void) {

	int n = 0;
	fn(&n); // Note: A variable name, when preceded by the '&' character, will invoke it's pointer value instead. 
	
	cout << "\n";
	cout << "\tYou have changed 'n' from 0 to " << n << " .\n";
	cout << endl;

	return 0;
}
