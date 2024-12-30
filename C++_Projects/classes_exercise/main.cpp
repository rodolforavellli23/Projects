#include <iostream>
#include <string>

using namespace std;

class savingsAccount{
    public:
        unsigned accNumber;
        double balance;
        string name;
};

double deposit (savingsAccount& s, double amount){
    s.balance += amount;
    return s.balance;
}

int main(int nNumberofArgs, char* pszArgs[]){
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
    if(confirm){
        deposit(myAccount, amount);
    }
    printf("\n\tAccount balance: $ %.2f", myAccount.balance);
    cout << "\n" << endl;

    return 0;
}