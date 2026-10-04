# Day 5 - Arrays, Strings & I/O

## Today's Tasks

Arrays, strings, I/O

Raw arrays, `std::string`, `std::cin/cout`, string operations.

* Declare and iterate raw arrays — understand array decay to pointer.
* Use `std::string`: `find`, `substr`, `append`, `compare`, `size`.
* Read from stdin: name + 3 sensor values.
* Format output with `fixed`, `setprecision`.
* **Main Task:** Read 5 joint angles from the user and print them as a formatted robot state table.

---

## Arrays

### What is an Array?

* An array is a fixed-size data structure that stores a collection of elements of the **same data type** in **contiguous (sequential) memory locations**.

* Okk... that was heavy.

We know how to create variables, right?

Whenever we create variables, they can be stored at different memory addresses. But with an array, we can store multiple values of the **same data type next to each other in memory**.

For example:

```cpp
int sensor_data[5] = {17, 26, 34, 1, 7};
```

Here, we have 5 integers stored next to each other.

---

### Okk Ankur, I get it. But what's the point?

The important thing about contiguous memory is that the computer can access array elements efficiently using their position/index.

For example:

```text
sensor_data[0]
sensor_data[1]
sensor_data[2]
sensor_data[3]
sensor_data[4]
```

The computer knows where the next element is because the elements are stored at fixed offsets from each other.

**Time complexity, cache behavior, pointers, etc. — don't overthink this right now. We'll learn these properly later.**

---

### Properties of Arrays

1. **Homogeneous** — Every element must have the same data type.
2. **Contiguous** — Elements are stored in continuous memory locations.
3. **Fixed size** — A raw array's size is fixed once it is created.
4. **0th Index** — Array indexing starts from `0`.

For example:

```text
Index:        0    1    2    3
Value:       10   20   30   40
```

---

## Declaration and Initialization

The basic syntax is:

```cpp
type array_name[size];
```

Example:

```cpp
int values[4];
```

This declares an array capable of storing 4 integers.

We don't always have to explicitly specify the size when initializing an array.

For example:

```cpp
int values[] = {0, 1, 2, 3};
```

The compiler can determine the size from the number of elements.

---

# Array Decay → Pointer

This was an important concept today.

**Array decay** is when an array is automatically converted to a pointer to its first element in certain situations, especially when passing an array to a function.

So when we do:

```cpp
printArray(robsens, 10);
```

the function doesn't actually receive the complete array as an array object.

It receives a pointer to its first element.

```text
robsens
   ↓
┌────┬────┬────┬────┬────┐
│  1 │  2 │  3 │  4 │ ...│
└────┴────┴────┴────┴────┘
   ↑
   pointer points here
```

That's why the function needs the size separately.

```cpp
void printArray(int* arr, int size)
```

`arr` tells us **where the array starts**, while `size` tells us **how many elements we can access**.

### Example

```cpp
void printArray(int* arr, int size) {

    for (int i = 0; i < size; i++) {

        std::cout << arr[i] << " ";

    }

    std::cout << "\n";
}
```

```cpp
int main() {

    int robsens[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    printArray(robsens, 10);

    return 0;
}
```

### Important thing to remember

> **An array knows its size, but after it decays to a pointer, the pointer itself does not know the array's size.**

This is why we passed `10` separately.

---

# String Operations

Some useful string operations we worked with today:

---

## 1. `size()`

Returns the number of characters in the string.

```cpp
string.size()
```

Example:

```cpp
std::string name = "Robot";
std::cout << name.size();
```

---

## 2. `find()`

Used to search for a particular word or sequence of characters inside a string.

```cpp
string.find("word")
```

If the text is found, it returns the **index where it starts**.

If it isn't found, it returns:

```cpp
std::string::npos
```

### What is `std::string::npos`?

It is a special constant used to represent **"no position"**.

So instead of assuming that `find()` returned `-1`, we should compare the result with:

```cpp
std::string::npos
```

Example idea:

```cpp
if (name.find("Robot") != std::string::npos)
```

means:

> "If `Robot` was found somewhere inside the string..."

---

## 3. `substr()`

Used to extract a smaller part of an existing string.

Syntax:

```cpp
string.substr(start_index, length);
```

Example:

```cpp
std::string branch = "Robotics and Automation";

std::string field = branch.substr(0, 8);

std::cout << field << "\n";
```

Output:

```text
Robotics
```

Remember:

> `substr()` does not modify the original string. It gives us a new string containing the requested part.

---

## 4. `append()`

Used to add characters or another string to the **end** of an existing string.

Syntax:

```cpp
string.append(text_to_add);
```

Example:

```cpp
robot_name.append(" Version_1");
```

The original `robot_name` is modified.

---

## 5. `compare()`

Used to compare two strings.

Syntax:

```cpp
string1.compare(string2)
```

The result tells us whether the strings are equal or which one comes before the other lexicographically.

For simple equality checks, we can also use:

```cpp
string1 == string2
```

which is much easier to read.

---

## 6. `cin >>` vs `getline()`

This one is important.

### `std::cin >>`

Reads a value/word and stops at whitespace.

For example:

```cpp
std::string name;
std::cin >> name;
```

If the user enters:

```text
Ankur Ujawane
```

only:

```text
Ankur
```

is read.

### `std::getline()`

Reads the entire line, including spaces.

```cpp
std::getline(std::cin, name);
```

So:

```text
Ankur Ujawane
```

is read as one string.

---

# Tasks

The tasks are basically small implementations of the concepts above.

Instead of just reading about arrays and strings, the idea is to actually use them in small programs.

---

## Task-1: Raw Array

### Create an array containing 5 sensor readings.

Creating an array is almost as simple as creating a variable.

Here we declared an array called `sensor_data` and initialized it with 5 values.

Then we used a `for` loop to iterate through the array and print each sensor reading along with its sensor number.

This task mainly reinforces:

* Array declaration
* Array initialization
* Indexing
* Iteration using a `for` loop
* Accessing individual elements

Here is the task file: [Code_1](code1.cpp)

---

## Task-2: Array Function

### Create a function that receives an array and prints its elements.

Similar to Task-1, but here instead of doing everything directly inside `main()`, we move the array-printing logic into a function.

The important part of this task is not just functions.

It is understanding **how arrays behave when passed to functions**.

```cpp
void printArray(int arr[], int size)
```

The array is passed to the function, but because of array decay, `arr` effectively behaves like a pointer to the first element.

That's why we also pass:

```cpp
size
```

The task also introduces dynamically allocating an array:

```cpp
int* arr = new int[size];
```

and freeing it afterwards:

```cpp
delete[] arr;
```

So this task connects multiple concepts:

* Functions
* Arrays
* Array decay
* Pointers
* Dynamic memory
* `new[]`
* `delete[]`

Here is the task file: [Code_2](code2.cpp)

---

## Task-3: String Operation

### Create a string representing a robot-related name and perform operations.

This task is designed to improve our understanding of basic `std::string` operations.

Here we created a robot-related string and performed operations such as:

* Printing its size
* Searching for a word
* Extracting a part of the string
* Appending another string
* Comparing strings

For example, we started with:

```cpp
std::string robot_name = "Underwater Teleoperated Vehicle";
```

Then we used:

```cpp
robot_name.size()
```

to get the number of characters,

```cpp
robot_name.find("Teleoperated")
```

to search for a word,

```cpp
robot_name.substr(...)
```

to extract part of the string,

and:

```cpp
robot_name.append(...)
```

to add something to the end.

For comparison, we also created another string and compared the two.

Here is the task file: [Code_3](code3.cpp)

---

## Task-4: Sensor Input

### Write a program that asks the user for inputs and displays them appropriately.

This task takes the previous array concept one step further.

Instead of deciding the sensor values directly inside the program, we ask the user:

> How many sensor readings do you want to enter?

Then we create an array of that size and take the readings from the user.

The basic flow is:

```text
Ask for number of readings
        ↓
Create array of that size
        ↓
Take sensor readings
        ↓
Store them in the array
        ↓
Iterate through the array
        ↓
Display the readings
```

The interesting part here is:

```cpp
int* sensor_data = new int[a];
```

The size of the array is decided **at runtime** based on the user's input.

Since `new[]` was used to allocate the memory, we need to release it using:

```cpp
delete[] sensor_data;
```

This task therefore combines:

* `std::cin`
* Arrays
* Loops
* Pointers
* Dynamic memory allocation
* `new[]`
* `delete[]`

Here is the task file: [Code_4](code4.cpp)

---

## What I Learned Today

Today's main focus was not just learning a bunch of array/string functions.

The bigger picture was understanding how C++ handles **collections of data and user input**.

The important concepts I want to remember are:

```text
Arrays
  ↓
Contiguous memory
  ↓
Indexing
  ↓
Iteration
  ↓
Array decay → Pointer
  ↓
Passing arrays to functions
```

And for strings:

```text
std::string
  ↓
size()
find()
substr()
append()
compare()
```

For input:

```text
std::cin
   ↓
User input
   ↓
Store in variables / arrays
   ↓
Process
   ↓
Formatted output
```

### Still to learn

The main task for today involves:

* `fixed`
* `setprecision`
* Reading 5 joint angles
* Formatting them as a robot-state table

I have skipped the implementation for now and will work on it myself.
