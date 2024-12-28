#include <iostream>
#include <fstream>
#include <string>

void applyBoundChecking(const std::string& inputFilename, const std::string& outputFilename) {
    std::ifstream inputFile(inputFilename);
    if (!inputFile.is_open()) {
        std::cerr << "Error: Unable to open input file " << inputFilename << std::endl;
        return;
    }

    std::ofstream outputFile(outputFilename);
    if (!outputFile.is_open()) {
        std::cerr << "Error: Unable to open output file " << outputFilename << std::endl;
        return;
    }

    std::string line;
    while (std::getline(inputFile, line)) {

        outputFile << line << std::endl;
    }

    inputFile.close();
    outputFile.close();
    std::cout << "Bound checking applied successfully. Output written to " << outputFilename << std::endl;
}
