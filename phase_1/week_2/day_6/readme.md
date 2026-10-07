# Day 6 — Pointers and References Deep Dive

## Today's Topic

Pointer syntax, dereferencing, `nullptr`, pointer arithmetic, reference rules

## Today's Tasks

* Declare pointer, assign address, dereference, print address vs value
* Show pointer arithmetic on an array — count steps
* Demonstrate `nullptr` check before dereference
* Show what a dangling pointer looks like (read only, never run with UB)
* Use references as aliases — show you can't rebind
* Task: write `swap()` with pointers AND with references; compare

---

## Pointer Fundamentals

Okkk let's start with basics..

### What is a pointer?

A pointer is another way of accessing the stored value of a variable.

The exact definition:

> A pointer is a variable whose value is the memory address of another variable.

Instead of storing the actual data, a pointer stores the **location in memory** where that data is stored.

Consider this:

```text
ptr ─────────► x
               100
```

where:

* `x` = the variable where the actual value is stored
* `ptr` = the pointer variable
* `ptr` stores the memory address of `x`
* `*ptr` can then be used to access the value stored in `x`

For example:

```cpp
int x = 100;
int* ptr = &x;
```

Here:

```text
ptr  → address of x
*ptr → value of x
```

---

## What's the use of pointers though?

Pointers are useful when we need to work with the **memory location of an object** instead of just its value.

Some important uses:

### Direct Memory Access

Pointers are heavily used in low-level programming, operating systems, embedded systems and hardware-related programming where specific memory locations may need to be accessed.

### Efficient Data Handling

Pointers can allow functions to work with existing data instead of making unnecessary copies, especially when dealing with large objects.

### Dynamic Memory

Pointers are also involved in dynamically allocated memory and data structures such as linked lists, trees, etc.

---

## How to declare a pointer?

The basic syntax is:

```cpp
data_type* pointer_name;
```

Examples:

```cpp
int* ptr;
double* p;
char* ch;
```

The type tells us what kind of object the pointer is intended to point to.

---

## Initializing a Pointer

A pointer should be initialized with the address of an object it is supposed to point to.

```cpp
int x = 10;

int* ptr = &x;
```

Here:

* `&x` gives the memory address of `x`
* `ptr` stores that address
* `ptr` therefore points to `x`

### Important operators

```cpp
&x
```

means:

> Give me the address of `x`.

Whereas:

```cpp
*ptr
```

means:

> Access the value stored at the address contained in `ptr`.

---

## Why do we need to define the Pointer Type?

You might wonder why we need to write:

```cpp
int* ptr;
double* ptr;
char* ptr;
```

instead of just having a generic pointer.

The pointer type tells the compiler what type of object the pointer points to.

This becomes important when:

1. Dereferencing the pointer — the compiler needs to know how to interpret the data.
2. Performing pointer arithmetic — the size of the pointed-to type determines how far the pointer moves.

For example:

```cpp
int* ptr;
```

means `ptr` is expected to point to an `int`.

Similarly:

```cpp
double* ptr;
```

means it is expected to point to a `double`.

---

## Dereferencing a Pointer

It's easy to store an address in a pointer, but we also need a way to access the actual value.

That's where **dereferencing** comes in.

```cpp
int x = 10;
int* ptr = &x;

std::cout << *ptr;
```

Output:

```text
10
```

`*ptr` accesses the value stored at the memory address contained in `ptr`.

We can also modify the original variable through the pointer:

```cpp
int x = 10;
int* ptr = &x;

*ptr = 12;
```

Now:

```text
x = 12
```

The pointer did not create another copy of `x`.

It accessed the original `x` through its memory address.

---

# nullptr

`nullptr` is a C++11 keyword that represents a **null pointer value**.

It means that the pointer is currently not pointing to an object.

```cpp
int* ptr = nullptr;
```

This is different from an uninitialized pointer:

```cpp
int* ptr;
```

An uninitialized pointer contains an indeterminate value and should not be dereferenced.

So why create a pointer and then store "nothing" in it?

Because sometimes a pointer doesn't have a valid object to point to yet.

Initializing it to `nullptr` gives it a **known state** that we can safely check.

For example:

```cpp
if (ptr != nullptr)
{
    // Safe to consider dereferencing ptr
}
```

This is much better than leaving a pointer uninitialized and not knowing what it contains.

### Important

`nullptr` does **not** mean a valid memory address.

It represents the state:

> This pointer is not pointing to an object.

Never do:

```cpp
int* ptr = nullptr;

std::cout << *ptr;
```

Dereferencing a null pointer results in **undefined behavior**.

---

# Pointer Arithmetic

As the name suggests, pointer arithmetic means performing arithmetic operations on pointer values.

But there is one important thing to understand:

> Pointer arithmetic moves between elements based on the type being pointed to. It does not simply increase the address by one byte.

## Pointer Increment / Decrement

Consider:

```cpp
int arr[] = {10, 20, 30};

int* ptr = arr;
```

Here `ptr` points to the first element:

```text
ptr → arr[0]
```

If we do:

```cpp
ptr++;
```

the pointer moves to the next `int`:

```text
ptr → arr[1]
```

Similarly:

```cpp
ptr--;
```

moves it back by one `int`.

For example, if an `int` occupies 4 bytes, conceptually:

```text
arr[0] → 0x1000
arr[1] → 0x1004
arr[2] → 0x1008
```

So:

```cpp
ptr++;
```

moves to the next `int`, meaning the address changes by `sizeof(int)` bytes.

This is why pointer arithmetic depends on the pointer's type.

---

# Relationship Between Arrays and Pointers

Arrays and pointers are closely related in C++, especially when an array is used in an expression.

Consider:

```cpp
int arr[3] = {100, 200, 300};
```

In many expressions, the array name `arr` converts to a pointer to its first element.

So conceptually:

```cpp
arr
```

can be used as a pointer to:

```cpp
&arr[0]
```

This is why we can write:

```cpp
int* ptr = arr;
```

and `ptr` points to the first element.

### Array indexing and pointer arithmetic

These are equivalent:

```cpp
arr[i]
```

and:

```cpp
*(arr + i)
```

For example:

```cpp
std::cout << arr[0];
std::cout << *arr;
```

Both give:

```text
100
```

And:

```cpp
std::cout << arr[2];
std::cout << *(arr + 2);
```

Both give:

```text
300
```

This is one of the most important connections between arrays and pointers.

### Important clarification

An array is **not the same thing as a pointer**.

An array can decay to a pointer to its first element in many contexts, but the array itself and a pointer are different types of objects.

---

# Dangling Pointers

There is also a concept called a **dangling pointer**.

A dangling pointer is a pointer that still contains an address, but the object that used to exist at that address has already reached the end of its lifetime or has been destroyed/deallocated.

Conceptually:

```text
Object exists
     ↑
   pointer
```

Then the object is destroyed:

```text
Object → gone

pointer ─────► old address
```

The pointer still exists, but the object it was supposed to point to no longer exists.

Using such a pointer to access the old object results in **undefined behavior**.

### Important distinction

A dangling pointer is different from `nullptr`.

```text
nullptr pointer:
pointer → nothing

dangling pointer:
pointer → old address, but object is gone
```

For this section, only understand and show the concept. **Do not intentionally execute code that dereferences a dangling pointer.**

---

# References

A reference is an **alias / alternate name for an existing variable**.

Example:

```cpp
int x = 10;

int& ref = x;
```

Now `ref` refers to the same object as `x`.

If we do:

```cpp
ref = 20;
```

then `x` also becomes:

```text
x = 20
```

We are not modifying some separate copy.

`ref` is simply another way of accessing `x`.

We can also read through it:

```cpp
int y = ref;
```

Now:

```text
y = 20
```

---

## Key Rules for References

### 1. Must be initialized

A reference must be initialized when it is declared:

```cpp
int& ref = x;
```

You cannot simply create an uninitialized normal reference and decide what it will refer to later.

### 2. Cannot be rebound

Once:

```cpp
int& ref = x;
```

has been established, `ref` cannot later be made to refer to `y`.

If we write:

```cpp
ref = y;
```

we are **assigning the value of `y` to `x`**.

We are not changing what `ref` refers to.

### 3. No `nullptr` reference

A normal reference must refer to an existing object. Unlike a pointer, it cannot represent "points to nothing" using `nullptr`.

### 4. Reference to reference

You don't normally declare a direct reference-to-reference such as:

```cpp
int&&& ref;
```

C++ has more advanced rules such as **reference collapsing**, but that is beyond what we need for this Day 6 introduction.

---

# Pointers vs References

| Feature                   | Pointer (`T*`)              | Reference (`T&`)                |
| ------------------------- | --------------------------- | ------------------------------- |
| Syntax                    | Uses `*`                    | Uses `&`                        |
| Initialization            | Can be initialized later    | Must be initialized             |
| Null                      | Can be `nullptr`            | Cannot be null                  |
| Rebinding                 | Can point to another object | Cannot be rebound               |
| Access                    | Requires dereferencing      | Acts like the original variable |
| Can represent "no object" | Yes                         | No                              |

The important conceptual difference:

> A pointer is an object that stores an address.

> A reference is an alias for an existing object.

---

# Pointers with Functions

Pointers become especially useful when passing data to functions.

A pointer parameter can receive the address of an existing variable.

For example, conceptually:

```cpp
void modify(int* ptr)
{
    // work with the original object through ptr
}
```

The caller can pass the address:

```cpp
modify(&x);
```

Inside the function, dereferencing the pointer allows the function to access or modify the original variable.

References can achieve a similar result:

```cpp
void modify(int& value)
{
    // work directly with the original object
}
```

The caller can simply write:

```cpp
modify(x);
```

This is one of the practical reasons pointers and references are important in functions.

---

# Swap Experiment

For today's main practical task, I implemented `swap()` in two different ways:

1. Using pointers
2. Using references

The pointer version receives the **addresses** of the two variables and uses dereferencing to modify their original values.

The reference version receives **aliases** to the original variables and can modify them directly.

The pointer version also performs a `nullptr` check:

```cpp
if (a == nullptr || b == nullptr)
    return;
```

This is possible because pointers can represent the absence of an object.

The reference version doesn't need such a check because a normal reference is expected to refer to a valid object.

### One thing to notice in the experiment

The program first swaps `x` and `y` using references and then swaps them again using pointers.

So if the initial values are:

```text
x = 5
y = 10
```

after the first swap:

```text
x = 10
y = 5
```

and after the second swap:

```text
x = 5
y = 10
```

So the final values return to the original values because the program performs **two swaps**.

### Main takeaway

Both pointers and references can allow a function to modify the caller's original variables.

The main difference is how they represent that relationship:

```text
Pointer:
variable → address → object

Reference:
reference → alias of object
```
