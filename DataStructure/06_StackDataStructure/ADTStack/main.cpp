#include <iostream>
#include "AdtStack.h"

using namespace std;

int main() {
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
