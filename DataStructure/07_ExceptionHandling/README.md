## Exception Handling Strategies

### Table of Contents:

1. **Introduction to Exception Handling**
2. **Why Exception Handling is Important**
3. **Exception Handling Use Cases**
4. **Common Exception Handling Strategies**
5. **Best Practices for Exception Handling**

### Resources

- [Exceptions and Use cases](./ExceptionHandling.cpp)
- [Other Languages](./Others.md)

---

### 1. Introduction to Exception Handling

**Exception handling** is a mechanism in programming that deals with unexpected events or errors during the execution of
a program. These errors, referred to as "exceptions," can disrupt the normal flow of a program and cause it to terminate
prematurely if not handled properly.

Exception handling provides a way to gracefully manage these errors by "catching" them when they occur, and then
deciding how to respond. This allows the program to continue functioning or to terminate in a controlled manner,
providing meaningful feedback to the user or developer.

---

### 2. Why Exception Handling is Important

- **Program Stability:** Without exception handling, programs may crash or produce unpredictable results when errors
  occur. Exception handling ensures that the program can handle errors in a structured way, reducing the likelihood of
  unexpected crashes.

- **User Experience:** Proper exception handling improves user experience by providing meaningful error messages instead
  of abrupt termination. Users can be informed about what went wrong and how to resolve the issue.

- **Maintainability:** Exception handling helps developers write cleaner, more maintainable code. Instead of scattering
  error-checking logic throughout the codebase, exception handling centralizes error management, making the code easier
  to understand and maintain.

- **Debugging Aid:** Exceptions often include information about where and why the error occurred, which aids in
  debugging and resolving issues more efficiently.

---

### 3. Exception Handling Use Cases

- **Division by Zero:** In a program that performs mathematical calculations, dividing a number by zero would result in
  an error. Exception handling can be used to catch this error and provide an alternative course of action.

- **File Not Found:** When a program tries to open a file that does not exist, an exception will be thrown. Exception
  handling can catch this error and prompt the user to check the file path or handle it by creating a new file.

- **Network Failure:** In applications that rely on network connections, such as web applications or API calls,
  exceptions can handle scenarios like network timeouts or server errors, allowing the program to retry or notify the
  user of the issue.

- **Invalid Input:** If a user inputs data that does not match the expected format (e.g., entering text when a number is
  expected), exception handling can manage the error by asking the user to input valid data.

---

### 4. Common Exception Handling Strategies

1. **Try-Catch Blocks:**
    - A `try` block contains the code that may throw an exception, and a `catch` block handles the exception if it
      occurs. This is the most common exception-handling structure.
   ```cpp
   try {
       // Code that may throw an exception
   } catch (ExceptionType e) {
       // Code to handle the exception
   }
   ```

2. **Throwing Exceptions:**
    - Instead of handling exceptions locally, a function can throw an exception and let the calling function handle it.
   ```cpp
   void divide(int a, int b) {
       if (b == 0) {
           throw "Division by zero!";
       }
       return a / b;
   }
   ```

3. **Finally Block:**
    - In some languages (like Java or Python), the `finally` block ensures that a specific block of code will execute
      regardless of whether an exception occurred or not. This is useful for releasing resources like file handles or
      network connections.
   ```python
   try:
       # Code that might throw an exception
   except Exception as e:
       # Handle the exception
   finally:
       # Code that always runs, such as closing a file
   ```

4. **Multiple Catch Blocks:**
    - Different types of exceptions can be handled separately by having multiple `catch` blocks.
   ```cpp
   try {
       // Code that may throw exceptions
   } catch (const std::out_of_range& e) {
       // Handle out of range exception
   } catch (const std::invalid_argument& e) {
       // Handle invalid argument exception
   }
   ```

5. **Custom Exceptions:**
    - In many cases, it's useful to define custom exception classes to represent specific error conditions in the
      application. This provides more detailed information about errors and helps categorize them more efficiently.
   ```cpp
   class CustomException : public std::exception {
       const char* what() const noexcept override {
           return "Custom exception occurred!";
       }
   };
   ```

---

### 5. Best Practices for Exception Handling

- **Use Exceptions for Exceptional Cases Only:** Exceptions should be used to handle unexpected events, not as a
  substitute for regular control flow (e.g., using exceptions for simple conditions like null checks).

- **Provide Meaningful Messages:** When throwing exceptions, include detailed messages to help developers understand the
  cause of the error. Avoid generic error messages.

- **Don’t Catch Generic Exceptions:** Catching broad exceptions (like `catch (Exception e)` in C++) without proper
  handling can obscure the root cause of the issue. Catch only the specific exceptions that you are prepared to handle.

- **Release Resources Properly:** Use `finally` blocks (or equivalent mechanisms) to release resources such as file
  handles, database connections, or network connections, ensuring they are cleaned up even if an exception occurs.

- **Log Exceptions:** For production systems, it's important to log exceptions so that they can be reviewed and
  addressed. This is crucial for debugging and maintenance.

- **Re-Throw Exceptions if Necessary:** If a function cannot fully handle an exception, it can re-throw it to be handled
  further up the call stack.

---

### Conclusion

Exception handling is a critical concept in software development that helps ensure program stability, improves user
experience, and makes code more maintainable. By understanding common use cases and strategies for exception handling,
developers can build robust and reliable applications. Properly using try-catch blocks, throwing exceptions, and
adhering to best practices ensures that errors are managed effectively and efficiently.

---

## C++ Exceptions and Use Case

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

A game inventory system where missing items are rare but critical. Instead of returning undefined values, exceptions are thrown when an item is not found.

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

Custom exceptions are useful in applications with complex error-handling needs, such as a banking system where different types of errors (e.g., insufficient funds, account not found) need distinct handling.

---

### **Conclusion**

C++ provides multiple mechanisms for error detection and handling:

1. **Assertions** for debugging.
2. **Exceptions** for runtime error handling.
3. **Custom Exception Classes** for domain-specific error conditions.

## **When `try-catch` Solves the Problem but `if-else` Doesn't**

### **1. Handling Invalid Input Conversion (`std::stoi`)**
**Problem:** Converting a string to an integer might fail if the input is invalid (e.g., a non-numeric string). `if-else` cannot catch these exceptions.

#### **Using `if-else` (Fails to catch exception)**
```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string input = "abc"; // Invalid number
    int num;

    if (!isdigit(input[0])) { // Doesn't properly check entire string
        cout << "Invalid input" << endl;
    } else {
        num = stoi(input); // Causes a runtime error
        cout << "Converted number: " << num << endl;
    }
}
```
- **Problem:** `isdigit(input[0])` only checks the first character, failing for cases like `"12a"`.
- **`stoi()` throws an exception**, which crashes the program if not handled.

#### **Using `try-catch` (Proper Exception Handling)**
```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string input = "abc"; // Invalid number
    try {
        int num = stoi(input); // Might throw an exception
        cout << "Converted number: " << num << endl;
    } catch (const exception& e) {
        cout << "Error: Invalid number format. " << e.what() << endl;
    }
}
```
**✅ Works:** Prevents program crash and handles the invalid conversion safely.

---

### **2. File Handling Errors**
**Problem:** Opening a file that doesn’t exist or is inaccessible can fail at runtime. `if-else` cannot detect these issues properly.

#### **Using `if-else` (Fails in some cases)**
```cpp
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream file("nonexistent.txt");

    if (file.is_open()) {
        cout << "File opened successfully." << endl;
    } else {
        cout << "Failed to open file." << endl;
    }

    return 0;
}
```
- **Problem:** It **only checks if the file is open**, but doesn't handle unexpected runtime failures (e.g., permissions, disk errors).

#### **Using `try-catch` (Proper Handling)**
```cpp
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    try {
        ifstream file("nonexistent.txt");
        if (!file) {
            throw runtime_error("File not found or inaccessible.");
        }
        cout << "File opened successfully." << endl;
    } catch (const exception& e) {
        cout << "Exception: " << e.what() << endl;
    }
}
```
**✅ Works:** Catches file-related exceptions properly.

---

### **3. Memory Allocation Failure (`new` Operator)**
**Problem:** Allocating memory dynamically (`new`) may fail if the system runs out of memory.

#### **Using `if-else` (Doesn't Handle Exception)**
```cpp
#include <iostream>
using namespace std;

int main() {
    int* arr = new int[100000000000]; // Large allocation

    if (arr == nullptr) { // This check doesn’t work for `new`
        cout << "Memory allocation failed!" << endl;
    } else {
        cout << "Memory allocated successfully!" << endl;
    }

    delete[] arr;
    return 0;
}
```
- **Problem:** `new` **does not return `nullptr`** when allocation fails; instead, it throws a `std::bad_alloc` exception.

#### **Using `try-catch` (Proper Exception Handling)**
```cpp
#include <iostream>
#include <exception>
using namespace std;

int main() {
    try {
        int* arr = new int[100000000000]; // Large allocation
        cout << "Memory allocated successfully!" << endl;
        delete[] arr;
    } catch (const bad_alloc& e) {
        cout << "Exception: Memory allocation failed - " << e.what() << endl;
    }

    return 0;
}
```
**✅ Works:** Prevents program crash due to `std::bad_alloc`.

---

### **4. Division by Zero**
**Problem:** Checking for division by zero using `if-else` works, but if the divisor is a **user input or calculation result**, it may unexpectedly be zero.

#### **Using `if-else` (Prevents issue but lacks robustness)**
```cpp
#include <iostream>
using namespace std;

double divide(int a, int b) {
    if (b == 0) {
        cout << "Error: Division by zero!" << endl;
        return 0;
    }
    return a / b;
}

int main() {
    cout << divide(10, 0) << endl;
    return 0;
}
```
- **Problem:** Returning `0` is not always the right solution.
- **May not work if division is deep in a function call stack.**

#### **Using `try-catch` (Better Error Handling)**
```cpp
#include <iostream>
using namespace std;

double divide(int a, int b) {
    if (b == 0) throw runtime_error("Division by zero!"); // Throw an exception
    return static_cast<double>(a) / b;
}

int main() {
    try {
        cout << divide(10, 0) << endl;
    } catch (const runtime_error& e) {
        cout << "Exception caught: " << e.what() << endl;
    }
    return 0;
}
```
**✅ Works:** The program doesn't continue with incorrect values.

---

### **When to Use `try-catch` Instead of `if-else`**
| Situation | Use `if-else` | Use `try-catch` |
|-----------|--------------|----------------|
| Simple predictable errors | ✅ | ❌ |
| Invalid user input handling | ✅ | ❌ (unless an exception is thrown) |
| File I/O failures | ❌ | ✅ |
| Memory allocation failures | ❌ | ✅ |
| Converting strings to numbers | ❌ | ✅ |
| Division by zero deep in function calls | ❌ | ✅ |

**Conclusion:**
- **Use `if-else` for expected conditions** where you can check before execution.
- **Use `try-catch` for unexpected runtime errors** like memory allocation failures, file handling, and exceptions thrown by library functions.




