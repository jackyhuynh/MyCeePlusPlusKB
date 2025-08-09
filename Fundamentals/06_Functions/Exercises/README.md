# Exercises

***

### Basic Exercises

1. **Greeting Function:** Write a `void` function called `sayHello` that takes a `string` parameter for a person's name
   and prints a greeting message. In your `main` function, call `sayHello` with a name of your choice.

2. **Square a Number:** Write a function called `square` that takes an `int` parameter and returns the square of that
   number as an `int`. In `main`, get a number from the user, call the `square` function, and print the result.

3. **Find the Maximum:** Write a function called `findMax` that takes two `double` parameters and returns the larger of
   the two. Use an `if/else` statement inside the function to determine the maximum value.

4. **Area of a Rectangle:** Write a function called `calculateArea` that takes two `double` parameters for length and
   width. It should return the area of the rectangle as a `double`. Call the function from `main` and display the
   result.

5. **Even or Odd:** Write a function called `isEven` that takes an `int` parameter and returns a `bool` value. The
   function should return `true` if the number is even and `false` if it is odd. Use the modulus operator (`%`) to check
   for evenness.

6. **Celsius to Fahrenheit:** Write a function called `celsiusToFahrenheit` that takes a `double` parameter for a
   temperature in Celsius and returns the equivalent temperature in Fahrenheit. The formula is $F = \frac{9}{5}C + 32$.

7. **Default Arguments:** Create a function called `printMessage` that takes a `string` parameter for a message and an
   `int` parameter for the number of times to print it, with a default value of `1` for the integer. Call the function
   once with only a message and once with both a message and a number of times to print.

***

### Medium Exercises

8. **Pass by Reference:** Create a function called `swapNumbers` that takes two `int` parameters by reference. Inside
   the function, swap the values of the two variables. In `main`, declare two integer variables, print their values,
   call `swapNumbers`, and then print their values again to show that they have been swapped.

9. **Function Overloading:** Write two overloaded functions, both named `add`. The first `add` function should take two
   `int` parameters and return their sum. The second `add` function should take three `int` parameters and return their
   sum. Call both functions from `main` to demonstrate how the compiler chooses the correct function based on the number
   of arguments.

***

### Advanced Exercise

10. **Recursive Factorial:** Write a recursive function called `factorial` that takes a single `int` parameter and
    returns the factorial of that number. A factorial is the product of an integer and all the integers below it (
    e.g., $5! = 5 \times 4 \times 3 \times 2 \times 1$). The base case for the recursion is when the number is 0 or 1,
    in which case the function should return 1. Your `main` function should get a number from the user and call the
    `factorial` function.