#include <iostream>
#include "Stack.h"

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

    return 0;
}
