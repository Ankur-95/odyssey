#include <iostream>
#include <string>

int main() {
    std::string text = "Hello world";

    // Scenario A: Text is found
    size_t found1 = text.find("world"); 
    if (found1 != std::string::npos) {
        std::cout << "Found at index: " << found1 << "\n"; // Outputs: 6
    }

    // Scenario B: Text is NOT found
    size_t found2 = text.find("apple");
    if (found2 == std::string::npos) {
        std::cout << "Text not found!\n"; // This line will run
    }

    return 0;
}
