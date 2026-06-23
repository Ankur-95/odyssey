//  Explaining the difference between overflowing and underflowing

#include <iostream>
int main()
{
    // 1. SHOWING OVERFLOW (Hitting the ceiling and rolling over)

    // Unsigned maxes out at 255
    unsigned char u_max = 255;
    u_max = u_max + 1; // Pushed past its limit!
    std::cout << "Unsigned (255 + 1) rolls over to: " << (int)u_max << "\n";
    // It resets to its lowest possible number: 0

    // Signed maxes out at 127
    signed char s_max = 127;
    s_max = s_max + 1; // Pushed past its limit!
    std::cout << "Signed (127 + 1) rolls over to: " << (int)s_max << "\n\n";
    // It instantly snaps around to its lowest possible negative number: -128

    // 2. SHOWING UNDERFLOW (Hitting the floor and snapping back)

    // Unsigned lowest number is 0
    unsigned char u_min = 0;
    u_min = u_min - 1; // Pushed below its limit!
    std::cout << "Unsigned (0 - 1) snaps back to: " << (int)u_min << "\n";
    // Because it can't be negative, it snaps to its absolute highest number: 255

    // Signed lowest number is -128
    signed char s_min = -128;
    s_min = s_min - 1; // Pushed below its limit!
    std::cout << "Signed (-128 - 1) snaps back to: " << (int)s_min << "\n";
    // It snaps right back to its highest positive number: 127

    return 0;
}

