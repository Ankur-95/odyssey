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

Consider:

```text
ptr ─────────► x
               100
```

where:

* `x` = variable where the actual value is stored
* `ptr` = pointer variable
* `ptr` stores the memory address of `x`
* `*ptr` can be used to access the value stored in `x`

For example:

```cpp
int x = 100;
int* ptr = &x;
```

### Quick Syntax Reference

| Syntax    | Meaning                         | Example             |
| --------- | ------------------------------- | ------------------- |
| `int x`   | Normal integer variable         | `int x = 10;`       |
| `int* x`  | Pointer to an integer           | `int* x = &a;`      |
| `int& x`  | Reference (alias) to an integer | `int& x = a;`       |
| `&x`      | Address of `x`                  | `int* p = &x;`      |
| `*x`      | Dereference pointer `x`         | `*p = 20;`          |
| `nullptr` | Pointer points to nothing       | `int* p = nullptr;` |

**Don't confuse:**

* `int& x` → declaring a reference
* `&x` → getting the address of `x`

---

## Pointer Declaration and Initialization

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

To initialize a pointer with the address of a variable:

```cpp
int x = 10;
int* ptr = &x;
```

Here:

```text
&x   → address of x
ptr  → stores that address
*ptr → value stored at that address
```

The pointer type tells the compiler what type of object the pointer points to. It also matters during dereferencing and pointer arithmetic.

---

## Dereferencing

It's easy to store an address in a pointer, but we also need a way to access the value at that address.

That's called **dereferencing**:

```cpp
int x = 10;
int* ptr = &x;

std::cout << *ptr;
```

Output:

```text
10
```

We can also modify the original variable through the pointer:

```cpp
*ptr = 12;
```

Now `x` is `12`.

The pointer doesn't create another copy of `x`; it accesses the original object through its address.

---

### `nullptr`

`nullptr` represents a pointer that is **not currently pointing to an object**.

```cpp
int* ptr = nullptr;
```

This is different from:

```cpp
int* ptr;
```

An uninitialized pointer contains an indeterminate value and should not be dereferenced.

Initializing it with `nullptr` gives it a known state that can be checked:

```cpp
if (ptr != nullptr)
{
    // safe to consider dereferencing ptr
}
```

Never dereference a null pointer:

```cpp
int* ptr = nullptr;

std::cout << *ptr; // Undefined behavior
```

---

# Pointer Arithmetic

Pointer arithmetic moves between elements based on the type being pointed to.

Consider:

```cpp
int arr[] = {10, 20, 30};

int* ptr = arr;
```

`ptr` points to `arr[0]`.

```cpp
ptr++;
```

moves it to the next `int`:

```text
ptr → arr[1]
```

If an `int` occupies 4 bytes, conceptually:

```text
arr[0] → 0x1000
arr[1] → 0x1004
arr[2] → 0x1008
```

So `ptr++` moves by `sizeof(int)` bytes, not simply by one byte.

---

## Arrays and Pointers

In many expressions, an array name converts to a pointer to its first element.

```cpp
int arr[3] = {100, 200, 300};

int* ptr = arr;
```

Here `ptr` points to `arr[0]`.

These are equivalent:

```cpp
arr[i]
*(arr + i)
```

For example:

```cpp
arr[2]
*(arr + 2)
```

both access `300`.

**Important:** An array is not the same thing as a pointer. They are different types, but arrays can decay to a pointer to their first element in many contexts.

---

# Dangling Pointers

A dangling pointer is a pointer that still contains an address, but the object that used to exist at that address has already reached the end of its lifetime.

Conceptually:

```text
Object exists
     ↑
   pointer

Object destroyed
     ↑
   pointer
```

The pointer still contains an address, but the object is no longer valid.

Using such a pointer to access the old object results in **undefined behavior**.

### `nullptr` vs dangling pointer

```text
nullptr:
pointer → no object

dangling pointer:
pointer → old address, but object is gone
```

For this section, understand the concept but **never intentionally execute code that dereferences a dangling pointer.**

---

# References

A reference is an **alias / alternate name for an existing variable**.

```cpp
int x = 10;

int& ref = x;
```

Now `ref` refers to the same object as `x`.

```cpp
ref = 20;
```

Now `x` is also `20`.

### Reference Rules

* Must be initialized when declared.
* Cannot be rebound to another object.
* Cannot represent `nullptr`.
* Acts directly as an alias for the original object.

For example:

```cpp
int x = 10;
int y = 20;

int& ref = x;

ref = y;
```

This does **not** make `ref` refer to `y`.

Instead, it copies the value of `y` into `x`.

---

# Pointers vs References

| Feature           | Pointer (`T*`)                    | Reference (`T&`)                |
| ----------------- | --------------------------------- | ------------------------------- |
| Stores an address | Yes                               | Acts as an alias                |
| Initialization    | Can be initialized with `nullptr` | Must refer to an object         |
| Null              | Can be `nullptr`                  | Cannot be null                  |
| Rebinding         | Can point to another object       | Cannot be rebound               |
| Access            | Requires `*` to dereference       | Used like the original variable |

The simplest way I understand the difference:

```text
Pointer:
object → address → pointer

Reference:
object ← alias
```

---

# Swap Experiment

For the main practical task, I implemented `swap()` in two ways:

1. Using pointers
2. Using references

The pointer version receives addresses:

```cpp
swapby_ptr(&x, &y);
```

Inside the function, `*a` and `*b` access the original variables.

The reference version receives aliases:

```cpp
swapby_ref(x, y);
```

and can modify the original variables directly.

The pointer version also checks for `nullptr` because pointers can represent "no object".

Both approaches can modify the caller's original variables, but they express the relationship differently:

```text
Pointer:
address → object

Reference:
alias → object
```

### One thing to notice

In my experiment, I call both swap functions one after another.

Starting:

```text
x = 5
y = 10
```

After the first swap:

```text
x = 10
y = 5
```

After the second swap:

```text
x = 5
y = 10
```

So the final values return to the original values because the variables were swapped **twice**.

---
