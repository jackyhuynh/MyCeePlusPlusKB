# C++ Exceptions and Use Case

### **Background**

Exceptions are used in C++ to handle situations where the preconditions for a method might not be met. Traditional
return values like `false` are not always sufficient to indicate errors. For example, a method like `peek()` on an empty
stack may not provide clear feedback if it returns a `bool`. This is where exceptions come in.

---

### **Problem Example: `findBox`**

Consider a function `findBox` that searches for a string in an array. When the target string is not found, the function
initially returns `boxes[size]`, which leads to undefined behavior. This can cause issues when clients try to use the
undefined "box."

```cpp
// Initial version of findBox
int findBox(std::string boxes[], int size, std::string target) {
    for (int i = 0; i < size; i++) {
        if (boxes[i] == target) {
            return i;
        }
    }
    return size;  // Returning undefined value when not found
}
```

#### Use Case

You have an array of labeled boxes, and you want to find the index of a specific box label. If the label is not found,
you must return a valid indicator of failure.

---

### **Assertions**

Assertions are a debugging tool used to verify preconditions or postconditions in code. In C++, assertions can be added
using the `assert` function, which halts the program if a condition is false.

```cpp
#include <cassert>

int findBoxWithAssertion(std::string boxes[], int size, std::string target) {
    assert(size > 0);  // Ensure size is valid
    for (int i = 0; i < size; i++) {
        if (boxes[i] == target) {
            return i;
        }
    }
    return size;
}
```

> **Note:** Assertions are not substitutes for `if` statements and should not be used in production code.

#### Use Case

In debugging, assertions help ensure that the array size is valid before performing operations like searching.

---

### **Throwing Exceptions**

Exceptions provide an alternate way to handle errors. When a function encounters an error, it can throw an exception,
transferring control to an exception handler.

```cpp
int findBoxWithException(std::string boxes[], int size, std::string target) {
    for (int i = 0; i < size; i++) {
        if (boxes[i] == target) {
            return i;
        }
    }
    throw std::runtime_error("Target not found");
}
```

#### Use Case

A game inventory system where missing items are rare but critical. Instead of returning undefined values, exceptions are
thrown when an item is not found.

---

### **Handling Exceptions**

To handle exceptions, C++ uses `try` and `catch` blocks. Code that might throw exceptions is placed in the `try` block,
while the `catch` block handles specific exceptions.

```cpp
try {
    int index = findBoxWithException(boxes, size, target);
    std::cout << "Box found at index " << index << std::endl;
} catch (const std::runtime_error& e) {
    std::cerr << "Error: " << e.what() << std::endl;
}
```

- **Try block:** Code that might throw exceptions.
- **Catch block:** Handles the exception and defines steps based on the exception type.

#### Use Case

A file search utility where the program continues executing even if a file is missing, showing an appropriate error
message.

---

### **Multiple `catch` Blocks**

You can handle multiple types of exceptions by using several `catch` blocks. C++ checks them in order, with the most
specific exceptions first.

```cpp
try {
    int index = findBoxWithException(boxes, size, target);
} catch (const std::invalid_argument& e) {
    std::cerr << "Invalid argument: " << e.what() << std::endl;
} catch (const std::runtime_error& e) {
    std::cerr << "Runtime error: " << e.what() << std::endl;
}
```

---

### **Uncaught Exceptions**

When an exception is thrown but not caught, the program terminates. This situation should be avoided in production code.

```cpp
int main() {
    std::string boxes[] = {"box1", "box2", "box3"};
    try {
        int index = findBoxWithException(boxes, 3, "box4");
    } catch (...) {
        std::cerr << "An error occurred." << std::endl;
    }
    return 0;
}
```

---

### **Programmer-Defined Exception Classes**

Programmers can define their own exceptions by creating classes derived from the `std::exception` class. This provides
more granular control over the error-handling process.

```cpp
class BoxNotFoundException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Box not found exception";
    }
};
```

#### Use Case

Custom exceptions are useful in applications with complex error-handling needs, such as a banking system where different
types of errors (e.g., insufficient funds, account not found) need distinct handling.

---

### **Conclusion**

C++ provides multiple mechanisms for error detection and handling:

1. **Assertions** for debugging.
2. **Exceptions** for runtime error handling.
3. **Custom Exception Classes** for domain-specific error conditions.

These tools help ensure that programs can handle unexpected situations gracefully.

