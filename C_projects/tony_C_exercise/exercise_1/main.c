#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <getopt.h>
#include <pwd.h>
#include <grp.h>
#include <math.h>
#include <time.h>

// Tony C Tutorial - How ls works?

// Global Variables
int show_all = 0;
int print_long_out = 0;

// Functions

// Usage message, stdout
void print_usage_stdout(const char *prog_name, const char *pad) {
	fprintf(stdout, "\n%sTony's ls clone tutorial\n", pad);
	fprintf(stdout, "\n%sUsage: %s [ -h , -a, -l ] [path]\n", pad, prog_name);
	fprintf(stdout, "%s%s-h\tPrints this help messagen\n", pad, pad);
	fprintf(stdout, "%s%s-a\tShows hidden files and directories\n", pad, pad);
	fprintf(stdout, "%s%s-l\tShows permission information of files and directories on the given [path]\n", pad, pad);
	fprintf(stdout, "\n");
}

// Usage message, stderr
void print_usage_stderr(const char *prog_name, const char *pad) {
	fprintf(stderr, "\n%sTony's ls clone tutorial\n", pad);
	fprintf(stdout, "\n%sUsage: %s [ -h , -a , -l ] [path]\n", pad, prog_name);
	fprintf(stdout, "%s%s-h\tPrints this help messagen\n", pad, pad);
	fprintf(stdout, "%s%s-a\tShows hidden files and directories\n", pad, pad);
	fprintf(stdout, "%s%s-l\tShows permission information of files and directories on the given [path]\n", pad, pad);
	fprintf(stdout, "\n");
}

// Building permissions string
void mode_string(mode_t mode, char *str) {
	/* Type of object being listed  */
	     if (S_ISDIR(mode))  { str[0] = 'd'; } 
	else if (S_ISLNK(mode))  { str[0] = 'l'; }
	else if (S_ISCHR(mode))  { str[0] = 'c'; }
	else if (S_ISBLK(mode))  { str[0] = 'b'; }
	else if (S_ISFIFO(mode)) { str[0] = 'p'; }
	else if (S_ISSOCK(mode)) { str[0] = 's'; }
	else                     { str[0] = '-'; }
	/* User  Permisions  */
	str[1] = (mode & S_IRUSR)? 'r' : '-';
	str[2] = (mode & S_IWUSR)? 'w' : '-';
	str[3] = (mode & S_IXUSR)? 'x' : '-';
	/* Group Permisions  */
	str[4] = (mode & S_IRGRP)? 'r' : '-';
	str[5] = (mode & S_IWGRP)? 'w' : '-';
	str[6] = (mode & S_IXGRP)? 'x' : '-';
	/* Other Permisions  */
	str[7] = (mode & S_IROTH)? 'r' : '-';
	str[8] = (mode & S_IWOTH)? 'w' : '-';
	str[9] = (mode & S_IXOTH)? 'x' : '-';
	/* End of String  */
	str[10] = '\0';
}

void print_long(const char *dir, const char *name, const char *pad) {

	size_t name_t = (size_t)round(pow(2, 9));

	char fullpath[4096];
	size_t fpath_t = sizeof(fullpath)/sizeof(fullpath[0]);
	(void)snprintf(fullpath, fpath_t, "%s/%s", dir, name);

	struct stat st;
	char error_mesg_2[name_t];
	size_t emes_2_t = sizeof(error_mesg_2)/sizeof(error_mesg_2[0]);
	(void)snprintf(error_mesg_2, emes_2_t, "\n%s%s", pad, name );

	// The side effect of the lstat function is that it dumps the contents 
	// of the fullpath into st, and returns a number (either: -1 (error), 0 (success))
	if (lstat(fullpath, &st) < 0) {
		perror(error_mesg_2);
		return;
	}

	char modes[11];
	mode_string(st.st_mode, modes);

	struct passwd *pw    = getpwuid(st.st_uid);
	struct group  *gr    = getgrgid(st.st_gid);
	const  char   *user  = pw? pw->pw_name : "?";
	const  char   *group = gr? gr->gr_name : "?";

	char timebuf[64];
	size_t tbuf_t = sizeof(timebuf)/sizeof(timebuf[0]);

	struct tm *tm = localtime(&st.st_mtim.tv_sec);
	strftime(timebuf, tbuf_t, "%b %e %H:%M", tm);

	// Output
	printf("%s%s %lu %s %s %ld %s %s\n", \
			pad, \
			modes, \
			(unsigned long)st.st_nlink, \
			user, \
			group, \
			(long)st.st_size, \
			timebuf, \
			name);
}

// Program Entry Point
int main(int argc, char *argv[]) {
	// Start

	// Formatted pad string
	char pad[8];
	size_t pad_t = sizeof(pad)/sizeof(pad[0]);
	(void)snprintf(pad, pad_t, "%4s", " ");

	// Long options struct
	static struct option long_options[] = {
		{"help", no_argument, NULL, 'h'}
	};

	// Options
	int opt;
	while((opt = getopt_long(argc, argv, "ahl", long_options, NULL)) != -1) {
		switch(opt) {
			case 'a':
				show_all = 1;
				break;
			case 'h':
				print_usage_stdout(argv[0], pad);
				return 0;
			case 'l':
				print_long_out = 1;
				break;
			default:
				print_usage_stderr(argv[0], pad);
				return 1;
		}
	}

	// Path
	const char *path = (optind < argc)? argv[optind] : ".";

	// Directory entity
	DIR *dir = opendir(path);

	// Error handling

	/* opendir error */
	char error_mesg_1[16];
	size_t emes_1_t = sizeof(error_mesg_1)/sizeof(error_mesg_1[0]);
	(void)snprintf(error_mesg_1, emes_1_t, "\n%sopendir", pad);
	
	if (!dir) {
		perror(error_mesg_1); 
		print_usage_stderr(argv[0], pad);
		printf("\n");
		return 1;
	}

	// End of error handling
	
	// Reading the directory entity
	struct dirent *entry;
	entry = readdir(dir);

	// Text Output
	printf("\n");
	if ((print_long_out == 1) && (show_all == 1)) {
		while ((entry = readdir(dir)) != NULL) {
			print_long(path, entry->d_name, pad);
		}
	} else if ((print_long_out == 1) && (show_all == 0) ){
		while ((entry = readdir(dir)) != NULL) {
			if ((strncmp(entry->d_name, ".", 1)) == 0) {
				continue;
			} else {
				print_long(path, entry->d_name, pad);
			}
		}
	} else if (show_all == 1) {
		while ((entry = readdir(dir)) != NULL) {
			printf("%s%s\n", pad, entry->d_name);
		}
	} else if (show_all == 0) {
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
