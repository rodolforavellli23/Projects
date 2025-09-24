#include <iostream>
#include <iomanip>
#include <string>
#include <format>
#include <chrono>
#include "getmemsize.hpp"

// Create a cmd utility that will print, in color format, the total size of disk storage, the amount used & the amount of free disk space available.

// The instructions for compiling this program are on the "notes.txt" file, which is to be found within this file's working directory. 

/*Common ANSI Color Codes:
Text Colors (Foreground):
30: Black
31: Red
32: Green
33: Yellow
34: Blue
35: Magenta
36: Cyan
37: White
90-97: Bright versions of the above colors
Background Colors:
40: Black
41: Red
42: Green
43: Yellow
44: Blue
45: Magenta
46: Cyan
47: White
100-107: Bright versions of the above colors
*/

void SetColor(std::string textColor) {
    std::cout << "\033[" << textColor << "m";
}

void ResetColor() {
    std::cout << "\033[0m";
}

int main(void) {

	// Start

	// Variable Declaration
	std::string mem_size 	= "0";
	std::string mem_used 	= "0";
	std::string mem_free 	= "0";
	std::string mem_avail 	= "0";
	std::string mem_percent = "0";

	DiskInfo disk;	

	// Logic

	// Get Time Information

	auto now = std::chrono::system_clock::now();
	std::time_t now_time = std::chrono::system_clock::to_time_t(now);

	// Get Disk Information

	mem_size = disk.printHumanReadable(disk.getTotalSize());

	mem_used = disk.printHumanReadable(disk.getUsedSize());

	mem_free = disk.printHumanReadable(disk.getFreeSize());

	mem_avail = disk.printHumanReadable(disk.getAvailableSize());

	mem_percent = disk.printHumanReadable(disk.getUsagePercentage());
	
	// Text Output

	// Time
	std::cout << "\n";
	SetColor("1;38;5;208");
	std::cout << std::setfill(' ') << std::setw(26) << "Disk status at: ";
	ResetColor();
	std::cout << std::setfill(' ') << std::setw(26) << std::ctime(&now_time);

	// Total Disk Size
	// std::cout << "\n";
	SetColor("1;38;5;208");
	std::cout << std::setfill(' ') << std::setw(26) << "Total Disk Space: ";
	ResetColor();
	std::cout << std::setw(10) << std::right << mem_size;

	// Disk Storage Used
	std::cout << "\n";
	SetColor("1;38;5;208");
	std::cout << std::setfill(' ') << std::setw(26) << "Disk Storage Used: ";
	ResetColor();
	std::cout << std::setw(10) << std::right << mem_used;

	// Disk Storage Free
	std::cout << "\n";
	SetColor("1;38;5;208");
	std::cout << std::setfill(' ') << std::setw(26) << "Disk Storage Free: ";
	ResetColor();
	std::cout << std::setw(10) << std::right << mem_free;

	// Available Disk Storage
	std::cout << "\n";
	SetColor("1;38;5;208");
	std::cout << std::setfill(' ') << std::setw(26) << "Available Disk Storage: ";
	ResetColor();
	std::cout << std::setw(10) << std::right << mem_avail;

	// Percentage of Disk Used
	std::cout << "\n";
	SetColor("1;38;5;208");
	std::cout << std::setfill(' ') << std::setw(26) << "Percentage of Disk Used: ";
	ResetColor();
	std::cout << std::setw(7) << std::right << mem_percent;
	std::cout << std::setw(3) << std::right << "%";

	// End
	std::cout << "\n";
	return 0;
}
