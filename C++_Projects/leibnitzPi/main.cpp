#include <iostream>
#include <cmath>

/*
 *   This function was discovered by the German mathematician Gottfried Wilhelm Leibniz,
 *   and it can be used to aproximate the value of the constant 'pi', which is an irrational number
 *   approximately equal to 22/7, and is the result of the division of the cord length of any given
 *   regular circle's circunference by it's own diameter.
 *
 */

using namespace std;

int main()
{
    float k = 0.0f, result = 0.0f;

    for(int i = 0; i < 10000000; i++){
        result+=(pow((-1), k))/((2.0*k)+1.0);
        k++;
    }

    result*=4.0f;

    printf("\nPi is approximately equal to: %.8f\n", result);

    return 0;
}
