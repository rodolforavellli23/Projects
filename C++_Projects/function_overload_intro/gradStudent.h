#pragma once

#include <iostream>
#include "Student.h"

using namespace std;

class gradStudent : public Student
{
    public:
    void calcTuition(){
        cout << "\n\tWe're in gradStudent::calcTuition()" << endl;
    };
};
