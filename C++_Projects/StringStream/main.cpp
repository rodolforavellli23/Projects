// stringstream exercise from the C++ book

#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

/**
 * Reads a string buffer, as if it was a file.
 * It will read: name, account number and balance
 */

bool parseString(const char *pString, char *pName, int arraySize, long &accountNum, double &balance)
{
    // Matches an input string stream object with the given string
    istringstream inp(pString);

    // Read until a coma is found
    inp.getline(pName, arraySize, ',');

    // Read account number
    inp >> accountNum;

    // Read balance
    inp >> balance;

    // Error handling
    return !inp.fail();
}

int main(int nNumberofArgs, char*  pszArgs[])
{
    // File name
    char szFileName[128];
    cout << "\n\tInput the name of the file to be parsed: ";
    cin.getline(szFileName, 128);

    // Catches file stream
    ifstream* pFileStream = new ifstream(szFileName);
    if (!pFileStream->good())
    {
        cerr << "\n\tCan't open " << pszArgs[1] << endl;
        return 0;
    }
    
    

}