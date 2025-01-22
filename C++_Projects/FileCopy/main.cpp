// FileCopy program from a C++ exercise

#include <iostream>
#include <fstream>

using namespace std;

int main(int nNumberofArgs, char *pszArgs[])
{

    // Loop to repeat per argument passed to the program
    // Note pszArgs[0] is the program name itself, so start at 1

    for (int i = 1; i < nNumberofArgs; i++)
    {
        // Create a variable to store the file, plus a '.backup'
        string szSource(pszArgs[i]);
        string szTarget = szSource + ".backup";

        /**
         * Open the file to be read which was passed as an argument,
         * and create the backup.
         */

        ifstream input(szSource.c_str(), ios_base::in | ios_base::binary);

        ofstream output(szTarget.c_str(), ios_base::out | ios_base::binary | ios_base::trunc);

        if (input.good() && output.good())
        {
            cout << "\n\tBacking up " << szSource << "...";

            // Read an write 4 blocks until an EOF of Error Trow

            while (!input.eof() && input.good())
            {
                char buffer[4096];
                input.read(buffer, 4096);
                /**
                 * This makes it so that we don't hit the buffer limit
                 * should input < 4096 characters long.
                 */
                output.write(buffer, input.gcount());
            }
            cout << "\n\n\tFinished" << endl;
        }
        else
        {
            cout << "\n\n\tCouldn't copy " << szSource << endl;
        }
        
    }

    cout << "\n\tPress Enter to continue..." << endl;
    cin.ignore(10, '\n');
    cin.get();
    return 0;
}
