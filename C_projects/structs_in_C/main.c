#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Example Struct
struct Student {
	char name[16];
	float gpa;
};

int main() {
	// Start
	// Students
	struct Student student1 = {"SpongeBob", 3.0};
	struct Student student2 = {"Patrick", 2.5};
	struct Student student3 = {"Sandy", 4.0};
	struct Student student4 = {"Squidward", 2.0};

	// Students Array List
	struct Student students[] = {student1, student2, student3, student4};

	// Array Length
	int length = sizeof(students)/sizeof(students[0]);

	// Loop through the array and print its contents
	// The minus character inside '%-16' indicates that this is a left-alligned string 
	for(int i = 0; i < length; i++) {
		printf("\nName: %-16s GPA: %.2f\n", students[i].name, students[i].gpa);

	}

	//End
	printf("\n");
	return 0;
}
