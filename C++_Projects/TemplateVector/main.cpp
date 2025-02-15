#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "templatevector.h"

using namespace std;

int main(int argc, char *pArgs[])
{
    TemplateVector<int> myVector = {10, 20, 30, 40, 50};

    cout << "\n\tVector size: " << myVector.size() << " items\n\n";

    for (int i = 0; i < myVector.size(); i++)
    {
        cout << "\tItem (" << i << "): " << myVector.get() << endl;
    }

    cout << "\n\tPress Enter to continue..." << endl;
    cin.ignore(10, '\n');
    cin.get();
    return 0;
}