#include <iostream>

/**
 *Virtual (in the context of C++)
 * Virtual Functions:
 * In C++, the virtual keyword is used in the declaration of a member function in a base class to 
 * indicate that the function can be overridden by derived classes. This is a key aspect of achieving runtime polymorphism through dynamic dispatch.

 * **/
class Base {
public:
    virtual void someFunction() {
        // Base class implementation
    }
};

class Derived : public Base {
public:
    void someFunction() override {
        // Derived class implementation
    }
};

/**
 * Here, the virtual keyword in the Base class allows derived classes like Derived to provide their own implementation of the someFunction method.
 * Prototype (in the context of C)
 * Function Prototype:
 * In C, the term "prototype" typically refers to the declaration of a function before its actual implementation.
 * A function prototype provides information about the function's name, return type, and parameters. It allows the compiler to check the correctness of function calls and to perform type checking.
 * 
*/

// Function prototype
int add(int a, int b);

int main() {
    int result = add(3, 4);  // Function call based on the prototype
    std::cout << result << std::endl;
    return 0;
}

// Function definition
int add(int a, int b) {
    return a + b;
}

// In this example, the add function prototype declares the function's signature before its actual implementation. This allows the main function to call add before the function's full definition.
// To sum up, "virtual" in C++ refers to the usage of the virtual keyword in the context of polymorphism, particularly with virtual functions. On the other hand, "prototype" in C refers to the declaration of a function before its implementation for proper function calling and type checking. The two concepts are related to different aspects of programming in their respective languages.





