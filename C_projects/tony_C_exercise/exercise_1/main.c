#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<dirent.h>
#include<errno.h>
#include<string.h>

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

	// Directory entity
	DIR *dir = opendir(path);

	// Reading the directory entity
	struct dirent *entry;
	entry = readdir(dir);

	// Error handling
	//
	// opendir error
	char error_mesg[16];
	size_t emes_t = sizeof(error_mesg)/sizeof(error_mesg[0]);
	int emes_count = snprintf(error_mesg, emes_t, "\n%sopendir", pad);
	if (!dir) {
		perror(error_mesg);
		printf("\n");
		return 1;
	}
	
	// Text Output -- To Do: Replace this logic with getopt
	printf("\n");
	if (argv[2] && (strncmp(argv[2], "-a", 2)) == 0 ) {
		while ((entry = readdir(dir)) != NULL) {
			printf("%s%s\n", pad, entry->d_name);
		}
	} else {
		while ((entry = readdir(dir)) != NULL) {
			if ((strncmp(entry->d_name, ".", 1)) == 0) {
				continue;
			} else {
				printf("%s%s\n", pad, entry->d_name);
			}
		}
	}

	// Close the directory entity
	closedir(dir);

	// End
	printf("\n");
	return 0;
}
