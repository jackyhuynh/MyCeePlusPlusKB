# Basic Stack Implemention:

This code defines a basic stack data structure using linked lists in C++. Here's a detailed breakdown of the [Stack.cpp](./Stack.cpp). We also need the [Stack.h](./Stack.h) so that the app can operate properly.

### 1. `Node::Node(int data)`
This is the constructor for the `Node` class, which is used to represent each element in the stack.
- **`data`**: Holds the actual data of the node.
- **`next`**: Points to the next node in the stack. Initially, it's set to `nullptr` because the node does not point to any other node yet.
  
```cpp
Node::Node(int data) {
    this->data = data;
    this->next = nullptr;
}
```
This constructor initializes the node by assigning the provided `data` to the node and setting `next` to `nullptr`, indicating that it doesn't point to another node initially.

### 2. `Stack::Stack()`
This is the constructor for the `Stack` class. The stack is implemented using a singly linked list, and it uses a pointer `top` to keep track of the top node.
  
```cpp
Stack::Stack() {
    top = nullptr;
}
```
- The `top` pointer is initialized to `nullptr` because the stack is empty when it is first created.

### 3. `void Stack::push(int data)`
This method adds a new element (node) to the top of the stack.
  
```cpp
void Stack::push(int data) {
    Node* newNode = new Node(data);
    newNode->next = top; // Set the new node's next to the current top
    top = newNode;       // Make the new node the top of the stack
}
```
- A new node is created using the `Node` constructor.
- The `next` pointer of the new node is set to the current top node (so the new node points to the old top).
- The `top` is updated to point to the new node, making it the new top of the stack.

### 4. `int Stack::pop()`
This method removes and returns the top element of the stack.
  
```cpp
int Stack::pop() {
    if (isEmpty()) {
        throw std::out_of_range("Stack underflow: cannot pop from an empty stack");
    }
    Node* temp = top;    // Store the current top node
    int poppedData = top->data; // Get the data from the top node
    top = top->next;     // Move the top to the next node
    delete temp;         // Free memory of the old top node
    return poppedData;
}
```
- First, it checks if the stack is empty by calling `isEmpty()`. If it is, an exception is thrown.
- The `temp` pointer temporarily holds the current top node.
- The `poppedData` variable stores the data from the top node to be returned.
- The `top` pointer is updated to point to the next node, effectively removing the old top node.
- The old top node is deleted to free up memory.
- The method returns the value that was stored in the popped node.

### 5. `bool Stack::isEmpty() const`
This method checks if the stack is empty.
  
```cpp
bool Stack::isEmpty() const {
    return top == nullptr;
}
```
- It returns `true` if the `top` is `nullptr`, meaning the stack is empty.

### 6. `int Stack::peek() const`
This method returns the data at the top of the stack without removing it.
  
```cpp
int Stack::peek() const {
    if (isEmpty()) {
        throw std::out_of_range("Stack is empty: cannot peek");
    }
    return top->data; // Return the data of the top node
}
```
- First, it checks if the stack is empty by calling `isEmpty()`. If so, it throws an exception.
- If the stack is not empty, it returns the data from the top node.

### 7. `Stack::~Stack()`
This is the destructor for the `Stack` class, which is responsible for cleaning up memory when the stack is no longer needed.
  
```cpp
Stack::~Stack() {
    while (!isEmpty()) {
        pop(); // Continuously pop until the stack is empty
    }
}
```
- The destructor continuously calls `pop()` until the stack is empty, effectively deleting all the nodes in the stack and freeing the memory.

### Summary
This code implements a stack using a singly linked list. It provides basic operations:
- **`push`**: Add an element to the top.
- **`pop`**: Remove and return the top element.
- **`peek`**: View the top element without removing it.
- **`isEmpty`**: Check if the stack is empty.
- **Destructor**: Automatically cleans up the stack's memory when the stack object is destroyed.

This is a typical implementation of a stack with dynamic memory allocation in C++.

[Prev](./README.md)