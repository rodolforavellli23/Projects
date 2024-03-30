#include <iostream>
#include <math.h>

using namespace std;

int main(void){
    int count = 0;
    for(int i = 0; i < 1000; i++){
        if(i % 3 == 0 || i % 5 == 0){
            count+=i;
        }
    }

    cout << "\n";
    cout << "The sum of all integers divisible by 3 & 5 that are smaller than 1000 is equal to : " << count ;
    cout << "\n";

    return 0;
}
