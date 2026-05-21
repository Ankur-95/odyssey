#include <iostream>
// The iostream header provides input/output capabilities
// It stands for "Input/Output String Stream."
// it replaces the C's <stdio.h>

// This is the mainn function where the execution of the program begins
int main()
{
    // std:: cout is the c++ way to print text on the screen.
    //  It stands for " Standard Character output".
    //  It replaces C's "print f" function

    // The "<<" symbols are insertion operators.
    // They "push" your text into the output stream.

    // std::endl stands for "End Line".
    // It creates a new line, replacing C's "\n" character.

    std::cout << "Hello, World!" << std::endl;
    // Signals to the operating system that the program finished successfully.    return 0;
    return 0;
}
