#pragma once

#include <iostream>

using namespace std;

class Bed
{
public:
    Bed() {}
    void sleep() { cout << "\n\tSleep" << endl; }
    int weight;
};