# Arrays and Vectors Exercises

## Exercise 1: Array Basics and Processing

Write a program that demonstrates fundamental array operations:

**Requirements:**
- Create an array of 10 integers
- Use a loop to input values from the user
- Implement functions to:
  - Calculate and return the sum of all elements
  - Calculate and return the average
  - Find and return the largest element
  - Find and return the smallest element
  - Display the array contents
- Handle **off-by-one errors** by ensuring subscripts range from 0 to n-1

**Test your program by:**
- Entering both positive and negative numbers
- Verifying all calculations are correct
- Ensuring no array bounds are violated

---

## Exercise 2: Range-Based For Loop and Array Initialization

Create a program that uses different array initialization techniques and range-based for loops:

**Requirements:**
- Declare and initialize an array of doubles using an initialization list with at least 8 values
- Demonstrate **implicit array sizing** by not specifying the size
- Use a traditional for loop to display elements with their subscripts
- Use a range-based for loop to display all elements
- Use a range-based for loop with a reference variable to multiply each element by 2
- Create a second array with partial initialization (initialize first 5 values, leaving rest as 0)

**Output should show:**
- Original array contents with indices
- Array contents after modification
- The partially initialized array showing zeros for uninitialized elements

---

## Exercise 3: Parallel Arrays for Student Records

Design a program using parallel arrays to manage student information:

**Requirements:**
- Create three parallel arrays:
  - `studentNames` (string array) - holds student names
  - `testScores` (int array) - holds test scores
  - `letterGrades` (char array) - holds letter grades
- Store data for at least 6 students
- Implement functions that accept all three arrays:
  - `calculateGrades()` - assigns letter grades based on scores (90-100: A, 80-89: B, etc.)
  - `displayStudentInfo()` - displays name, score, and grade for all students
  - `findHighestScore()` - returns the name of the student with the highest score
  - `calculateClassAverage()` - returns the average test score

**Test your program by:**
- Populating arrays with sample data
- Displaying all student information in a formatted table
- Showing the highest scoring student and class average

---

## Exercise 4: Two-Dimensional Arrays - Matrix Operations

Implement a program that performs operations on 2D arrays:

**Requirements:**
- Create two 3x3 matrices (two-dimensional arrays) of integers
- Implement functions that:
  - `inputMatrix()` - accepts a 2D array and populates it with user input
  - `displayMatrix()` - displays a 2D array in table format
  - `addMatrices()` - adds two matrices and stores result in a third matrix
  - `findRowSum()` - calculates and returns the sum of a specified row
  - `findColumnSum()` - calculates and returns the sum of a specified column
- Use nested loops to process rows and columns
- Pass the 2D arrays to functions correctly

**Test your program by:**
- Creating and displaying both matrices
- Adding them together and displaying the result
- Calculating and displaying sums for each row and column

---

## Exercise 5: STL Vector Operations

Create a program that demonstrates the flexibility of vectors:

**Requirements:**
- Create an empty vector of doubles
- Implement a menu-driven program with options to:
  - Add a value to the vector using `push_back()`
  - Remove the last value using `pop_back()`
  - Display all elements and the current size using `size()`
  - Calculate and display the sum and average
  - Clear all elements using `clear()`
  - Check if the vector is empty using `empty()`
- Use the `[]` operator to access individual elements
- Handle the case when operations are attempted on an empty vector

**Your program should:**
- Loop until the user chooses to exit
- Display appropriate messages for each operation
- Demonstrate that vectors can grow and shrink dynamically

---

## Exercise 6: Arrays of Objects with typedef

Design a program using arrays of objects to manage inventory:

**Requirements:**
- Create a `Product` class with:
  - Private members: `productName` (string), `price` (double), `quantity` (int)
  - Constructor with default parameters
  - Accessor and mutator methods
  - `displayProduct()` method
  - `getTotalValue()` method (returns price × quantity)
- Use `typedef` to create an alias for the Product array type:
  ```cpp
  typedef Product Inventory[100];
  ```
- Create an array of 5 Product objects
- Initialize the array with an initialization list (use different constructors)
- Implement functions that:
  - Accept the array and display all products
  - Calculate total inventory value across all products
  - Find the most expensive product
- Pass the array to functions using the typedef alias

**Test your program by:**
- Creating products with various prices and quantities
- Displaying the complete inventory
- Showing total inventory value
- Identifying the most expensive item

---

## Bonus Challenge: Combining Concepts

Create a gradebook program that uses both 2D arrays and vectors:

**Requirements:**
- Use a 2D array to store test scores for multiple students and multiple tests
- Use a vector of strings to store student names
- Calculate each student's average
- Calculate the class average for each test
- Find the highest score on each test
- Display all data in a formatted table

This exercise combines multiple concepts from the chapter!
