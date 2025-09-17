#include <iostream>
#include <string>
#include <vector>
#include "gettype.h"

int main() {
	int a = 10;
	std::string s = "hello";
	std::vector<int> v;

	std::cout << "Type of 'a': " << get_type_name(typeid(a)) << std::endl;
	std::cout << "Type of 's': " << get_type_name(typeid(s)) << std::endl;
	std::cout << "Type of 'v': " << get_type_name(typeid(v)) << std::endl;

	return 0;
}
