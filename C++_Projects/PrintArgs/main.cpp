#include <iostream>

using namespace std;

/* Note: if you pass the wildcard character * the executable will then
         list all files inside the same directory in which it is located
         in, kind of like a worse form of the 'ls' program.
*/

int main(int nNumberofArgs, char* pszArgs[])
{
    cout << "\nThe given program arguments are: " << endl;
    for(int i = 0; i < nNumberofArgs; i++){
        cout << "\n(" << i << "): " << pszArgs[i] << ";\n";
    }

    cout << "\nAll arguments given have been listed. End of program.\n" << endl;

    return 0;
}
