#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "bound_checking.cpp"
#include "parsing.cpp"
#include "static_code_analysis.cpp"
#include "safe_unsafe_fn.cpp"


std::string removeComments(const std::string& line) {
    std::string result;
    bool inBlockComment = false;
    bool inLineComment = false;
    bool inQuotes = false;

    for (size_t i = 0; i < line.size(); ++i) {
        if (!inQuotes) {
            if (line[i] == '/' && i + 1 < line.size()) {
                if (line[i + 1] == '/') {
                    inLineComment = true;
                    break;
                } else if (line[i + 1] == '*') {
                    inBlockComment = true;
                    ++i; // Skip '*' character
                    continue;
                }
            }
        }

        if (inBlockComment) {
            if (line[i] == '*' && i + 1 < line.size() && line[i + 1] == '/') {
                inBlockComment = false;
                ++i; // Skip '/' character
                continue;
            }
        }

        if (!inBlockComment && !inLineComment) {
            result += line[i];
        }

        if (line[i] == '"' && (i == 0 || line[i - 1] != '\\')) {
            inQuotes = !inQuotes;
        }
    }

    return result;
}

int main() {
    std::ifstream inputFile("input.cpp");
    std::ofstream outputFile("removed_comments.cpp");

    if (inputFile.is_open() && outputFile.is_open()) {
        std::string line;
        while (std::getline(inputFile, line)) {
            std::string lineWithoutComments = removeComments(line);
            outputFile << lineWithoutComments << std::endl;
        }
        inputFile.close();
        outputFile.close();
    } else {
        std::cerr << "Error: Unable to open input or output file!" << std::endl;
        return 1;
    }

    // Parsing input file to extract array accesses
    std::vector<std::string> arrayAccesses = parseInputFile("removed_comments.cpp");

    std::cout << "Array accesses found in input file:" << std::endl;
    for (const std::string& access : arrayAccesses) {
        std::cout << access << std::endl;
    }

    // Applying bound checking to the input code 
    applyBoundChecking("removed_comments.cpp", "output.cpp");

    // Performing static code analysis on the input file
    performStaticCodeAnalysis("removed_comments.cpp");

    // Example usage of safe and unsafe function checks
    std::ifstream removedCommentsFile("removed_comments.cpp");
    if (removedCommentsFile.is_open()) {
        std::string line;
        while (std::getline(removedCommentsFile, line)) {
            // Check for unsafe function
            if (containsUnsafeFunction(line)) {
                std::cout << "Unsafe function found: " << line << std::endl;
            }
            // Check for safe function
            if (containsSafeFunction(line)) {
                std::cout << "Safe function found: " << line << std::endl;
            }
        }
        removedCommentsFile.close();
    }

    return 0;
}
