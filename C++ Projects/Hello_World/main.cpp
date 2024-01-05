#include <iostream>
#include <string>

using namespace std;

string version(int a){
    string b = "";
    switch(a){
        case 202101:
            b = "C++23";
            break;
        case 202002:
            b = "C++20";
            break;
        case 201703:
            b = "C++17";
            break;
        case 201402:
            b = "C++14";
            break;
        case 201103:
            b = "C++11";
            break;
        case 199711:
            b = "C++98";
            break;
        default:
            b = "pre-standard C++";
    }

    return b;
}

int main() {

    cout << "Hello World! from version " << version(__cplusplus) << ".\n";

    return 0;
}
