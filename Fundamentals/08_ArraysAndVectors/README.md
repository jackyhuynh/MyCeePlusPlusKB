# Chapter 8: Arrays and Vectors

This chapter introduces **arrays** and **vectors**, which are data structures used to hold multiple values of the same
type.

---

## 8.1 Arrays

An **array** is a variable that can store multiple values of the same data type in a series of consecutive memory
locations. They're declared using the square bracket (`[]`) operator. The number of elements in an array is specified by
a **size declarator**. The total memory allocated for an array is calculated by multiplying the number of elements by
the number of bytes required for each element.

## 8.2 Accessing Array Elements

Each element in an array is accessed using a **subscript**. Array subscripts start at **0**. The first element of an
array has a subscript of 0, the second has a subscript of 1, and so on. Array elements, when accessed with their
subscript, can be used just like regular variables. An array subscript can be an integer constant, an integer variable,
or an integer expression.

When working with arrays, it's important to be aware of **no bounds checking**. C++ does not check if an array subscript
is within the valid range. Using an invalid subscript can cause a program to overwrite other memory. This can lead to *
*off-by-one errors**, which occur when a program accesses data one position beyond the end of the array or misses the
first or last element. If an array has a size of *n*, the valid subscripts range from 0 to *n*-1.

## 8.3 Inputting and Displaying Array Contents

You can use `cin` and `cout` to store values into and display values from an array. A `for` loop is commonly used to
process all elements of an array, using the loop control variable as the array subscript.

## 8.4 Array Initialization

Arrays can be initialized at the time of definition using an **initialization list**, which is a comma-separated list of
values inside curly braces `{}`. If an array is initialized with fewer values than its declared size, the remaining
elements are automatically set to 0 (for numeric types) or the empty string (for strings).

Alternatively, you can use **implicit array sizing** where C++ automatically determines the array size based on the
number of values in the initialization list.

## 8.5 The Range-Based for Loop

Introduced in C++ 11, the **range-based for loop** simplifies iterating through all elements of an array without using a
subscript. The loop variable holds a copy of each array element for each iteration. To modify the array's contents, the
loop variable must be a reference variable. A range-based for loop is a simpler way to process an entire array but it
doesn't provide access to the element subscripts.

## 8.6 Processing Array Contents

Array elements can be used in arithmetic operations, relational expressions, and other operations just like ordinary
variables. When using increment (`++`) or decrement (`--`) operators, it's important not to confuse the element with the
subscript.

You can't copy one array to another using a single assignment statement. Instead, you must use a loop to copy each
element individually. Similarly, you can't compare two entire arrays in a single expression; you must compare them
element by element, often with a loop and a `bool` variable.

You can use a loop to find the **sum** or **average** of array elements. A loop can also be used to find the **largest**
or **smallest** element in an array by comparing each element to a variable that stores the current largest or smallest
value.

## 8.7 Using Parallel Arrays

**Parallel arrays** are two or more arrays that contain related data. The relationship between the data is maintained by
using the same subscript to access corresponding elements across the arrays. Parallel arrays don't need to hold the same
data type. For example, one array might hold student names (`string`), and a parallel array could hold their grades (
`float`).

## 8.8 The typedef Statement

The **`typedef`** statement creates an alias for an existing data type. This can make code more readable and simplifies
the notation for complex data types, such as arrays. The format is `typedef existingType newName;`.

## 8.9 Arrays as Function Arguments

Passing a single array element to a function is the same as passing a regular variable of that type. To pass an entire
array to a function, you pass the array name as the argument. In the function prototype and header, an empty set of
square brackets (`[]`) indicates an array parameter. It's also common to pass the array size as a separate argument so
the function knows how many elements to process.

When an array is passed to a function, changes made to the array inside the function affect the original array in the
calling function. The **`const`** keyword can be used in the function prototype and header to prevent an array from
being inadvertently changed.

## 8.10 Two-Dimensional Arrays

A **two-dimensional array** can store multiple sets of data, similar to a table or spreadsheet. You use two size
declarators in the definition, one for the number of rows and one for the number of columns. To access an element, you
use two subscripts: the first for the row and the second for the column. Two-dimensional arrays are initialized row by
row.

## 8.11 Arrays with Three or More Dimensions

Arrays can have any number of dimensions. When passing a multi-dimensional array to a function, you must specify the
size of all dimensions except for the first one.

## 8.12 Introduction to the STL Vector

The **Standard Template Library (STL) vector** is a container that holds a sequence of elements, similar to a
one-dimensional array. A key difference is that a vector's size is flexible, allowing it to grow and shrink as needed,
so you don't need to specify its size when you define it. You must include the `<vector>` header to use vectors.

Vectors can hold elements of any data type, which is specified inside angle brackets `< >`. You can access individual
elements using the `[]` operator.

Vectors have member functions to manage their size and contents:

* **`push_back`**: Adds an element to the end of the vector.
* **`size`**: Returns the number of elements currently in the vector.
* **`pop_back`**: Removes the last element from the vector.
* **`clear`**: Removes all elements from the vector.
* **`empty`**: Returns a boolean value indicating if the vector is empty.

## 8.13 Arrays of Objects

Arrays can hold objects and structures as their elements. An array of structures can be used as an alternative to
parallel arrays. You use the array subscript to access a specific object or structure in the array, and then use the dot
operator to access its members or member functions.

When initializing an array of objects, you can use a default constructor or provide specific values with an
initialization list. If the initialization list is shorter than the array size, the default constructor is used for the
remaining objects.