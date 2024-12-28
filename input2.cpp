#include <iostream>
#include <cstring>

using namespace std;

int main() {
    // Declare a fixed-size buffer with a size of 10 characters
    char buffer[10];
    
    // Prompt the user for input
    cout << "Enter some text: ";
    
    // Read user input using gets() function (deprecated and unsafe)
    // This function reads a line from stdin into the buffer
    // without checking for buffer overflow.
    gets(buffer);
    
    // Display the input text
    cout << "You entered: " << buffer << endl;
    
    return 0;
}
// i have to provide this  code  to the main code for testing file name is new_main.cpp