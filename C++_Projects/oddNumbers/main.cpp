#include <iostream>
#include <array>
#include <numeric> // For the iota function

using namespace std;

int main(void)
{

    int i = 0; // Counter of odd numbers
    array<int, 33> arr; // Casts the array to be filled
    iota(arr.begin(), arr.end(), 0); // Fills up the 'arr' array

    for (int num : arr)
    {
        if (arr[num & 1] & 1)
        {
            i++; // The binary form of any odd number always ends in '1'
        }
    } // This loop will count how many odd numbers there are

    cout << "\n"; // Start spacer

    int j = 0; // index counter for the 'oddArr' array
    int oddArr[i]; // array storing odd numbers
    for (int num : arr)
    {
        if (arr[num] & 1)
        {
            oddArr[j] = arr[num];

            if (j < 5)
            {
                cout << "\t(0" << j << "): 0" << oddArr[j] << ";" << endl;
            }
            else if (j < 10)
            {
                cout << "\t(0" << j << "): " << oddArr[j] << ";" << endl;
            }
            else if (j > 9)
            {
                cout << "\t(" << j << "): " << oddArr[j] << ";" << endl;
            }

            j++;
        } // Logic for formating the console output of the array of odd numbers
    }// Loop for storing the odd number values from 'arr' into 'oddArr'

    int sizeOddArr = sizeof(oddArr) / sizeof(oddArr[0]);
    // Calculates the size of the odd numbers array

    cout << "\n\tSize of the odd numbers array: " << sizeOddArr << endl;
    // Console output for the sizeof 'oddArr'
    cout << "\n"; // End spacer

    return 0; // end program
}