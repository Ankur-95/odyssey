# Day 3 — Control Flow

## Today's Tasks

* Understand different control flow statements.
* Write a menu-driven program using `switch`.
* Detect robot states using nested `if-else`.
* Use a range-based `for` loop with an initializer list.
* Practice `break` and `continue` using a search program.
* Simulate a countdown timer that skips multiples of `3` and stops at fault code `7`.

---

# Task 1 — Understanding Control Flow Statements

Control flow statements decide **how a program moves from one statement to another.** They help us make decisions and repeat a block of code whenever required.

## `if`

The `if` statement is the simplest conditional statement. It executes a block of code only if the given condition is true.

**Syntax**

```cpp
if (condition)
{
    // Code
}
```

**Example**

```cpp
if (robot_sensor == true)
{
    std::cout << "Robot Sensor is ON";
}
```

---

## `if-else`

The `if-else` statement is used when there are only two possible outcomes. If the condition is true, the `if` block executes; otherwise, the `else` block executes.

**Syntax**

```cpp
if (condition)
{
    // Code
}
else
{
    // Code
}
```

---

## `else-if`

`else-if` is useful when more than two conditions need to be checked. The conditions are checked one by one until one of them becomes true.

**Syntax**

```cpp
if (condition1)
{
    // Code
}
else if (condition2)
{
    // Code
}
else
{
    // Code
}
```

---

## `switch`

The `switch` statement is another way of handling multiple choices. Instead of writing several `if-else` statements, we can compare one expression against different fixed values, which often makes the code cleaner and easier to read.

**Syntax**

```cpp
switch (expression)
{
case value1:
    // Code
    break;

case value2:
    // Code
    break;

default:
    // Code
    break;
}
```

---

## `for` Loop

The `for` loop is generally used when the number of iterations is already known.

**Syntax**

```cpp
for(initialization; condition; update)
{
    // Code
}
```

**Example**

```cpp
for(int i = 1; i <= 10; i++)
{
    std::cout << i << " ";
}
```

---

## `while` Loop

The `while` loop is useful when we don't know beforehand how many times the loop should run. It keeps executing until the condition becomes false.

**Syntax**

```cpp
while(condition)
{
    // Code
}
```

---

## `do-while` Loop

The `do-while` loop works almost the same as a `while` loop. The only difference is that the loop body executes at least once before checking the condition.

**Syntax**

```cpp
do
{
    // Code
}
while(condition);
```

### When should we use which loop?

* **for** → When the number of iterations is known.
* **while** → When execution depends on a condition.
* **do-while** → When the loop must execute at least once.

---

## `break`

The `break` statement immediately exits the nearest loop or `switch` statement.

---

## `continue`

The `continue` statement skips the current iteration and moves directly to the next iteration of the loop.

---

# Task 2 — Menu Driven Program Using `switch`

### Why this exercise?

The purpose of this exercise is to understand how the `switch` statement works. Instead of writing multiple `if-else` statements, the program performs different actions based on the option entered by the user.

### Requirements

| Input | Action        |
| ----: | ------------- |
|     1 | Move Forward  |
|     2 | Move Backward |
|     3 | Turn Left     |
|     4 | Turn Right    |
|     5 | Stop          |

For now, the program simply prints the corresponding robot action.

**Code:** [code1.cpp](code1.cpp)

---

# Task 3 — Robot State Detection Using Nested `if-else`

### Why this exercise?

This exercise was written to understand how nested `if-else` statements work. Here, one decision depends on another, making nested conditions a suitable choice.

### Inputs

* Battery Level
* Motor Status
* Fault Flag

### Possible States

* Idle
* Moving
* Fault

**Code:** [code2.cpp](code2.cpp)

---

# Task 4 — Range-Based `for` Loop

This small program demonstrates how a range-based `for` loop can be used to iterate through an initializer list. In this example, all the values are added to calculate their total sum.

```cpp
#include <iostream>

int main()
{
    int sum = 0;

    for (auto value : {10, 20, 30, 40, 50, 60})
    {
        sum += value;
    }

    std::cout << "Total Sum: " << sum << std::endl;

    return 0;
}
```

---

# Task 5 — Practicing `break` with a Search Program

The aim of this exercise is to search for a user-entered number in an array. Once the number is found, the loop terminates using the `break` statement and prints its position.

**Code:** [code3.cpp](code3.cpp)

---

# Task 6 — Countdown Timer

The final exercise combines loops with `continue` and `break`.

### Requirements

* Countdown from **15** to **0**.
* Skip all multiples of **3**.
* Stop the countdown when the value becomes **7**.

**Code:** [code4.cpp](code4.cpp)

---

