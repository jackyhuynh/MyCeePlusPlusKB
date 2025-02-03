//### **Exercise 1: Shape Hierarchy (Polymorphism & Virtual Functions)**
//**Objective:** Implement a base class `Shape` with a virtual function `area()`. Create derived classes (`Circle`, `Rectangle`, `Triangle`) that override `area()`.
//
//**Requirements:**
//- Define a base class `Shape` with a **pure virtual function** `area()`.
//- Create derived classes `Circle`, `Rectangle`, and `Triangle`.
//- Implement `area()` in each derived class.
//- Use **polymorphism** to compute the area dynamically.

#include <iostream>
#include <cmath> // for M_PI

class Shape {
public:
    virtual double area() const = 0; // Pure virtual function
    virtual void display() const {
        std::cout << "This is a shape.\n";
    }
    virtual ~Shape() {} // Virtual destructor
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() const override {
        return M_PI * radius * radius;
    }
    void display() const override {
        std::cout << "Circle with area: " << area() << "\n";
    }
};

// class Rectangle : public Shape {}

// class Triangle : public Shape {}

int main() {
    Shape* shapes[] = {
        new Circle(5),
        new Rectangle(4, 6),
        new Triangle(3, 7)
    };

    for (Shape* shape : shapes) {
        shape->display();
        delete shape;
    }

    return 0;
}

//### **Expected Output**
//Circle with area: 78.5398
//Rectangle with area: 24
//Triangle with area: 10.5


//### **Concepts Covered in These Exercises**
//✅ **Polymorphism:** Using `virtual` functions to dynamically determine method calls.
//✅ **Abstract Classes & Pure Virtual Functions:** Ensuring derived classes implement specific behavior.
//✅ **Memory Management:** Proper usage of `delete` to avoid memory leaks.
//✅ **Encapsulation & Inheritance:** Structuring reusable and extensible code.