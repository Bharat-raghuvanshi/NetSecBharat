#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream> 

// List of unsafe functions 
std::vector<std::string> unsafeFunctions = {
    "gets",
    "sprintf",
    "strcpy",
    "strcat",
    "scanf",
    "memcpy",
    "memccpy",
    "fscanf",
    "vprintf",
    "vsprintf",
    "vscanf",
    "vsscanf",
    "makepath"
};

// List of safe functions 
std::vector<std::string> safeFunctions = {
    "strncpy",
    "snprintf",
    "strcpy_s",
    "strncat",
    "strcat_s",
    "sprintf_s",
    "sscanf",
    "scanf_s",
    "vsnprintf",
    "memcpy_s",
    "memmove",
    "fgets"
};

// Function to check unsafe function
bool containsUnsafeFunction(const std::string& line) {
    for (const auto& unsafeFunc : unsafeFunctions) {
        if (line.find(unsafeFunc) != std::string::npos) {
            return true;
        }
    }
    return false;
}

// Function to check safe function 
bool containsSafeFunction(const std::string& line) {
    for (const auto& safeFunc : safeFunctions) {
        if (line.find(safeFunc) != std::string::npos) {
            if (line.find("sizeof") != std::string::npos &&
                line.find("- 1") != std::string::npos) {
                if (safeFunc == "memcpy_s" &&
                    line.find("memcpy_s") != std::string::npos &&
                    line.find("dest, destSize, src, count") != std::string::npos) {
                    return true;
                }
                else if (safeFunc != "memcpy_s") {
                    return true;
                }
            }
            else if (safeFunc == "fgets" &&
                     line.find("fgets(") != std::string::npos &&
                     line.find("sizeof") != std::string::npos) {
                return true;
            }
        }
    }
    return false;
}

