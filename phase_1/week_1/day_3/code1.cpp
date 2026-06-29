#include <iostream>
int main()
{
    std::cout << "1 - Move Forward\n2 - Move Backward\n3 - Turn Left\n4 - Turn Right\n5 - Stop" << std::endl;
    int a;
    std::cout << "Enter the number for the Action(1-5): ";
    std::cin >> a;
    switch (a)
    {
    case 1:
        std::cout << "Moving Forward";
        break;
    case 2:
        std::cout << "Moving Backward";
        break;
    case 3:
        std::cout << "Turning Left";
        break;
    case 4:
        std::cout << "Turning Right";
        break;
    case 5:
        std::cout << "Stopping";
        break;
    default:
        std::cout << "Invalid Input";
    }
}

// //  For future reference I am also trying to implement or say integrate the exact action commands/motions of the robot in the code.
// // Consideration : My robot is 4 wheeled and has a skid steering mechanism. The robot can move forward, backward, turn left, turn right, and stop. The commands will be sent to the robot's motor controller to execute the desired actions.

// #include <iostream>

// int main()
// {
//     int motorright = 0;
//     int motorleft = 0;
//     std::cout << "\n--- Robot Control Menu ---" << std::endl;
//     std::cout << "1 - Move Forward\n2 - Move Backward\n3 - Turn Left\n4 - Turn Right\n5 - Stop\nx - Exit" << std::endl;

//     // Use while(true) for a clean, explicit infinite loop
//     while (true)
//     {

//         char a;
//         std::cout << "Enter the number for the Action (1-5 or x): ";
//         std::cin >> a;

//         // Handles the explicit exit condition
//         if (a == 'x' || a == 'X')
//         {
//             std::cout << "Exiting the program." << std::endl;
//             break; // 'break' exits the while loop cleanly
//         }

//         switch (a)
//         {
//         case '1': // Added single quotes because 'a' is a char
//             std::cout << "-> Action: Moving Forward" << std::endl;
//             motorleft = 100;
//             motorright = 100;
//             break;
//         case '2':
//             std::cout << "-> Action: Moving Backward" << std::endl;
//             motorleft = -100;
//             motorright = -100;
//             break;
//         case '3':
//             std::cout << "-> Action: Turning Left" << std::endl;
//             motorleft = -100;
//             motorright = 100;
//             break;
//         case '4':
//             std::cout << "-> Action: Turning Right" << std::endl;
//             motorleft = 100;
//             motorright = -100;
//             break;
//         case '5':
//             std::cout << "-> Action: Stopping" << std::endl;
//             motorleft = 0;
//             motorright = 0;
//             break;
//         default:
//             std::cout << "-> Error: Invalid Input!"
//                       << std::endl;
//             // Skip printing motor states on invalid input
//             continue;
//         }

//         // Display current states at the end of every successful loop
//         std::cout << "Motor States -> Left: " << motorleft << " | Right: " << motorright << std::endl;
//     }

//     return 0; // Program ends only when loop is broken
// }
