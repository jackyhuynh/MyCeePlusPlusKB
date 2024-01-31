#include <iostream>
/*
 Overloaded operators allow you to define custom behavior for operators (such as +, -, *, /, etc.)
 when they're applied to instances of your custom classes. 

 Here's an example that demonstrates both concepts, using a simple Vector2D class that represents a 
 2-dimensional vector. We'll overload the addition (+) operator to add two Vector2D objects together, and we'll use the friend keyword to allow the overloaded operator function to access private members of the class:
*/

// Forward declaration is necessary for the friend declaration.
class Vector2D;

// Overloaded operator function is declared as a friend.
Vector2D operator+(const Vector2D& lhs, const Vector2D& rhs);

class Vector2D {
private:
    float x, y;

public:
    // Constructor to initialize the vector.
    Vector2D(float x = 0.0, float y = 0.0) : x(x), y(y) {}

    // Friend declaration gives the operator+ function access to private members.
    // &: pass by constant reference
    friend Vector2D operator+(const Vector2D& lhs, const Vector2D& rhs);

    // Method to display the vector for demonstration purposes.
    void display() const {
        std::cout << "Vector2D(" << x << ", " << y << ")\n";
    }
};

// Implementation of the overloaded operator+. It has access to private members of Vector2D.
Vector2D operator+(const Vector2D& lhs, const Vector2D& rhs) {
    return Vector2D(lhs.x + rhs.x, lhs.y + rhs.y);
}

int main() {
    Vector2D vec1(1.0, 2.0), vec2(3.0, 4.0);

    // Use the overloaded + operator.
    Vector2D vec3 = vec1 + vec2;

    // Display the result.
    vec3.display();

    return 0;
}

/*
    Passed by constant reference in C++ is a method of passing arguments to functions 
    that combines the efficiency of pass-by-reference with the safety of pass-by-value. 
    This approach allows you to pass large or complex data types 
    (like objects, structs, or arrays) to functions without the overhead of 
    copying the entire data structure, while also ensuring that the original data 
    cannot be modified by the function. It's particularly useful when working with 
    large objects that you want to read without altering.
*/