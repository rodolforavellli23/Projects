// BoolTest program - Tests two integers and outputs wether the comparison is true or false.

#include <cstdio>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main(int nNumberofArgs, char* pszArgs[])
{
    //Sets the output format for boolean variables to 'true' or 'false', instead of '1' or '0'.
    cout.setf(cout.boolalpha);

    //Arguments Declaration.
    int nArg1 = 0;
    cout << "First  Argument input: ";
    cin >> nArg1;

    int nArg2 = 0;
    cout << "\nSecond Argument input: ";
    cin >> nArg2;

    //Compare
    bool b = 1;
    b = (nArg1 == nArg2);

    //Print
    cout << "\nThe statement " << nArg1 << " equals " << nArg2 << " is " << b <<". \n\n";

    return 0;
}
