#include <iostream>
#include "Stack.h"
#include "AdtStack.h"

using namespace std;

int main() {
    // Our Stack
    Stack stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);

    std::cout << "Top element is: " << stack.peek() << std::endl; // Should print 3

    while (!stack.isEmpty()) {
        std::cout << "Popping: " << stack.pop() << std::endl;
    }

    // ADT Stacks
    ADTStack<int> intStack; // Create a stack of ints

    // Push numbers onto stack
    intStack.push(1);
    intStack.push(2);
    intStack.push(3);

    // Pop elements from the stack and print them
    while (!intStack.isEmpty()) {
        cout << intStack.pop() << endl;
    }

    return 0;
}
