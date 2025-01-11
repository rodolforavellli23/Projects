#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gradStudent.h"

using namespace std;

void fn(Student& x){
    x.calcTuition();
}

int main(){
    Student s;
    gradStudent gS;

    /**
     * By passing an instance of an student object, the method will use the
     * method in the Student class since we declared the '.calcTuition()' method
     * of the class as a virtual method, and vice versa for the method in the
     * 'gradStudent' class.
     */

    fn(s);
    fn(gS);

    cout << "\n";
    return 0;
}