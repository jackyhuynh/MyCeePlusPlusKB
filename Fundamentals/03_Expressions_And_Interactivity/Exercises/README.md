# Exercises


### Exercise 1: Unit Conversion

Write a program that converts a user-entered number of inches into centimeters. The program should:
1.  Prompt the user to enter a value in inches.
2.  Read the value into a `double` variable.
3.  Calculate the equivalent length in centimeters (1 inch = 2.54 cm).
4.  Print the original value in inches and the converted value in centimeters, clearly labeled.

---

### Exercise 2: Average Test Scores

Create a program that asks the user to input three test scores. The program should then calculate and display the average of the three scores. Ensure the average is displayed with a decimal point and two decimal places. You will need to include the `<iomanip>` header file and use manipulators like `fixed` and `setprecision`.

---

### Exercise 3: Change Calculator

Write a program that takes a total dollar amount (e.g., $4.78) as input from the user and calculates the number of dollars, quarters, dimes, nickels, and pennies needed to make that amount. For this exercise, you can use a combination of integer division and the modulus operator to solve the problem.

---

### Exercise 4: Random Number Game

Modify the random number program from the chapter to create a simple "Heads or Tails" game. The program should simulate a coin flip and tell the user whether it was heads or tails.
- Use `rand()` to get a random number.
- Use `srand(time(0))` to seed the random number generator so you get different results each time.
- Use the modulus operator to scale the random number so it is either `0` (for heads) or `1` (for tails).

---

### Exercise 5: Quadratic Formula

Write a program that solves for the roots of a quadratic equation using the quadratic formula: $x = \frac{-b \pm \sqrt{b^2 - 4ac}}{2a}$. The program should:
1.  Prompt the user to enter three `double` values for `a`, `b`, and `c`.
2.  Calculate the two roots.
3.  Print the two roots, clearly labeled.

**Hint:** You'll need to use functions from the `<cmath>` library, specifically `sqrt()` and `pow()`. For this exercise, assume the discriminant ($b^2 - 4ac$) is non-negative.