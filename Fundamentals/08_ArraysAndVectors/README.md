# Chapter 8: Arrays and Vectors

This chapter introduces **arrays** and **vectors**, which are data structures used to hold multiple values of the same
type.

---

## 8.1 Arrays

An **array** is a variable that can store multiple values of the same data type in a series of consecutive memory
locations. They're declared using the square bracket (`[]`) operator. The number of elements in an array is specified by
a **size declarator**. The total memory allocated for an array is calculated by multiplying the number of elements by
the number of bytes required for each element.

```cpp
// Array declaration
int scores[5];           // Array of 5 integers
double temperatures[7];  // Array of 7 doubles
string names[10];        // Array of 10 strings

// Memory allocation: 5 elements * 4 bytes (int) = 20 bytes
const int SIZE = 5;
int values[SIZE];
```

## 8.2 Accessing Array Elements

Each element in an array is accessed using a **subscript**. Array subscripts start at **0**. The first element of an
array has a subscript of 0, the second has a subscript of 1, and so on. Array elements, when accessed with their
subscript, can be used just like regular variables. An array subscript can be an integer constant, an integer variable,
or an integer expression.

When working with arrays, it's important to be aware of **no bounds checking**. C++ does not check if an array subscript
is within the valid range. Using an invalid subscript can cause a program to overwrite other memory. This can lead to *
*off-by-one errors**, which occur when a program accesses data one position beyond the end of the array or misses the
first or last element. If an array has a size of *n*, the valid subscripts range from 0 to *n*-1.

```cpp
int scores[5];

// Accessing with integer constant
scores[0] = 85;  // First element
scores[4] = 92;  // Last element (index 4, not 5!)

// Accessing with variable
int index = 2;
scores[index] = 78;

// Accessing with expression
scores[index + 1] = 88;

// NO BOUNDS CHECKING - Dangerous!
scores[5] = 100;   // ERROR: Out of bounds (valid: 0-4)
scores[-1] = 50;   // ERROR: Negative subscript
```

## 8.3 Inputting and Displaying Array Contents

You can use `cin` and `cout` to store values into and display values from an array. A `for` loop is commonly used to
process all elements of an array, using the loop control variable as the array subscript.

```cpp
const int SIZE = 5;
int numbers[SIZE];

// Input values into array
cout << "Enter " << SIZE << " numbers:\n";
for (int i = 0; i < SIZE; i++) {
    cout << "Number " << (i + 1) << ": ";
    cin >> numbers[i];
}

// Display array contents
cout << "\nYou entered:\n";
for (int i = 0; i < SIZE; i++) {
    cout << "numbers[" << i << "] = " << numbers[i] << endl;
}
```

## 8.4 Array Initialization

Arrays can be initialized at the time of definition using an **initialization list**, which is a comma-separated list of
values inside curly braces `{}`. If an array is initialized with fewer values than its declared size, the remaining
elements are automatically set to 0 (for numeric types) or the empty string (for strings).

Alternatively, you can use **implicit array sizing** where C++ automatically determines the array size based on the
number of values in the initialization list.

```cpp
// Full initialization
int scores[5] = {85, 92, 78, 88, 95};

// Partial initialization (remaining set to 0)
int values[10] = {1, 2, 3};  // values[3] through values[9] are 0

// Initialize all to zero
double prices[100] = {0};  // All elements set to 0.0

// Implicit array sizing
int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
// Compiler determines size is 12

string months[] = {"Jan", "Feb", "Mar", "Apr"};  // Size is 4
```

## 8.5 The Range-Based for Loop

Introduced in C++ 11, the **range-based for loop** simplifies iterating through all elements of an array without using a
subscript. The loop variable holds a copy of each array element for each iteration. To modify the array's contents, the
loop variable must be a reference variable. A range-based for loop is a simpler way to process an entire array but it
doesn't provide access to the element subscripts.

```cpp
int scores[] = {85, 92, 78, 88, 95};

// Read-only access (loop variable is a copy)
for (int score : scores) {
    cout << score << " ";
}
cout << endl;

// Modifying array (loop variable is a reference)
for (int &score : scores) {
    score += 5;  // Add 5 bonus points to each score
}

// Auto keyword for type deduction
for (auto value : scores) {
    cout << value << " ";
}

// Const reference (efficient for large objects, prevents modification)
string names[] = {"Alice", "Bob", "Charlie"};
for (const auto &name : names) {
    cout << name << endl;
}
```

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

```cpp
const int SIZE = 5;
int scores[SIZE] = {85, 92, 78, 88, 95};

// Calculate sum and average
int sum = 0;
for (int i = 0; i < SIZE; i++) {
    sum += scores[i];
}
double average = static_cast<double>(sum) / SIZE;
cout << "Average: " << average << endl;

// Find largest element
int largest = scores[0];
for (int i = 1; i < SIZE; i++) {
    if (scores[i] > largest) {
        largest = scores[i];
    }
}
cout << "Largest: " << largest << endl;

// Copy array (element by element)
int copy[SIZE];
for (int i = 0; i < SIZE; i++) {
    copy[i] = scores[i];
}

// Compare arrays
int arr1[3] = {1, 2, 3};
int arr2[3] = {1, 2, 3};
bool areEqual = true;
for (int i = 0; i < 3; i++) {
    if (arr1[i] != arr2[i]) {
        areEqual = false;
        break;
    }
}

// Increment element vs subscript
scores[0]++;      // Increments the value at index 0 (85 becomes 86)
// scores[i++];   // Increments the subscript (dangerous!)
```

## 8.7 Using Parallel Arrays

**Parallel arrays** are two or more arrays that contain related data. The relationship between the data is maintained by
using the same subscript to access corresponding elements across the arrays. Parallel arrays don't need to hold the same
data type. For example, one array might hold student names (`string`), and a parallel array could hold their grades (
`float`).

```cpp
const int NUM_STUDENTS = 4;

// Parallel arrays for student data
string names[NUM_STUDENTS] = {"Alice", "Bob", "Charlie", "Diana"};
int ids[NUM_STUDENTS] = {1001, 1002, 1003, 1004};
float grades[NUM_STUDENTS] = {92.5, 87.3, 95.0, 89.8};

// Display related data using same index
for (int i = 0; i < NUM_STUDENTS; i++) {
    cout << "ID: " << ids[i] << ", Name: " << names[i]
         << ", Grade: " << grades[i] << endl;
}

// Search for a student by name
string searchName = "Bob";
for (int i = 0; i < NUM_STUDENTS; i++) {
    if (names[i] == searchName) {
        cout << searchName << "'s ID: " << ids[i]
             << ", Grade: " << grades[i] << endl;
        break;
    }
}
```

## 8.8 The typedef Statement

The **`typedef`** statement creates an alias for an existing data type. This can make code more readable and simplifies
the notation for complex data types, such as arrays. The format is `typedef existingType newName;`.

```cpp
// Create alias for array type
typedef int IntArray[10];
typedef double Matrix[5][5];

// Use the alias
IntArray scores;       // Same as: int scores[10];
IntArray grades;       // Same as: int grades[10];
Matrix data;           // Same as: double data[5][5];

// Makes function declarations cleaner
void processScores(IntArray arr);  // Instead of: void processScores(int arr[10]);

// Another example
typedef string StringArray[100];
StringArray names;     // Same as: string names[100];
```

## 8.9 Arrays as Function Arguments

Passing a single array element to a function is the same as passing a regular variable of that type. To pass an entire
array to a function, you pass the array name as the argument. In the function prototype and header, an empty set of
square brackets (`[]`) indicates an array parameter. It's also common to pass the array size as a separate argument so
the function knows how many elements to process.

When an array is passed to a function, changes made to the array inside the function affect the original array in the
calling function. The **`const`** keyword can be used in the function prototype and header to prevent an array from
being inadvertently changed.

```cpp
// Function prototypes
void displayArray(const int[], int);       // Read-only (const)
void doubleValues(int[], int);             // Can modify array
double getAverage(const double[], int);    // Read-only

// Function definitions
void displayArray(const int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void doubleValues(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] *= 2;  // Modifies original array
    }
}

double getAverage(const double arr[], int size) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum / size;
}

// Using the functions
int main() {
    int scores[5] = {85, 92, 78, 88, 95};

    displayArray(scores, 5);     // Display: 85 92 78 88 95
    doubleValues(scores, 5);     // Modifies scores array
    displayArray(scores, 5);     // Display: 170 184 156 176 190

    return 0;
}
```

## 8.10 Two-Dimensional Arrays

A **two-dimensional array** can store multiple sets of data, similar to a table or spreadsheet. You use two size
declarators in the definition, one for the number of rows and one for the number of columns. To access an element, you
use two subscripts: the first for the row and the second for the column. Two-dimensional arrays are initialized row by
row.

```cpp
const int ROWS = 3;
const int COLS = 4;

// Declaration
int matrix[ROWS][COLS];

// Initialization row by row
int grades[3][4] = {
    {85, 92, 78, 88},    // Row 0 (Student 1)
    {90, 87, 95, 93},    // Row 1 (Student 2)
    {76, 84, 88, 91}     // Row 2 (Student 3)
};

// Accessing elements
grades[0][2] = 80;   // Row 0, Column 2 (Student 1, Test 3)
cout << grades[1][3] << endl;  // Display: 93

// Processing with nested loops
for (int row = 0; row < ROWS; row++) {
    cout << "Student " << (row + 1) << ": ";
    for (int col = 0; col < COLS; col++) {
        cout << grades[row][col] << " ";
    }
    cout << endl;
}

// Calculate average per student (row)
for (int row = 0; row < ROWS; row++) {
    int sum = 0;
    for (int col = 0; col < COLS; col++) {
        sum += grades[row][col];
    }
    double avg = static_cast<double>(sum) / COLS;
    cout << "Student " << (row + 1) << " average: " << avg << endl;
}
```

## 8.11 Arrays with Three or More Dimensions

Arrays can have any number of dimensions. When passing a multi-dimensional array to a function, you must specify the
size of all dimensions except for the first one.

```cpp
// 3D array: [departments][students][tests]
const int DEPTS = 2;
const int STUDENTS = 3;
const int TESTS = 4;

int scores[DEPTS][STUDENTS][TESTS];

// Initialize
scores[0][0][0] = 85;  // Dept 0, Student 0, Test 0
scores[1][2][3] = 92;  // Dept 1, Student 2, Test 3

// Process with triple nested loop
for (int d = 0; d < DEPTS; d++) {
    cout << "Department " << d << ":\n";
    for (int s = 0; s < STUDENTS; s++) {
        cout << "  Student " << s << ": ";
        for (int t = 0; t < TESTS; t++) {
            cout << scores[d][s][t] << " ";
        }
        cout << endl;
    }
}

// Function with 2D array - must specify all dimensions except first
void processMatrix(int arr[][COLS], int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

// Function with 3D array
void processScores(int arr[][STUDENTS][TESTS], int depts) {
    // Process array...
}
```

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

```cpp
#include <vector>
using namespace std;

// Declaration (empty vector)
vector<int> numbers;        // Vector of integers
vector<string> names;       // Vector of strings

// Declaration with initial size
vector<double> scores(10);  // Vector of 10 doubles (initialized to 0.0)

// Declaration with size and initial value
vector<int> values(5, 100); // Vector of 5 ints, each set to 100

// Adding elements
numbers.push_back(10);
numbers.push_back(20);
numbers.push_back(30);
// numbers now contains: [10, 20, 30]

// Accessing elements
cout << numbers[0] << endl;     // Output: 10
numbers[1] = 25;                // Modify element
cout << numbers[1] << endl;     // Output: 25

// Size operations
cout << "Size: " << numbers.size() << endl;  // Output: 3

if (numbers.empty()) {
    cout << "Vector is empty\n";
} else {
    cout << "Vector has " << numbers.size() << " elements\n";
}

// Removing elements
numbers.pop_back();  // Remove last element (30)
// numbers now contains: [10, 25]

// Processing with loop
for (int i = 0; i < numbers.size(); i++) {
    cout << numbers[i] << " ";
}
cout << endl;

// Range-based for loop
for (int num : numbers) {
    cout << num << " ";
}
cout << endl;

// Clear all elements
numbers.clear();
cout << "Size after clear: " << numbers.size() << endl;  // Output: 0

// Initialization list (C++11)
vector<int> data = {1, 2, 3, 4, 5};
```

## 8.13 Arrays of Objects

Arrays can hold objects and structures as their elements. An array of structures can be used as an alternative to
parallel arrays. You use the array subscript to access a specific object or structure in the array, and then use the dot
operator to access its members or member functions.

When initializing an array of objects, you can use a default constructor or provide specific values with an
initialization list. If the initialization list is shorter than the array size, the default constructor is used for the
remaining objects.

```cpp
// Define a structure
struct Student {
    int id;
    string name;
    float gpa;
};

// Array of structures
const int NUM_STUDENTS = 3;
Student students[NUM_STUDENTS] = {
    {1001, "Alice", 3.8},
    {1002, "Bob", 3.5},
    {1003, "Charlie", 3.9}
};

// Accessing members using dot operator
cout << students[0].name << endl;      // Output: Alice
cout << students[1].gpa << endl;       // Output: 3.5

students[2].gpa = 4.0;  // Modify a member

// Processing array of structures
for (int i = 0; i < NUM_STUDENTS; i++) {
    cout << "ID: " << students[i].id
         << ", Name: " << students[i].name
         << ", GPA: " << students[i].gpa << endl;
}

// Define a class
class Circle {
private:
    double radius;
public:
    Circle() : radius(1.0) {}
    Circle(double r) : radius(r) {}
    double getArea() { return 3.14159 * radius * radius; }
    void setRadius(double r) { radius = r; }
};

// Array of objects
Circle circles[5];  // Calls default constructor for each

circles[0].setRadius(2.5);
circles[1].setRadius(3.0);

cout << "Area of circle 0: " << circles[0].getArea() << endl;

// Array of objects with initialization
Circle moreCircles[3] = {Circle(1.0), Circle(2.0), Circle(3.0)};
```