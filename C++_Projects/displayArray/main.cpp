#include <iostream>

using namespace std;

/*	C++ Exercise for studying pointers.
 *
 * 	Function for displaying the number of elements
 * 	inside an array.
 * */

void displayArray(int intArray[], int nSize) {
	
	// Whenever an '*p' pointer is referencing an array as it is declared,
	// it points to &array[0]
	
	cout << "\tThe elements inside the array are:";

	int* pArray = intArray;

	for(int i = 0; i < nSize; i++) {
		cout << "\n\tElement " << i << ": " << pArray[i];
	}
	cout << endl;
}

int main(int nNumberofArgs, char* pszArgs[]) {

	int array[] = {4,3,2,1};

	cout << "\n";

	displayArray(array, 4);

	cout << "\tPress enter to continue..." << endl;
	cin.ignore(10, '\n');
	cin.get();
	return 0;
}
