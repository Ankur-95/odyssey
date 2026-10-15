# Day 9 — Debugging and Error Reading in C++

## 1. What Is Debugging?

Debugging is the process of identifying, understanding, and fixing errors in a program.

A program can compile successfully and still produce incorrect results, crash unexpectedly, or access memory it should not access.

There are three broad categories of problems:

| Error type | Meaning | Example |
|---|---|---|
| Compile-time error | The compiler cannot compile the program. | Passing a `std::string` to a function expecting an `int`. |
| Runtime error | Something goes wrong while the program executes. | Accessing invalid memory and triggering a crash. |
| Logical error | The program runs but produces an incorrect result. | Using subtraction when the calculation requires addition. |

For example:

```cpp
int calculate(int a, int b)
{
    return a - b;
}
```

If this function is intended to calculate a sum, it contains a logical error even though the compiler reports no problem.

**Important:** A compiler checks whether code satisfies language rules. It does not guarantee that your program implements the intended behavior.

## 2. Reading Compiler Errors

The compiler translates C++ source code into machine code. During this process, it checks syntax, types, declarations, and other language rules.

When compilation fails, the compiler produces diagnostic messages. Learning to interpret these messages is one of the most useful programming skills you can develop.

### Example: Type Mismatch

```cpp
#include <iostream>

int main()
{
    int angle = "90";
    std::cout << angle << '\n';
    return 0;
}
```

Compile it:

```bash
g++ -std=c++17 -Wall -Wextra -g main.cpp -o main
```

The compiler reports an error because a string literal cannot be converted directly to an integer.

- `int` represents an integer value.
- `"90"` is a string literal, not an integer.
- `90` without quotation marks is an integer literal.

The correction is:

```cpp
int angle = 90;
```

### How to Interpret an Error Message

When you encounter a compiler error, look for these details:

1. **File and line number:** Where the compiler detected the problem.
2. **Error description:** What rule was violated.
3. **Relevant types or declarations:** Which types or names are incompatible.
4. **Earlier diagnostics:** Whether another error caused the current one.

The reported line is where the compiler detected a problem, but the underlying cause may be earlier in the code. For example, a missing brace or semicolon can cause several misleading errors later.

### Errors Versus Warnings

An **error** generally prevents compilation from completing successfully. A **warning** indicates suspicious or potentially unintended code that the compiler can still compile.

If a variable is declared but never used, the compiler may warn about it depending on the compiler and warning settings.

Compile with useful warnings enabled:

```bash
g++ -std=c++17 -Wall -Wextra -Wpedantic -g main.cpp -o main
```

- `-Wall`: Enables many common warnings.
- `-Wextra`: Enables additional warnings.
- `-Wpedantic`: Warns about certain non-standard language extensions.
- `-g`: Adds debugging information for tools such as GDB.

Warnings are worth investigating even when the program compiles successfully.

## 3. Understanding GDB

GDB stands for **GNU Debugger**. It lets you pause a program while it runs, inspect its state, and execute instructions one at a time.

Without a debugger, you might print variables throughout your code and repeatedly run the program. With GDB, you can stop at a particular line, examine values, follow function calls, and investigate where behavior becomes incorrect.

### Step 1: Compile with Debugging Information

Suppose you have `main.cpp`.

```bash
g++ -std=c++17 -g -O0 main.cpp -o main
```

- `-g` includes debugging symbols.
- `-O0` disables optimization, making source-level debugging easier.
- `-o main` names the executable `main`.

### Step 2: Start GDB

```bash
gdb ./main
```

Inside GDB, run the program with:

```gdb
run
```

Leave GDB using:

```gdb
quit
```

### Step 3: Set Breakpoints

A **breakpoint** tells the debugger to pause execution at a particular location.

```gdb
break main
```

You can also specify a function or line number:

```gdb
break calculate
break main.cpp:12
```

Useful commands:

| Command | Purpose |
|---|---|
| `break main` | Pause at `main()`. |
| `info breakpoints` | List existing breakpoints. |
| `delete 1` | Delete breakpoint number 1. |
| `disable 1` | Temporarily disable breakpoint number 1. |
| `continue` | Resume execution until the next breakpoint or stop. |

A breakpoint does not fix a bug. It gives you a controlled point from which to investigate it.

### Step 4: Step Through the Code

Consider this program:

```cpp
#include <iostream>

int calculate(int a, int b)
{
    int result = a + b;
    return result;
}

int main()
{
    int x = 10;
    int y = 5;

    int answer = calculate(x, y);

    std::cout << answer << '\n';
    return 0;
}
```

Save it as `main.cpp`, compile it with debugging symbols, and start GDB.

```gdb
break main
run
```

Use these commands:

| Command | Behavior |
|---|---|
| `next` or `n` | Execute the next source line without stepping into a called function. |
| `step` or `s` | Execute the next source line, entering a function call when possible. |
| `finish` | Continue until the current function returns. |
| `continue` or `c` | Continue running until the next breakpoint or another stopping condition. |

**The key difference between `next` and `step`:**

Suppose the current line is:

```cpp
int answer = calculate(x, y);
```

- Using `next` executes the call and pauses at the following source line.
- Using `step` enters `calculate()` so you can inspect its execution.

Use `step` when you suspect a problem inside a function. Use `next` when you want to treat the function as one operation and inspect what happens afterward.

### Step 5: Inspect Variables

While execution is paused, examine values:

```gdb
print x
print y
print answer
```

You can also inspect local variables in the current function:

```gdb
info locals
```

For the example, you can verify that `x` is `10`, `y` is `5`, and the returned value is `15`.

This helps answer questions such as:

- Did the function receive the expected arguments?
- Did a calculation produce the expected intermediate value?
- Did a variable change before the problem appeared?

A local variable might not yet have been initialized when you inspect it. Do not assume its value is meaningful until execution has reached the appropriate statement.

## 4. Stack Traces and Stack Frames

When a program crashes or produces an unexpected result inside a deeply nested function call, you need to understand how execution reached that point.

Consider:

```cpp
void moveJoint()
{
    // Joint movement logic
}

void executeCommand()
{
    moveJoint();
}

int main()
{
    executeCommand();
}
```

The sequence of calls is:

```text
main()
  └── executeCommand()
        └── moveJoint()
```

Each active function call has a corresponding **stack frame**, which contains information about that call, such as its local variables and execution context.

In GDB, run:

```gdb
backtrace
```

Or use the shorter form:

```gdb
bt
```

The backtrace shows the active call stack. It helps you identify the sequence of function calls leading to the current location.

Other useful commands:

```gdb
frame 1
info locals
```

- `frame 1` selects stack frame number 1.
- `info locals` displays local variables belonging to the selected frame.

Frame numbering typically starts at `0` for the currently executing function, with higher numbers representing its callers.

**Why this matters in robotics:** A failure may occur inside a low-level function even though the incorrect input originated in a higher-level controller. A stack trace helps you follow the path from the failure back toward its source.

## 5. Watchpoints: Finding Where a Variable Changes

A breakpoint stops execution when a location is reached. A **watchpoint** stops execution when a watched expression changes or otherwise satisfies its configured condition.

Consider:

```cpp
int main()
{
    int position = 0;

    position = 10;
    position = 25;
    position = 40;

    return 0;
}
```

Suppose you do not know which statement unexpectedly changes `position`.

Compile with debugging information and start GDB. Then:

```gdb
break main
run
```

Once `position` has been initialized, set the watchpoint:

```gdb
watch position
continue
```

GDB pauses when the watched value changes. Inspect the current value:

```gdb
print position
backtrace
```

Continue again to observe later changes.

A watchpoint is particularly useful when a variable is modified in several places, including through function calls.

### Important Limitations

- Set a watchpoint only after the variable exists and has been initialized.
- Hardware watchpoints have limited resources on many systems.
- GDB may use software watchpoints in some situations, which can be considerably slower.
- A normal watchpoint tracks changes in value. It might not stop if a variable is written with the same value it already holds.

For example, `watch position` tracks value changes, whereas `awatch position` can stop on reads or writes, subject to debugger and target support.

## 6. Runtime Memory Errors and AddressSanitizer

C++ allows direct access to memory, which provides flexibility but also creates opportunities for serious bugs.

One common problem is **out-of-bounds access**: reading or writing an array element outside its valid range.

Consider:

```cpp
#include <iostream>

int main()
{
    int angles[3] = {10, 20, 30};

    for (int i = 0; i <= 3; ++i)
    {
        std::cout << angles[i] << '\n';
    }

    return 0;
}
```

The valid indices are `0`, `1`, and `2`.

However, the condition `i <= 3` also permits `i == 3`. That accesses `angles[3]`, which is outside the array.

The bug is the loop condition. It should be:

```cpp
for (int i = 0; i < 3; ++i)
```

### Why Is Out-of-Bounds Access Dangerous?

The program might:

- Print a seemingly random value.
- Appear to work correctly.
- Produce incorrect results elsewhere.
- Crash immediately or later.

This is **undefined behavior**. The C++ language does not guarantee what happens when a program performs an operation with undefined behavior.

A crash is not required for a memory bug to exist.

### Detecting the Bug with AddressSanitizer

AddressSanitizer (ASan) is a runtime memory-error detection tool supported by GCC and Clang.

Compile the faulty example using:

```bash
g++ -std=c++17 -g -O0 -fsanitize=address -fno-omit-frame-pointer main.cpp -o main
```

Then execute it:

```bash
./main
```

AddressSanitizer should report the invalid access when it detects it. The report typically includes:

- **Error category:** For example, `stack-buffer-overflow`.
- **Source location:** The line associated with the invalid access.
- **Stack trace:** The function-call path.
- **Memory details:** Information about the invalid memory region and nearby object boundaries.

The exact report depends on the compiler, operating system, and runtime environment.

### What Does Each Compiler Flag Do?

| Flag | Purpose |
|---|---|
| `-g` | Adds debugging information. |
| `-O0` | Disables optimization for easier debugging. |
| `-fsanitize=address` | Instruments code to detect many memory errors at runtime. |
| `-fno-omit-frame-pointer` | Helps preserve useful stack-frame information for diagnostics. |

AddressSanitizer detects many memory errors, but it does not detect every possible bug. It also cannot replace careful reasoning about program behavior.

## 7. GDB vs. AddressSanitizer vs. Compiler Diagnostics

These tools solve related but different problems.

| Tool | Best used for | Example |
|---|---|---|
| Compiler diagnostics | Problems detected during compilation | Incorrect argument type |
| GDB | Investigating program execution | A variable unexpectedly becomes `0` |
| AddressSanitizer | Detecting many runtime memory errors | Out-of-bounds array access |

They can also be used together.

For example, if a robotics program produces an incorrect joint angle:

1. Read the compiler warnings and verify the types.
2. Use GDB to inspect the angle before and after the relevant function.
3. Set a watchpoint if the value changes unexpectedly.
4. Use AddressSanitizer if you suspect invalid memory access.

Not every bug requires all three tools. Choose the tool based on the evidence you have.

## 8. A Practical Debugging Workflow

When a program misbehaves, follow this sequence.

### Step 1: Read the Diagnostics

Understand the first meaningful compiler error or warning. Avoid making random changes.

### Step 2: Reproduce the Problem

Run the program and identify the incorrect output, crash, or unexpected behavior.

### Step 3: Pause Execution

Set a breakpoint near the suspicious function or statement.

### Step 4: Inspect the Program State

Use `print`, `info locals`, `step`, `next`, and `backtrace` to investigate.

### Step 5: Fix and Verify

Correct the cause, rebuild, and rerun the program to check that the bug is gone.

**Important rule:** Do not stop at the first line that looks suspicious. Find the cause of the incorrect behavior. A crash location, for example, may be different from the location where invalid data was first introduced.

## 9. Quick Reference: Essential Commands

| Command | Meaning |
|---|---|
| `g++ -g -O0 main.cpp -o main` | Compile with debugging information |
| `gdb ./main` | Start GDB |
| `break main` | Set a breakpoint |
| `run` | Start the program |
| `next` | Execute the next source line without entering a function |
| `step` | Step into a function call |
| `continue` | Resume execution |
| `finish` | Run until the current function returns |
| `print variable` | Inspect a variable or expression |
| `info locals` | Inspect local variables |
| `backtrace` | Display the call stack |
| `frame 1` | Select stack frame 1 |
| `watch variable` | Stop when the variable's value changes |
| `info breakpoints` | List breakpoints and watchpoints |
| `quit` | Exit GDB |

## 10. Practical Exercise

Use a C++ program from Days 1–8. Identify three bugs using debugging tools rather than guessing at corrections.

### Bug 1 — Compile-Time Error

Introduce a type mismatch. Read the compiler diagnostic, identify the incompatible types, and fix the actual cause.

### Bug 2 — Memory Error

Introduce an out-of-bounds array access. Compile with AddressSanitizer, reproduce the issue, and interpret the report.

### Bug 3 — Unexpected Variable Change

Make a variable change incorrectly inside a function or through an incorrect assignment. Use a breakpoint, stepping, and a watchpoint to locate the responsible statement.

## Key Takeaways

- Compiler errors explain why code cannot be compiled; warnings highlight potentially problematic code.
- Breakpoints control where execution pauses.
- `step` enters functions, while `next` normally executes a call without entering it.
- Stack traces reveal the function-call path.
- Watchpoints help identify unexpected changes to variables.
- AddressSanitizer detects many runtime memory errors.
- A program that compiles and runs is not necessarily correct.

**The goal of Day 9 is not to memorize GDB commands. It is to learn how to investigate a problem systematically and gather evidence before changing your code.**