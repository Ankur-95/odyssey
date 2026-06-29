#include <iostream>

int main()
{
    int sum = 0; // Declare outside so it doesn't reset to 0 every time

    for (auto value : {10, 20, 30, 40, 50, 60})
    {
        sum += value; // Directly add the current number to the total
    }

    std::cout << "Total Sum: " << sum << std::endl; // Prints 210
    return 0;
}
