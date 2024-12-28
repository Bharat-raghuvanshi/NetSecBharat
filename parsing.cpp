#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

std::vector<std::string> parseInputFile(const std::string& filename) {
    std::ifstream inputFile(filename);
    std::vector<std::string> arrayAccesses;

    if (!inputFile.is_open()) {
        std::cerr << "Error: Unable to open input file " << filename << std::endl;
        return arrayAccesses;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        std::string word;
        while (iss >> word) {
            if (word.find('[') != std::string::npos) {
                arrayAccesses.push_back(word);
            }
        }
    }

    inputFile.close();
    return arrayAccesses;
}
 