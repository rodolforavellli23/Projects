#include <iostream>
#include <string>

using namespace std;

class savingsAccount{
    public:
        unsigned accNumber;
        double balance;
        string name;
};

int main(int nNumberofArgs, char* pszArgs[]){

    savingsAccount myAccount;
    myAccount.accNumber = 1234;
    myAccount.balance = 0.0;
    myAccount.name = "Rodolfo";

    cout << "\n\tAccount name: " << myAccount.name;
    cout << "\n\tAccount number: " << myAccount.accNumber;
    // cout << "\tAccount balance: " << myAccount.balance << "\n";
    printf("\n\tAccount balance: %.2f", myAccount.balance);
    cout << "\n" << endl;

    return 0;
}