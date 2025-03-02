
# **Understanding Space Complexity and Its Relation to Time Complexity**

---
## **1. What is Space Complexity?**
Space complexity refers to the **amount of memory (space) required** by an algorithm to execute relative to the input size \( n \). It includes:
1. **Fixed Part:** Memory used for constants, variables, and program instructions.
2. **Variable Part:** Memory needed for:
    - **Input storage** (arrays, linked lists, etc.).
    - **Auxiliary storage** (temporary arrays, recursion stacks, etc.).

### **Formula for Space Complexity**
```
S(n) = Fixed Space + Variable Space
```

---
## **2. How to Measure Space Complexity?**
We measure space complexity by considering:
1. **Input Storage:** The memory needed to store input data.
2. **Auxiliary Space:** Extra space required for computation.
3. **Recursion Stack Space:** Space used in recursive function calls.

---
## **3. Examples of Space Complexity in C++**
### **Example 1: Constant Space \( O(1) \)**
An algorithm that uses a **fixed amount of memory**, regardless of input size.

```cpp
#include <iostream>
using namespace std;

void printSum(int a, int b) {
    int sum = a + b;  // Fixed space
    cout << sum << endl;
}

int main() {
    printSum(5, 10);
    return 0;
}
```
📌 **Space Complexity: \( O(1) \)**  
✅ **Why?** Only a few integer variables are used, and no extra space is required.

---
### **Example 2: Linear Space \( O(n) \)**
An algorithm that **stores input data dynamically**.

```cpp
#include <iostream>
using namespace std;

void storeNumbers(int n) {
    int* arr = new int[n];  // Dynamically allocated array
    for (int i = 0; i < n; i++) {
        arr[i] = i;
    }
    cout << "Array stored!" << endl;
    delete[] arr;  // Free memory
}

int main() {
    storeNumbers(1000);
    return 0;
}
```
📌 **Space Complexity: \( O(n) \)**  
✅ **Why?** The array grows linearly with \( n \), so memory usage increases.

---
### **Example 3: Quadratic Space \( O(n^2) \)**
When a **2D array (matrix)** is used.

```cpp
#include <iostream>
using namespace std;

void createMatrix(int n) {
    int** matrix = new int*[n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[n];  // Creating a 2D array
    }
    cout << "Matrix created!" << endl;
    
    // Free memory
    for (int i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int main() {
    createMatrix(5);
    return 0;
}
```
📌 **Space Complexity: \( O(n^2) \)**  
✅ **Why?** The matrix requires \( n^2 \) memory slots.

---
### **Example 4: Recursive Space \( O(n) \)**
Recursion requires **stack memory** for each function call.

```cpp
#include <iostream>
using namespace std;

void recursiveFunction(int n) {
    if (n == 0) return;
    cout << n << " ";
    recursiveFunction(n - 1);
}

int main() {
    recursiveFunction(5);
    return 0;
}
```
📌 **Space Complexity: \( O(n) \)**  
✅ **Why?** Each recursive call adds a new stack frame, requiring additional memory.

---
## **4. Relation Between Space and Time Complexity**
There is often a **trade-off** between space and time complexity:
- **Optimizing for time** can increase space usage (e.g., using **memoization**).
- **Optimizing for space** can increase time complexity (e.g., recalculating values instead of storing them).

### **Example: Fibonacci Calculation**
#### **Recursive Fibonacci (High Time, Low Space)**
```cpp
#include <iostream>
using namespace std;

int fibonacci(int n) {
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    cout << fibonacci(10) << endl;
    return 0;
}
```
📌 **Time Complexity: \( O(2^n) \)**  
📌 **Space Complexity: \( O(n) \) (recursion stack)**

---
#### **Optimized Fibonacci (High Space, Low Time)**
```cpp
#include <iostream>
using namespace std;

int fibonacci(int n) {
    int *fib = new int[n+1]; // Extra memory
    fib[0] = 0, fib[1] = 1;
    
    for (int i = 2; i <= n; i++)
        fib[i] = fib[i - 1] + fib[i - 2];

    int result = fib[n];
    delete[] fib;  // Free memory
    return result;
}

int main() {
    cout << fibonacci(10) << endl;
    return 0;
}
```
📌 **Time Complexity: \( O(n) \)**  
📌 **Space Complexity: \( O(n) \) (storing values)**

---
## **5. Summary Table**
| **Case**            | **Example**                 | **Time Complexity** | **Space Complexity** | **Why?** |
|---------------------|---------------------------|----------------------|----------------------|----------|
| Constant \( O(1) \) | Sum of two numbers        | \( O(1) \) | \( O(1) \) | Uses fixed memory |
| Linear \( O(n) \)   | Storing values in an array | \( O(n) \) | \( O(n) \) | Uses memory proportional to input |
| Quadratic \( O(n^2) \) | 2D Matrix | \( O(n^2) \) | \( O(n^2) \) | Uses memory for \( n^2 \) elements |
| Recursive \( O(n) \) | Recursive function calls | \( O(n) \) | \( O(n) \) | Each call takes up stack memory |
| Space vs Time Trade-off | Fibonacci (Memoization) | \( O(n) \) | \( O(n) \) | Faster but uses extra memory |

---
## **6. Key Takeaways**
- **Time Complexity** measures execution time, while **Space Complexity** measures memory usage.
- **Optimizing one may increase the other.**
- **Recursive algorithms** often have higher space complexity due to stack usage.
- **Dynamic programming and memoization** trade space for faster execution.