#include <iostream>

using namespace std;

template <class T>
T maximum(T t1, T t2)
{
    return (t1 > t2) ? t1 : t2;
}

int main(int argc, char *pszArgs[])
{
    cout << "\n\tmaximum(-1, 3) = " << maximum(-1, 3) << endl;
    cout << "\n\tmaximum(2, 2.5) = " << maximum<double>(2, 2.5) << endl;

    cout << "\n\tPress Enter to continue..." << endl;
    cin.ignore(10, '\n');
    cin.get();
    return 0;
}