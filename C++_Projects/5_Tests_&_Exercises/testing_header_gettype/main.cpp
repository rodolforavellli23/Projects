#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "gettype.hpp"

int main() {
	int a = 10;
	double b = 3.3;
	std::string s = "hello";
	std::vector<int> v;

	std::cout << "\n";
	std::cout << std::setfill(' ') << std::setw(25) << std::right << "Type of var 'a': " << get_type_name(typeid(a)) << std::endl;
	std::cout << std::setfill(' ') << std::setw(25) << std::right << "Type of var 'b': " << get_type_name(typeid(b)) << std::endl;
	std::cout << std::setfill(' ') << std::setw(25) << std::right << "Type of var 's': " << get_type_name(typeid(s)) << std::endl;
	std::cout << std::setfill(' ') << std::setw(25) << std::right << "Type of var 'v': " << get_type_name(typeid(v)) << std::endl;
	std::cout << "\n";

	return 0;
}
