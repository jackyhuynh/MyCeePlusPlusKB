# Advance

## **1. Smart Pointers & Exception Safety**
**Objective:** Use **smart pointers (`std::unique_ptr`)** to manage memory safely with exceptions.

**Instructions:**
- Create a function `allocateMemory(int size)` that **allocates an array** using `std::unique_ptr<int[]>`.
- If `size <= 0`, throw an exception `"Invalid size for memory allocation!"`.
- Use a try-catch block to **handle the exception and ensure no memory leaks**.

---

### **2. Exception Propagation in Class Hierarchy**
**Objective:** Implement **exception propagation across classes**.

**Instructions:**
- Create a class `Database` with a method `connect(string dbName)`.
- If the database name is **empty**, throw an exception `"Database name cannot be empty!"`.
- Create another class `Application` that calls `Database::connect()`.
- In `main()`, instantiate `Application` and handle the exception at the top level.

---

### **3. Exception Handling with Multi-Level Catch Blocks**
**Objective:** Handle **multiple exception types with catch blocks**.

**Instructions:**
- Create a function `processData(int x)`.
- If `x < 0`, throw a `logic_error`.
- If `x == 0`, throw a `runtime_error`.
- If `x > 100`, throw an **integer exception**.
- Handle these **exceptions separately** in `main()`.

---

### **4. Exception Handling with RAII (Resource Acquisition Is Initialization)**
**Objective:** Implement **RAII** to manage file resources properly.

**Instructions:**
- Write a class `FileManager` that **opens a file** in the constructor and **closes it** in the destructor.
- If the file cannot be opened, throw an exception.
- Use a **try-catch block** in `main()` to handle the exception.

---

### **5. Rethrowing Exceptions**
**Objective:** Demonstrate **rethrowing** in exception handling.

**Instructions:**
- Implement a function `lowLevelFunction()` that throws an `overflow_error`.
- Create a function `midLevelFunction()` that **calls `lowLevelFunction()` and rethrows the exception**.
- In `main()`, catch the exception and display the **origin of the error**.

---

### **6. Exception Handling with Threads (C++11)**
**Objective:** Handle **exceptions thrown in threads**.

**Instructions:**
- Create a thread that performs division (`a / b`).
- If `b == 0`, throw a `runtime_error`.
- In `main()`, **catch the exception properly from the thread**.

Here are the **sample solutions** for the **advanced exception handling exercises in C++**:

---

## **1. Smart Pointers & Exception Safety**
```cpp
#include <iostream>
#include <memory>
#include <stdexcept>

using namespace std;

void allocateMemory(int size) {
    if (size <= 0) {
        throw invalid_argument("Invalid size for memory allocation!");
    }

    unique_ptr<int[]> data(new int[size]); // Smart pointer manages memory
    cout << "Memory allocated successfully for size: " << size << endl;
}

int main() {
    try {
        allocateMemory(10);
        allocateMemory(-5);  // This will throw an exception
    } catch (const exception &e) {
        cout << "Exception: " << e.what() << endl;
    }

    return 0;
}
```

---

## **2. Exception Propagation in Class Hierarchy**
```cpp
#include <iostream>
#include <stdexcept>

using namespace std;

class Database {
public:
    void connect(const string &dbName) {
        if (dbName.empty()) {
            throw runtime_error("Database name cannot be empty!");
        }
        cout << "Connected to database: " << dbName << endl;
    }
};

class Application {
private:
    Database db;
public:
    void run() {
        db.connect("");  // This will throw an exception
    }
};

int main() {
    Application app;
    try {
        app.run();
    } catch (const exception &e) {
        cout << "Exception caught in main: " << e.what() << endl;
    }

    return 0;
}
```

---

## **3. Exception Handling with Multi-Level Catch Blocks**
```cpp
#include <iostream>
#include <stdexcept>

using namespace std;

void processData(int x) {
    if (x < 0) throw logic_error("Negative values are not allowed!");
    if (x == 0) throw runtime_error("Zero is not a valid input!");
    if (x > 100) throw x; // Throw integer exception
    cout << "Processing data: " << x << endl;
}

int main() {
    int x;
    cout << "Enter a number: ";
    cin >> x;

    try {
        processData(x);
    } catch (const logic_error &e) {
        cout << "Logic Error: " << e.what() << endl;
    } catch (const runtime_error &e) {
        cout << "Runtime Error: " << e.what() << endl;
    } catch (int err) {
        cout << "Integer Exception: " << err << " is too large!" << endl;
    }

    return 0;
}
```

---

## **4. Exception Handling with RAII (File Handling)**
```cpp
#include <iostream>
#include <fstream>
#include <stdexcept>

using namespace std;

class FileManager {
private:
    ifstream file;
public:
    FileManager(const string &filename) {
        file.open(filename);
        if (!file) throw runtime_error("Failed to open file: " + filename);
        cout << "File opened successfully: " << filename << endl;
    }

    ~FileManager() {
        if (file.is_open()) {
            file.close();
            cout << "File closed properly." << endl;
        }
    }
};

int main() {
    try {
        FileManager fm("data.txt");  // Ensure the file exists
    } catch (const exception &e) {
        cout << "Exception: " << e.what() << endl;
    }

    return 0;
}
```

---

## **5. Rethrowing Exceptions**
```cpp
#include <iostream>
#include <stdexcept>

using namespace std;

void lowLevelFunction() {
    throw overflow_error("Buffer overflow in low-level function!");
}

void midLevelFunction() {
    try {
        lowLevelFunction();
    } catch (...) {
        cout << "Exception caught in midLevelFunction, rethrowing..." << endl;
        throw; // Rethrow exception
    }
}

int main() {
    try {
        midLevelFunction();
    } catch (const exception &e) {
        cout << "Exception caught in main: " << e.what() << endl;
    }

    return 0;
}
```

---

## **6. Exception Handling with Threads (C++11)**
```cpp
#include <iostream>
#include <thread>
#include <stdexcept>

using namespace std;

void divide(int a, int b) {
    if (b == 0) {
        throw runtime_error("Division by zero in thread!");
    }
    cout << "Result: " << a / b << endl;
}

int main() {
    try {
        thread t(divide, 10, 0); // This will throw an exception
        t.join(); // Join the thread before handling exceptions
    } catch (const exception &e) {
        cout << "Exception caught in main: " << e.what() << endl;
    }

    return 0;
}
```

---

### ✅ **Summary of Advanced Concepts Covered**
1. **Smart Pointers & Exception Safety** – Prevents memory leaks using `std::unique_ptr`.
2. **Exception Propagation Across Classes** – Demonstrates how exceptions propagate from class methods.
3. **Multi-Level Exception Handling** – Handles different exception types with separate `catch` blocks.
4. **RAII with File Handling** – Ensures proper resource management even when exceptions occur.
5. **Rethrowing Exceptions** – Shows how exceptions can be caught, logged, and then rethrown.
6. **Threads & Exception Handling** – Handles exceptions thrown from C++ threads.
