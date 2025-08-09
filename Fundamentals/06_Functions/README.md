# Chapter 6: Functions

This chapter introduces functions, a powerful tool for organizing and reusing code.

-----

## 6.1 Modular Programming

**Modular programming** is the practice of breaking a program into smaller, manageable functions or modules. This
approach simplifies program development, makes code more readable, and improves maintainability.

-----

## 6.2 Defining and Calling Functions

A **function definition** contains the code that makes up the function. A **function call** is a statement that causes a
function to execute.

### Function Definition Structure

* **Return type:** The data type of the value the function returns. `void` is used if the function doesn't return a
  value.
* **Name:** The function's name.
* **Parameter list:** A list of variables that hold the values passed to the function.
* **Body:** The statements that perform the function's task.

### Example

```cpp
#include <iostream>

// Function definition
void sayHello()
{
    std::cout << "Hello!" << std::endl;
}

int main()
{
    sayHello(); // Function call
    return 0;
}
```

-----

## 6.3 Function Prototypes

A **function prototype** is a declaration that tells the compiler about a function before it is called. It includes the
return type, name, and parameter data types.

`void sayHello();`

Prototypes are typically placed at the top of the program.

-----

## 6.4 Sending Data into a Function (Pass by Value)

Data can be passed to a function as **arguments**. The function's **parameters** hold the values of these arguments. In
**pass by value**, a copy of the argument's value is sent to the function. This means the original argument in the
calling function cannot be changed.

### Example

```cpp
// Function that takes an integer parameter
void doubleNumber(int num)
{
    num *= 2; // Changes the local copy, not the original
    std::cout << "Inside function: " << num << std::endl;
}

int main()
{
    int value = 10;
    doubleNumber(value);
    std::cout << "Outside function: " << value << std::endl; // Still 10
    return 0;
}
```

-----

## 6.7 Returning a Value from a Function

A function can return a value using the `return` statement. The function's return type must match the type of the value
being returned.

-----

## 6.10 Local and Global Variables

* **Local variables:** Defined inside a function and are only accessible within that function.
* **Global variables:** Defined outside all functions and are accessible to all functions. Global variables should be
  used sparingly as they can make programs harder to debug and maintain. Global constants, however, are a safe and
  useful alternative.

-----

## 6.11 Static Local Variables

A **`static` local variable** is initialized only once and retains its value between function calls.

-----

## 6.12 Default Arguments

You can provide default values for function parameters in the function prototype. If an argument is omitted during a
function call, the default value is used.

-----

## 6.13 Using Reference Variables as Parameters (Pass by Reference)

By using a **reference variable** (`&`) as a parameter, you can pass an argument **by reference**. This means the
function works with the original variable, not a copy, and can modify the original value.

### Example

```cpp
// Pass by reference
void doubleByRef(int &num)
{
    num *= 2; // Changes the original variable
}

int main()
{
    int value = 10;
    doubleByRef(value);
    std::cout << "Value is now: " << value << std::endl; // Now 20
    return 0;
}
```

-----

## 6.14 Overloading Functions

**Overloading** allows you to have multiple functions with the same name, as long as they have different **signatures
** (different number or types of parameters).

-----

## 6.15 The `exit()` Function

The **`exit()`** function (from `<cstdlib>`) immediately terminates the program. It's typically used for abnormal
program termination.

-----

## 6.16 Stubs and Drivers

**Stubs** and **drivers** are dummy functions used during program development to test other functions before the entire
program is complete.

-----

## Coding Exercises

1. **Function for Calculation:** Write a function that takes two `double` parameters, calculates their average, and
   returns the result. Call this function from `main` and print the returned value.
2. **Pass by Reference:** Create a function that takes an integer variable as a reference parameter. Inside the
   function, ask the user to input a new value and store it in the parameter. Call this function from `main` to see how
   the original variable is changed.
3. **Overloaded Functions:** Write two overloaded functions named `calcArea`. One should take a single `double`
   parameter (radius) and calculate the area of a circle. The other should take two `double` parameters (length, width)
   and calculate the area of a rectangle.