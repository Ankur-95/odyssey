#include <iostream>
int main()
{
    int n;
    std::cout << "Enter the number from where you want to start";
    std::cin >> n;
    for (int i = n; i > 0; i--)
    {
        if (i == 7)
        {
            break;
            ;
        }
        else if (i % 3 == 0)
        {
            continue;
        }
        else
        {
            std::cout << i << "\n";
        }
    }
}