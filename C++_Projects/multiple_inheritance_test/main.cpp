// multiple inheritance chapter of the book

#include <iostream>
#include "Bed.h"
#include "Sofa.h"

using namespace std;

class SleeperSofa : public Bed, public Sofa
{
public:
    SleeperSofa(int w) : Furniture(w) {}
    void foldOut() { cout << "\n\tFold out" << endl; }
};

int main(int nNumberofArgs, char *pszArgs[])
{
    SleeperSofa ss(10);

    ss.watchTV();
    ss.foldOut();
    ss.sleep();

    cout << "\n\tWeight = " << ss.weight << " kg" << endl;

    cout << "\n\tPress Enter to continue...";
    cin.ignore(10, '\n');
    cin.get();
    return 0;
}