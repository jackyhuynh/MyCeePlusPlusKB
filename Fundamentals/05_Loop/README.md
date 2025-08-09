
# Chapter 5: Looping

This chapter introduces loops, a control structure that allows a program to repeat a section of code.

-----

## 5.1 Introduction to Loops: The `while` Loop

A **loop** is a control structure that causes a statement or block of statements to repeat. The `while` loop is a *
*pretest loop**, meaning its condition is checked before each iteration.

### Format

```cpp
while (condition)
{
    // Statements to repeat
}
```

If the condition is initially `false`, the loop body will never execute. If the condition never becomes `false`, you
have an **infinite loop**.

## 5.2 Using the `while` Loop for Input Validation

The `while` loop is perfect for input validation. You can use a loop to keep prompting the user for input until they
enter a value that is within the valid range.

## 5.3 The Increment and Decrement Operators

The increment (`++`) and decrement (`--`) operators add or subtract one from a variable.

* **Prefix mode (`++val`):** Increments/decrements the variable and *then* returns the new value.
* **Postfix mode (`val++`):** Returns the current value of the variable and *then* increments/decrements it.

## 5.4 Counters

A **counter** is a variable that is incremented or decremented during each loop iteration. It is often used to control
how many times a loop repeats.

## 5.5 Keeping a Running Total

An **accumulator** is a variable that keeps a **running total** of a series of numbers. It is initialized to a starting
value (usually zero) before the loop begins, and the values are added to it inside the loop.

## 5.6 Sentinels

A **sentinel** is a special value that marks the end of a list of values. It is used to terminate a loop when the user
doesn't know in advance how many items they will enter.

## 5.7 The `do-while` Loop

The **`do-while`** loop is a **post-test loop**, meaning its condition is checked *after* each iteration. This
guarantees that the loop body will execute at least once.

### Format

```cpp
do
{
    // Statements to repeat
} while (condition);
```

## 5.8 The `for` Loop

The **`for`** loop is ideal for **counter-controlled loops** where the number of iterations is known.

### Format

```cpp
for (initialization; test; update)
{
    // Statements to repeat
}
```

The `initialization` statement runs once before the loop begins. The `test` expression is evaluated before each
iteration. The `update` expression is executed after each iteration.

### Example

```cpp
#include <iostream>

int main()
{
    int sum = 0;
    // Loop from 1 to 10
    for (int num = 1; num <= 10; num++)
    {
        sum += num;
    }
    std::cout << "The sum of numbers from 1 to 10 is: " << sum << std::endl;
    return 0;
}
```

## 5.10 Nested Loops

A **nested loop** is a loop inside another loop. The inner loop completes all of its iterations for each single
iteration of the outer loop.

## 5.11 Breaking Out of a Loop

The `break` statement immediately terminates a loop. The `continue` statement skips the rest of the current loop
iteration and moves to the next one. Both should be used sparingly to avoid making your code hard to follow.

## 5.12 Using Files for Data Storage

You can read from and write to files using file stream objects (`ifstream` for input, `ofstream` for output). This
allows data to persist even after the program has finished.

## Coding Exercises

1. **Sum of Numbers:** Write a program that asks the user for a positive integer and then uses a `for` loop to calculate
   and display the sum of all integers from 1 up to that number.
2. **Multiplication Table:** Use nested `for` loops to generate a multiplication table that displays the products of
   numbers from 1 to 10.
3. **Simple Guessing Game:** Improve the guessing game from the previous chapter by using a `while` loop to allow the
   user to make multiple guesses until they get the correct number.
4. **File Reader:** Write a program that creates a text file named `numbers.txt`, writes five numbers to it, and then
   reads those numbers from the file and calculates their average.