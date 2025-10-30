## 🎯 Pointer Exercises (Easy to Advanced)

-----

### 1\. Easy: Basic Address and Value Access

**Goal:** Understand the relationship between a variable, its address (`&`), a pointer variable (`int*`), and the value it points to (`*`).

**Code Exercise:**

```cpp
#include <iostream>

void exercise_easy() {
    int value = 42;
    // 1. Declare an integer pointer named 'ptr'.
    int* ptr;

    // 2. Store the memory address of 'value' in 'ptr'.
    ptr = &value;

    std::cout << "--- Easy Exercise ---" << std::endl;
    std::cout << "Original value: " << value << std::endl;
    std::cout << "Address of value (&value): " << &value << std::endl;
    std::cout << "Value stored in ptr (address): " << ptr << std::endl;

    // 3. Use the indirection operator (*) to change the value of 'value' to 100.
    *ptr = 100;

    std::cout << "New value of 'value' (after *ptr = 100): " << value << std::endl;
}
```

-----

### 2\. Intermediate: Array Traversal and Pointer Arithmetic

**Goal:** Demonstrate the equivalence between array notation (`array[i]`) and pointer notation (`*(ptr + i)`) and use basic pointer arithmetic (`++`).

**Code Exercise:**

```cpp
#include <iostream>

void exercise_intermediate() {
    int numbers[] = {10, 20, 30, 40, 50};
    const int SIZE = 5;

    // Initialize an integer pointer 'p' to point to the start of the array.
    int* p = numbers; // Array name 'numbers' is the starting address

    std::cout << "\n--- Intermediate Exercise ---" << std::endl;
    std::cout << "Accessing array elements using pointer arithmetic:" << std::endl;

    // 1. Loop through the array using pointer arithmetic and the indirection operator.
    for (int i = 0; i < SIZE; ++i) {
        // Access the element at index 'i' using *(p + i)
        std::cout << "Element " << i << ": " << *(p + i) << std::endl;
    }

    // 2. Use pointer increment (p++) to advance the pointer and print the values.
    std::cout << "\nUsing pointer increment (p++) to print:" << std::endl;
    p = numbers; // Reset pointer to the start

    for (int i = 0; i < SIZE; ++i) {
        std::cout << "Element " << i << ": " << *p << std::endl;
        p++; // Move to the next element
    }
}
```

-----

### 3\. Advanced: Dynamic Memory Allocation and Function Return

**Goal:** Practice **dynamic memory allocation** using `new`, ensuring proper deallocation with `delete`, and returning a pointer from a function (to dynamically allocated memory, not a local variable).

**Code Exercise:**

```cpp
#include <iostream>

// Function that dynamically allocates an array and returns its address.
int* createDynamicArray(int size) {
    // 1. Dynamically allocate an array of 'size' integers using 'new'.
    int* arrPtr = new int[size];
    
    // Initialize the array elements
    for (int i = 0; i < size; ++i) {
        arrPtr[i] = (i + 1) * 10;
    }
    
    return arrPtr; // Return the address of the dynamically allocated memory
}

void exercise_advanced() {
    std::cout << "\n--- Advanced Exercise ---" << std::endl;
    int size = 5;

    // 2. Call the function and store the returned pointer.
    int* myArray = createDynamicArray(size);

    std::cout << "Dynamically created array elements:" << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cout << "Value at index " << i << ": " << myArray[i] << std::endl;
    }

    // 3. Crucially, free the memory allocated by 'new' using 'delete []'.
    delete[] myArray;
    myArray = nullptr; // Set the pointer to nullptr to avoid a dangling pointer.

    std::cout << "Dynamic memory freed." << std::endl;
}
```

-----

### 4\. Expert: Pointers to Structures and the Structure Pointer Operator (`->`)

**Goal:** Use a pointer to a **structure/class object** and access its members using the **structure pointer operator (`->`)** instead of the combination `(*ptr).member`.

**Code Exercise:**

```cpp
#include <iostream>

struct Student {
    int id;
    double gpa;
    std::string name;
};

void printStudentInfo(const Student* studentPtr) {
    // Access members using the structure pointer operator (->)
    std::cout << "Student ID: " << studentPtr->id << std::endl;
    std::cout << "Student Name: " << studentPtr->name << std::endl;
    std::cout << "Student GPA: " << studentPtr->gpa << std::endl;

    // This is equivalent to:
    // std::cout << "Student ID: " << (*studentPtr).id << std::endl;
}

void exercise_expert() {
    std::cout << "\n--- Expert Exercise ---" << std::endl;

    // 1. Create a Student object.
    Student s1 = {101, 3.85, "Alice"};

    // 2. Create a pointer to the Student object.
    Student* studentPtr = &s1;

    // 3. Pass the pointer to a function to print the info.
    std::cout << "Printing info using the -> operator:" << std::endl;
    printStudentInfo(studentPtr);

    // 4. Use the -> operator to directly modify a member.
    studentPtr->gpa = 3.99;

    std::cout << "\nAfter GPA update via pointer:" << std::endl;
    std::cout << "New GPA (s1.gpa): " << s1.gpa << std::endl;
}
```

-----

### 🚀 Running the Exercises

```cpp
// Main function to run all exercises
int main() {
    exercise_easy();
    exercise_intermediate();
    exercise_advanced();
    exercise_expert();
    return 0;
}
```
