# Recursion vs. loop (NO TEST)
Let's break down the concepts of recursion and loops to clarify their differences.

## What is a Loop (While Loop or For Loop)?

A **loop** is a control structure that repeatedly executes a block of code as long as a given condition is true. There are two common types of loops:

1. **For Loop**: Iterates a specific number of times, typically based on a counter.
   ```cpp
   for (int i = 1; i <= n; i++) {
       result *= i;
   }
   ```

2. **While Loop**: Repeats as long as a certain condition is true.
   ```cpp
   while (n > 0) {
       result *= n;
       n--;
   }
   ```

## Difference Between Recursion and Loops

| **Feature**         | **Recursion**                                   | **While Loop / For Loop**                        |
|---------------------|-------------------------------------------------|--------------------------------------------------|
| **Definition**       | Function that calls itself to solve a problem.  | Repeats a block of code until a condition is met. |
| **Termination**      | Terminates when a **base case** is reached.     | Terminates when the loop condition becomes false. |
| **Problem Structure**| Suited for problems that can be divided into smaller subproblems (e.g., tree traversal, factorial). | Suited for iterative problems where a known number of steps or a specific condition needs to be met. |
| **Memory Usage**     | Uses **stack memory** for each recursive call (may lead to stack overflow if recursion is too deep). | Uses less memory as it executes iteratively within the same function. |
| **Efficiency**       | Can be less efficient if recursion depth is large due to repeated function calls. | Generally more efficient for iterative tasks because there is no overhead from function calls. |
| **Examples**         | Factorial, Fibonacci, Tower of Hanoi, Tree Traversal. | Iterating through arrays, counting loops, processing lists. |

## Example: Factorial Using a Loop vs. Recursion

**Factorial Using Recursion**:
```cpp
int factorial(int n) {
    if (n <= 1) return 1; // base case
    return n * factorial(n - 1); // recursive call
}
```

**Factorial Using a Loop**:
```cpp
int factorial(int n) {
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}
```

## Key Points:
- **Recursion** is elegant and can solve problems that are naturally recursive (like traversing tree structures or solving puzzles like Tower of Hanoi).
- **Loops** (for/while) are typically more efficient and preferred for simple iterative tasks (like iterating through arrays or summing numbers).

[Prev](./README.md)
