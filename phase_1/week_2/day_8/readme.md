# Day 8 — `const`, `constexpr`, `auto`, and Type Aliases

## Objective

Understand modern C++ type discipline by working with constants, read-only access, automatic type deduction, and readable type aliases. Apply these concepts to robotics-related math utilities.

## 1. `const`

`const` is a type qualifier that prevents an entity from being modified through that identifier after initialization.

### 1.1 Const Variables

A `const` variable must be initialized when declared and cannot be reassigned afterward.

```cpp
const double wheelRadius = 0.15;
// wheelRadius = 0.20; // Error
```

### 1.2 Const References

A reference is another name for an existing variable. A const reference allows us to read the original variable but prevents modification through that reference.

```cpp
double speed = 5.0;
const double& refSpeed = speed;

std::cout << refSpeed;
// refSpeed = 10.0; // Error
```

The original variable `speed` can still be modified directly or through another non-const reference.

### 1.3 Const in Function Parameters

**Pass-by-value with `const`:** The function receives a copy of the argument. The function cannot reassign its local parameter, but the original variable remains unaffected.

```cpp
void printSpeed(const double speed) {
    std::cout << speed;
}
```

**Pass-by-const-reference:** The function accesses the original object without copying it and cannot modify it through that reference.

```cpp
void printAngles(const std::vector<double>& angles) {
    for (const auto& angle : angles) {
        std::cout << angle << '\n';
    }
}
```

This is useful when passing large objects such as vectors, because it avoids copying the entire container.

### 1.4 `const` and Pointers

| Declaration               | Meaning                                                                                     |
| ------------------------- | ------------------------------------------------------------------------------------------- |
| `const double* ptr`       | The pointed-to value cannot be modified through `ptr`, but the pointer can point elsewhere. |
| `double* const ptr`       | The pointer cannot point elsewhere, but the pointed-to value can be modified.               |
| `const double* const ptr` | Neither the pointer nor the pointed-to value can be changed through `ptr`.                  |

Remember: the position of `const` determines whether the data, the pointer, or both are protected.

## 2. `constexpr`

`constexpr` is a C++ keyword that allows variables and functions to participate in compile-time evaluation.

- **Variables:** Must be initialized using a constant expression and are implicitly `const`.
- **Functions:** Can execute at compile time when their arguments and context permit it, or at runtime when given runtime inputs.

### 2.1 Compile Time vs Runtime

- **Compile time:** The compiler processes the program before execution.
- **Runtime:** The compiled program executes and processes inputs.

```cpp
int x = 10;
// constexpr int b = x; // Error: x is not a constant expression

const int a = 10;
constexpr int b = a; // Valid

constexpr double square(double x) {
    return x * x;
}

constexpr double result = square(3.0); // Compile time

double input;
std::cin >> input;

double runtimeResult = square(input); // Runtime
```

A `constexpr` function does not have to execute at compile time every time. It can also execute at runtime when its inputs are only known during execution.

### 2.2 Why Use `constexpr` for Physical Constants?

For constants such as (\pi), gravitational acceleration, and degrees-to-radians conversion, `constexpr` provides typed, scoped constants that can be evaluated at compile time.

It is generally preferable to `#define` for these values because it respects C++ types and scope.

```cpp
constexpr double PI = 3.14159265358979323846;
constexpr double G = 9.81;
constexpr double DEG_TO_RAD = PI / 180.0;
```

## 3. `auto` — Type Deduction

`auto` asks the compiler to deduce a variable's type from its initializer.

```cpp
auto speed = 5.5;       // double
auto maxSteps = 100;    // int
auto robotName = "Rover"; // const char*
```

It is especially useful when working with iterators, whose types can be long or complicated.

### 3.1 `auto` in Range-Based Loops

Consider a vector containing three joint angles:

```cpp
std::vector<double> jointAngles = {0.0, 1.57, 3.14};
```

**Pass-by-value — `auto angle`**

```cpp
for (auto angle : jointAngles) {
    angle += 0.1;
}
```

Each element is copied into a separate local variable. Changing `angle` does not change the original vector.

**Read-only reference — `const auto& angle`**

```cpp
for (const auto& angle : jointAngles) {
    std::cout << angle << '\n';
}
```

The variable refers directly to each original element without copying it. Modification through this reference is prohibited.

**Mutable reference — `auto& angle`**

```cpp
for (auto& angle : jointAngles) {
    angle += 0.1;
}
```

The variable refers directly to each original element, so the changes are reflected in the vector.

**Practical rule:**

- Use `const auto&` when reading elements, especially from larger objects.
- Use `auto&` when modifying the original elements.
- Use `auto` when you need a separate copy.

### 3.2 `auto` with Iterators

```cpp
auto it = jointAngles.begin();
std::cout << *it << '\n';
```

The compiler deduces the iterator type. The `*it` expression accesses the element to which the iterator refers.

## 4. Type Aliases — `using`

A type alias gives an existing C++ type a more meaningful name without changing its underlying type or memory representation.

```cpp
using JointAngle = double;
using Distance = double;
using EncoderTicks = int;
```

Example:

```cpp
JointAngle shoulderAngle = 1.57;
Distance armLength = 0.5;
EncoderTicks encoderCount = 1024;
```

The declarations communicate the purpose of each variable more clearly than generic types alone.

However, `JointAngle` and `Distance` are both aliases for `double`. The compiler will not automatically prevent one from being used in place of the other.

## 5. Practical Tasks

### Task 1 — Physical Constants and Type Aliases  
Here is the link to the code [file](code1.cpp)

- Declare `PI`, `G`, and `DEG_TO_RAD` using `constexpr`.
- Create type aliases such as `JointAngle`, `Distance`, and `EncoderTicks`.
- Use these aliases in a small robotics-related calculation.
- Verify that the program compiles and produces the expected result.

### Task 2 — Const Propagation and `auto`  
Here is the link to the code [file](code2.cpp)
- Write a function that accepts a vector using a const reference.
- Print its elements using `const auto&`.
- Demonstrate how `auto` copies an element and how `auto&` modifies the original.
- Use `auto` to declare an iterator.

### Task 3 — Rewrite Math Utilities

Update the existing math utilities to use `constexpr` constants and suitable type aliases throughout. Apply `const` to function parameters where appropriate and use `auto` where it improves readability.

It is similar to our task1.

## 6. Questions to Check Understanding

1. Can a variable be `const` without being `constexpr`?
2. Why must a `constexpr` variable be initialized with a constant expression?
3. What is the difference between `const double*` and `double* const`?
4. What is the difference between `auto`, `const auto&`, and `auto&` in a range-based loop?
5. Why is `const std::vector<double>&` useful as a function parameter?
6. Does `using JointAngle = double;` prevent a distance from being passed where an angle is expected?
7. Why are `constexpr` constants useful in robotics math utilities?


**Day 8 takeaway:** Use `const` to control modification, `constexpr` for compile-time constants and eligible computations, `auto` to reduce unnecessary type repetition, and type aliases to make robotics code more readable.
