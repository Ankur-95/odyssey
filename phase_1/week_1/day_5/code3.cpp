// ## Task-3: String operation
// ### Create a string representing a robot-related name and perform operations.

#include <iostream>
#include <string>

int main(){
    std::string robot_name = "Underwater Teleoperated Vehicle"; // Assigning a robot-related name to the string variable
    std::cout << "Robot Name: " << robot_name << std::endl; // Printing the robot name
    std::cout << " Size of the robot name: " << robot_name.size() << std::endl; // Printing the size of the string
    std::cout << " The word teleoperated is present at index: " << robot_name.find("Teleoperated") << std::endl; // Searching for the word "Teleoperated" in the string
    std::cout << " Extracting the word 'Underwater': " << robot_name.substr(0, 11) << std::endl; // Extracting the word "Underwater" from the string
    robot_name.append(" Version_1"); // Appending to the string
    std::cout << " After appending: " << robot_name << std::endl;
    std::string another_robot_name = "Underwater Teleoperated Vehicle"; // Another string variable for comparison
    if (robot_name == another_robot_name) { // Comparing the two strings
        std::cout << "Both robot names are the same." << std::endl;
        }
     else {
        std::cout << "Robot names are different." << std::endl;
     }
    
}