# Stack Data Structure

### What is Stacks:
A **stack** is a linear data structure that follows the **Last In, First Out (LIFO)** principle. This means that the last element added to the stack is the first one to be removed. You can think of it as a stack of plates—each new plate is placed on top of the others, and to remove a plate, you take the one from the top.

-[Stack](./images/stack.jpg)

### Key Operations:
1. **Push**: Add an element to the top of the stack.
2. **Pop**: Remove the top element from the stack.
3. **Peek (or Top)**: View the top element without removing it.
4. **isEmpty**: Check if the stack is empty.

### Characteristics:
- **LIFO principle**: The last element pushed onto the stack is the first one to be popped off.
- **Dynamic size**: Depending on the implementation (using arrays or linked lists), the size of the stack can grow dynamically.

### Resources:

- [Basic Stack Implementation C++](./StackImplementation.md)
- [Stack Implementation using Vector<T> or Template<T>](./AdtStack.cpp)

### Use Cases of Stack:

1. **Function Call Management (Recursion)**
   - When a function calls another function, or calls itself recursively, the system uses a **call stack** to keep track of the return addresses and local variables. Each function call pushes a frame onto the stack, and when the function returns, its frame is popped off.
   
   **Example**: Managing function calls in programming languages like C++, Python, or Java.

2. **Expression Evaluation and Syntax Parsing**
   - Stacks are used to evaluate arithmetic expressions (postfix, infix, and prefix notations) and check balanced parentheses in expressions.
   
   **Example**: Evaluating mathematical expressions like `3 + 5 * (2 - 1)` or checking if `[{()}]` is a valid sequence of parentheses.

3. **Undo/Redo Operations**
   - Many applications, such as text editors, use stacks to implement the undo and redo functionality. Each action performed is pushed onto a stack (undo stack), and undoing an action pops it from the stack. Redo is implemented by using another stack to store the undone actions.
   
   **Example**: Undo/Redo in a word processor like Microsoft Word or code editor.

4. **Backtracking Algorithms**
   - Stacks are used in algorithms where backtracking is required, such as finding a path through a maze, solving puzzles (like the Tower of Hanoi), or searching for solutions in games (like chess or Sudoku solvers).
   
   **Example**: Depth-First Search (DFS) uses a stack to explore nodes in graphs.

5. **Browser History Navigation**
   - In web browsers, the back button works by maintaining a stack of previously visited URLs. When you visit a new page, it's pushed onto the stack. When you press the back button, the current page is popped off, and the previous one is displayed.
   
   **Example**: Navigating through visited websites in a browser like Chrome.

6. **Text Processing (Reversing Data)**
   - A stack can be used to reverse strings or other sequences. Each character or element is pushed onto a stack, and then popped off, reversing the order.
   
   **Example**: Reversing a string or checking for palindromes.

7. **Memory Management**
   - Stack data structures are used in low-level memory management in computer systems. Stack-based memory allocation is commonly used for local variables and function calls.

   **Example**: Managing memory in system programming for efficient allocation and deallocation of variables.

### Example Visualization of Stack Operations:

Let’s say we have a stack and perform the following operations:
1. `push(5)`
2. `push(10)`
3. `pop()` returns 10
4. `push(20)`
5. `peek()` returns 20

The stack evolves as:
- Initially: Empty.
- After `push(5)`: [5]
- After `push(10)`: [10, 5]
- After `pop()`: [5] (10 is removed)
- After `push(20)`: [20, 5]
- After `peek()`: The top element is 20, but the stack remains [20, 5].

### Conclusion:
Stacks are a fundamental data structure used in many areas of computing. Their simple, LIFO nature makes them suitable for a wide range of practical applications, from programming language interpreters to undo functionality in software.