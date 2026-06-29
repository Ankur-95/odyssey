#include <iostream>

int main()
{
    int sum = 0; // Declare outside so it doesn't reset to 0 every time
    int a, i = 0;
    std::cout << "Enter a number: ";
    std::cin >> a;
    for (auto value : {10, 20, 30, 40, 50, 60})
    {
        i++;
        if (a == value)
        {
            std::cout << "the number is present in the list at the position:" << i << "\n";
        }
    }
    return 0;
}
