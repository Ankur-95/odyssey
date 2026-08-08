# Day 4 — Functions: Design and Passing

## Today's Topic

Declaration, definition, overloading, pass by value/ref/const-ref, default arguments

## Today's Tasks

* Write 5 small pure functions (`clamp`, `normalize`, `deg-to-rad`, `rad-to-deg`, `sign`)
* Demonstrate pass-by-value vs pass-by-reference with a swap experiment
* Use `const` reference for expensive inputs
* Write overloaded `clamp()` for `int` and `double`
* Task: a small math utility `.h` + `.cpp` with 6 helper functions — compile separately

---

# Understanding Today's Topics

## Functions

A function is a block of code which is designed specifically so that we can use that block of code multiple times.

Instead of writing the same code again and again, we can write it once and wrap it inside a function. Then, this function can be called multiple times whenever we need it.

What is a **call**, you ask?

Well, call is, as the name suggests, a method which helps us to call our functions. It is simply done by writing the name of the function followed by `()`.

For example:

```cpp
calculateArea();
```

Here, `calculateArea()` is the function call.

---

## Declaration vs Definition

**Declaration** is the process of declaring or introducing a function to the program without providing its actual implementation.

For example:

```cpp
double calculateArea(double radius);
```

This tells the compiler that a function named `calculateArea` exists, it takes a `double` parameter, and it returns a `double`.

Whereas,

**Definition** is the actual implementation of the function. It tells the program what the function does and contains the code inside `{}`.

For example:

```cpp
double calculateArea(double radius)
{
    return 3.14 * radius * radius;
}
```

So, in simple terms:

* **Declaration** → tells the compiler that the function exists.
* **Definition** → contains the actual logic of the function.

---

## Parameter

Ooh, wait. I didn't introduce you to our friend here — **Parameter**, right?

Parameters are the value holders assigned to a particular function. They act as placeholders that receive data whenever that function is called.

For example:

```cpp
void printNumber(int number)
{
    std::cout << number;
}
```

Here, `number` is the parameter.

When we call:

```cpp
printNumber(10);
```

`10` is the argument being passed to the function.

There are different ways in which we can pass these values to a function.

### 1. Pass by Value

* Pass by value creates a local copy of the argument's data inside the function.
* The function works on this copy.
* Modifying the parameter inside the function has no effect on the original argument outside the function.

For example:

```cpp
void changeValue(int x)
{
    x = 100;
}
```

Here, `x` is only a copy of the original variable.

So:

```text
original → copy → function modifies copy → original unchanged
```

---

### 2. Pass by Reference

Pass by reference allows the function to work directly with the original variable instead of creating a copy.

We use the `&` symbol with the parameter.

```cpp
void changeValue(int& x)
{
    x = 100;
}
```

Here, `x` refers to the original variable.

Therefore, any changes made to `x` inside the function will also change the original variable.

In simple terms:

```text
original → reference → function modifies original → original changes
```

---

### 3. Pass by `const` Reference

A `const` reference is similar to pass-by-reference, but it does not allow the function to modify the passed value.

```cpp
void printValue(const int& x)
{
    std::cout << x;
}
```

Here, the parameter refers to the original value, but the `const` keyword prevents the function from modifying it.

This is useful when we want to avoid making a copy of a larger object but also don't want the function to modify the original object.

---

## Return

Every function can be classified based on whether it returns a value or not.

### Value-Returning Functions

These functions calculate something and return a value to the place where they were called.

For example:

```cpp
double calculateArea(double radius)
{
    return 3.14 * radius * radius;
}
```

`calculateArea()` returns a `double` value.

Another example is:

```cpp
int main()
```

where `main()` returns an integer, usually `0` to indicate successful program execution.

### Void Functions

These functions perform an action but do not return a value.

For example:

```cpp
void printMessage()
{
    std::cout << "Hello";
}
```

Here, the function performs the action of printing a message but returns nothing.

---

## Function Overloading

Function overloading is a feature that allows multiple functions to have the **same name**, as long as they have different parameter lists.

To show you valid overloading, look at this example:

### Valid

```cpp
void print(int x);
void print(double x);
```

Both functions have the same name, but they take different parameter types.

### Invalid

Only changing the return type is not enough for function overloading.

```cpp
int print(int x);
void print(int x);
```

Both functions have the same name and the same parameter list. The only difference is their return type, which does not count as function overloading.

---

# Header Files and Source Files

C++ allows us to split our code into different files. This becomes useful when the program starts getting larger and we don't want everything sitting inside one `.cpp` file.

There are two files we are focusing on here:

### 1. Header File — `.h`

The header file generally contains the function declarations or prototypes.

For example:

```cpp
double calculateArea(double radius);
```

Basically, it tells the compiler:

> "A function with this name and these parameters exists."

### 2. Source File — `.cpp`

The source file contains the actual definition of the function.

For example:

```cpp
double calculateArea(double radius)
{
    return 3.14 * radius * radius;
}
```

So, the basic idea is:

```text
.h   → declaration
.cpp → definition / actual logic
```

---

# Task 1 — Write 5 Small Pure Functions

The first task was to write 5 small functions:

* `clamp`
* `normalize`
* `degToRad`
* `radToDeg`
* `sign`

### What is a Pure Function?

A pure function is a function which depends only on its inputs and does not change anything outside the function.

The idea is simple: if we give the same input, we should get the same output.

### `clamp`

`clamp` returns the number if it is within the given limits. If it is outside the range, it returns the nearest limit — either the minimum or maximum value.

### `normalize`

`normalize` takes a value within a specific range and converts it into a fraction between `0` and `1`.

Formula:

```text
(value - min) / (max - min)
```

### `degToRad`

Converts an angle from degrees into radians.

For example:

```text
180° → π radians
```

### `radToDeg`

Converts radians back into degrees.

For example:

```text
π radians → 180°
```

### `sign`

`sign` tells us whether a number is positive, negative, or zero.

It returns:

```text
 1 → number is positive
-1 → number is negative
 0 → number is zero
```

The functions are implemented here:

[code1.cpp](https://github.com/Ankur-95/odyssey/blob/main/phase_1/week_1/day_4/code1.cpp)

---

# Task 2 — Pass-by-Value vs Pass-by-Reference

For this task, I used two separate functions to demonstrate the difference between pass-by-value and pass-by-reference using a simple swap experiment.

### Pass by Value

```cpp
void passbyValue(int a, int b)
{
    int temp;

    temp = a;
    a = b;
    b = temp;
}
```

The swapping logic itself works correctly.

However, `a` and `b` are copies of the variables passed from `main()`. The function swaps these local copies, and once the function finishes, those copies are destroyed.

Therefore, the original variables in `main()` remain unchanged.

The important difference is:

```text
Pass by value:
original → copy → function modifies copy → original unchanged

Pass by reference:
original → reference → function modifies original → original changes
```

Code:

[code2.cpp](https://github.com/Ankur-95/odyssey/blob/main/phase_1/week_1/day_4/code2.cpp)

---

# Task 3 — Use `const` Reference for Expensive Inputs

This task was used to understand how `const` reference works when passing larger inputs to a function.

The reference avoids making a copy of the object, while `const` makes sure that the function cannot modify the original object.

Code:

[code3.cpp](https://github.com/Ankur-95/odyssey/blob/main/phase_1/week_1/day_4/code3.cpp)

---

# Task 4 — Write Overloaded `clamp()` for `int` and `double`

In this task, I used function overloading to create two versions of `clamp()`.

One works with `int` values and the other works with `double` values.

For example:

```cpp
int clamp(int value, int min, int max);

double clamp(double value, double min, double max);
```

Both functions have the same name, but their parameter types are different.

Code:

[code4.cpp](https://github.com/Ankur-95/odyssey/blob/main/phase_1/week_1/day_4/code4.cpp)

---
