#pragma once

#include <iostream>
#include <filesystem>
#include <string>
#include <format>
#include <system_error>
#include <iomanip>

// Change path to "/" when on the desktop,
// to "/storage/emulated/" when on Android.

class DiskInfo {
private:
    std::string path_;
    uintmax_t total_size_;
    uintmax_t free_size_;
    uintmax_t available_size_;

public:
    DiskInfo(const std::string& path = "/") : path_(path) {
        refresh();
    }

    bool refresh() {
        std::error_code ec;
        std::filesystem::space_info si = std::filesystem::space(path_, ec);

        if (ec) {
            std::cout << "Error: " << ec.message() << std::endl;
            return false;
        }

        total_size_ 	= si.capacity;
        free_size_  	= si.free;
        available_size_ = si.available;
        return true;
    }

    uintmax_t getTotalSize() const { return total_size_; }
    uintmax_t getFreeSize() const { return free_size_; }
    uintmax_t getAvailableSize() const { return available_size_; }
    uintmax_t getUsedSize() const { return total_size_ - free_size_; }

    double getUsagePercentage() const {
        return (static_cast<double>(getUsedSize()) / total_size_) * 100.0;
    }

    auto printHumanReadable(uintmax_t bytes) const {
        const char* suffixes[] = {"B", "KB", "MB", "GB", "TB", "PB"};

        int suffix_index = 0;

	    double size = static_cast<double>(bytes);

        while (size >= 1024 && suffix_index < 5) {
                size /= 1024;
                suffix_index++;
        }

        std::string ss;
        ss = std::format("{:.2f} {}", size, suffixes[suffix_index]);

	    return ss;
    }
};
