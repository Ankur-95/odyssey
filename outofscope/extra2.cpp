#include <iostream>
int fact(int n)
{
    int a = 1;
    for (int i = 1; i <= n; i++)
    {
        a *= i;
    }
    return a;
}
int ncr(int n, int r)
{
    return fact(n) / (fact(r) * fact(n - r));
}

int main()
{
    std::cout << "Enter the value for the pascal triangle: ";
    int n;
    std::cin >> n;
    for (int i = 0; i <= n; i++)
    {
        for (int p = 0; p < n - i; p++)
        {
            std::cout << " ";
        }
        for (int j = 0; j <= i; j++)
        {
            std::cout << ncr(i, j) << " ";
        }
        std::cout << std::endl;
    }
}
