# Class and Objects Exercises

## Exercise 1: Rectangle Class with Constructors

Create a `Rectangle` class that demonstrates proper class design principles:

**Requirements:**
- Private member variables: `length` and `width` (both `double`)
- Default constructor that initializes both dimensions to 1.0
- Parameterized constructor that accepts length and width
- Accessor methods: `getLength()` and `getWidth()`
- Mutator methods: `setLength()` and `setWidth()` with validation (must be positive)
- Member functions: `getArea()` and `getPerimeter()`
- Destructor that displays a message when the object is destroyed

**Test your class by:**
- Creating objects using both constructors
- Testing all member functions
- Attempting to set invalid dimensions (negative values)

---

## Exercise 2: Bank Account with Private Members

Design a `BankAccount` class that demonstrates data hiding and encapsulation:

**Requirements:**
- Private member variables: `accountNumber` (string), `balance` (double), `accountHolder` (string)
- Constructor that initializes account with account number, holder name, and initial balance
- Public member functions:
  - `deposit(double amount)` - adds to balance, validates amount is positive
  - `withdraw(double amount)` - subtracts from balance, validates sufficient funds
  - `getBalance()` - returns current balance (accessor)
  - `displayAccountInfo()` - shows account details
- Private member function: `isValidAmount(double amount)` - validates transaction amounts

**Test your class by:**
- Creating multiple account objects
- Performing deposits and withdrawals
- Attempting invalid transactions
- Displaying account information

---

## Exercise 3: Student Record with Nested Structures

Create a program using structures to manage student records:

**Requirements:**
- Define a `Date` structure with members: `day`, `month`, `year`
- Define a `Student` structure containing:
  - `name` (string)
  - `studentID` (int)
  - `birthDate` (Date structure)
  - `gpa` (double)
- Implement a constructor for the `Student` structure
- Write functions that:
  - Accept a `const` reference to a `Student` and display all information
  - Accept a `Student` by reference and update the GPA
  - Return a `Student` structure with user-provided data

**Test your program by:**
- Creating an array of at least 3 students
- Displaying all student information
- Updating GPAs for specific students

---

## Exercise 4: Circle Class with Object Composition

Implement object composition by creating classes that work together:

**Requirements:**
- Create a `Point` class:
  - Private members: `x` and `y` coordinates (double)
  - Constructor, getters, and setters
  - `display()` method
- Create a `Circle` class that uses object composition:
  - Private members: `center` (Point object) and `radius` (double)
  - Constructor accepting x, y coordinates and radius
  - Methods: `getArea()`, `getCircumference()`, `displayCircleInfo()`
  - Demonstrate using a `Point` object as a member variable

**Test your classes by:**
- Creating circles at different positions
- Moving circles by updating the center point
- Calculating and displaying area and circumference

---

## Exercise 5: Inventory Item with Enumerated Types

Design an inventory management system using classes and enumerations:

**Requirements:**
- Define an enumerated type `Category` with values: ELECTRONICS, CLOTHING, FOOD, FURNITURE
- Create an `InventoryItem` class:
  - Private members: `itemName` (string), `itemCategory` (Category), `quantity` (int), `price` (double)
  - Constructor with member initialization list
  - Methods to add/remove stock with validation
  - `getInventoryValue()` - returns quantity × price
  - `displayItem()` - shows all item details including category name
- Implement a function that accepts the category as an `int` using `static_cast`

**Test your class by:**
- Creating items of different categories
- Adding and removing stock
- Calculating total inventory value
- Converting between enum and int types

---

## Exercise 6: Multi-File Class Organization

Reorganize one of the previous exercises using proper file separation:

**Requirements:**
- Choose either the Rectangle (Exercise 1) or BankAccount (Exercise 2) class
- Create three files:
  - Header file (`.h`): Class declaration with include guards
  - Implementation file (`.cpp`): Member function definitions
  - Driver program (`.cpp`): Client code that uses the class
- Properly use the scope resolution operator (`::`)
- Include appropriate `#include` directives
- Compile and link all files together

**Compilation command:**
```bash
g++ -std=c++17 ClassName.cpp driver.cpp -o program
```

**Demonstrate:**
- Proper use of include guards
- Separation of interface and implementation
- Creating and using objects from the main program
- Successful compilation and execution
