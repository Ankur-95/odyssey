# Day 4 —  Functions — design and passing

## Today's Topic

Declaration, definition, overloading, pass by value/ref/const-ref, default args

## Today's Task 
Write 5 small pure functions (clamp, normalize, deg-to-rad, rad-to-deg, sign)

Demonstrate pass-by-value vs pass-by-reference with a swap experiment

Use const reference for expensive inputs

Write overloaded clamp() for int and double

Task: a small math utility .h + .cpp with 6 helper functions — compile separately

---

# Understanding todays topics

### Funtions
Function : function is the block of code which is designed specifically so that user can used that block of code multiple times.
Instead of writing those code again and again we will wwrite it and wrap it as a fuction and then this function can be call multiple times.
what is call you asks ?
well call is (as the name suggests) a method which helps us to call our functions. It is just done by writing (or in this case calling) the name of function.


Declaration vs Definition 
Declaration is the process of declaring or proposing/introducing the function into the program with/without stating what it does, whereas
Definition is the process of defining or stating the complete function and gives the information such as: what the function does ? what are the parameters passed ? etc

ooh wait I didnt introduce you our friend here 'Parameter' ? right ?

### Parameter 
Parameter are the value holder assigned or alloted to a particular function which acts as placeholder that receive data whenever that function is called.
Every function parameter falls into of the following types :
1. Pass by value:
- Pass by value creates a local copy of the argument's data inside the function.
- The function allocates new memory for the parameter and copies the value into it.
- Modifying the parameter inside the function has zero effect on the original argument outside the function.

2. Pass by Reference:
- Pass by reference is a method of using a variable by calling it using its memory address instead of variable_name.
-The parameter directly points to the original variable's memory slot.
- Any changes made to the parameter inside the function immediately alter the original variable.

3. Const Reference:
A const reference is the one step advanced as comp to pass-by-reference, it doesnt allow modification of the passed value.
-The parameter directly points to the original variable's memory slot.
- The `const` keyword strictly forbids the function from modifying the data.


### Return 
Every function can be classified into two major types based on its return type:
Value-Returning Functions:
These functions compute a result and always return a value to the place where they were called.
Ex: - int main() returns an integer (usually 0 to signal success).
    - double calculateArea() returns a decimal number.
Void Functions:These functions perform an action but do not return any value.
Ex: - void printMessage() prints text to the screen but returns nothing.

### Function Overloading 
Function overloading is a feature that allows multiple functions to have the exact same name, as long as they have different parameter lists.
To show you the valid overloading, look at the following example:
-Valid
void print(int x);
void print(double x); 

-Invalid (Only the return type is different - will cause an error)
int print(int x);
void print(int x)

### Header Files and Sources Files
C++ splits code into two distinct file types to keep large projects organized and fast to compile.
1. Header File(.h): 
- Gives us the function prototype 
- Basically it tells the compiler that 'a function with this name and these parameters exists.'
2.Source File(.cpp):
- Contains definition (actual logic inside {} )
-Gives the code that actually does the work.

---
### Task - 1: Write 5 small pure functions (clamp, normalize, deg-to-rad, rad-to-deg, sign)
The "pure function" means the function must only depend on their inputs and must not change any outside variables.
Here is what each function example does and its explanation: 
- clamp : return the no. if it is within the limit otherwise return max or min value based on where the values lies.
- normalize : takes a value within a specific range and converts it into a fraction between 0 to 1. Formula= (value -min)/(max - min)
- degToRad : Converts an angle from degrees (like 180°) to radians (like \(\pi \)).
-radToDeg : Converts radians back into degrees.
- sign : Tells you if a number is positive, negative, or zero.
Return 1 if the number is greater than zero, -1 if it is less than zero, and 0 if it is exactly zero.
The link to the file containing all the functions is [Here](https://github.com/Ankur-95/odyssey/blob/main/phase_1/week_1/day_4/code1.cpp)

---
### Task -2:Demonstrate pass-by-value vs pass-by-reference with a swap 

I used two separate functions to demonstrate the difference between pass-by-value and pass-by-reference.

In the pass-by-value version:

void passbyValue(int a, int b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

The swapping logic itself works correctly. However, a and b are copies of the variables passed from main(). The function swaps these local copies, and once the function finishes, those copies are destroyed. Therefore, the original variables in main() remain unchanged.



The important difference is:

Pass by value
original → copy → function modifies copy → original unchanged

Pass by reference
original → reference → function modifies original → original changes

Link to the folder [Here](https://github.com/Ankur-95/odyssey/blob/main/phase_1/week_1/day_4/code2.cpp)

---

### Task -3: Use const reference for expensive inputs

Link to the folder [Here](https://github.com/Ankur-95/odyssey/blob/main/phase_1/week_1/day_4/code3.cpp)


### Task 4 : Write overloaded clamp() for int and double

Link to the folder [Here](https://github.com/Ankur-95/odyssey/blob/main/phase_1/week_1/day_4/code4.cpp)
