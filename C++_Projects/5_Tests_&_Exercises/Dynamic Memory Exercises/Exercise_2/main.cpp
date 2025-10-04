#include <iostream>
#include <string>
#include <limits> // Needed for std::numeric_limits

// Array printer function
void printer(const std::string *arr, int size) {
    for(int i = 0; i < size; i++) {
        if(i == (size - 1)) {
            std::cout << arr[i];
        } else {
            std::cout << arr[i] << " , ";
        }
    }
}

int main() {
    // Start
    // Variable declaration
    int size = 0;
    std::string *pGrades = NULL;
    
    // User input for array size
    std::cout << "\n";
    std::cout << "How many grades? ";
    std::cin >> size;
    std::cout << "\n";

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clears the buffer after reading the size
    
    // Array of strings to store multi-character grades
    pGrades = new std::string[size];

    // User input loop
    for(int i = 0; i < size; i++) {
        std::cout << "Enter grade " << (i + 1) << ": ";
        std::getline(std::cin, pGrades[i]); // Will read entire line as a string
    }
    
    // Print grades
    std::cout << "\nGrades array: ";
    printer(pGrades, size);
    
    // End
    std::cout << "\n";

    // Free memory
    delete[] pGrades;
    return 0;
}
