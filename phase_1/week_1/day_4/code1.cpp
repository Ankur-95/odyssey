#include<iostream>

int clamp(int x){

    std::cout<<"Enter a number to see the clamping in the range of [10,20]:";
    std::cin>>x;
    if(x<10){
        return 10;
    }
    else if(x>20){
        return 20;
    }
    else{
        return x;
    }
}
int normalize(int a){
    std::cout<<"Enter a number to see the normalizing in the range of [0,100]:";
    std::cin>>a;
    std::cout<<"Number after normalizing: ";
    return a/100;
}
int degtorad(int a){
    std::cout<<"Enter a value in degree ";
    std::cin>>a;
    std::cout<<"Value in the radian is : ";
    return a*3.14/180;
}
int degtored(int a){
    std::cout<<"Enter a value in radian ";
    std::cin>>a;
    std::cout<<"Value in the degree is : ";
    return a*180/3.14;
}
int sign(int a){
    std::cout<<"Enter a number to see the sign of the number: ";
    std::cin>>a;
    if(a>0){
        return 1;
    }
    else if(a<0){
        return -1;
    }
    else{
        return 0;
    }

}