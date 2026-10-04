// ## Task-4: Sensor Input
// ### Write a program that asks the user for inputs and display it appropriately

#include <iostream>
int main() {
    int a;
    std::cout << "Enter the number of sensor readings you want to input: ";
    std::cin >> a;
    int* sensor_data = new int[a]; // Array to hold 5 sensor readings
    std::cout << "Enter " << a << " sensor readings:\n";
    for (int i = 0; i < a; i++) {
        std::cin >> sensor_data[i]; // Taking input for each sensor reading
    }
    std::cout << "\nYou entered the following sensor readings:\n";
    for (int i = 0; i < a; i++) {
        std::cout << "Sensor " << (i + 1) << ": " << sensor_data[i] << std::endl; // Displaying the entered sensor readings
    }
    delete[] sensor_data;
    return 0;
}   
