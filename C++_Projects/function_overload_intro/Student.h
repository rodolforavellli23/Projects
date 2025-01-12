#pragma once

#include <iostream>

using namespace std;


/*
 * Signing a function as virtual adds polymorphism to that function, which allows
 * for that function to determine to which class the overloaded method belongs
 * to.
*/
class Student
{
    public:
    virtual void calcTuition(){ 
        cout << "\n\tWe're in Student::calcTuition()" << endl;
    };
};
