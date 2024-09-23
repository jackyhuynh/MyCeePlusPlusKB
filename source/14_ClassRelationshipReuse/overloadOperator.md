# **Operator Overloading in C++**

---

**Operator overloading** allows you to redefine how operators (like `+`, `-`, `*`, etc.) work for user-defined types. This makes it possible to use operators on objects just as you would with built-in types.

## Resource:
- [Overload Operator](./OverloadOperator.cpp)
- [Array Overload Operator](./ArrayOverloadOperator.cpp)

## **Key Points**:
- You can overload most operators, except for a few like `.` (dot), `::` (scope resolution), and `?:` (ternary).
- Overloading operators makes your code more intuitive and cleaner when working with objects.
- Operator overloading functions can be member functions or non-member functions (friend functions).

## **Common Overloadable Operators**:
- **Arithmetic operators**: `+`, `-`, `*`, `/`, `%`
- **Comparison operators**: `==`, `!=`, `<`, `>`, `<=`, `>=`
- **Assignment operators**: `=`, `+=`, `-=`, `*=`, `/=`
- **Increment/Decrement operators**: `++`, `--`

## **Code Example (Operator Overloading for `+`)**:

```cpp
#include <iostream>
using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    Complex() : real(0), imag(0) {}
    Complex(double r, double i) : real(r), imag(i) {}

    // Overload the + operator
    Complex operator + (const Complex& obj) {
        Complex temp;
        temp.real = real + obj.real;
        temp.imag = imag + obj.imag;
        return temp;
    }

    void display() {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main() {
    Complex c1(3.0, 4.0);
    Complex c2(1.5, 2.5);
    Complex c3;

    c3 = c1 + c2;  // Using overloaded + operator

    cout << "Result of addition: ";
    c3.display();

    return 0;
}
```

## **Use Case**:
Operator overloading is frequently used when you need to make user-defined types behave like primitive types. For example, a **`Complex`** number class benefits from overloading the `+`, `-`, and `*` operators to allow for intuitive arithmetic operations on complex numbers.

---

## **Friend Function with Operator Overloading**

Sometimes, operator overloading is implemented using a **friend function** when the operator needs to access private members of both operands but is not a member of the class.

## **Code Example (Overloading `<<` for Output Stream Using Friend Function)**:

```cpp
#include <iostream>
using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    // Friend function to overload << operator for output
    friend ostream& operator<<(ostream& os, const Complex& c);
};

// Define the friend function for << overloading
ostream& operator<<(ostream& os, const Complex& c) {
    os << c.real << " + " << c.imag << "i";
    return os;
}

int main() {
    Complex c1(3.2, 4.5);
    cout << "Complex number: " << c1 << endl;

    return 0;
}
```

## **Use Case**:
Overloading the stream insertion (`<<`) and extraction (`>>`) operators using friend functions is a common practice to make classes compatible with input/output streams in C++.

---

## **Summary**:

- **Operator overloading** provides a way to redefine how operators behave for user-defined types, making object manipulation easier and more intuitive.
- Combining **friend functions** and **operator overloading** is often done to provide more flexibility in accessing private data, especially when dealing with multiple classes or input/output operations.