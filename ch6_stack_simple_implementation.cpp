#include <iostream>
#include <stdexcept> // Includes std::runtime_error

class Node {
public:
    int data;
    Node* next;

    // Constructor
    // 
    Node(int data) : data(data), next(nullptr) {}
};

class Stack {
private:
    Node* top;

public:
    Stack() : top(nullptr) {}

    // Add element to the top of the stack
    void push(int data) {
        Node* newNode = new Node(data);
        newNode->next = top; // Point new node to the current top
        top = newNode;       // Update top to the new node
    }

    // Remove and return the top element of the stack
    int pop() {
        if (isEmpty()) {
            throw std::out_of_range("Stack is empty. Cannot pop.");
        }
        Node* temp = top;
        int data = top->data;
        top = top->next; // Update top to the next element
        delete temp;     // Free the old top
        return data;
    }

    // Check if the stack is empty
    bool isEmpty() const {
        return top == nullptr;
    }

    // Return the top element of the stack without removing it
    int peek() const {
        if (isEmpty()) {
            throw std::out_of_range("Stack is empty. Cannot peek.");
        }
        return top->data;
    }

    // Destructor to free the allocated memory
    ~Stack() {
        while (!isEmpty()) {
            pop(); // Pop all elements to free memory
        }
    }
};

int main() {
    Stack stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);

    std::cout << "Top element is: " << stack.peek() << std::endl; // Should print 3

    while (!stack.isEmpty()) {
        std::cout << "Popping: " << stack.pop() << std::endl;
    }

    return 0;
}
