/*
- Make all physical constants constexpr (PI, G, DEG_TO_RAD)
- Use using to create type aliases: using JointAngle = double*/
#include<iostream>

// Type aliases
using pi_data = float;
using gravity = double;
using degree = double;

// Physical constants using constexpr
constexpr pi_data PI = 3.14159265358979323846f;
constexpr gravity G = 9.81;
constexpr degree DEG_TO_RAD = PI / 180.0;   


int main() {
	std::cout << " Gravitational constant (G): " << G << std::endl;
    std::cout << " Value of PI: " << PI << std::endl;
	return 0;
}