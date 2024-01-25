#include <iostream>
#include <string>

using namespace std;

// [(t_F - 32)/9] = (t_C)/5 ; where t_F is a given temperature in the Farenheit scale, and t_C is a given temperature in the Celcius scale.

double convertFromF(double a) {
    double result = ((a-32)*5)/9;
    return result;
}

double convertFromC(double b) {
    double result = ((b/5)*9)+32;
    return result;
}

int main() {
    int c = 0;
    int d = 0;
    double e = 0;
    string exit = "";

    while(exit != "e") {
        cout << "Convert from Farenheit to Celsius, or the other way around? \n\nType 0 for °F to °C, 1 for the other way around: ";
        cin >> c;
        cout << "\nWhat is the value to be converted? ";
        cin >> e;

        if( c == 0 ) {
            d = convertFromF(e);
        } else {
            d = convertFromC(e);
        }

        string sign = (c == 0)?"°C":"°F";

        cout << "\nResult: " << d << sign << " \n";

        cout << "\nExit Program? Type \"e\" to exit: ";
        cin >> exit;
        cout << " ";
    }

    return 0;
}
