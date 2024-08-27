#include "Stack.h"

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
    Node* newNode = new Node(data);
    newNode->next = top; // Set the new node's next to the current top
    top = newNode;       // Make the new node the top of the stack
}

// Pop and return the top element of the stack
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
