#include <iostream>
#include <string>
#include <iomanip>
#include <typeinfo> // Required for typeid()
#include "gettype.h"

template <typename T>
void array_printer(T *arr, int size){
	for(int i = 0; i < size; i++){
		if(i == (size - 1)){
			std::cout << arr[i];
		} else {
			std::cout << arr[i] << ", ";
		}
	}
}

int main(void){

	// Variable Declaration
	// Pointers must be of the same type as the variable being referenced
	
	std::string  Name  = "Bro";
	std::string* pName = &Name;

	int age = 30;
	int* pAge = &age;

	std::string pizza_arr[] = {"pizza 1", "pizza 2", "pizza 3", "pizza 4", "pizza 5"};
	int size_arr = sizeof(pizza_arr)/sizeof(pizza_arr[0]);

	// Text Output
    // Start
	std::cout << "\n";

	std::cout << std::setfill(' ') << std::setw(21) << std::right << "Var Content: " << Name << "\n";
	// std::cout << "\n\tVar Type: " << typeid(Name).name();
	std::cout << std::setfill(' ') << std::setw(21) << std::right << "Var Type: " << get_type_name(typeid(Name)) << "\n";
	std::cout << std::setfill(' ') << std::setw(21) << std::right << "Var Pointer Adress: " << pName << "\n\n";

	std::cout << std::setfill(' ') << std::setw(21) << std::right << "Age: " << *pAge << "\n";
    std::cout << std::setfill(' ') << std::setw(21) << std::right << "Pointer of var Age: " << pAge << "\n\n";

	std::cout << std::setfill(' ') << std::setw(21) << std::right << "Pizza pointer: " << pizza_arr << "\n";
   	std::cout << std::setfill(' ') << std::setw(21) << std::right << "Pizza array: ";

	array_printer(pizza_arr, size_arr);

    // End
	std::cout << "\n";
	return 0;
}

