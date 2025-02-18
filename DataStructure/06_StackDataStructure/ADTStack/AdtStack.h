#ifndef ADTSTACK_H
#define ADTSTACK_H

#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class ADTStack {
private:
    vector<T> elements; // The dynamic array to store stack elements

public:
    // Push element onto stack
    void push(const T& element);

    // Check if the stack is empty
    bool isEmpty() const;

    // Pop element from stack
    T pop();

    // Get the top element of the stack
    T peek() const;
};

#endif