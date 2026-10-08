# Day 7

## Understand how a real C++ project is organized beyond putting everything into one `.cpp` file — especially declarations, definitions, namespaces, and linking.

### Header/source separation + namespaces, `#pragma once`, `.h/.cpp` split, namespace, scope

* Split math utils into proper `.h` + `.cpp`
* Add a namespace `robotmath::` around all functions
* Understand one-definition rule: why definitions stay in `.cpp`
* Write a second namespace `robotutils::` with string helpers
* Task: `main.cpp` uses both namespaces — compile with CMake, zero warnings

---

Have you ever seen those `.hpp` / `.h` files while you were tinkering with any C++ package?

What are those files?

What are their uses?

Well, those are called **header files**, and we will be reading about those files.

---

# Header Files

A header file acts as the public interface or "blueprint" of a C++ module.

They allow different `.cpp` files to access things such as:

* function declarations
* class interfaces
* type definitions
* constants

without needing to know the underlying implementation details.

Common header extensions are:

```text
.h
.hpp
```

Both are commonly used for C++ headers.

---

## Why Are Header Files Used?

### Compilation Model

C++ generally compiles each `.cpp` file separately.

The compiler needs to know the types and function signatures that a source file is going to use.

For example, if `main.cpp` wants to call:

```cpp
robotmath::clamp(value, min, max);
```

it needs to know that `robotmath::clamp()` exists and what parameters it accepts.

The header provides that information.

### Preventing Duplication

Without headers, we would have to manually write the same function declarations in every `.cpp` file that needs them.

Instead, we can write the declaration once:

```cpp
double clamp(double val, double min, double max);
```

and include the header wherever it is needed.

### Encapsulation

Headers generally expose **what a module provides**, while `.cpp` files contain **how it works**.

```text
Header
   ↓
What can I use?

Source file
   ↓
How does it work?
```

---

# Declaration vs Definition

You could think of them as two friends, when asked about a trip's plan.

Our **Declaration friend** will just say:

> Trust me bro..

Whereas our **Definition friend** is the one who will give you all the info which he planned (after spending nights on research!! but you still won't go!! knew it).

## Declaration

A declaration introduces a name and tells the compiler about its type or function signature.

For example:

```cpp
double clamp(double val, double min, double max);
```

This tells the compiler:

* a function named `clamp` exists
* it returns a `double`
* it accepts three `double` parameters

It does not provide the implementation of the function.

## Definition

A definition provides the actual implementation.

```cpp
double clamp(double val, double min, double max)
{
    // implementation
}
```

So, in simple terms:

```text
Declaration
    ↓
"Something called this exists."

Definition
    ↓
"Here is how it actually works."
```

This distinction becomes important when separating `.h` and `.cpp` files.

---

# `#include` and Header Protection

## How `#include` Works

`#include` is a **preprocessor directive** in C++.

For a simple mental model, think of it as an automated **"copy and paste"** operation.

When the preprocessor encounters:

```cpp
#include "filename"
```

it processes that header and makes its contents available to the source file.

The preprocessed result is then passed to the compiler.

This resulting source is called a **translation unit**.

So roughly:

```text
.cpp file
    ↓
#include headers
    ↓
Preprocessing
    ↓
Translation Unit
    ↓
Compilation
```

---

## `#include "filename"` vs `#include <filename>`

For example:

```cpp
#include "robot_math.h"
#include <iostream>
```

### `"filename"`

Usually used for project/user-created headers.

```cpp
#include "robot_math.h"
```

The compiler searches locations associated with the current source/project include paths.

### `<filename>`

Usually used for standard library or system headers.

```cpp
#include <iostream>
```

The compiler searches its configured system/compiler include paths.

A simple way to remember:

```text
"filename"
    ↓
Usually project header

<filename>
    ↓
Usually system/standard header
```

The exact search order depends on the compiler and build configuration.

---

# `#pragma once`

You have been seeing this line quite a few times:

```cpp
#pragma once
```

So what is it actually doing?

Suppose multiple files include the same header, directly or indirectly.

Without protection, the same header contents could be processed more than once within the same translation unit.

`#pragma once` tells the preprocessor:

> **Process this header only once per translation unit.**

So:

```cpp
#pragma once
```

helps prevent problems caused by repeated inclusion.

### Traditional Header Guards

Another way to achieve this is with include guards:

```cpp
#ifndef CODE_UTILS_H
#define CODE_UTILS_H

// Header contents

#endif
```

For our projects, we will use `#pragma once`.

---

# Splitting a Program into `.h` and `.cpp`

Now we can separate the **interface** from the **implementation**.

The basic idea is:

```text
.h
 ↓
Declarations / interface

.cpp
 ↓
Definitions / implementation

main.cpp
 ↓
Uses the interface
```

I implemented this using the `clamp()` math utility in a separate practical example.

### Practical Example

The complete implementation is available separately in:

```text
Code_exp1/
├── code_utils.h
├── code_utils.cpp
└── code_1.cpp
```

`code_utils.h` contains the declaration.

`code_utils.cpp` contains the implementation.

`code_1.cpp` includes the header and uses the function.

I am keeping the complete code in the separate `Code_exp1` folder instead of duplicating it here.

---

# Namespaces

Now imagine a large project containing many functions.

Different libraries or modules might accidentally use the same name:

```cpp
calculate();
```

Which `calculate()` are we talking about?

This is where **namespaces** help.

A namespace provides a named scope for related identifiers.

It helps:

* organize code
* avoid naming conflicts
* separate modules
* make it clear where a function or type belongs

For our math utilities:

```cpp
namespace robotmath {

    double clamp(double val, double min, double max);

}
```

Now the function belongs to the `robotmath` namespace.

Its full name is:

```cpp
robotmath::clamp()
```

---

# Scope Resolution Operator `::`

The **scope resolution operator** is:

```cpp
::
```

It specifies the scope to which an entity belongs.

For example:

```cpp
robotmath::clamp(val, min, max);
```

Here:

```text
robotmath
    ↓
namespace

::
    ↓
scope resolution

clamp
    ↓
function
```

So we are telling the compiler to find `clamp()` inside the `robotmath` namespace.

General form:

```cpp
namespace_name::function_name(arguments);
```

The `::` operator is also used with classes and the global scope, which we will encounter later.

---

# Multiple Namespaces

We can create another namespace for a different category of utilities:

```cpp
namespace robotutils {

    // string-related utility functions

}
```

Now we have:

```text
robotmath
    ↓
Mathematical utilities

robotutils
    ↓
General/string utilities
```

This keeps unrelated functionality logically separated.

---

# One Definition Rule — ODR

> No need to get surprised — we will learn about it soon..

The **One Definition Rule (ODR)** is a set of rules that controls how definitions can appear in a C++ program.

The important idea for now is:

> A normal entity should not have multiple conflicting definitions across the program.

For example, we can place this declaration in a header:

```cpp
double clamp(double val, double min, double max);
```

and include that header in multiple `.cpp` files.

But we generally don't want every `.cpp` file to contain its own ordinary definition of the same function.

That is one reason we commonly use:

```text
.h
 ↓
Declaration

.cpp
 ↓
Definition
```

There are special cases such as `inline` functions and templates where definitions can appear in headers. Those will be covered separately when needed.

---

# Compilation vs Linking

This is important for understanding why multi-file projects work.

A simplified C++ build process looks like:

```text
.cpp files
    ↓
Preprocessing
    ↓
Compilation
    ↓
Object files
    ↓
Linking
    ↓
Executable
```

For our example:

```text
code_1.cpp
    ↓
code_1.o

code_utils.cpp
    ↓
code_utils.o

code_1.o + code_utils.o
    ↓
Linker
    ↓
Final executable
```

### Compilation

Each `.cpp` file is generally compiled separately into an object file.

### Linking

The linker combines the required object files and resolves references between them.

For example, `code_1.cpp` calls:

```cpp
robotmath::clamp(...);
```

while the actual implementation exists in `code_utils.cpp`.

The linker connects these together.

This is why a program can sometimes compile successfully but fail during the **linking stage**.

---

# CMake and Multi-File Projects

Handling compilation manually becomes difficult as a project grows.

**CMake** helps automate the build process.

For example:

```cmake
add_executable(robot_program
    code_1.cpp
    code_utils.cpp
)
```

This tells CMake that both `.cpp` files belong to the `robot_program` executable.

Conceptually:

```text
code_1.cpp
    ↓
compiler
    ↓
code_1.o

code_utils.cpp
    ↓
compiler
    ↓
code_utils.o

code_1.o + code_utils.o
    ↓
linker
    ↓
robot_program
```

CMake itself is not the compiler or linker. It manages the build process and invokes the required tools.

---

## What About the Header?

Notice that we don't need to compile:

```text
code_utils.h
```

into its own object file.

Instead:

```cpp
#include "code_utils.h"
```

makes its declarations available to the source file during preprocessing.

The `.cpp` files are the source files that are compiled.

---

# Final Project Structure

A larger project can eventually be organized like:

```text
day7/
├── include/
│   ├── math_utils.h
│   └── string_utils.h
│
├── src/
│   ├── math_utils.cpp
│   ├── string_utils.cpp
│   └── main.cpp
│
└── CMakeLists.txt
```

The general idea is:

```text
include/
    ↓
Interfaces / declarations

src/
    ↓
Implementations

CMakeLists.txt
    ↓
Build instructions
```

This isn't the only possible project structure, but it becomes useful as projects grow.

---

# Why This Matters for Robotics

At first, splitting a small program into multiple files might feel unnecessary.

But robotics software quickly becomes much larger than a single `.cpp` file.

You may eventually encounter:

```text
controller.hpp
controller.cpp
sensor.hpp
sensor.cpp
motor.hpp
motor.cpp
main.cpp
```

ROS 2 C++ packages also make heavy use of:

* header files
* `.cpp` files
* namespaces
* CMake
* multiple source files
* compilation and linking

So understanding this structure now will make larger robotics projects much easier to read later.

---

# Day 7 Summary

The main idea is to move from:

```text
Everything in one .cpp
```

to:

```text
Header
    ↓
What the module provides

Source file
    ↓
How it works

Namespace
    ↓
Where its names belong

CMake
    ↓
How the project is built
```

The important concepts from today are:

* Header files
* `.h` / `.hpp` vs `.cpp`
* Declaration vs definition
* `#include`
* Translation units
* `#pragma once`
* Namespaces
* Scope resolution `::`
* One Definition Rule
* Compilation vs linking
* CMake and multi-file projects

---

## Practical Work

The implementation for today's topic has already been completed separately in:

```text
Code_exp1
```

The task was to:

* split the math utility into `.h` and `.cpp`
* use the `robotmath` namespace
* create `robotutils` for string helpers
* use both namespaces from `main.cpp`
* build the project with CMake
* achieve zero warnings

The code is kept separately so this README/learning note focuses on **understanding the concepts rather than duplicating the implementation**.
