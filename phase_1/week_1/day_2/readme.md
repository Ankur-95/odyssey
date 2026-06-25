# Day 2 — Variables, Types, and Operators

## Today's Tasks

* Declare variables of every built-in type and print them
* Understand signed vs unsigned overflow with a small experiment
* Use `const` and `constexpr` — know the difference
* Practice operators: `+`, `-`, `*`, `/`, `%`, `<<`, `>>`, `&`, `|`, `^`
* Use `auto` for type deduction — know when it helps and when it hurts
* Build a simple sensor unit converter (`raw int → voltage as double → display string`)

---

## Task 1: Built-in Data Types

In C++, every variable must be assigned a data type. A data type tells the compiler what kind of value the variable will store and how much memory should be allocated for it.

### 1. int

Used for storing whole numbers (integers).

**Typical Size:** 4 bytes (32 bits)

**Examples:**

```cpp
int age = 20;
int sensorCount = 150;
```

### 2. float

Used for storing decimal numbers with single precision.

**Typical Size:** 4 bytes (32 bits)

**Precision:** Approximately 6–7 decimal digits

**Examples:**

```cpp
float temperature = 36.5f;
float speed = 12.75f;
```

### 3. bool

Used for storing logical values.

Possible values:

* true
* false

**Example:**

```cpp
bool obstacleDetected = true;
```

### 4. char

Used for storing a single character.

**Example:**

```cpp
char grade = 'A';
char symbol = '%';
```

### 5. std::string

Used for storing a sequence of characters (text).

**Example:**

```cpp
std::string name = "Ankur";
```

### 6. double

Used for storing decimal numbers with higher precision than float.

**Typical Size:** 8 bytes (64 bits)

**Precision:** Approximately 15–17 decimal digits

**Example:**

```cpp
double voltage = 12.567891234567;
```

---

## Task 2: Signed vs Unsigned Values

### Signed Integers

Signed integers can store both positive and negative values.

The highest bit is generally used to represent the sign of the number.

Example (8-bit signed integer):

```text
Range: -128 to 127
```

### Unsigned Integers

Unsigned integers can store only non-negative values.

Since no bit is reserved for a sign, the entire range can be used for positive values.

Example (8-bit unsigned integer):

```text
Range: 0 to 255
```

Program demonstrating this concept: [code1.cpp](https://github.com/Ankur-95/odyssey/main/phase_1/week_1/day_2/code1.cpp)

---

### Overflow

Overflow occurs when a value exceeds the maximum capacity of a data type.

Example:

```text
255 + 1 = 0
```

for an 8-bit unsigned integer.

The value wraps around and starts again from the minimum value.

### Underflow

Underflow occurs when a value goes below the minimum capacity of a data type.

Example:

```text
0 - 1 = 255
```

for an 8-bit unsigned integer.

The value wraps around to the maximum value.

Program demonstrating overflow and underflow:  [code2.cpp](https://github.com/Ankur-95/odyssey/main/phase_1/week_1/day_2/code2.cpp)

### Which is Better for Sensor Values?

There is no universal answer.

The correct choice depends on the physical quantity being measured.

Examples:

* Distance → usually unsigned
* Battery percentage → unsigned
* Velocity → can be signed
* Acceleration → can be signed
* Gyroscope readings → can be signed

The best practice is to choose the type that accurately represents the range of the real-world data.

---

## Task 3: const and constexpr

### const

A `const` variable cannot be modified after initialization.

```cpp
const int maxSpeed = 100;
```

The value may be known only when the program starts running.

Example:

```cpp
int input;
std::cin >> input;

const int value = input;
```

### constexpr

A `constexpr` variable must have a value that is known during compilation.

```cpp
constexpr int wheelCount = 4;
```

The compiler evaluates it before the program runs.

### Why Use constexpr?

1. Enables compile-time calculations
2. Can improve performance
3. Allows use in contexts that require compile-time constants
4. Helps catch errors earlier during compilation

---

## Task 4: Operators

### Arithmetic Operators

| Operator | Meaning             |
| -------- | ------------------- |
| +        | Addition            |
| -        | Subtraction         |
| *        | Multiplication      |
| /        | Division            |
| %        | Modulus (remainder) |

---

### Bitwise Operators

| Operator | Meaning     |
| -------- | ----------- |
| <<       | Left Shift  |
| >>       | Right Shift |
| &        | Bitwise AND |
| |        | Bitwise OR  |
| ^        | Bitwise XOR |

#### Left Shift (<<) 
Shifts bits to the left.  
Each shift roughly multiplies the value by 2.

#### Right Shift (>>)

Shifts bits to the right.  
Each shift roughly divides the value by 2.

#### Bitwise AND (&)

Returns 1 only when both bits are 1.

#### Bitwise OR (|)

Returns 1 when at least one bit is 1.

#### Bitwise XOR (^)

Returns 1 when the bits are different.

---

## Task 5: auto

### What is auto?

`auto` is a C++ keyword that allows the compiler to automatically deduce the type of a variable.

Example:

```cpp
auto number = 10;
```

The compiler automatically determines that `number` is an `int`.

### When Does It Help?

* When types are long and complex
* Improves readability in loops
* Reduces repetitive typing

### When Can It Hurt?

Overusing `auto` can make code harder to understand.

Example:

```cpp
auto result = someFunction();
```

Without knowing the return type of `someFunction()`, the reader may have difficulty understanding the code immediately.

Use `auto` when it improves readability, not when it hides important information.
