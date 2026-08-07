// Basic function to tell you what exactly is pass-by-value and pass-by-reference

#include <iostream>

void passbyValue(int a, int b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}
void passbyref(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}
int main()
{
    int a, b;
    std::cout << "Enter the first no.:";
    std::cin >> a;
    std::cout << "Enter the second no.:";
    std::cin >> b;
    passbyValue(a, b);
    std::cout << "\nAfter passbyValue -> a: " << a << ", b: " << b << "\n";
    passbyref(a, b);
    std::cout << "\nAfter passbyref -> a: " << a << ", b: " << b << "\n";
    return 0;
}

// As you have seen in the above code, when we pass the values of a and b to the function passbyValue, it does not change the values of a and b in main() because it is passed by value. 
// However, when we pass the values of a and b to the function passbyref, it changes the values of a and b in main() because it is passed by reference.
// Now why the value of a and b did not change in the first case? Because when we pass the values of a and b to the function passbyValue, it creates a copy of the values of a and b in the function's local scope. 
// So when we change the values of a and b in the function, it does not affect the original values of a and b in main().
