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

int main(int nNumberofArgs, char *pszArgs[])
{
    // File name
    char szFileName[128];
    cout << "\n\tInput the name of the file to be parsed: ";
    cin.getline(szFileName, 128);

    // Catches file stream
    ifstream *pFileStream = new ifstream(szFileName);
    if (!pFileStream->good())
    {
        /* Error Handing */
        cerr << "\n\tCan't open " << pszArgs[1] << endl;
        return 0;
    }

    // Reads and prints out each line of a file + Analysis
    for (int nLineNum = 1;; nLineNum++)
    {
        /* Reads the buffer */
        char buffer[256];
        pFileStream->getline(buffer, 256);
        if (pFileStream->fail())
        {
            /* Error Handing */
            break;
        }
        /* Writes to std out stream each line until a deliminator is found */
        cout << "\n\tLine " << nLineNum << ": " << buffer << endl;

        // Analysis
        char name[80];
        long accountNum;
        double balance;
        bool result = parseString(buffer, name, 80, accountNum, balance);

        if (result == false)
        {
            /* code */
            cerr << "\n\tError parsing string\n"
                 << endl;
            continue;
        }

        // Takes result and prints it out on screen as fields
        cout << "\n\tThe program read the following fields: " << endl;
        cout << "\tName: " << name
             << "\n\tAccount: " << accountNum
             << "\n\tBalance: " << balance << endl;

        // Reordered new line
        ostringstream out;
        out << name << ", "
            << balance << ", "
            << accountNum << ends;

        string oString = out.str();
        cout << "\n\tReordered line: " << oString << endl;
    }

    // End program
    cout << "\n\tPress Enter to continue..." << endl;
    cin.ignore(10, '\n');
    cin.get();
    return 0;
}