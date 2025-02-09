#pragma once

#include <iostream>
#include "Furniture.h"

using namespace std;

class Bed : virtual public Furniture
{
public:
    Bed(int w = 0) : Furniture(w) {}
    void sleep() { cout << "\n\tSleep" << endl; }
};