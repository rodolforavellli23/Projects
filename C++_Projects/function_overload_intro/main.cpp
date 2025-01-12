#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gradStudent.h"

/**
 * Since the class inside the header file "gradStudent.h" inherits the class
 * inside the "Student.h" header file, we only need to call the one header file
 * that inherits its parent class.
*/

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
     *
     * By default C++ is a statically compiled language, but using the 'virtual'
     * reserved keyword, we can use the polymorphic property of OOP.
    */

    fn(s);
    fn(gS);

    cout << "\n";
    return 0;
}