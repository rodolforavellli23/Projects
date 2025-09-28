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

void PrintHelp() {
    std::cout << "Disk Information Utility\n";
    std::cout << "Usage: mydisk [OPTIONS]\n\n";
    std::cout << "Options:\n";
    std::cout << "  -h, --help     Show this help message\n";
    std::cout << "  -p, --path     Specify filesystem path to analyze (default: /)\n";
    std::cout << "  --version      Show version information\n";
    std::cout << "\nExamples:\n";
    std::cout << "  mydisk                    # Show disk info for root path\n";
    std::cout << "  mydisk -p /home           # Show disk info for /home\n";
    std::cout << "  mydisk --help             # Show this help\n";
}

void PrintVersion() {
    std::cout << "\nDisk Information Utility v1.0\n";
}

void SetColor(std::string textColor) {
    std::cout << "\033[" << textColor << "m";
}

void ResetColor() {
    std::cout << "\033[0m";
}

void PrintDiskInfo(const std::string& path) {
    // Variable Declaration
    std::string mem_size     = "0";
    std::string mem_used     = "0";
    std::string mem_free     = "0";
    std::string mem_avail    = "0";
    std::string mem_percent  = "0";

    DiskInfo disk(path);

    size_t str_leng = (path.length()) + 1;

    // Logic

    // Get Time Information
    auto now = std::chrono::system_clock::now();
    std::time_t now_time = std::chrono::system_clock::to_time_t(now);

    // Get Disk Information
    mem_size    = disk.printHumanReadable(disk.getTotalSize());
    mem_used    = disk.printHumanReadable(disk.getUsedSize());
    mem_free    = disk.printHumanReadable(disk.getFreeSize());
    mem_avail   = disk.printHumanReadable(disk.getAvailableSize());
    mem_percent = disk.printHumanReadable(disk.getUsagePercentage());

    // Text Output
    // Start

    // Time
    std::cout << "\n";
    SetColor("1;38;5;208");
    std::cout << std::setfill(' ') << std::setw(26) << "Disk status at: ";
    ResetColor();
    std::cout << std::setfill(' ') << std::setw(26) << std::ctime(&now_time);

    // Path being analyzed
    SetColor("1;38;5;208");
    std::cout << std::setfill(' ') << std::setw(26) << "Analyzing path: ";
    ResetColor();
    std::cout << std::setw(str_leng) << std::right << path << "\n";

    // Total Disk Size
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
}

int main(int argc, char* argv[]) {

    // default path
    std::string path = "/";

    // Parse command line arguments
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];

        if (arg == "-h" || arg == "--help") {
            PrintHelp();
            return 0;
        }
        else if (arg == "--version") {
            PrintVersion();
            return 0;
        }
        else if (arg == "-p" || arg == "--path") {
            // Check if there's a next argument for the path
            if (i + 1 < argc) {
                path = argv[++i];
            } else {
                std::cerr << "Error: -p option requires a path argument\n";
                return 1;
            }
        }
        else {
            std::cerr << "Error: Unknown option '" << arg << "'\n";
            std::cerr << "Use '-h' for help.\n";
            return 1;
        }
    }

    PrintDiskInfo(path);
    return 0;
}
