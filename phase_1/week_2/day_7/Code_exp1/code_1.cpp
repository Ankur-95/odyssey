#include <iostream>
#include "code_utils.h"

int main(){
    double val;
    std::cout<<"Enter the first value: "<<std::endl;
    std::cin>>val;

    double min;
    std::cout<<"Enter the second value: "<<std::endl;
    std::cin>>min;

    double max;
    std::cout<<"Enter the third value: "<<std::endl;
    std::cin>>max;

    double clamped_val = robotmath::clamp(val, min, max);
    std::cout << "Clamped value: " << clamped_val << std::endl;

    return 0;
}

