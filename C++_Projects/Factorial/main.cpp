#include <iostream>
#include <math.h>
#include <string>

using namespace std;

int factorial(int a) {

    if (a == 0 || a == 1){
        return 1;
    } else {
        return a * factorial(a - 1);
    }
}

int main(void)
{
    int var;
    int result;

    cout << "\n Type number to factorialize: ";
    cin >> var;

    result = factorial(var);

    cout << "\n Result: " << result << endl;
    cout << "\n";

    return 0;
}
