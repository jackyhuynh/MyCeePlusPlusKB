# Chapter 1: Introduction to Computers and Programming

This chapter provides a foundational understanding of computer systems, programming, and the process of creating a
program.

## 1.1 Why Program?

At its core, a **computer** is a machine that follows a set of instructions. These instructions, known as a **program**
or **software**, are what allow a computer to perform tasks. Without programs, a computer is just a piece of hardware. A
**programmer** is the person who designs, creates, and tests these programs. Programming is both an art and a science,
requiring an understanding of the language and a knack for organizing tasks and designing user interactions.

## 1.2 Computer Systems: Hardware and Software

A computer system is composed of **hardware** (physical components) and **software** (the programs that run on it).

### Hardware

* **Central Processing Unit (CPU):** The "brain" of the computer. It fetches, decodes, and executes program
  instructions.

* **Main Memory (RAM):** A volatile storage area that holds program instructions and data while the program is running.

* **Secondary Storage:** Non-volatile storage devices (like disk drives or flash drives) that hold data even when the
  computer is off.

* **Input Devices:** Used to send data to the computer (e.g., keyboard, mouse).

* **Output Devices:** Used to display or send data from the computer (e.g., screen, printer).

### Software

* **System Software:** Manages the computer's hardware, like **operating systems** and **utility programs**.

* **Application Software:** The programs that allow users to perform specific tasks.

## 1.3 Programs and Programming Languages

An **algorithm** is a set of well-defined steps to solve a problem. A **programming language** is a special language
used to write a program. C++ is a **high-level language**, which is closer to human language than a low-level language.

The process of turning a C++ program into an executable file involves several steps:

1. **Source Code:** You write your program in a text editor.

2. **Preprocessor:** The preprocessor reads your source code and prepares it for the compiler.

3. **Compiler:** The compiler translates your source code into **machine code** (an object file).

4. **Linker:** The linker links the object file with necessary library code to create the final **executable file**.

## 1.4 What is a Program Made of?

All programs are built from fundamental elements:

* **Key Words:** Words with a special meaning in C++ (e.g., `int`, `return`).

* **Programmer-Defined Identifiers:** Names you create for variables, functions, etc. (e.g., `myVariable`).

* **Operators:** Symbols that perform operations on data (e.g., `+`, `-`, `=`, `*`).

* **Punctuation:** Characters that mark the end of statements or separate items (e.g., `;`, `{}`).

* **Syntax:** The set of rules that must be followed when writing a program.

### Variables

A **variable** is a named location in memory that holds a piece of data. Before you can use a variable, you must *
*define** it by specifying its name and data type.

Here is a simple C++ program that demonstrates these concepts.

```cpp
#include <iostream>

int main()
{
    // A variable definition. 'num1' is the programmer-defined identifier.
    double num1 = 5, num2, sum;

    // The '=' is an assignment operator.
    num2 = 12;

    // The '+' is an arithmetic operator.
    sum = num1 + num2;

    // 'cout' is the standard output object.
    std::cout << "The sum is " << sum << std::endl;

    // 'return' is a keyword.
    return 0;
}
```

## 1.5 Input, Processing, and Output

Most programs follow a three-step process:

1. **Input:** Gather data from the user or a file.

2. **Processing:** Manipulate the data.

3. **Output:** Display the results of the processing.

## 1.6 The Programming Process

The overall process of creating a program is a cycle that involves:

1. Defining the program's purpose.

2. Planning the program's logic (e.g., using pseudocode or flowcharts).

3. Writing the code.

4. Compiling, linking, and testing the program.

5. Fixing any errors that are found.

6. Validating that the program does what it's supposed to do.

## Coding Exercises

1. **Hello, World\!:** Write a program that prints the phrase "Hello, World\!" to the console.

2. **Variable Practice:** Write a program that defines two integer variables, assigns them values, adds them together,
   and prints the sum.

3. **Simple I/O:** Write a program that asks the user to enter their name, stores the name in a string variable, and
   then prints a greeting using the entered name.