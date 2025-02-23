#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>
#include <iomanip>
#include <limits>

using namespace std;

// [(t_F - 32)/9] = (t_C)/5 ; where t_F is a given temperature in the Fahrenheit scale, and t_C is a given temperature in the Celsius scale.

double convertFromF (double a) {
    double result = ((a-32)*5)/9;
    return result;
}

double convertFromC (double b) {
    double result = ((b/5)*9)+32;
    return result;
}

bool isInteger(const string& input) {
    istringstream iss(input);
    int value;
    // Try to read an integer from the string
    return (iss >> value) && (iss.eof()); // Check if the entire string was consumed
}

bool isFloatingPoint(const string& input) {
    istringstream iss(input);
    double value;
    // Try to read a floating-point number from the string
    return (iss >> value) && (iss.eof()); // Check if the entire string was consumed
}

int main() {
    string c = "";
    double d = 0;
    string e = "";
    string sign = "";
    string exit = "";

    while (exit != "e") {
        try {
            cout << "\nConvert from Fahrenheit to Celsius, or the other way around? \n\nType 0 for °F to °C, 1 for the other way around: ";
            cin >> c;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            int selection;
            try {
                selection = stoi(c); // Try to convert the selection to an integer
            } catch (const invalid_argument&) {
                throw invalid_argument("\nInvalid selection! Only select 0 (°F -> °C), or 1 (°C -> °F )");
                return -1;
            }

            if ( selection == 0 ) {
                sign = "°C";
                cout << "\nWhat is the value to be converted? ";
                getline(cin, e);
                if(isInteger(e)) {
                    d = convertFromF(stoi(e));
                    cout << "\nResult: " << fixed << setprecision(2) << d << sign << " \n";
                } else if(isFloatingPoint(e)) {
                    d = convertFromF(stod(e));
                    cout << "\nResult: " << fixed << setprecision(2) << d << sign << " \n";
                } else {
                    throw invalid_argument("\nThe value to be converted must be an number!");
                }
            } else if ( selection == 1) {
                sign = "°F";
                cout << "\nWhat is the value to be converted? ";
                getline(cin, e);
                if(isInteger(e)) {
                    d = convertFromC(stoi(e));
                    cout << "\nResult: " << fixed << setprecision(2) << d << sign << "\n";
                } else if(isFloatingPoint(e)) {
                    d = convertFromC(stod(e));
                    cout << "\nResult: " << fixed << setprecision(2) << d << sign << "\n";
                } else {
                    throw invalid_argument("\nThe value to be converted must be an number!");
                }
            } else {
                throw invalid_argument("\nInvalid selection! Only select 0 (°F -> °C), or 1 (°C -> °F )");
            }
        } catch (const invalid_argument &ei){
            cerr << ei.what() << endl;
            return -1;
        };

        cout << "\nExit Program? Type \"e\" to exit: ";
        cin >> exit;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    return 0;
}
