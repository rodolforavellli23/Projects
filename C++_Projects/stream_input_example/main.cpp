// Simple input stream from a file using fstream

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

ifstream &openFile()
{
    ifstream *pFileStream = 0;
    for (;;)
    {
        // Open file given as argument by the user
        string sFileName;
        cout << "\n\tEnter the name of a file you wish to read: ";
        cin >> sFileName;

        // Takes the file text output to the declared pointer
        pFileStream = new ifstream(sFileName.c_str());

        // Error Handling
        if (pFileStream->good())
        {
            pFileStream->seekg(0);
            cerr << "\n\tSuccessfully opened " << sFileName << endl;
            cout << "\n";
            break;
        }
        cerr << "\n\tCouldn't open " << sFileName << endl;
        delete pFileStream;
    }

    return *pFileStream;
}

int main(int nNumberofArgs, char *pszArg[])
{

    cout << "\n\tTo exit the program press Ctrl+C" << endl;

    // Retrieves an file from the std io stream

    ifstream &fileStream = openFile();

    // Reads a file line by line, and then prints the result
    string line;
    while (getline(fileStream, line))
    {
        cout << "\t" << line << endl;
    }

    /**
     * Note: the getline() function will read a stream of characters until
     *       it gets to read some kind of new line, eof or any delimiter is
     *       found.
     */

    cout << "\n\tPress Enter to Continue." << endl;
    cin.ignore(10, '\n');
    cin.get();
    return 0;
}