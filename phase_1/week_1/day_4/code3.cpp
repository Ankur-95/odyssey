#include <iostream>
#include <string>
#include <vector>

// 1. Using const reference for an expensive string
void printLargeString(const std::string &text) {
    // The function can read the string but cannot modify it
    std::cout << text << "\n"; //  VALID: Read-only access
}

// 2. Using const reference for an expensive vector (list of numbers)
void printLargeVector(const std::vector<int> &numbers) {
    std::cout << "Vector size: " << numbers.size() << "\n";
}

int main() {
    // Imagine this is a massive block of text loaded from a file
    std::string hugeText = "This is a very long and expensive string memory-wise...";
    
    std::vector<int> hugeList = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Passed instantly with 0 bytes copied!
    printLargeString(hugeText);
    printLargeVector(hugeList);

    return 0;
}
