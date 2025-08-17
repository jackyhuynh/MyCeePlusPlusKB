# Exercises

### Exercise 1: The "Name Tag" Program

Your first task is to write a simple program that prints your name and a short bio. You should use at least two separate
`cout` statements and at least one escape sequence (`\n` or `\t`) to format your output on different lines.

**Example Output:**

```
My name is John Doe.
My favorite subject is C++.
```

-----

### Exercise 2: Variable Declarations

Write a program that defines and initializes several variables. You should declare one variable for each of the
following data types:

- an integer `int`
- a floating-point number `double`
- a single character `char`
- a boolean `bool`
- a string `string`

Assign an appropriate literal value to each variable when you define it. Finally, print the value of each variable to
the console.

**Code Snippet:**

```cpp
#include <iostream>
#include <string>

int main() {
    // Define and initialize your variables here
    // ...

    // Print the variables here
    // ...

    return 0;
}
```

-----

### Exercise 3: Simple Calculation

Create a program that asks the user to enter two whole numbers. The program should then calculate and print the sum,
difference, product, and average of those two numbers. Make sure your output is clearly labeled so the user knows which
number is which.

**Hint:** Remember that integer division truncates the decimal part. You might need to consider data types carefully to
get the correct average.

-----

### Exercise 4: Personal Greeting

Write a program that prompts the user for their first name and their age. Store the first name in a `string` variable
and the age in an `int` variable. The program should then print a personalized greeting that includes both the user's
name and age.

**Example Interaction:**

```
What is your name?
Alice
How old are you?
25
Hello, Alice! You are 25 years old.
```

-----

### Exercise 5: The `sizeof` Operator

This exercise will help you understand how much memory different data types use. Write a program that uses the `sizeof`
operator to determine the size in bytes of the following data types: `int`, `double`, `char`, and `bool`. Print the
results to the console, clearly stating which size corresponds to which data type.

**Example Output:**

```
Size of int: 4 bytes
Size of double: 8 bytes
...
```