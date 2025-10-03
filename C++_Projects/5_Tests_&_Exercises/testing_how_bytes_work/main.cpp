#include <iostream>
#include <string>
#include <iomanip>
#include <format>
#include "gettype.hpp"
#include "getmemsize.hpp"

int main(void){
	DiskInfo disk("/");

	auto test = disk.getTotalSize();

	std::cout << "\n";
	std::cout << std::setfill(' ') << std::setw(20) << "test: " << test;
	std::cout << "\n";
	std::cout << std::setfill(' ') << std::setw(20) << "type of test: " << get_type_name(typeid(test));
	std::cout << "\n";

	return 0;
}
