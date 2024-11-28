#include <iostream>
#define MAX_SIZE 100  // Maximum size of the stack

class Stack {
private:
    int arr[MAX_SIZE];  // Array to store stack elements
    int top;            // Index of the top element in the stack

public:
    // Constructor to initialize the stack
    Stack() {
        top = -1;  // Stack is empty
    }

    // Push an element onto the stack
    void push(int value) {
        if (top == MAX_SIZE - 1) {
            std::cout << "Stack Overflow! Cannot push " << value << std::endl;
            return;
        }
        arr[++top] = value;
        std::cout << "Pushed " << value << " onto the stack." << std::endl;
    }

    // Pop an element from the stack
    int pop() {
        if (top == -1) {
            std::cout << "Stack Underflow! Cannot pop from an empty stack." << std::endl;
            return -1;  // Return a dummy value
        }
        int poppedValue = arr[top--];
        std::cout << "Popped " << poppedValue << " from the stack." << std::endl;
        return poppedValue;
    }

    // Peek at the top element of the stack
    int peek() const {
        if (top == -1) {
            std::cout << "Stack is empty. Nothing to peek." << std::endl;
            return -1;  // Return a dummy value
        }
        return arr[top];
    }

    // Check if the stack is empty
    bool isEmpty() const {
        return top == -1;
    }

    // Print all elements in the stack
    void printStack() const {
        if (top == -1) {
            std::cout << "Stack is empty." << std::endl;
            return;
        }
        std::cout << "Stack elements: ";
        for (int i = 0; i <= top; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    Stack stack;

    // Test the stack
    stack.push(10);
    stack.push(20);
    stack.push(30);

    // Display the stack
    stack.printStack();

    // Pop from the top
    stack.pop();

    // Display the stack again
    stack.printStack();

    // Peek test
    std::cout << "Top element is: " << stack.peek() << std::endl;

    return 0;
}
