#include <iostream>
#include <string>
#include "savingsAccount.h"

using namespace std;

int main(int nNumberofArgs, char *pszArgs[])
{
    // My User
    savingsAccount myAccount;
    myAccount.accNumber = 1234;
    myAccount.balance = 0.0;
    myAccount.name = "Rodolfo";
    int confirm = 0;
    double amount = 0.0;

    // Display the user's information
    cout << "\n\tAccount name: " << myAccount.name;
    cout << "\n\tAccount number: " << myAccount.accNumber;
    printf("\n\tAccount balance: $ %.2f", myAccount.balance);

    // Make a deposit?
    cout << "\n\n\tDo a deposit? type 1 for yes, or 0 for no ";
    cin >> confirm;
    cout << "\n\tAmount total of deposit: ";
    cin >> amount;
    if (confirm)
    {
        myAccount.deposit(myAccount, amount);
    }
    printf("\n\tAccount balance: $ %.2f", myAccount.balance);
    cout << "\n" << endl;

    // End program
    return 0;
}