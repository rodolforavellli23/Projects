#include <iostream>
#include <math.h>

/*
*	The sum of all integers that are multiples of 3 & 5, without repetition, that are smaller than 1000, 
*	is equal to the sum of all multiples of 3 and 5 up to the element immediately before 1000, minus the *	 multiples of '3 x 5' to avoid double counting.
*
*	Arithmetic sum: sum = ((a_1 + a_n)*n)/2; where a_1 is the first element of the series, which goes to 
*	a_n, the last element in the series being summed.
*/ 

using namespace std;

int sum3(){
	int a = ((3+999)*333)/2;
	return a;
}

int sum5(){
	int b = ((5+995)*199)/2;
	return b;
}

int sum15(){
	int c = ((15+990)*66)/2;
	return c;
}

int main(){

	int total = 0;
	total = sum3() + sum5() - sum15();

	cout << "\nThe sum of all integers that are multiples of 3 & 5, without repetition, that are smaller than 1000, is equal to the sum of all multiples of 3 and 5 up to the element immediately before 1000, minus the multiples of '3 x 5' to avoid double counting.";
	cout << "\n\nThe result is equal to " << total;
	cout << "\n";

	return 0;
}
