#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include <string>

using namespace std;

class savingsAccount
{
public:
    unsigned accNumber;
    double balance;
    string name;
    double deposit(savingsAccount &s, double amount)
    {
        s.balance += amount;
        return s.balance;
    }
};

#endif