# Use Case

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
