#include <iostream>
#include <iomanip>
#include <string>
#include <format>
#include <chrono>
#include "getmemsize.hpp"
#include "colortxt.hpp"

// Create a cmd utility that will print, in color format, the total size of disk storage, the amount used & the amount of free disk space available.

// The instructions for compiling this program are on the "notes.txt" file, which is to be found within this file's working directory.

void PrintHelp() {
    std::cout << "\n";
    std::cout << std::setfill(' ') << std::setw(29) << "Disk Information Utility";
    std::cout << "\n";
    std::cout << std::setfill(' ') << std::setw(28) << "Usage: mydisk [OPTIONS]";
    std::cout << "\n\n";
    std::cout << std::setfill(' ') << std::setw(13) << "Options:";
    std::cout << "\n";
    std::cout << std::setfill(' ') << std::setw(53) << "-h, --help         Show this help message";
    std::cout << "\n";
    std::cout << std::setfill(' ') << std::setw(78) << "-p, --path         Specify filesystem path to analyze (default: /)";
    std::cout << "\n";
    std::cout << std::setfill(' ') << std::setw(55) << "-v, --version      Show version information";
    std::cout << "\n\n";
    std::cout << std::setfill(' ') << std::setw(14) << "Examples:";
    std::cout << "\n";
    std::cout << std::setfill(' ') << std::setw(68) << "mydisk                    # Show disk info for root path";
    std::cout << "\n";
    std::cout << std::setfill(' ') << std::setw(64) << "mydisk -p /home           # Show disk info for /home";
    std::cout << "\n";
    std::cout << std::setfill(' ') << std::setw(54) << "mydisk --help             # Show this help";
    std::cout << "\n";
}

void PrintVersion() {
    std::cout << "\n";
    std::cout << std::setfill(' ') << std::setw(34) << "Disk Information Utility v1.1";
    std::cout << "\n";
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
    std::cout << std::setfill(' ') << std::setw(30) << "Disk status at: ";
    ResetColor();
    std::cout << std::setfill(' ') << std::setw(26) << std::ctime(&now_time);

    // Path being analyzed
    SetColor("1;38;5;208");
    std::cout << std::setfill(' ') << std::setw(30) << "Analyzing path: ";
    ResetColor();
    std::cout << std::setw(str_leng) << std::right << path << "\n";

    // Total Disk Size
    SetColor("1;38;5;208");
    std::cout << std::setfill(' ') << std::setw(30) << "Total Disk Space: ";
    ResetColor();
    std::cout << std::setw(10) << std::right << mem_size;

    // Disk Storage Used
    std::cout << "\n";
    SetColor("1;38;5;208");
    std::cout << std::setfill(' ') << std::setw(30) << "Disk Storage Used: ";
    ResetColor();
    std::cout << std::setw(10) << std::right << mem_used;

    // Disk Storage Free
    std::cout << "\n";
    SetColor("1;38;5;208");
    std::cout << std::setfill(' ') << std::setw(30) << "Disk Storage Free: ";
    ResetColor();
    std::cout << std::setw(10) << std::right << mem_free;

    // Available Disk Storage
    std::cout << "\n";
    SetColor("1;38;5;208");
    std::cout << std::setfill(' ') << std::setw(30) << "Available Disk Storage: ";
    ResetColor();
    std::cout << std::setw(10) << std::right << mem_avail;

    // Percentage of Disk Used
    std::cout << "\n";
    SetColor("1;38;5;208");
    std::cout << std::setfill(' ') << std::setw(30) << "Percentage of Disk Used: ";
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
        else if (arg == "-v"|| arg == "--version") {
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
