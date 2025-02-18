### **Exercise 1: Implement Push and Pop in a Simple Stack**
Implement a simple stack using an array or linked list. Write the `push` and `pop` methods.

**Requirements:**
- Implement a `Stack` class with the following methods:
    - `push(value)`: Adds an element to the top of the stack.
    - `pop()`: Removes and returns the top element of the stack.
    - `is_empty()`: Returns `True` if the stack is empty, `False` otherwise.
    - `peek()`: Returns the top element without removing it.
- Demonstrate the stack operations with test cases.

**Example Usage:**
```cpp
#include <iostream>
#include <stdexcept> // Includes std::out_of_range

// Node class representing each element in the stack
class Node {
public:
    int data;
    Node* next;

    // Constructor to initialize a node with data
    Node(int data);
};

// Stack class to represent a stack data structure
class Stack {
private:
    Node* top; // Pointer to the top of the stack

public:
    // Constructor to initialize an empty stack
    Stack();

    // Push an element onto the stack
    void push(int data);

    // Pop and return the top element of the stack
    int pop();

    // Check if the stack is empty
    bool isEmpty() const;

    // Peek the top element without removing it
    int peek() const;

    // Destructor to clean up memory
    ~Stack();
};

// Node constructor to initialize a node with data
Node::Node(int data) {
    this->data = data;
    this->next = nullptr;
}

// Stack constructor to initialize an empty stack
Stack::Stack() {
    top = nullptr;
}


// Push an element onto the stack
void Stack::push(int data) {
    // Set the new node's next to the current top
    // Make the new node the top of the stack
}

// Pop and return the top element of the stack
int Stack::pop() {
    if (isEmpty()) {
        throw std::out_of_range("Stack underflow: cannot pop from an empty stack");
    }
    // Store the current top node
    // Get the data from the top node
    // Move the top to the next node
    // Free memory of the old top node
    return poppedData;
}

// Check if the stack is empty
bool Stack::isEmpty() const {
    return top == nullptr;
}

// Peek the top element without removing it
int Stack::peek() const {
    if (isEmpty()) {
        throw std::out_of_range("Stack is empty: cannot peek");
    }
    return top->data; // Return the data of the top node
}

// Stack destructor to clean up memory
Stack::~Stack() {
    while (!isEmpty()) {
        pop(); // Continuously pop until the stack is empty
    }
}

Stack s;
s.push(10);
s.push(20);
s.pop(); // Removes 20
s.push(30);
cout << s.peek(); // Outputs 30
```

---

### **Exercise 2: Check for Balanced Parentheses**
Write a function to determine if a given string of parentheses (`()`, `{}`, `[]`) is balanced using a stack.

**Example Input & Output:**
```cpp
Input: "{[()]}"  
Output: true  

Input: "{[(])}"  
Output: false
```

**Hint:**
- Use a stack to keep track of opening brackets.
- When encountering a closing bracket, check if it matches the top of the stack.

---

### **Exercise 3: Reverse a String Using a Stack**
Write a program that takes a string and reverses it using a stack.

**Example Input & Output:**
```cpp
Input: "hello"
Output: "olleh"
```

**Hint:**
- Push each character of the string onto a stack.
- Pop characters from the stack to construct the reversed string.

---

### **Exercise 4: Next Greater Element**
Given an array, find the **next greater element** for each element. The next greater element of an element `x` in the array is the first greater element on the right side of `x`. If no greater element exists, return `-1`.

**Example Input & Output:**
```cpp
Input: [4, 5, 2, 25]
Output: [5, 25, 25, -1]
```

**Hint:**
- Use a stack to track elements while iterating from right to left.