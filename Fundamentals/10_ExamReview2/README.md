# C++ Fundamentals Review Questions - Exam2 Review

## Arrays - Declaration and Initialization

**Question 1:** Write the declaration for an array called `int_values` to hold 15 integer values. Write the code required to set all the array elements to -1 (you must use a loop).

**Question 2:** Declare an array called `temperatures` that can store 30 double values. Initialize all elements to 98.6 using a loop.

**Question 3:** Create an array named `scores` to hold 50 integer values. Write a loop to initialize all elements to their index number (element 0 gets value 0, element 1 gets value 1, etc.).

---

## Functions with Arrays

**Question 4:** Write a value-returning function that receives an array of double values and the array size as parameters and returns the sum of all elements in the array.

**Question 5:** Write a function that receives an array of integer values and the array size as parameters and returns a count of the number of elements that are greater than 100.

**Question 6:** Create a function that takes an array of integers and its size as parameters and returns the average of all elements. The function should return a double value.

---

## Struct Declarations

**Question 7:** Write a struct declaration for `Book` which has four elements: a string for title, a string for author, an integer for pages, and a double for price. Then write the declaration for a structure variable of type `Book`, using an initialization list to initialize the members.

**Question 8:** Write a struct declaration for `Student` which has three elements: a string for name, an integer for student ID, and a double for GPA. Then declare a variable of type `Student` and initialize it using an initialization list.

**Question 9:** Create a struct called `Rectangle` with two integer members: length and width. Declare a variable of type `Rectangle` and initialize both members to 10 using an initialization list.

---

## Class Member Functions

**Question 10:** Given the following partially complete class `BankAccount`, write two member functions associated with the `balance` member variable. One to get the account balance and one to set the account balance. The set function should contain a parameter that is passed a new value. If the passed balance is negative, set it to zero.

```cpp
class BankAccount
{
private:
    string accountNumber;
    string owner;
    double balance;
public:
    BankAccount()
    {
        accountNumber = "";
        owner = "";
        balance = 0.0;
    }
};
```

**Question 11:** Given the following Circle class, write two member functions for the `radius` member variable. One getter function to retrieve the radius and one setter function to set the radius. The setter should only accept positive values; if a negative or zero value is passed, set radius to 1.0.

```cpp
class Circle
{
private:
    double radius;
    string color;
public:
    Circle()
    {
        radius = 1.0;
        color = "red";
    }
};
```

---

## Arrays of Objects

**Question 12:** Given the following Car class, write C++ code to create an array of 15 occurrences of the class. Then, set the mileage of the first car occurrence in the array to 50000.

```cpp
class Car
{
private:
    string make;
    string model;
    int year;
    double mileage;
public:
    Car()
    {
        make = "";
        model = "";
        year = 2000;
        mileage = 0.0;
    }
    void setMileage(double m)
    {
        mileage = m;
    }
};
```

**Question 13:** Given the following Employee class, write code to create an array of 100 occurrences of the class. Then, set the salary of the tenth employee in the array to 75000.

```cpp
class Employee
{
private:
    int employeeID;
    string department;
    double salary;
public:
    Employee()
    {
        employeeID = 0;
        department = "";
        salary = 0.0;
    }
    void setSalary(double s)
    {
        salary = s;
    }
};
```

---

## Searching Algorithms

**Question 14:** Assume a string array called `cities` already exists containing 40 unsorted city names. Write code to perform a linear search for the city "Boston". Display the message "City found" if the city was found in the list. Otherwise display "City not found". You do not need to write an entire program.

**Question 15:** Assume an integer array called `ids` already exists containing 100 sorted employee ID numbers. Write code to perform a binary search for the ID number 5550. Display "ID exists" if found, otherwise display "ID does not exist". You do not need to write an entire program.

---

## Array Copying

**Question 16:** The arrays `source` and `destination` each hold 30 double elements. Write code that copies the values in `source` to `destination`.

**Question 17:** Two integer arrays `original` and `backup` each contain 100 elements. Write a loop that copies all values from `original` to `backup` in reverse order (the last element of `original` should be the first element of `backup`).

---

## Code Tracing - Classes

**Question 18:** What will the following program code display on the screen:

```cpp
class Container
{
private:
    int capacity;
public:
    Container()
    { capacity = 10; }
    Container(int c)
    { capacity = c; }
    int getCapacity()
    { return capacity; }
};

int main ()
{
    Container container1, container2(25), container3(40);
    cout << container1.getCapacity() << endl;
    cout << container2.getCapacity() << endl;
    cout << container3.getCapacity() << endl;
}
```

**Question 19:** What will the following program code display on the screen:

```cpp
class Counter
{
private:
    int count;
public:
    Counter()
    { count = 0; }
    Counter(int c)
    { count = c; }
    void increment()
    { count++; }
    int getCount()
    { return count; }
};

int main ()
{
    Counter c1, c2(5);
    c1.increment();
    c1.increment();
    c2.increment();
    cout << c1.getCount() << endl;
    cout << c2.getCount() << endl;
}
```

---

## Sorting Algorithms

**Question 20:** The following code appears in a selection sort function. Will this function sort in increasing order (smallest first) or decreasing order (largest first)? Explain your answer.

```cpp
if (list[index] > list[minIndex])
{
    minIndex = index;
}
```

**Question 21:** The following code appears in a bubble sort function. Will this function sort in increasing order (smallest first) or decreasing order (largest first)? Explain your answer.

```cpp
if (list[index] > list[index + 1])
{
    temp = list[index];
    list[index] = list[index + 1];
    list[index + 1] = temp;
}
```
