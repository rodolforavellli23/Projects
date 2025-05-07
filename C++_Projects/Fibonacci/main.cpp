#include <iostream>
#include <string>

using namespace std;

void fib(int i) {
    // Create array.
	int arr[i];
	arr[0] = 0;
	
	// Fibonacci logic.
	if(i > 1) {
		arr[1] = 1;
	}

	if(i > 2) {
		for(int num = 2; num < i; num++) {
			arr[num] = (arr[num - 1]) + (arr[num - 2]);
		}
	}

    for(int index = 0; index < i; index++) {
        if(arr[index] < 10) {
    		cout << "\n\tElement (" << index + 1 << "):  "  << arr[index] << ";";
        } else {
            cout << "\n\tElement (" << index + 1 << "): "  << arr[index] << ";";
        }
	}

//	cout << "\n\n\tFibonacci numbers up to element number \"" << i << "\": ";

//	for(int element = 0; element < i; element++) {
//		cout << arr[element] << " ";
//	}

	cout << "\n\n";
}

int main(void) {
	
	// How large must the array be?
	int i = 0;
	cout << "\n\tHow many elements of the Fibonacci sequence do you wish to print? \n\n\t";
	cin >> i;
	
	fib(i);

	// End program
	return 0;
}
