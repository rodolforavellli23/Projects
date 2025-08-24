#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <numbers>

double pi(int n){
	// Local Variables
	double pi = 3.0;

	// The Nilakantha series for approximating π
	for(int i = 1; i < n; i++){
		int sign = pow((-1), (i + 1));
		double denom = ((2.0 * i) * ((2.0 * i) + 1.0) * ((2.0 * i) + 2.0));
		pi += (sign * (4.0 / (denom)));
	}

	return pi;
}

int main(void){
	// Text Output
	std::cout << "\n" << std::setw(51) << "π from <cmath>: " << std::fixed << std::setprecision(8) << (acos(-1));
	std::cout << "\n" << "π from <numbers>: " << std::fixed << std::setprecision(8) << std::numbers::pi;
	std::cout << "\n" << "π from 100 interactions of the Nilakantha series: " << std::fixed << std::setprecision(8) << pi(100) << "\n\n";
	return 0;
}
