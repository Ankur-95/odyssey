#include <iostream>
#include <vector>

void printAngles(const std::vector<double>& angles) {
    for (const auto& angle : angles) {
        std::cout << angle << '\n';
    }
}

int main() {
    std::vector<double> jointAngles = {0.0, 1.57, 3.14};

    // auto deduces the iterator type
    auto it = jointAngles.begin();
    std::cout << "First angle: " << *it << '\n';

    printAngles(jointAngles);

    // Modify the original elements using a reference
    for (auto& angle : jointAngles) {
        angle += 0.1;
    }

    printAngles(jointAngles);

    return 0;
}