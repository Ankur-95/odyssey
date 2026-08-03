// #include <iostream>
// int fact(int n)
// {
//     int a = 1;
//     for (int i = 1; i <= n; i++)
//     {
//         a *= i;
//     }
//     return a;
// }
// int ncr(int n, int r)
// {
//     return fact(n) / (fact(r) * fact(n - r));
// }

// int main()
// {
//     std::cout << "Enter the value for the pascal triangle: ";
//     int n;
//     std::cin >> n;
//     for (int i = 0; i <= n; i++)
//     {
//         for (int p = 0; p < n - i; p++)
//         {
//             std::cout << " ";
//         }
//         for (int j = 0; j <= i; j++)
//         {
//             std::cout << ncr(i, j) << " ";
//         }
//         std::cout << std::endl;
//     }
// }

/*Enter the value for the pascal triangle: 5
     1
    1 1
   1 2 1
  1 3 3 1
 1 4 6 4 1
1 5 10 10 5 1 */

// //  Program to swap two numbers using a third variable:
// #include <iostream>
// int main()
// {
//     int a = 21;
//     int b = 12;
//     std::cout << a << " " << b << std::endl;
//     int temp = a;
//     a = b;
//     b = temp;
//     std::cout << a << " " << b << std::endl;
// }

// Program to swap two numbers without using a third variable: (Mathematical Magic)
// #include <iostream>
// int main()
// {
//     int x = 21;
//     int y = 12;
//     std::cout << x << " " << y << std::endl;
//     x = x + y;
//     y = x - y;
//     x = x - y;
//     std::cout << x << " " << y << std::endl;
// }

// // Function of max
// #include <iostream>

// void max(int a, int b)
// {
//     if (a > b)
//     {
//         std::cout << "The largest No: " << a << std::endl;
//     }
//     else if (a < b)
//     {
//         std::cout << "The largest No: " << b << std::endl;
//     }
//     else
//     {
//         std::cout << "Both are equal" << std::endl;
//     }
// }
// int main()
// {
//     int a;
//     int b;
//     std::cout << "Enter the first no:";
//     std::cin >> a;
//     std::cout << "Enter the second no:";
//     std::cin >> b;
//     max(a, b);
//     return 0;
// }

// RECURSION: A function that calls itself is called a recursive function. Recursion is a process in which a function calls itself directly or indirectly.
//  The corresponding function is called a recursive function. The recursion continues until the base condition is met.
// #include <iostream>
// void num(int n)
// {
//      static int m = 1;
//      if (m >= n)
//      {
//           return;
//      }
//      std::cout << m << std::endl;
//      m += 1;
//      num(n);
// }
// int main()
// {
//      int a;
//      std::cout << "Enter The no.:";
//      std::cin >> a;
//      num(a);
// }

// Ye chiz jo mai abhi likhunga voh dimag ghuma dega ye recursion ki hi concept hai.
#include <iostream>
void num(int n)
{
     if (n == 0)
     {
          return;
     }

     std::cout << n << std::endl; // work
     num(n - 1);                  // call
}
int main()
{
     std::cout << "Enter the Number: ";
     int a;
     std::cin >> a;
     num(a);
}
/*OUTPUT :
Enter the Number: 5
5
4
3
2
1
*/

// #include <iostream>
// void num(int n)
// {
//      if (n == 0)
//      {
//           return;
//      }

//      num(n - 1);                  // call
//      std::cout << n << std::endl; // work
// }
// int main()
// {
//      std::cout << "Enter the Number: ";
//      int a;
//      std::cin >> a;
//      num(a);
// }
/*
Enter the Number: 5
1
2
3
4
5*/