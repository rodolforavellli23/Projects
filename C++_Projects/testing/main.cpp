#include <iostream>
#include <string>
#include <format>  // For std::format
#include <iomanip> // For std::setw
 
// To compile use: g++ -std=c++20 main.cpp -o ./bin/testing

// Repeater method
void repeater(char c, std::string pad, size_t size) {
	std::cout << "\n" << pad << "|";
	std::cout << std::setfill(c) << std::setw(size) << ""; // Need to apply this to an empty string
	std::cout << "|\n";
}

int main(void){
	// Pad
	std::string pad;
	pad = std::format("{:4c}", ' ');
	
	// First test
	char my_char_1 = '*';
	size_t size_1 = 5;

	// Second test
	char my_char_2 = 'a';
	size_t size_2 = 4;

	// Output
	repeater(my_char_1, pad, size_1);
	repeater(my_char_2, pad, size_2);

	// End of program
	std::cout << std::endl;
	return 0;
}
