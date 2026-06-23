//  Code to show the Difference between signed and unsigned int
#include <iostream>

int main()
{
    // We give both variables the exact same input number
    unsigned char u_var = 200;
    signed char s_var = 200;

    // Print out how each one reads that number
    std::cout << "Unsigned char sees 200 as: " << (int)u_var << "\n";
    // 200 in binary = 11001000
    std::cout << "Signed char sees 200 as: " << (int)s_var << "\n";
    // but since signed char only goes upto 127 the next number goes directly to -128.
    return 0;
}
