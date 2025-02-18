# Basic Exercises

---

## **Exercise 1: Divide by Zero Exception**
**Objective:** Handle division by zero errors.

**Instructions:**
- Write a function `divide(int a, int b)` that takes two integers and returns the result of `a / b`.
- If `b == 0`, throw an exception with a message `"Division by zero is not allowed"`.
- In `main()`, take user input for `a` and `b`, call `divide()`, and handle exceptions appropriately.

```cpp
#include <iostream>
#include <stdexcept>

using namespace std;

double divide(int a, int b) {
    if (b == 0) {
        throw runtime_error("Division by zero is not allowed");
    }
    return static_cast<double>(a) / b;
}

int main() {
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;

    try {
        double result = divide(a, b);
        cout << "Result: " << result << endl;
    } catch (const exception &e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
```

## **Exercise 2: Array Index Out of Bounds**
**Objective:** Handle array index out-of-bounds errors.

**Instructions:**
- Create an array of size 5 with some integers.
- Ask the user for an index and display the corresponding element.
- If the user enters an index out of range (less than 0 or greater than 4), throw an exception with a suitable message.
- Handle the exception and prompt the user again.

```cpp
#include <iostream>
#include <stdexcept>

using namespace std;

int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    int index;

    cout << "Enter an index (0-4): ";
    cin >> index;

    try {
        if (index < 0 || index >= 5) {
            throw out_of_range("Index out of bounds!");
        }
        cout << "Value at index " << index << ": " << arr[index] << endl;
    } catch (const exception &e) {
        cout << "Exception: " << e.what() << endl;
    }

    return 0;
}
```

---

## **Exercise 3: Custom Exception Class**
**Objective:** Create and use a custom exception class.

**Instructions:**
- Define a class `NegativeNumberException` that inherits from `std::exception`.
- Override the `what()` function to return `"Negative numbers are not allowed"`.
- Write a function `sqrtValue(double num)` that calculates the square root of a number.
- If `num < 0`, throw `NegativeNumberException`.
- Catch the exception in `main()` and display an appropriate message.

```cpp
#include <iostream>
#include <cmath>
#include <exception>

using namespace std;

class NegativeNumberException : public exception {
public:
    const char* what() const noexcept override {
        return "Negative numbers are not allowed!";
    }
};

double sqrtValue(double num) {
    if (num < 0) {
        throw NegativeNumberException();
    }
    return sqrt(num);
}

int main() {
    double num;
    cout << "Enter a number: ";
    cin >> num;

    try {
        cout << "Square Root: " << sqrtValue(num) << endl;
    } catch (const exception &e) {
        cout << "Exception: " << e.what() << endl;
    }

    return 0;
}
```

---

## **Exercise 4: Multiple Exception Types**
**Objective:** Handle multiple types of exceptions.

**Instructions:**
- Write a function `compute(int a, int b, char op)` that:
    - Performs addition, subtraction, multiplication, and division.
    - Throws `std::runtime_error` if `op` is not `+, -, *, /`.
    - Throws `std::logic_error` if division by zero occurs.
- Handle both exceptions in `main()`.

```cpp
#include <iostream>
#include <stdexcept>

using namespace std;

double compute(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': 
            if (b == 0) throw logic_error("Division by zero is not allowed!");
            return static_cast<double>(a) / b;
        default:
            throw runtime_error("Invalid operator!");
    }
}

int main() {
    int a, b;
    char op;
    
    cout << "Enter two numbers and an operator (+, -, *, /): ";
    cin >> a >> b >> op;

    try {
        cout << "Result: " << compute(a, b, op) << endl;
    } catch (const exception &e) {
        cout << "Exception: " << e.what() << endl;
    }

    return 0;
}
```

---

## **Exercise 5: Stack Overflow Simulation**
**Objective:** Use exceptions to prevent stack overflow.

**Instructions:**
- Implement a stack using an array of size 5.
- Implement `push(int x)` and `pop()` functions.
- If `push()` is called when the stack is full, throw an exception `"Stack Overflow"`.
- If `pop()` is called when the stack is empty, throw an exception `"Stack Underflow"`.
- Handle exceptions properly.

```cpp
#include <iostream>
#include <stdexcept>

using namespace std;

class Stack {
private:
    int arr[5];
    int top;

public:
    Stack() : top(-1) {}

    void push(int x) {
        if (top >= 4) {
            throw overflow_error("Stack Overflow!");
        }
        arr[++top] = x;
    }

    int pop() {
        if (top < 0) {
            throw underflow_error("Stack Underflow!");
        }
        return arr[top--];
    }
};

int main() {
    Stack s;
    try {
        s.push(10);
        s.push(20);
        s.push(30);
        s.push(40);
        s.push(50);
        s.push(60); // This will throw an exception
    } catch (const exception &e) {
        cout << "Exception: " << e.what() << endl;
    }

    try {
        for (int i = 0; i < 6; i++) {
            cout << "Popped: " << s.pop() << endl;
        }
    } catch (const exception &e) {
        cout << "Exception: " << e.what() << endl;
    }

    return 0;
}
```

---

## **Exercise 6: File Handling with Exception Handling**
**Objective:** Handle file read/write errors.

**Instructions:**
- Write a program that tries to open a file `"data.txt"`.
- If the file does not exist, throw an exception `"File not found"`.
- Catch and display an error message.

```cpp
#include <iostream>
#include <fstream>
#include <stdexcept>

using namespace std;

void readFile(const string& filename) {
    ifstream file(filename);
    if (!file) {
        throw runtime_error("File not found!");
    }
    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
}

int main() {
    string filename = "data.txt";

    try {
        readFile(filename);
    } catch (const exception &e) {
        cout << "Exception: " << e.what() << endl;
    }

    return 0;
}
```

---

### ✅ **Summary of Exception Handling Concepts Covered**
- `throw` and `catch` for handling errors.
- Standard exceptions like `runtime_error`, `logic_error`, `out_of_range`, etc.
- Custom exception class by inheriting `std::exception`.
- Handling multiple exception types.
- Exception handling in **stack operations** (overflow & underflow).
- Exception handling in **file operations**.
