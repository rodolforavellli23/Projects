#pragma once

#include <iostream>
#include "Furniture.h"

using namespace std;

class Sofa : virtual public Furniture
{
public:
    Sofa(int w = 0) : Furniture(w) {}
    void watchTV() { cout << "\n\tWatchTV" << endl; }
};