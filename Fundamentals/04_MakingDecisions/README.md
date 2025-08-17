# Chapter 4: Making Decisions

This chapter covers how to write programs that can make decisions using conditional statements and relational operators.

-----

## 4.1 Relational Operators

Relational operators are used to compare values and create **Boolean** expressions that evaluate to `true` or `false`.

| **Operator** | **Meaning**              |
|:-------------|:-------------------------|
| `>`          | Greater than             |
| `<`          | Less than                |
| `>=`         | Greater than or equal to |
| `<=`         | Less than or equal to    |
| `==`         | Equal to                 |
| `!=`         | Not equal to             |

-----

## 4.2 The `if` Statement

The **`if`** statement allows a program to execute a block of code only if a condition is `true`.

### Format

```cpp
if (condition)
{
    // Statements to execute if condition is true
}
```

-----

## 4.3 The `if/else` Statement

The **`if/else`** statement provides two paths of execution. If the condition is `true`, the `if` block executes. If the
condition is `false`, the `else` block executes.

### Format

```cpp
if (condition)
{
    // Statements for true condition
}
else
{
    // Statements for false condition
}
```

-----

## 4.4 The `if/else if` Statement

This statement is used to handle a series of mutually exclusive conditions. The program checks each condition in order,
executing the first block of code for which the condition is true. An optional trailing `else` can be used to handle a
default case.

### Example

```cpp
#include <iostream>

int main()
{
    int score;
    std::cout << "Enter your test score: ";
    std::cin >> score;

    if (score >= 90)
    {
        std::cout << "Your grade is A." << std::endl;
    }
    else if (score >= 80)
    {
        std::cout << "Your grade is B." << std::endl;
    }
    else if (score >= 70)
    {
        std::cout << "Your grade is C." << std::endl;
    }
    else
    {
        std::cout << "Your grade is F." << std::endl;
    }

    return 0;
}
```

-----

## 4.6 Nested `if` Statements

A **nested `if` statement** is an `if` statement inside another `if` or `else` block. This allows for more complex
decision-making based on multiple conditions.

-----

## 4.7 Logical Operators

Logical operators combine relational expressions.

| **Operator** | **Meaning** | **Example**          |
|:-------------|:------------|:---------------------|
| `&&`         | AND         | `(x > 0) && (y > 0)` |
| `            |             | `                    | OR | `(x > 0) || (y > 0)` |
| `!`          | NOT         | `!(x > 10)`          |

-----

## 4.12 The `switch` Statement

The **`switch`** statement is an alternative to a long chain of `if/else if` statements when you are testing a single
integer or character expression against a series of constant values.

### Format

```cpp
switch (IntExpression)
{
    case exp1:
        // statements
        break;
    case exp2:
        // statements
        break;
    // ...
    default:
        // statements
}
```

The `break` statement is crucial for exiting the `switch` after a case is handled. Without it, the program will fall
through to the next case.

-----

## 4.13 Enumerated Data Types

An **enumerated data type** (or `enum`) is a programmer-defined data type that consists of a set of named integer
constants. It makes code more readable.

```cpp
enum Days { Mon, Tue, Wed, Thur, Fri };
Days workDay = Mon;
```

-----

## Coding Exercises

1. **Leap Year Calculator:** Write a program that asks the user for a year and determines if it is a leap year. A year
   is a leap year if it is divisible by 4, unless it is divisible by 100 but not by 400.
2. **Menu-Driven Calculator:** Create a simple calculator that presents a menu to the user with options for addition,
   subtraction, multiplication, and division. Use a `switch` statement to perform the selected operation and a trailing
   `else` to handle invalid input.
3. **Password Validator:** Write a program that asks the user to enter a password and checks if it meets certain
   criteria, such as a minimum length and containing both uppercase and lowercase letters. Use nested `if` statements or
   logical operators.