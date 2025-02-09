#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

template <typename T>
void processInput(T value)
{
    cout << "You entered a value of type " << typeid(T).name() << ": " << value << endl;
}

int main()
{
    string type;
    cout << "Enter the type (int, double, string): ";
    cin >> type;

    if (type == "int")
    {
        int intValue;
        cout << "Enter an integer: ";
        cin >> intValue;
        processInput(intValue);
    }
    else if (type == "double")
    {
        double doubleValue;
        cout << "Enter a double: ";
        cin >> doubleValue;
        processInput(doubleValue);
    }
    else if (type == "string")
    {
        string stringValue;
        cout << "Enter a string: ";
        cin >> stringValue;
        processInput(stringValue);
    }
    else if (type == "char")
    {
        char charValue;
        cout << "Enter a char: ";
        cin >> charValue;
        processInput(charValue);
    }
    else
    {
        cout << "Unsupported type!" << endl;
        return 1;
    }

    return 0;
}