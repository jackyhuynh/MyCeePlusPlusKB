#include "ADTStack.h"

// Push element onto the stack
template <typename T>
void ADTStack<T>::push(const T& element) {
    elements.push_back(element); // Adds the element to the end of the vector (top of the stack)
}

// Check if the stack is empty
template <typename T>
bool ADTStack<T>::isEmpty() const {
    return elements.empty(); // Returns true if the vector is empty, false otherwise
}

// Pop element from the stack
template <typename T>
T ADTStack<T>::pop() {
    if (isEmpty()) {
        throw std::out_of_range("Stack underflow: cannot pop from an empty stack");
    }
    T topElement = elements.back(); // Get the last element in the vector (top of the stack)
    elements.pop_back();            // Remove the last element
    return topElement;
}

// Get the top element of the stack without removing it
template <typename T>
T ADTStack<T>::top() const {
    if (isEmpty()) {
        throw std::out_of_range("Stack is empty: cannot get the top element");
    }
    return elements.back(); // Return the last element in the vector
}

// Explicit instantiations of the template class for common types (Optional but useful for compilation)
template class ADTStack<int>;
template class ADTStack<double>;
template class ADTStack<string>;
