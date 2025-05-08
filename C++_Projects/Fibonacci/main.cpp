#include <iostream>
#include <iomanip>
#include <vector>       // For dynamic arrays
#include <cstdint>      // For uint64_t
#include <boost/multiprecision/cpp_int.hpp>

using namespace boost::multiprecision;
using namespace std;

void fib(int i) {
	// Create array.
	vector<cpp_int> arr(i);
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

	int max_index_width = to_string(i).length(); 	// Width for the largest index
	int max_num_width = to_string(arr.back()).length();	 // Width for the largest Fibonacci number

	cout << "\n";

 	for(int index = 0; index < i; index++) {
        	cout << "\tElement (" 
             	     << setfill('0') << setw(max_index_width) << right << (index + 1) << "):  " 
             	     << setfill(' ') << setw(max_num_width) << right << arr[index] << ";\n";
	}

	cout << "\n";
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
