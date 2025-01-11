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

    fn(s);
    fn(gS);

    s.calcTuition();
    gS.calcTuition();

    cout << "\n";
    return 0;
}