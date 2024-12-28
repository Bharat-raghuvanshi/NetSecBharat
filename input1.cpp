#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    // Issue: accessing elements beyond the bounds of the vector
    for (int i = 0; i <= numbers.size(); ++i) {
        std::cout << "numbers[" << i << "] = " << numbers[i] << std::endl;
    }

    // Issue: uninitialized variable
    int x;
    std::cout << "Uninitialized variable x: " << x << std::endl;

    // Issue: unused variable
    int y = 5;

    // Issue: potential division by zero
    int denominator = 0;
    int result = 10 / denominator;

    return 0;
}
