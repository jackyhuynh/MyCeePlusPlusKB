# Big O Notations and Time Complexity

## **Why Big O Notation?**
Big O notation helps us analyze the efficiency of algorithms by estimating their worst-case performance based on input size (\( n \)). The key benefits of using Big O notation include:

1. **Predicting Performance:** Helps determine if an algorithm will be fast enough for large datasets.
2. **Comparing Algorithms:** Allows for the selection of the best algorithm for a given problem.
3. **Understanding Scalability:** Ensures an algorithm can handle increasing data sizes efficiently.
4. **Optimizing Code:** Helps developers improve code performance by identifying bottlenecks.

---
## **Detailed Explanation of Each Complexity with C++ Examples**

### **1. Constant Time: \( O(1) \)**
#### **How it works?**
- The function executes the same number of operations no matter how large the input is.
- It directly accesses an element in an array, which takes the same time regardless of the array size.

```cpp
#include <iostream>
using namespace std;

void constantFunction(int arr[], int n) {
    cout << arr[0] << endl; // Always accesses only the first element
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    constantFunction(arr, 5);
    return 0;
}
```
#### **Why does it work?**
- Accessing an element in an array takes one memory lookup operation.
- The runtime is **independent** of \( n \).

#### **When to use?**
- When retrieving a specific value from a data structure without looping.
- Example: **Hash table lookups** (assuming no collisions).

---

### **2. Linear Time: \( O(n) \)**
#### **How it works?**
- A loop runs from 0 to \( n-1 \), visiting each element once.

```cpp
#include <iostream>
using namespace std;

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) { // Loop runs 'n' times
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    printArray(arr, 5);
    return 0;
}
```
#### **Why does it work?**
- The time taken **grows proportionally** with the input size.
- If \( n \) doubles, the execution time doubles.

#### **When to use?**
- When you need to **process all elements**.
- Example: **Finding the maximum value in an array**.

---

### **3. Quadratic Time: \( O(n^2) \)**
#### **How it works?**
- Two nested loops iterate over the array, making it execute \( n \times n \) operations.

```cpp
#include <iostream>
using namespace std;

void printPairs(int arr[], int n) {
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < n; j++) { // Nested loop
            cout << "(" << arr[i] << "," << arr[j] << ") ";
        }
        cout << endl;
    }
}

int main() {
    int arr[] = {1, 2, 3};
    printPairs(arr, 3);
    return 0;
}
```
#### **Why does it work?**
- The outer loop runs \( n \) times.
- The inner loop runs \( n \) times **for each iteration of the outer loop**.
- **Total operations** = \( n \times n = n^2 \).

#### **When to use?**
- When **comparing all pairs of elements**.
- Example: **Bubble Sort, Insertion Sort**.

---

### **4. Logarithmic Time: \( O(\log n) \)**
#### **How it works?**
- Instead of iterating through all elements, it **divides the problem in half** at each step.

```cpp
#include <iostream>
using namespace std;

int binarySearch(int arr[], int left, int right, int key) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int main() {
    int arr[] = {1, 3, 5, 7, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 7;
    
    int result = binarySearch(arr, 0, n - 1, key);
    if (result != -1)
        cout << "Element found at index " << result << endl;
    else
        cout << "Element not found" << endl;
    
    return 0;
}
```
#### **Why does it work?**
- Each step **halves** the number of elements left to search.
- **Number of operations** = \( \log_2 n \).

#### **When to use?**
- When searching **sorted** data quickly.
- Example: **Binary Search, Tree Traversal**.

---

### **5. Linearithmic Time: \( O(n \log n) \)**
#### **How it works?**
- **Merge Sort** divides the array into halves recursively.
- It merges sorted halves **in linear time**.

```cpp
#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    int leftArr[n1], rightArr[n2];
    
    for (int i = 0; i < n1; i++) leftArr[i] = arr[left + i];
    for (int i = 0; i < n2; i++) rightArr[i] = arr[mid + 1 + i];
    
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) arr[k++] = leftArr[i++];
        else arr[k++] = rightArr[j++];
    }
    
    while (i < n1) arr[k++] = leftArr[i++];
    while (j < n2) arr[k++] = rightArr[j++];
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        
        merge(arr, left, mid, right);
    }
}

int main() {
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, n - 1);
    
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    
    return 0;
}
```
#### **Why does it work?**
- **Dividing takes \( O(\log n) \)**.
- **Merging takes \( O(n) \)**.
- **Total time = \( O(n \log n) \)**.

#### **When to use?**
- When sorting large datasets efficiently.
- Example: **Merge Sort, QuickSort (average case)**.

---

## **Summary Table**
| Complexity | Example | Why It Works? |
|------------|---------|--------------|
| \( O(1) \) | Array element access | Constant time memory lookup |
| \( O(n) \) | Loop through an array | Process each element once |
| \( O(n^2) \) | Nested loops | Each element compared to all others |
| \( O(\log n) \) | Binary Search | Problem size halves every step |
| \( O(n \log n) \) | Merge Sort | Recursive division + merging |

## **Combining Multiple Complexities in Big O Notation**

When an algorithm consists of multiple steps, each with different time complexities, we **combine** these complexities to determine the overall time complexity.

### **Rules for Calculating Big O Complexity**
1. **Keep the fastest-growing term**
    - If an algorithm has multiple terms, we **drop the lower-order terms** because they become insignificant as \( n \) grows.
    - Example: \( O(n^2 + n) \) simplifies to \( O(n^2) \).

2. **Drop constant multipliers**
    - Constants do not impact asymptotic behavior.
    - Example: \( O(3n^2) \) simplifies to \( O(n^2) \).

3. **Different complexity cases are added together if they are sequential**
    - If different steps **do not depend** on each other, their complexities are **added**.
    - Example: If Step 1 is \( O(n) \) and Step 2 is \( O(\log n) \), the total complexity is \( O(n + \log n) \).

4. **Multiply complexities for nested loops or recursive calls**
    - If one part of the algorithm **depends** on another, their complexities **multiply**.
    - Example: A loop inside another loop of complexity \( O(n) \) results in \( O(n \times n) = O(n^2) \).

---

## **Case 1: Addition of Complexities (Independent Steps)**
If an algorithm has two independent parts, we **add** their complexities.

### **Example 1: \( O(n) + O(\log n) = O(n) \)**
```cpp
#include <iostream>
using namespace std;

void linearFunction(int arr[], int n) {
    for (int i = 0; i < n; i++) { // O(n)
        cout << arr[i] << " ";
    }
    cout << endl;
}

int binarySearch(int arr[], int left, int right, int key) {
    while (left <= right) { // O(log n)
        int mid = left + (right - left) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int main() {
    int arr[] = {1, 3, 5, 7, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    linearFunction(arr, n); // O(n)
    binarySearch(arr, 0, n - 1, 5); // O(log n)

    return 0;
}
```
📌 **Final Complexity:**  
\[
O(n) + O(\log n) = O(n)
\]
✅ **Why?** The dominant term is \( O(n) \) (since \( O(\log n) \) is much smaller for large \( n \)).

---

### **Example 2: \( O(n^2) + O(n) = O(n^2) \)**
```cpp
#include <iostream>
using namespace std;

void quadraticFunction(int arr[], int n) {
    for (int i = 0; i < n; i++) { // O(n)
        for (int j = 0; j < n; j++) { // O(n)
            cout << arr[i] << "," << arr[j] << " ";
        }
        cout << endl;
    }
}

void linearFunction(int arr[], int n) {
    for (int i = 0; i < n; i++) { // O(n)
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    quadraticFunction(arr, n); // O(n^2)
    linearFunction(arr, n); // O(n)

    return 0;
}
```
📌 **Final Complexity:**  
\[
O(n^2) + O(n) = O(n^2)
\]
✅ **Why?** \( O(n^2) \) dominates, so we drop \( O(n) \).

---

## **Case 2: Multiplication of Complexities (Nested Loops & Recursion)**
When one operation is **inside another**, their complexities **multiply**.

### **Example 3: \( O(n) \times O(\log n) = O(n \log n) \)**
```cpp
#include <iostream>
using namespace std;

void logLoop(int n) {
    for (int i = 1; i < n; i *= 2) { // O(log n)
        cout << i << " ";
    }
    cout << endl;
}

void nestedLoop(int n) {
    for (int i = 0; i < n; i++) { // O(n)
        logLoop(n); // O(log n)
    }
}

int main() {
    nestedLoop(16);
    return 0;
}
```
📌 **Final Complexity:**  
\[
O(n) \times O(\log n) = O(n \log n)
\]
✅ **Why?** The outer loop runs \( n \) times, and the inner loop runs \( O(\log n) \).

---

### **Example 4: \( O(n) \times O(n) = O(n^2) \)**
```cpp
#include <iostream>
using namespace std;

void nestedLoop(int n) {
    for (int i = 0; i < n; i++) { // O(n)
        for (int j = 0; j < n; j++) { // O(n)
            cout << i << "," << j << " ";
        }
        cout << endl;
    }
}

int main() {
    nestedLoop(3);
    return 0;
}
```
📌 **Final Complexity:**  
\[
O(n) \times O(n) = O(n^2)
\]
✅ **Why?** The outer loop runs \( n \) times, and the inner loop runs \( n \) times **for each iteration**.

---

## **Case 3: Nested Recursion Complexity**
Recursion follows its own pattern for complexity.

### **Example 5: \( O(2^n) \) (Exponential Time)**
```cpp
#include <iostream>
using namespace std;

int fibonacci(int n) {
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2); // O(2^n)
}

int main() {
    cout << fibonacci(5) << endl;
    return 0;
}
```
📌 **Final Complexity:**  
\[
O(2^n)
\]
✅ **Why?** Each function call creates **two more function calls**, growing exponentially.

---

## **Summary of Rules**
| Case | Example | Final Complexity | Why? |
|------|---------|----------------|------|
| Addition | \( O(n) + O(\log n) \) | \( O(n) \) | Drop smaller term |
| Addition | \( O(n^2) + O(n) \) | \( O(n^2) \) | Drop smaller term |
| Multiplication | \( O(n) \times O(\log n) \) | \( O(n \log n) \) | Multiply complexities |
| Multiplication | \( O(n) \times O(n) \) | \( O(n^2) \) | Multiply complexities |
| Recursion | Fibonacci | \( O(2^n) \) | Exponential growth |

## **Key Takeaways**
1. **Drop lower-order terms** when adding complexities.
2. **Multiply complexities** when operations are nested.
3. **Understand recursion growth** to determine exponential behavior. 
4. Big O notation is crucial for writing **efficient and scalable** code. Understanding different complexities helps you **choose the best algorithms** for your applications.