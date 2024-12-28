#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

bool isProperVariableName(const std::string& variableName) {
    // Check if the variable name starts with a lowercase letter
    if (!islower(variableName[0])) {
        return false;
    }

    // Check if the variable name contains only alphanumeric characters or underscore
    for (char c : variableName) {
        if (!isalnum(c) && c != '_') {
            return false;
        }
    }

    // Check if the variable name contains at least one letter or digit
    bool containsLetterOrDigit = false;
    for (char c : variableName) {
        if (isalnum(c)) {
            containsLetterOrDigit = true;
            break;
        }
    }

    return containsLetterOrDigit;
}

void performStaticCodeAnalysis(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return;
    }

    std::string line;
    int lineNum = 0;
    int totalIssues = 0;

    int potentialMemoryLeaks = 0;
    int codingStandardsViolations = 0;
    int potentialBugs = 0;
    int performanceIssues = 0;
    int securityVulnerabilities = 0;

    while (std::getline(file, line)) {
        ++lineNum;

        // Check for potential memory leaks
        if (line.find("new") != std::string::npos) {
            std::cout << "Potential memory leak detected at line " << lineNum << ": " << line << std::endl;
            potentialMemoryLeaks++;
            totalIssues++;
        }

        // Check for coding standards violations
        // Example: variable naming conventions 
        size_t pos = line.find("=");
        if (pos != std::string::npos) {
            std::string variableName = line.substr(0, pos);
            if (!isProperVariableName(variableName)) {
                std::cout << "Improper variable name at line " << lineNum << ": " << variableName << std::endl;
                codingStandardsViolations++;
                totalIssues++;
            }
        }

        // Check for potential bugs
        // Example: Division by zero
        if (line.find("/ 0") != std::string::npos || line.find("/0") != std::string::npos) {
            std::cout << "Potential division by zero detected at line " << lineNum << ": " << line << std::endl;
            potentialBugs++;
            totalIssues++;
        }

        // Example: Null pointer dereference
        if (line.find("nullptr") != std::string::npos) {
            std::cout << "Potential null pointer dereference detected at line " << lineNum << ": " << line << std::endl;
            potentialBugs++;
            totalIssues++;
        }

        // Example: Out-of-bounds array access
        if (line.find("[") != std::string::npos && line.find("]") != std::string::npos) {
            std::size_t start_pos = line.find("[");
            std::size_t end_pos = line.find("]");
            std::string indexStr = line.substr(start_pos + 1, end_pos - start_pos - 1);
            try {
                int index = std::stoi(indexStr);
                if (index < 0) {
                    std::cout << "Potential out-of-bounds array access detected at line " << lineNum << ": " << line << std::endl;
                    potentialBugs++;
                    totalIssues++;
                }
            } catch (std::invalid_argument const&) {
                // Conversion failed
            } catch (std::out_of_range const&) {
                // Conversion out of range
            }
        }

        // Check for security vulnerabilities
        // Example: Buffer overflow
        if (line.find("strcpy") != std::string::npos || line.find("gets") != std::string::npos) {
            std::cout << "Potential buffer overflow detected at line " << lineNum << ": " << line << std::endl;
            securityVulnerabilities++;
            totalIssues++;
        }
    }

    // Generate a report summarizing the analysis results
    std::cout << "Summary Report:" << std::endl;
    std::cout << "Total number of issues found: " << totalIssues << std::endl;
    std::cout << "Potential memory leaks: " << potentialMemoryLeaks << std::endl;
    std::cout << "Coding standards violations: " << codingStandardsViolations << std::endl;
    std::cout << "Potential bugs: " << potentialBugs << std::endl;
    std::cout << "Performance issues: " << performanceIssues << std::endl;
    std::cout << "Security vulnerabilities: " << securityVulnerabilities << std::endl;
}
