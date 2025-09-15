#include<iostream>
#include<string>

// Function Templating Exercise:
//
// By using multiple templating type placeholders,
// we can mix and match variable types for our functions.
//
// The 'auto' keyword tells the compiler to deduce what
// return type should the function use.
template <typename T, typename U>
auto max(T x, U y){
	return (x > y)? x : y;
}

int main(void) {

	std::cout << "\n\tMax: " << max(3.5, 4);

	std::cout << "\n";
	return 0;
}
