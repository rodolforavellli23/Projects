#include<stdio.h>
#include<stdlib.h>

// tony C tutorial - How ls works?

int main(int argc, char *argv[]) {
	// Start
	// Variables
	const char *pad = "    ";
	const char *path = (argc > 1)? argv[1] : ".";

	// Text 
	printf("\n%s%s\n\n", pad, path);

	// End
	return 0;
}
