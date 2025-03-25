/*
**Explanation and Key Concepts:**

    1.  **Point Class (Overloading `+`):**
        * This demonstrates how to overload the `+` operator to perform vector addition for `Point` objects.
        * `Point operator+(const Point& other) const` defines the addition operation.
        * The `friend std::ostream& operator<<(std::ostream& os, const Point& point)` function enables printing `Point` objects to the console using `std::cout`.

    2.  **Counter Class (Overloading `++`):**
        * This shows how to overload the prefix (`++c`) and postfix (`c++`) increment operators.
        * `Counter& operator++()` (prefix) increments the value and returns a reference to the modified object.
        * `Counter operator++(int)` (postfix) creates a temporary copy of the object, increments the original, and returns the temporary copy. The `int` parameter is a dummy parameter that distinguishes the postfix version from the prefix version.

    3.  **SimpleArray Class (Overloading `[]`):**
        * This demonstrates how to overload the `[]` operator to provide array-like access to elements of a custom class.
        * `int& operator[](int index)` provides read/write access to elements.
        * `int operator[](int index) const` provides read only access to elements, and is used when the SimpleArray is a const object.
        * It includes bounds checking to prevent out-of-range access.
        * It also shows how to overload the output stream operator to print the entire array.
        * It includes a try catch block in main to show how the out of range exception can be handled.
*/

#include <iostream>

// Exercise 1: Overload the '+' operator for a simple Point class.
class Point {
public:
    int x, y;

    Point(int x = 0, int y = 0) : x(x), y(y) {}

    Point operator+(const Point& other) const {
        return Point(x + other.x, y + other.y);
    }

    friend std::ostream& operator<<(std::ostream& os, const Point& point) {
        os << "(" << point.x << ", " << point.y << ")";
        return os;
    }
};

// Exercise 2: Overload the '++' (prefix and postfix) operators for a Counter class.
class Counter {
public:
    int value;

    Counter(int value = 0) : value(value) {}

    Counter& operator++() { // Prefix ++
        ++value;
        return *this;
    }

    Counter operator++(int) { // Postfix ++
        Counter temp = *this;
        ++value;
        return temp;
    }

    friend std::ostream& operator<<(std::ostream& os, const Counter& counter) {
        os << counter.value;
        return os;
    }
};

// Exercise 3: Overload the '[]' operator for a SimpleArray class.
class SimpleArray {
private:
    int* data;
    int size;

public:
    SimpleArray(int size) : size(size), data(new int[size]) {}

    ~SimpleArray() {
        delete[] data;
    }

    int& operator[](int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of bounds");
        }
        return data[index];
    }

    int operator[](int index) const {
         if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of bounds");
        }
        return data[index];
    }

    friend std::ostream& operator<<(std::ostream& os, const SimpleArray& arr) {
        os << "[";
        for (int i = 0; i < arr.size; ++i) {
            os << arr.data[i];
            if (i < arr.size - 1) {
                os << ", ";
            }
        }
        os << "]";
        return os;
    }
};

int main() {
    // Exercise 1: Point class
    Point p1(1, 2);
    Point p2(3, 4);
    Point p3 = p1 + p2;
    std::cout << "p1: " << p1 << ", p2: " << p2 << ", p1 + p2: " << p3 << std::endl;

    // Exercise 2: Counter class
    Counter c1(5);
    std::cout << "c1: " << c1 << std::endl;
    std::cout << "++c1: " << ++c1 << std::endl;
    std::cout << "c1++: " << c1++ << std::endl;
    std::cout << "c1: " << c1 << std::endl;

    // Exercise 3: SimpleArray class
    SimpleArray arr(5);
    for (int i = 0; i < 5; ++i) {
        arr[i] = i * 2;
    }
    std::cout << "arr: " << arr << std::endl;
    std::cout << "arr[2]: " << arr[2] << std::endl;
    arr[2] = 10;
    std::cout << "arr: " << arr << std::endl;

    try{
        arr[10];
    }
    catch(const std::out_of_range& e){
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}

