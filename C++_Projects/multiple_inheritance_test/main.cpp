// multiple inheritance chapter of the book

#include <iostream>
#include "Bed.h"
#include "Sofa.h"

using namespace std;

class SleeperSofa : public Bed, public Sofa
{
public:
    SleeperSofa() {}
    void foldOut() { cout << "\n\tFold out" << endl; }
};

int main(int nNumberofArgs, char *pszArgs[])
{
    SleeperSofa ss;

    ss.watchTV();
    ss.foldOut();
    ss.sleep();

    cout << "\n\tPress Enter to continue...";
    cin.ignore(10, '\n');
    cin.get();
    return 0;
}