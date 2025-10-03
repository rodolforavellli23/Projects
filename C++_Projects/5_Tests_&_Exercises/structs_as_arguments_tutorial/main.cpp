#include<iostream>
#include<string>
#include<iomanip>

// Car struct
struct Car {
	std::string model = "";
	std::string color = "";
	int year;
};

// Method for printing the attributes of the Car struct
void PrintCar(Car c) {
	std::cout << "\n" << std::setfill(' ') << std::setw(10) << std::right << "Model: " << c.model;
	std::cout << "\n" << std::setfill(' ') << std::setw(10) << std::right <<  "Year: " << c.year ;
	std::cout << "\n" << std::setfill(' ') << std::setw(10) << std::right << "Color: " << c.color;
}

// Paint the Car by accessing its pointer
void PaintCar(Car &c, std::string new_color) {
	c.color = new_color;
}

int main(void) {
	// Start of Program
	// Building the Car objects
	Car car1;
	Car car2;

	car1.model =  "Mustang";
	car1.year  =       2023;
	car1.color =      "red";

	car2.model = "Corvette";
	car2.year  =       2024;
	car2.color =     "blue";

	PaintCar(car2, "green");

	// Text Output
	// Car1
	std::cout << "\nCar1";
	std::cout << "\0" << std::setfill('-') << std::setw(5) << std::left << "\n";
	PrintCar(car1);

	// New Line - So as to add line space in between entries
	std::cout << "\n";
	
	// Car2
	std::cout << "\nCar2";
	std::cout << "\0" << std::setfill('-') << std::setw(5) << std::left << "\n";
	PrintCar(car2);

	// End of program
	std::cout << "\n\n";
	return 0;
}
