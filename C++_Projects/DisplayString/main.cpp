#include <iostream>
#include <string>

using namespace std;

int main(int nNumberofArgs, char* pszArgs[])
{
    // String Declation
    const char* szString = "Hello World!";
    string s = szString;
    cout << "\n\tThe given array was: '" << szString << "'" << endl;

    // String displayed as array
    cout << "\tDisplaying the given string as an array: \n\n";
    for(int i = 0; i < s.length(); i++){
        if(i < 10){
            cout << "\t(" << i <<  "):  " << szString[i] << ";\n";
        } else {
            cout << "\t(" << i <<  "): " << szString[i] << ";\n";
        }
    }
    cout << endl;

    return 0;
}
