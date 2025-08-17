# Chapter 2: Introduction to C++

This chapter dives into the fundamental components of a C++ program, including data types, operators, and comments.

## 2.1 The Parts of a C++ Program

A basic C++ program includes:

* **Comments:** Notes in the code for human readers, ignored by the compiler.
* **Preprocessor Directive:** Instructions for the preprocessor, like `#include <iostream>`.
* **`main` function:** The starting point of every C++ program.
* **Statements:** Instructions that perform actions.

### A Sample Program

```cpp
// This is a single-line comment.
#include <iostream>

/*
This is a multi-line comment.
The program prints a greeting.
*/
int main()
{
    std::cout << "Hello, there!"; // Output statement
    return 0; // Return statement
}
```

## 2.2 The `cout` Object

The `cout` object is used to display output on the screen. The `<<` operator (stream insertion operator) sends data to
`cout`. You can start a new line using `std::endl` or the escape sequence `\n`.

### Escape Sequences

| Escape Sequence | Description    |
|-----------------|----------------|
| `\n`            | Newline        |
| `\t`            | Horizontal tab |
| `\\`            | Backslash      |
| `\"`            | Double quote   |

## 2.4 Variables and the Assignment Statement

A **variable** is a named memory location that stores a value. You must **define** a variable before using it by
specifying its data type and name. The **assignment operator (`=`)** is used to store a value in a variable.

## 2.5 Literals

A **literal** is a piece of data written directly in the source code.

* **Character literal:** `'A'` (single quotes)
* **String literal:** `"Hello"` (double quotes)
* **Integer literal:** `12`
* **Floating-point literal:** `3.14`

## 2.6 Identifiers

**Identifiers** are programmer-defined names for variables, functions, etc. They must start with a letter or an
underscore (`_`), followed by letters, digits, or underscores. They are also case-sensitive.

## 2.7 Integer Data Types

Integer data types are used to store whole numbers. Common types include `short`, `int`, and `long`.

## 2.8 Floating-Point Data Types

Floating-point data types store real numbers with a decimal point. Common types are `float`, `double`, and
`long double`.

## 2.9 The `char` Data Type

The `char` data type stores a single character. The character is internally represented by a numeric code, typically
ASCII.

## 2.10 The C++ `string` Class

The `string` class (requires `#include <string>`) allows you to work with sequences of characters. You can define string
variables, assign values, and print them with `cout`.

## 2.11 The `bool` Data Type

The `bool` data type stores `true` or `false` values, which are internally represented as `1` and `0`, respectively.

## 2.15 Arithmetic Operators

| Symbol | Operation           | Example       |
|:------:|---------------------|---------------|
|  `+`   | Addition            | `num1 + num2` |
|  `-`   | Subtraction         | `num1 - num2` |
|  `*`   | Multiplication      | `num1 * num2` |
|  `/`   | Division            | `num1 / num2` |
|  `%`   | Modulus (remainder) | `num1 % num2` |

Remember that integer division (e.g., `13 / 5`) truncates the result, while floating-point division (e.g., `13 / 5.0`)
produces a decimal result. The modulus operator (`%`) only works with integer operands.

## 2.16 Comments

Comments are essential for documenting your code.

* **Single-line comments:** Begin with `//`.
* **Multi-line comments:** Begin with `/*` and end with `*/`.

## Coding Exercises

1. **Calculate Area:** Write a program that defines two `double` variables for length and width, initializes them,
   calculates the area, and prints the result in a well-formatted sentence.
2. **ASCII Code:** Write a program that defines a `char` variable, assigns it a letter, and then prints the letter and
   its corresponding ASCII integer value.
3. **String Concatenation:** Write a program that uses the C++ `string` class to read a user's first and last name
   separately, and then combines them into a single full name to print a greeting.