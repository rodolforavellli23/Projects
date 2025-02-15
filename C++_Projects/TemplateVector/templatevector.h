#pragma once

#include <iostream>
#include <utility>

using namespace std;

template <class T>
class TemplateVector
{
public:
    TemplateVector(const initializer_list<T> il)
    {
        nSize = il.size();
        array = new T[nSize];
        nWriteIndex = 0;
        nReadIndex = 0;
        // Copies the contents of il to the vector
        for (const T &item : il)
        {
            add(item);
        }
    }
    ~TemplateVector() { delete[] array; }
    int size() { return nSize; }
    void add(const T &object)
    {
        if (nWriteIndex < nSize)
        {
            array[nWriteIndex] = object;
            nWriteIndex++;
        }
    }

    T &get()
    {
        if (nReadIndex >= nSize)
        {
            throw out_of_range("Read index out of bounds");
        }

        int a = nReadIndex;
        nReadIndex++;
        return array[a];
    }

protected:
    int nSize;
    int nWriteIndex;
    int nReadIndex;
    T *array;
};