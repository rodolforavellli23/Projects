#include <iostream>
#include <string>
#include <iomanip>

int main() {

	// It's good practice to assign NULLto an empty pointer when it is first declared. NULL means that it doesn't have an assigned value.
	int *pNum = NULL;

	// The 'new' keyword is an operator that dynamically allocates memory for a variable on runtime.
	// EVERY TIME YOU USE THE 'new' OPERATOR, YOU MUST FREE THE USED MEMORY SPACE WITH THE 'delete' OPERATOR.
	pNum = new int;

	*pNum = 21;

	std::cout << "\n";
	std::cout << std::setfill(' ') << std::setw(25) << "My pointer: " << pNum;
	std::cout << "\n";
	std::cout << std::setfill(' ') << std::setw(25) << "Value inside my pointer: " << *pNum;
	std::cout << "\n";

	delete pNum;

	return 0;
}
