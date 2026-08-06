#include <iostream>
#include <string>

//  g++ main_2.cpp -std=c++20 -o ./bin/testing_2

int main(void) {
	std::string pad;
	std::string fill;

	pad = std::string(4, ' ');
	fill = std::string(10, '*');

	std::cout \
		<< "\n" \
		<< pad \
		<< "|" \
		<< fill \
		<< "|\n" \
		<< std::endl;

	return 0;
}
