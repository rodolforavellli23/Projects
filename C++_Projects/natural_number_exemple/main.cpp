#include <iostream>

// Function to calculate factorial of a number
double factorial(int n) {
    double result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

// Function to calculate Euler's number
double calculateEuler(int terms) {
    double e = 0.0;
    for (int i = 0; i < terms; ++i) {
        e += 1.0 / factorial(i);
    }
    return e;
}

int main() {
    int terms;
    std::cout << "Enter the number of terms to approximate Euler's number: ";
    std::cin >> terms;

    double euler = calculateEuler(terms);
    std::cout << "\nApproximate value of Euler's number with " << terms << " terms is " << euler << std::endl;

    return 0;
}
