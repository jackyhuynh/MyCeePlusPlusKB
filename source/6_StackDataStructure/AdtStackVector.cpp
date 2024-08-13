// https://en.cppreference.com/w/cpp/container/vector

#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Stack {
private:
    vector<T> elements; // The dynamic array to store stack elements

public:
    // Push element onto stack
    void push(const T& element) {
        elements.push_back(element);
    }

    // Check if the stack is empty
    bool isEmpty() const {
        return elements.empty();
    }

    // Pop element from stack
    T pop() {
        if (isEmpty()) {
            throw out_of_range("Stack<>::pop(): empty stack");
        }
        T topElement = elements.back();
        elements.pop_back(); // Remove last element
        return topElement;
    }

    // Get the top element of the stack
    T top() const {
        if (isEmpty()) {
            throw out_of_range("Stack<>::top(): empty stack");
        }
        return elements.back();
    }
};

int main() {
    Stack<int> intStack; // Create a stack of ints

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
