#include <iostream>
#include <string>

/*	std::cout <<   - output to standard output (stdout)
 *	std::cin >>    - input to standard input (stdin)
 *	std::getline(<input_method>, <destination_var>) - allows you to get a line with space characters 
 * */

int main(void){

	std::string name;
	std::string status;
	int age;

	std::cout << "\n\nWhat's your name? ";
	std::getline(std::cin >> std::ws, name); 

	// Adding std::ws allows you to remove any prior special characters that may 
	// prevent getline from working properly.

	std::cout << "\nHow old are you? ";
	std::cin >> age;

	if(age >= 30){
		status = "old";
	}else{
		status = "young";
	}

	std::cout << "\nHello " << name << "!";
	std::cout << "\nYou're " << status << "!\n\n";
	
	return 0;
}
