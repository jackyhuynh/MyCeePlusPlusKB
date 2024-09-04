#ifndef STACK_H
#define STACK_H

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

#endif // STACK_H
