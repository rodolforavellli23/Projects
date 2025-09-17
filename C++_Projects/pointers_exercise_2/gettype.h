#pragma once

#include <iostream>
#include <string>
#include <typeinfo>

#ifndef _MSC_VER
#include <cxxabi.h> // Required for abi::__cxa_demangle on non-MSVC compilers
#include <memory>   // Required for std::unique_ptr
#include <cstdlib>  // Required for std::free
#endif

// Function to get a readable type name (demangled for non-MSVC compilers)
std::string get_type_name(const std::type_info& ti) {
#ifndef _MSC_VER
	int status;

	std::unique_ptr<char, void(*)(void*)> demangled_name(
        	abi::__cxa_demangle(ti.name(), nullptr, nullptr, &status),
        	std::free
	);

	std::string full_name = (status == 0) ? demangled_name.get() : ti.name();
#else
	std::string full_name = ti.name();
#endif

	// Step 1: Remove template arguments first
	size_t template_pos = full_name.find('<');
	if (template_pos != std::string::npos) {
		full_name = full_name.substr(0, template_pos);
	}

	// Step 2: Now, find the last occurrence of '::'
	size_t last_colon_pos = full_name.find_last_of("::");
	if (last_colon_pos != std::string::npos) {
		return full_name.substr(last_colon_pos + 1);
	}

	// If no '::' is found, return the full name
	return full_name;
}
