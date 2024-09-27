#include <iostream>
#include <string>

using namespace std;

int main(int nNumberofArgs, char* pszArgs[])
{
    // String Declation
    const char* szString = "Rodolfo";
    string s = szString;
    cout << "\nThe given array was: '" << szString << "'" << endl;

    // String displayed as array
    cout << "Displaying the given string as an array: \n\n";
    for(int i = 0; i < s.length(); i++){
        cout << "\t(" << i <<  "): " << szString[i] << ";\n";
    }
    cout << endl;

    return 0;
}
