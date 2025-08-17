# Exercises

***

### Exercise 1: Grade Calculator

Write a program that asks the user for a numeric test score. Based on the score, the program should display a letter
grade according to the following scale using an `if/else if` statement:

* 90-100: A
* 80-89: B
* 70-79: C
* 60-69: D
* Below 60: F

---

### Exercise 2: Password Validator

Create a program that prompts the user to enter a password. The program should validate the password based on two
conditions using a nested `if` statement:

1. The password must be exactly 8 characters long.
2. The password must contain at least one digit.

If both conditions are met, print a "Password accepted" message. Otherwise, print "Invalid password."

---

### Exercise 3: Shipping Calculator

Write a program that calculates the total cost of an order, including shipping. The program should get the order total
from the user. Use logical operators to apply the following shipping rules:

* If the order is under $25.00, shipping is $5.00.
* If the order is $25.00 or more, but less than $50.00, shipping is $3.00.
* If the order is $50.00 or more, shipping is free.

Finally, display the shipping cost and the total amount due.

---

### Exercise 4: Simple Menu Program

Create a menu-driven program that uses a `switch` statement. The program should display three options to the user:

1. Print "Hello World!"
2. Print the current year.
3. Exit the program.

The program should read the user's choice and perform the corresponding action. Use the `default` case to handle invalid
input.

---

### Exercise 5: Character Checker

Write a program that reads a single character from the user and determines if it is an uppercase letter, a lowercase
letter, a digit, or something else. You should use functions from the `<cctype>` library such as `isupper`, `islower`,
and `isdigit` within your conditional statements to make the checks.