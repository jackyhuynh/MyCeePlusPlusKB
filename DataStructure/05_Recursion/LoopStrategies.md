# Looping Strategies (NO TEST)

There are several types of looping strategies in programming. These loops allow for repetitive execution of code until a
certain condition is met. Here are the main types of loops and looping strategies used in various programming languages:

## 1. **For Loop**

- **Description**: Used when you know the exact number of iterations in advance.
- **Structure**: Typically involves initialization, a condition, and an update step.
- **Use Case**: Iterating over arrays, collections, or executing code a fixed number of times.

**Example (C++):**

```cpp
for (int i = 0; i < 5; i++) {
    cout << i << endl;
}
```

## 2. **While Loop**

- **Description**: Used when you don't know in advance how many times the loop will execute, but you know a condition
  that needs to be satisfied for it to continue.
- **Structure**: Executes as long as a specified condition is true.
- **Use Case**: Waiting for user input or running code until a certain condition is met.

**Example (C++):**

```cpp
int i = 0;
while (i < 5) {
    cout << i << endl;
    i++;
}
```

## 3. **Do-While Loop**

- **Description**: Similar to the `while loop`, but it guarantees at least one execution because the condition is
  checked after the code block is executed.
- **Structure**: The loop runs once before checking the condition.
- **Use Case**: When the code needs to be executed at least once before checking the condition (e.g., validating user
  input).

**Example (C++):**

```cpp
int i = 0;
do {
    cout << i << endl;
    i++;
} while (i < 5);
```

## 4. **Enhanced For Loop (For-Each Loop)**

- **Description**: Used to iterate over elements in a collection or array without needing to manage the index
  explicitly.
- **Structure**: Simplified syntax for iterating over collections or arrays.
- **Use Case**: Traversing elements in an array or a list where you don't need to modify the loop variable.

**Example (C++ - Range-based for loop):**

```cpp
vector<int> numbers = {1, 2, 3, 4, 5};
for (int num : numbers) {
    cout << num << endl;
}
```

## 5. **Infinite Loop**

- **Description**: A loop that runs indefinitely unless manually interrupted, typically using a break statement or
  external conditions.
- **Structure**: Created when no termination condition is given or the condition is always true.
- **Use Case**: Used in event-driven systems or servers that wait for external input.

**Example (C++):**

```cpp
while (true) {
    cout << "This will print forever until you break." << endl;
    break; // Example of how to exit an infinite loop.
}
```

## 6. **Recursion (Indirect Looping)**

- **Description**: Recursion is not a loop in the traditional sense but a looping mechanism where a function calls
  itself to solve smaller subproblems.
- **Structure**: Involves a base case and a recursive call.
- **Use Case**: When a problem can be broken down into smaller subproblems (e.g., factorial, Fibonacci sequence, tree
  traversal).

**Example (C++):**

```cpp
int factorial(int n) {
    if (n == 0) return 1; // Base case
    return n * factorial(n - 1); // Recursive call
}
```

## 7. **Nested Loops**

- **Description**: A loop inside another loop. The inner loop runs fully for each iteration of the outer loop.
- **Structure**: You can nest any type of loop inside another (e.g., `for` inside `while`, `for` inside `for`, etc.).
- **Use Case**: Commonly used in matrix operations, 2D arrays, or solving problems involving multiple dimensions.

**Example (C++):**

```cpp
for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
        cout << "i: " << i << ", j: " << j << endl;
    }
}
```

## 8. **Break and Continue in Loops**

- **Break**: Used to terminate the loop before its natural end.
- **Continue**: Skips the current iteration and moves on to the next one.

**Break Example (C++):**

```cpp
for (int i = 0; i < 5; i++) {
    if (i == 3) break; // Exit loop when i is 3
    cout << i << endl;
}
```

**Continue Example (C++):**

```cpp
for (int i = 0; i < 5; i++) {
    if (i == 3) continue; // Skip iteration when i is 3
    cout << i << endl;
}
```

## Summary of Looping Strategies:

1. **For Loop**: Known number of iterations.
2. **While Loop**: Unknown number of iterations but based on a condition.
3. **Do-While Loop**: Executes at least once before checking the condition.
4. **Enhanced For Loop**: Iterating through collections or arrays.
5. **Infinite Loop**: Runs indefinitely until interrupted.
6. **Recursion**: Function-based looping for problems that can be broken down.
7. **Nested Loops**: Loop within another loop for handling multidimensional data.

[Prev](./README.md)