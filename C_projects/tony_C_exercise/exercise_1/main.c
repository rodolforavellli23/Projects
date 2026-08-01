#include<stdio.h>
#include<stdlib.h>

// tony C tutorial - How ls works?

int main(int argc, char *argv[]) {
	// Start

	// Variables
	//
	// Formatted pad string
	char pad[8];
	size_t pad_t = sizeof(pad)/sizeof(pad[0]);
	int pad_count = snprintf(pad, pad_t, "%4s", " ");
	
	// Path
	const char *path = (argc > 1)? argv[1] : ".";

	// Text Output 
	printf("\n%s%s\n\n", pad, path);

	// End
	return 0;
}
