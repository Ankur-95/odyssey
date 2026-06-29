#include <iostream>
#include <string>
int main()
{
    int b;
    std::string m, f;
    std::cout << "Enter The Battery Level (1-99%):";
    std::cin >> b;
    std::cout << "Enter The Motor Status (Good/Bad):";
    std::cin >> m;
    std::cout << "Enter the Fault Status (Yes/No):";
    std::cin >> f;
    if (f == "Yes" || f == "yes" || f == "YES")
    {
        std::cout << "Fault Detected! Please Check the Robot." << std::endl;
        return 0;
    }
    else if (f == "No" || f == "no" || f == "NO" || f == "n" || f == "N")
    {
        if (m == "Good" || m == "good" || m == "GOOD")
        {
            if (b <= 10)
            {
                std::cout << "Battery Level is Low. Please Recharge the Robot." << std::endl;
            }
            else if (b > 10 && b <= 50)
            {
                std::cout << "Battery Level is Moderate. Robot can operate for a limited time." << std::endl;
            }
            else if (b > 50 && b <= 99)
            {
                std::cout << "Battery Level is Good. Robot can operate normally." << std::endl;
            }
            else
            {
                std::cout << "Invalid Battery Level Input. Please enter a value between 1 and 99." << std::endl;
                return 0;
            }
        }
        else if (m == "Bad" || m == "bad" || m == "BAD")
        {
            std::cout << "Motor Status is Bad. Please Repair the Motor." << std::endl;
        }
        else
        {
            std::cout << "Invalid Input for Motor Status. Please enter Good or Bad." << std::endl;
            return 0;
        }
    }
    else
    {
        std::cout << "Invalid Input for Fault Status. Please enter Yes or No." << std::endl;
        return 0;
    }
}