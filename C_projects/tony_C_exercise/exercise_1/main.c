#include     <stdio.h>
#include    <stdlib.h>
#include <sys/types.h>
#include    <dirent.h>
#include     <errno.h>
#include    <string.h>
#include    <unistd.h>
#include     <fcntl.h>
#include  <sys/stat.h>
#include    <getopt.h>

// tony C tutorial - How ls works?

// Global Variables
int show_all = 0;

// Functions
void print_usage_stdout(const char *prog_name, const char *pad) {
	fprintf(stdout, "\n%sTony's ls clone tutorial\n", pad);
	fprintf(stdout, "\n%sUsage: %s [ -h , -a ] [path]\n", pad, prog_name);
	fprintf(stdout, "%s%s-h\tPrints this help messagen\n", pad, pad);
	fprintf(stdout, "%s%s-a\tShows hidden files and directories\n", pad, pad);
	fprintf(stdout, "\n");
}

void print_usage_stderr(const char *prog_name, const char *pad) {
	fprintf(stderr, "\n%sTony's ls clone tutorial\n", pad);
	fprintf(stdout, "\n%sUsage: %s [ -h , -a ] [path]\n", pad, prog_name);
	fprintf(stdout, "%s%s-h\tPrints this help messagen\n", pad, pad);
	fprintf(stdout, "%s%s-a\tShows hidden files and directories\n", pad, pad);
	fprintf(stdout, "\n");
}

// Program Entry Point
int main(int argc, char *argv[]) {
	// Start

	// Formatted pad string
	char pad[8];
	size_t pad_t = sizeof(pad)/sizeof(pad[0]);
	int pad_count = snprintf(pad, pad_t, "%4s", " ");

	// Long options struct
	static struct option long_options[] = {
		{"help", no_argument, NULL, 'h'}
	};

	// Options
	int opt;
	while((opt = getopt_long(argc, argv, "ah", long_options, NULL)) != -1) {
		switch(opt) {
			case 'a':
				show_all = 1;
				break;
			case 'h':
				print_usage_stdout(argv[0], pad);
				return 0;
			default:
				print_usage_stderr(argv[0], pad);
				return 1;
		}
	}

	// Path
	const char *path = (optind < argc)? argv[optind] : ".";

	// Directory entity
	DIR *dir = opendir(path);

	// Reading the directory entity
	struct dirent *entry;
	entry = readdir(dir);

	// Error handling

	/* opendir error */
	char error_mesg[16];
	size_t emes_t = sizeof(error_mesg)/sizeof(error_mesg[0]);
	int emes_count = snprintf(error_mesg, emes_t, "\n%sopendir", pad);
	if (!dir) {
		perror(error_mesg);
		printf("\n");
		return 1;
	}
	
	// Text Output
	printf("\n");
	if (show_all == 1) {
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
