
# Chapter 3: Expressions and Interactivity

This chapter explores how to interact with the user and perform mathematical calculations using C++.

## 3.1 The `cin` Object

The **`cin`** object is used to read input from the keyboard. The `>>` operator (stream extraction operator) retrieves
data and stores it in a variable. It's good practice to use `cout` to display a prompt to the user before using `cin`.

### Example

```cpp
#include <iostream>

int main()
{
    int height, width;
    std::cout << "Enter the height and width separated by a space: ";
    std::cin >> height >> width; // Reading multiple values
    std::cout << "You entered " << height << " and " << width << std::endl;
    return 0;
}
```

## 3.2 Mathematical Expressions

An **expression** is anything that can be evaluated to produce a value, such as a literal, a variable, or a combination
of them with operators.

### Order of Operations

1. Parentheses `()`
2. Unary negation `-` (right to left)
3. Multiplication `*`, Division `/`, Modulus `%` (left to right)
4. Addition `+`, Subtraction `-` (left to right)

You can use parentheses to override the default order of operations.

## 3.3 Data Type Conversion and Type Casting

When an expression involves operands of different data types, C++ performs automatic type conversion (**coercion**). The
lower-ranked type is promoted to the higher-ranked type. You can also manually convert a data type using a **type cast
**. The modern C++ style is to use `static_cast`.

### Example

```cpp
#include <iostream>

int main()
{
    int sum = 10, count = 3;
    double average;

    // Integer division would result in 3.
    // We use a type cast to ensure floating-point division.
    average = static_cast<double>(sum) / count;

    std::cout << "The average is: " << average << std::endl;
    return 0;
}
```

## 3.4 Overflow and Underflow

**Overflow** occurs when a value is too large to be stored in a variable, while **underflow** occurs when a value is too
close to zero. The result can be unpredictable, so it's important to use appropriately-sized data types.

## 3.5 Named Constants

A **named constant** (declared with the `const` keyword) is a variable whose value cannot be changed after it is
initialized. They make programs more readable and easier to maintain.

```cpp
const double PI = 3.14159;
```

## 3.6 Multiple and Combined Assignment

You can assign a value to multiple variables in a single statement (e.g., `x = y = z = 0;`). You can also use **combined
assignment operators** for shorthand: `+=`, `-=`, `*=`, `/=`, `%=`.

## 3.7 Formatting Output

By including the `<iomanip>` header file, you can control the appearance of your output.

* `setw(x)`: Sets the field width to at least `x` spaces.
* `setprecision(x)`: Sets the number of significant digits or decimal places (when used with `fixed`).
* `fixed`: Displays floating-point numbers in a fixed-point notation.
* `left`, `right`: Justifies the output.

## 3.8 Working with Characters and Strings

You can read single words into a string object using `cin`. For strings that contain spaces, use `getline(cin, str)`.
Similarly, you can read single characters with `cin.get(ch)`.

## 3.9 More Mathematical Library Functions

The `<cmath>` header file provides many useful mathematical functions, such as `sqrt()` (square root) and `pow()` (
power).

## 3.10 Random Numbers

To generate random numbers, you need the `<cstdlib>` and `<ctime>` header files. The `rand()` function returns a random
integer. To get a different sequence of numbers each time, you can seed the generator with `srand(time(0))`. You can
scale the random number to a specific range using the modulus operator.

### Example: Dice Roll

```cpp
#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

int main()
{
    unsigned seed = time(0);
    srand(seed);

    const int SIDES = 6;
    int roll = rand() % SIDES + 1; // Rolls a 6-sided die

    std::cout << "You rolled a " << roll << std::endl;
    return 0;
}
```

## Coding Exercises

1. **Distance Calculation:** Write a program that asks the user for the `x` and `y` coordinates of two points and
   calculates the distance between them using the distance formula: $d = \\sqrt{(x\_2-x\_1)^2 + (y\_2-y\_1)^2}$.
   Remember to use the `pow()` and `sqrt()` functions from `<cmath>`.
2. **Monthly Payments:** Write a program that takes the loan amount, annual interest rate, and number of years as input.
   Calculate and display the monthly payment and total amount paid.
3. **Random Number Game:** Create a simple guessing game where the computer generates a random number between 1 and 100,
   and the user has to guess it. The program should tell the user if their guess is too high or too low.