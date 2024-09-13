# Pointer

### Resources:
- [Template <typename T>?](./) (NO TEST)
- [Template <typename T> pointer](./templateTypePointer.md) (NO TEST)
- [Template <typename T> pointer strategies](./templateTypePointerStrategies.md) (NO TEST)

A **pointer** in C++ is a variable that stores the **memory address** of another variable. Instead of holding a value directly, a pointer "points" to a location in memory where the actual value is stored. Pointers are a powerful feature in C++ and are used extensively for dynamic memory management, arrays, function arguments, and more.

### Key Concepts of Pointers

1. **Memory Address**: Every variable in a program is stored at a unique memory address. A pointer holds the memory address of a variable rather than the actual data.
2. **Dereferencing**: Accessing the value stored at the memory address a pointer points to is called "dereferencing" the pointer.
3. **Pointer Arithmetic**: Since pointers store memory addresses, you can perform arithmetic on pointers (e.g., incrementing to point to the next memory location).

### How to Declare and Use Pointers

#### 1. **Declaring a Pointer**
To declare a pointer, you use the `*` operator. Here’s the syntax:
```cpp
int* ptr;  // Declares a pointer to an int
```
This means `ptr` is a pointer that can hold the address of an `int` variable.

#### 2. **Assigning a Pointer**
You assign a pointer by using the **address-of operator (`&`)**, which gives the memory address of a variable.

```cpp
int x = 10;
int* ptr = &x;  // ptr holds the address of x
```
In this example:
- `x` is a variable of type `int` that holds the value `10`.
- `ptr` is a pointer that stores the **address** of `x`.

#### 3. **Dereferencing a Pointer**
To access or modify the value at the memory address stored by the pointer, you use the **dereference operator (`*`)**.

```cpp
cout << *ptr;  // Dereferencing ptr to get the value of x (10)
```
In this example, `*ptr` returns the value of `x`, which is `10`.

#### Example of Declaring, Assigning, and Dereferencing a Pointer:
```cpp
#include <iostream>
using namespace std;

int main() {
    int x = 10;        // Declare an integer variable
    int* ptr = &x;     // Declare a pointer and assign it the address of x

    cout << "Value of x: " << x << endl;       // Output: 10
    cout << "Address of x: " << &x << endl;    // Output: Memory address of x
    cout << "Value of ptr: " << ptr << endl;   // Output: Same memory address
    cout << "Value pointed to by ptr: " << *ptr << endl;  // Output: 10 (value of x)

    return 0;
}
```

### Pointer Operators:

- **`&` (Address-of Operator)**: Returns the memory address of a variable.
- **`*` (Dereference Operator)**: Accesses the value at the memory address the pointer is pointing to.

---

### Null Pointer

A **null pointer** is a pointer that doesn't point to any valid memory location. It's initialized using the keyword `nullptr` (or `NULL` in older C++ standards). Null pointers are useful to indicate that the pointer is not yet assigned.

```cpp
int* ptr = nullptr;  // ptr does not point to any valid address
```

### Pointer Arithmetic

Pointers in C++ support arithmetic operations such as increment (`++`), decrement (`--`), and addition or subtraction of integers. This is particularly useful for traversing arrays.

- **Incrementing a pointer (`++`)** makes it point to the next memory location (depending on the size of the data type).
- **Decrementing a pointer (`--`)** makes it point to the previous memory location.

Example:
```cpp
int arr[] = {10, 20, 30};
int* ptr = arr;  // Points to the first element of the array

cout << *ptr << endl;   // Output: 10
ptr++;                 // Moves the pointer to the next element
cout << *ptr << endl;   // Output: 20
```

### Pointers and Arrays

Arrays and pointers are closely related in C++. The name of an array is essentially a pointer to the first element of the array.

```cpp
int arr[3] = {10, 20, 30};
int* ptr = arr;  // arr is equivalent to &arr[0]

cout << *ptr << endl;  // Output: 10
```

### Dynamic Memory Allocation with Pointers

In C++, you can use pointers for **dynamic memory allocation** using `new` and `delete`. This is useful when the size of an object or array needs to be determined at runtime.

#### Example:
```cpp
int* ptr = new int;    // Dynamically allocate memory for an int
*ptr = 42;             // Assign the value 42 to the allocated memory
cout << *ptr << endl;  // Output: 42

delete ptr;            // Free the allocated memory
```

### Double Pointers

A **double pointer** is a pointer to a pointer. It stores the memory address of another pointer. This is often used in situations like passing pointers to functions by reference or when dealing with multidimensional arrays.

```cpp
int x = 10;
int* ptr = &x;     // Pointer to an int
int** dptr = &ptr; // Pointer to a pointer

cout << **dptr;    // Output: 10 (value of x)
```

### Common Use Cases for Pointers:

1. **Dynamic Memory Allocation**: Using `new` and `delete` for managing memory dynamically.
2. **Passing by Reference**: Pointers allow functions to modify variables outside their scope by passing addresses.
3. **Arrays and Strings**: Pointers are essential for working with arrays, strings (C-style), and data structures like linked lists.
4. **Data Structures**: Pointers are used in complex data structures such as linked lists, trees, and graphs.
5. **Function Pointers**: Storing addresses of functions for callback mechanisms.

---

### Example: Pointers and Functions

You can pass pointers to functions to modify variables outside the function's scope.

```cpp
#include <iostream>
using namespace std;

void changeValue(int* ptr) {
    *ptr = 20;  // Modify the value of the variable being pointed to
}

int main() {
    int x = 10;
    cout << "Before: " << x << endl;  // Output: 10

    changeValue(&x);  // Pass the address of x
    cout << "After: " << x << endl;   // Output: 20

    return 0;
}
```

### Summary:
- A **pointer** stores the memory address of another variable.
- You use the **address-of (`&`)** operator to get the address of a variable and the **dereference (`*`)** operator to access the value stored at that address.
- Pointers are critical for **dynamic memory allocation**, **arrays**, and **passing data by reference**.
- Understanding how to work with pointers is essential for handling complex data structures and memory management in C++.