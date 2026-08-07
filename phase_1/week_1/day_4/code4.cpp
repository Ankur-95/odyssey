#include <iostream>

// Version 1: Handles integers (int)
int clamp(int value, int min, int max) {
    if (value < min) return min;
    if (value > max) return max;
    return value;
}

// Version 2: Handles decimals (double) - Overloaded!
double clamp(double value, double min, double max) {
    if (value < min) return min;
    if (value > max) return max;
    return value;
}

int main() {
    // The compiler automatically picks Version 1 (int)
    int totalUsers = 15;
    int restrictedUsers = clamp(totalUsers, 0, 10); 
    std::cout << "Clamped int: " << restrictedUsers << "\n"; // Outputs 10

    // The compiler automatically picks Version 2 (double)
    double temperature = 42.5;
    double restrictedTemp = clamp(temperature, 0.0, 37.0);
    std::cout << "Clamped double: " << restrictedTemp << "\n"; // Outputs 37.0

    return 0;
}
