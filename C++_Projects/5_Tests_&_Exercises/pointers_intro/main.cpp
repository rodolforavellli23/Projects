#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

int main(int nNumberofArgs, char* pszArgs[]) {
	bool 	   b; char  c; int    n; long         L;
	long long ll; float f; double d; long double ld;

	cout << "sizeof a bool        =  " << sizeof  b << " bytes;" << endl;
	cout << "sizeof a char        =  " << sizeof  c << " bytes;" << endl;
	cout << "sizeof a int         =  " << sizeof  n << " bytes;" << endl;
	cout << "sizeof a long        =  " << sizeof  L << " bytes;" << endl;
	cout << "sizeof a long long   =  " << sizeof ll << " bytes;" << endl;
	cout << "sizeof a float       =  " << sizeof  f << " bytes;" << endl;
	cout << "sizeof a double      =  " << sizeof  d << " bytes;" << endl;
	cout << "sizeof a long double = "  << sizeof ld << " bytes;" << endl;

	/*
	 * Waits until the user is ready to end the program, 
	 * so that the user may see the results.
	 *
	 */
	
	cout << "\nPress ENTER to continue..." << endl;
	cin.ignore(10, '\n');
	cin.get();
	return 0;
}
