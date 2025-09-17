#include <iostream>
#include <string>
#include <iomanip>
#include <typeinfo> // Required for typeid()
#include "gettype.h"

// This version of the printer function will work for all arrays,
// independently of the array type.

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

	/* Variable Declaration.
     *
	 * Pointers must be of the same type as the variable being referenced.
     * using '*' on an array will access the value stored at index '0' of said array.
     */
	
	std::string  Name  = "Bro";
	std::string* pName = &Name;

	int age = 30;
	int* pAge = &age;

	std::string pizza_arr[] = {"pizza 1", "pizza 2", "pizza 3", "pizza 4", "pizza 5"};
	int size_arr = sizeof(pizza_arr)/sizeof(pizza_arr[0]);

	// Text Output
    // Start
	std::cout << "\n";

	std::cout << std::setfill(' ') << std::setw(25) << std::right << "Name Var Content: " << Name << "\n";
	std::cout << std::setfill(' ') << std::setw(25) << std::right << "Name Var Type: " << get_type_name(typeid(Name)) << "\n";
	std::cout << std::setfill(' ') << std::setw(25) << std::right << "Name Var Pointer Adress: " << pName << "\n\n";

	std::cout << std::setfill(' ') << std::setw(25) << std::right << "Age Var Content: " << *pAge << "\n";
	std::cout << std::setfill(' ') << std::setw(25) << std::right << "Age Var Type: " << get_type_name(typeid(*pAge)) << "\n";
    std::cout << std::setfill(' ') << std::setw(25) << std::right << "Age Var Pointer: " << pAge << "\n\n";

   	std::cout << std::setfill(' ') << std::setw(25) << std::right << "Pizza Array Content: ";
	array_printer(pizza_arr, size_arr);
    std::cout << "\n";
	std::cout << std::setfill(' ') << std::setw(25) << std::right << "Array Var Type: " << get_type_name(typeid(*pizza_arr)) << "\n";
	std::cout << std::setfill(' ') << std::setw(25) << std::right << "Pizza Array Pointer: " << pizza_arr << "\n";

    // End
	std::cout << "\n";
	return 0;
}

