#include <iostream>
/*
 Overloaded operators allow you to define custom behavior for operators (such as +, -, *, /, etc.)
 when they're applied to instances of your custom classes. 

 Here's an example that demonstrates both concepts, using a simple Vector2D class that represents a 
 2-dimensional vector. We'll overload the addition (+) operator to add two Vector2D objects together, and we'll use the friend keyword to allow the overloaded operator function to access private members of the class:
*/

class Vector2D;
Vector2D operator+(const Vector2D& lhs, const Vector2D& rhs);
Vector2D operator*(const Vector2D& lhs, const Vector2D& rhs);
std::ostream& operator<<(std::ostream& os, const Vector2D& obj);

class Vector2D {
private:
    float x, y;

public:
    Vector2D(float x = 0.0, float y = 0.0) : x(x), y(y) {}

    friend Vector2D operator+(const Vector2D& lhs, const Vector2D& rhs);

    friend Vector2D operator*(const Vector2D& lhs, const Vector2D& rhs);

    friend std::ostream& operator<<(std::ostream& os, const Vector2D& obj);
};

Vector2D operator+(const Vector2D& lhs, const Vector2D& rhs) {
    return Vector2D(lhs.x + rhs.x, lhs.y + rhs.y);
}

std::ostream& operator<<(std::ostream &os, const Vector2D &obj){
    std::cout << "Vector2D(" << obj.x << ", " << obj.y << ")\n";
    return os;
}

Vector2D operator*(const Vector2D& lhs, const Vector2D& rhs) {
    return Vector2D(lhs.x * rhs.x, lhs.y * rhs.y);
}

int main() {
    Vector2D vec1(1.0, 2.0), vec2(3.0, 4.0);

    std::cout << vec1 + vec2;

    std::cout << vec1 * vec2;

    return 0;
}