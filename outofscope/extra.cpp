// // Code for Getting the perimeter and Area of the rectangle:

// #include <iostream>
// int main()
// {

//     std::cout << "Enter the length: ";
//     int a;
//     std::cin >> a;
//     int b;

//     std::cout << "Enter the Breadth: ";
//     std::cin >> b;
//     int c = 2 * (a + b);
//     int d = a * b;
//     std::cout << "The Perimeter of the rectangle: " << c;
//     std::cout << "\nThe Area of the rectangle: " << d;

//     if (c < d)
//     {
//         std::cout << "\nThe Area of the rectangle is greater ";
//         std::cout << d;
//     }
//     else if (c > d)
//     {
//         std::cout << "\nThe Perimeter of the rectangle is greater ";
//         std::cout << c;
//     }
// }

// // Divisiblity Check

// #include <iostream>
// int main()
// {
//     int a;
//     std::cout << "Enter the number: ";
//     std::cin >> a;
//     if (a % 5 == 0 and a % 3 == 0)
//     {
//         std::cout << "Entered Number " << a << " is Divisible by both 5 and 3";
//     }
//     else
//     {
//         std::cout << "Entered Number " << a << " is not divisible by 5 and 3";
//     }
// }

// // Triangle Sides
// #include <iostream>
// int main()
// {
//     int a, b, c, sum1, sum2, sum3;
//     std::cout << "Enter the first side of the Triangle(A): ";
//     std::cin >> a;
//     std::cout << "Enter the second side of the Triangle(B): ";
//     std::cin >> b;
//     std::cout << "Enter the third side of the Triangle(C): ";
//     std::cin >> c;
//     sum1 == b + c;
//     sum2 == a + c;
//     sum3 == a + b;
//     if (sum1 > a and sum2 > b and sum3 > c)
//     {
//         std::cout << "The triangle is valid";
//     }
//     else
//     {
//         std::cout << "The triangle is not valid";
//     }
// }

// // Taking 3 inputs and printing least of them.
// #include<iostream>
// int main(){
//     int a,b,c;
//     std::cout<<"Enter the first number: ";
//     std::cin>>a;
//     std::cout<<"Enter the Second number: ";
//     std::cin>>b;
//     std::cout<<"Enter the Third number: ";
//     std::cin>>c;
//     if (a<b and a<c){
//         std::cout<<"The least number is: "<<a;
//     }
//     else if (b<a and b<c){
//         std::cout<<"The least number is: "<<b;
//     }
//     else {
//         std::cout<<"The least number is: "<<c;
//     }
// }

// // Printing whether the number is dvisible by 5or3 but not 15.

// #include <iostream>
// int main()
// {
//     int a;

//     std::cout << "Enter the number: ";
//     std::cin >> a;
//     if (a % 5 == 0 or a % 3 == 0 and a % 15 != 0)
//     {
//         std::cout << "The Enter Number is divisible by 5 or 3 but not divisible by 15";
//     }
//     else if (a % 5 == 0 or a % 3 == 0 and a % 15 == 0)
//     {
//         std::cout << "The Enter Number is divisible by 5 or 3 but also divisible by 15";
//     }
//     else
//     {
//         std::cout << "The Enter Number is neither divisible by 5 or 3 nor divisible by 15";
//     }
// }

// Loops
// For loops:
// #include <iostream>
// int main()
// {
//     int i, j;
//     std::cout << "enter the no. ";
//     std::cin >> i;
//     for (int j = 1; j <= i; j++)
//     {
//         std::cout << j << " " << "HEllo\n";
//     }
// }

// #include <iostream>
// int main()

// {
//     int j;
//     std::cout << "Enter The Number for its:";
//     std::cin >> j;
//     std::cout << "The table of " << j << " is \n";
//     for (int i = 1; i <= 10; i++)

//         std::cout << i * j << "\n";
// }

// // highest factor
// #include <iostream>
// int main()
// {
//     int i, j, new1 = 1;
//     std::cout << "Enter the number Whose highest factor is to be found: ";
//     std::cin >> i;
//     for (j = 1; j < i - 1; j++)
//     {
//         if (i % j == 0)
//         {
//             new1 = j;
//         }
//     }
//     std::cout << new1;
// }

// // ASCII value of the enter character
// #include <iostream>
// int main()
// {
//     char ch;
//     std::cout << "Enter The Characther: ";
//     std::cin >> ch;
//     std::cout << "The ASCII value of the enter character is: " << int(ch);
// }

// // Prromblem
// #include <iostream>
// int main(){
//     int x= 4 ,y =0 ;
//     while (x>=0) {
//         x++;y--;
//         if (x==y)
//             {continue;}
//         else std::cout<<x<<" "<<y;
//     }
// }

// // Write a program to count the number of digits
// #include <iostream>
// int main()
// {
//     int i, q, j = 0;
//     std::cout << "enter the number: ";
//     std::cin >> i;
//     for (q = i; q > 0; j++)
//     {
//         q /= 10;
//     }

//     std::cout << "THe number of digits is :" << j;
// }

// #include <iostream>
// int main()
// {
//     int i, j = 0;
//     std::cout << "Enter the number: ";
//     std::cin >> i;
//     while (i > 0)
//     {
//         i /= 10;
//         j++;
//     }
//     std::cout << "The number of digits is: " << j;
// }

// // TO find the sum of the digits of entered number
// #include <iostream>
// int main()
// {
//     int i;
//     std::cout << "ENTER THE NUMBER: ";
//     std::cin >> i;
//     int sum = 0, a;

//     while (i > 0)
//     {
//         a = i % 10;
//         sum += a;
//         i /= 10;
//     }
//     std::cout << sum;
// }

// //  Program to find the sum of the digits of a number using for and while loop

// #include <iostream>
// int main()
// {
//     int i, sum = 0, a;
//     std::cout << "Enter the number:";
//     std::cin >> i;
//     for (int j = i; j > 0; j /= 10)
//     {
//         a = j % 10;
//         sum += a;
//     }
//     std::cout << " The sum of the digits of the entered number is: " << sum << " \n";

//     int n, b, c = 0;
//     std::cout << "Enter the number: ";
//     std::cin >> n;
//     int m = n;
//     while (m > 0)
//     {
//         b = m % 10;

//         c += b;
//         m /= 10;
//     }
//     std::cout << c;
// }

// // Patterns
// #include <iostream>
// int main()
// {
//     int i, j, k;
//     for (i = 1; i <= 5; i++)
//     {
//         for (j = 4; j >= i; j--)
//         {
//             std::cout << " ";
//         }
//         for (k = 1; k <= i; k++)
//         {
//             std::cout << "*";
//         }
//         std::cout << "\n";
//     }
// }

// #include <iostream>
// int main()
// {
//     int a, b;
//     std::cout << "Enter the number of rows: ";
//     std::cin >> a;
//     std::cout << "Enter the number of column: ";
//     std::cin >> b;
//     for (int i = 1; i <= a; i++)
//     {
//         for (int j = 1; j <= b; j++)
//         {
//             if (i == 1 or i == a || j == 1 || j == b)
//             {
//                 std::cout << "*";
//             }
//             else
//             {
//                 // Print space for the hollow interior
//                 std::cout << " ";
//             }
//         }
//         std::cout << std::endl;
//     }
// }

// printing the number in the pattern using for loop
// #include <iostream>
// int main()
// {
//     int a;
//     std::cout << "enter the no. : ";
//     std::cin >> a;

//     for (int i = 1; i <= a; i++)
//     {
//         for (int j = 1; j <= a; j++)
//         {
//             std::cout << j << " ";
//         }
//         std::cout << " \n";
//     }
// } o/p:enter the no. : 5
// 1 2 3 4 5
// 1 2 3 4 5
// 1 2 3 4 5
// 1 2 3 4 5
// 1 2 3 4 5

// // printing the number in the pattern using while loop  (top bottom)
// #include <iostream>
// int main()
// {
//     int a;
//     std::cout << "enter the no. : ";
//     std::cin >> a;

//     for (int i = 1; i <= a; i++)
//     {
//         int j = 1;
//         while (j <= a)
//         {
//             std::cout << i << " ";
//             j++;
//         }
//         std::cout << " \n";
//     }
// } o/p:enter the no. : 5
// 1 1 1 1 1
// 2 2 2 2 2
// 3 3 3 3 3
// 4 4 4 4 4
// 5 5 5 5 5

// #include <iostream>
// int main()
// {
//     int a;
//     std::cout << "enter the nos.: ";
//     std::cin >> a;
//     for (int i = 1; i <= a; i++)
//     {
//         for (int j = 1; j <=i; j++)
//         {
//             std::cout << "* ";
//         }
//         std::cout << std::endl;
//     }
// }

// o/p:enter the nos.: 5
// *
// * *
// * * *
// * * * *
// * * * * *

// #include <iostream>
// int main()
// {
//     int a;
//     std::cout << "enter the nos.: ";
//     std::cin >> a;
//     for (int i = a; i >= 1; i--)
//     {
//         for (int j = 1; j <= i; j++)
//         {
//             std::cout << "* ";
//         }
//         std::cout << std::endl;
//     }
// }
// enter the nos.: 5
// * * * * *
// * * * *
// * * *
// * *
// *

// #include <iostream>
// int main()
// {
//     int a;
//     std::cout << "enter the nos.: ";
//     std::cin >> a;
//     for (int i = 1; i <= a; i++)
//     {
//         for (int j = 1; j <= i; j++)
//         {
//             std::cout << j;
//         }
//         std::cout << std::endl;
//     }
// }
// enter the nos.: 5
// 1
// 12
// 123
// 1234
// 12345

// #include <iostream>
// int main()
// {
//     int a;
//     std::cout << "enter the nos.: ";
//     std::cin >> a;
//     for (int i = 1; i <= a; i++)
//     {
//         for (int j = 1; j <= a - i + 1; j++)
//         {
//             std::cout << i;
//         }
//         std::cout << std::endl;
//     }
// }
// enter the nos.: 5
// 11111
// 2222
// 333
// 44
// 5

// #include <iostream>
// int main()
// {
//     int a;
//     std::cout << "enter the nos.: ";
//     std::cin >> a;
//     for (int i = a; i >= 1; i--)
//     {
//         for (int j = a; j >= i; j--)
//         {
//             std::cout << j;
//         }
//         std::cout << std::endl;
//     }
// }
// enter the nos.: 4
// 4
// 43
// 432
// 4321

// OR YOU CAN ALSO DO IT LIKE THIS:

// #include <iostream>
// int main()
// {
//     int a;
//     std::cout << "enter the nos.: ";
//     std::cin >> a;
//     for (int i = 1; i <= a; i++)
//     {
//         for (int j = 1; j <= i; j++)
//         {
//             std::cout << a - j + 1;
//         }
//         std::cout << std::endl;
//     }
// }
// enter the nos.: 4
// 4
// 43
// 432
// 4321

// #include <iostream>
// int main()
// {
//     int a;
//     std::cout << "enter the nos.: ";
//     std::cin >> a;
//     for (int i = a; i >= 1; i--)
//     {
//         for (int j = 1; j <= i; j++)
//         {
//             std::cout << (char)(j + 64);
//         }
//         std::cout << std::endl;
//     }
// }
// enter the nos.: 5
// ABCDE
// ABCD
// ABC
// // AB
// // A

// #include <iostream>
// int main()
// {
//     int a;
//     std::cout << "Enter The  Number: ";
//     std::cin >> a;
//     for (int i = 1; i <= a; i += 2)
//     {
//         for (int j = 1; j <= i; j += 2)
//         {
//             std::cout << j;
//         }
//         std::cout << std::endl;
//     }
// }

// #include <iostream>
// int main()
// {
//     int a;
//     std::cout << "Enter the number:";
//     std::cin >> a;
//     int n = 1;
//     for (int i = 1; i <= a; i++)
//     {
//         for (int j = 1; j <= i; j++)
//         {
//             std::cout << n << " ";
//             n++;
//         }
//         std::cout << std::endl;
//     }
// }
// Enter the number:4
// 1
// 2 3
// 4 5 6
// 7 8 9 10

// #include <iostream>
// int main()
// {
//     int a;
//     std::cout << "Enter the number:";
//     std::cin >> a;
//     for (int i = 1; i <= a; i++)
//     {
//         for (int j = 1; j <= i; j++)
//         {
//             if ((i + j) % 2 == 0)

//             {
//                 std::cout << "1";
//             }
//             else
//             {
//                 std::cout << "0";
//             }
//         }
//         std::cout << "\n";
//     }
// }
// Enter the number:5
// 1
// 01
// 101
// 0101
// 10101

// #include <iostream>

// int main()
// {
//     int a;
//     std::cout << "Enter the number:";
//     std::cin >> a;

//     // CRITICAL FIX: Initialise both variables to 1
//     int n = 1;
//     int m = 1;

//     while (n <= a)
//     {
//         // Added '&& n <= a' to prevent printing past your target number
//         for (int i = 1; i <= m && n <= a; i++)
//         {
//             std::cout << n << " "; // Added a space for readability
//             n++;
//         }
//         std::cout << std::endl;
//         m++;
//     }
// }

// #include <iostream>

// int main()
// {
//     while (true)
//     {
//         int a;
//         std::cout << "Enter the odd number: ";
//         std::cin >> a;

//         if (a % 2 != 0)
//         {
//             int b = (a / 2) + 1;

//             for (int i = 1; i <= a; i++)
//             {
//                 for (int j = 1; j <= a; j++)
//                 {
//                     if (i == b || j == b)
//                     {
//                         std::cout << "* "; // FIX: Added a space after the *
//                     }
//                     else
//                     {
//                         std::cout << "  "; // FIX: Changed to two spaces
//                     }
//                 }
//                 std::cout << std::endl;
//             }
//         }
//         else
//         {
//             std::cout << "Please enter the odd number only \n";
//         }
//     }
// }
// Enter the odd number: 5
//     *
//     *
// * * * * *
//     *
//     *
