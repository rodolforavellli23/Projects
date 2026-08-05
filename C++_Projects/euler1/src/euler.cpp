#include <iostream>
#include <sstream>
#include <iomanip>
#include <locale>

/*
*	The sum of all integers that are multiples of 3 & 5, without repetition, that are smaller than 1000,
*	is equal to the sum of all multiples of 3 and 5 up to the element immediately before 1000, minus the *	 multiples of '3 x 5' to avoid double counting.
*
*	Arithmetic sum: sum = ((a_1 + a_n)*n)/2; where a_1 is the first element of the series, which goes to
*	a_n, the last element in the series being summed.
*/

int sum3() {
	int a = ((3+999)*333)/2;
	return a;
}

int sum5() {
	int b = ((5+995)*199)/2;
	return b;
}

int sum15() {
	int c = ((15+990)*66)/2;
	return c;
}

int main() {

    /* Variables */
	double total = 0;
    std::stringstream ss;

    /* Sets the locale rules */
    ss.imbue(std::locale("en_US.UTF-8"));

    /* Calculate Total */
	total = sum3() + sum5() - sum15();

	/* Set fixed-point notation and exactly 1 decimal place */
    ss << std::fixed << std::setprecision(1) << total;
    std::string result = ss.str();

	std::cout << "\nThe sum of all integers that are multiples of 3 & 5, ";
	std::cout << "without repetition, \nthat are smaller than 1000, ";
	std::cout << "is equal to the sum of all multiples of 3 and 5 \nup to the element immediately before 1000, ";
	std::cout << "minus the multiples of '3 x 5' \nto avoid double counting.";
	std::cout << "\n\nThe result is equal to \"" << result << "\".\n";
	std::cout << "\n";

	return 0;
}
