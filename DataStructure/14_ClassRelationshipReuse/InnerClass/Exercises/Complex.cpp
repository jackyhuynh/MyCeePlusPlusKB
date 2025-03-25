/*
*       *Explanation:**
    1.  **Exercise 7 (Multiple Inheritance):**
        * Demonstrates how an inner class can inherit from multiple base classes (`BaseA` and `BaseB`).
        * The `Inner7` class inherits members and methods from both base classes.
    2.  **Exercise 8 (Multi-level Inheritance):**
        * Shows multi-level inheritance, where `Inner8` inherits from `IntermediateBase`, which itself inherits from `GrandBase`.
        * This demonstrates how an inner class can be part of a complex inheritance hierarchy.
    3.  **Exercise 9 (Virtual Multiple Inheritance):**
        * This shows how to use virtual inheritance to solve the diamond problem.
        * Both `DerivedVirtualA` and `DerivedVirtualB` inherit virtually from `VirtualBase`, ensuring that `Inner9` contains only one copy of `VirtualBase`.
        * The `printVirtual()` override is called to demonstrate how the virtual function is handled.
 */

#include <iostream>
#include <string>

// Exercise 7: Inner Class with Multiple Inheritance
class BaseA {
public:
    int a = 10;
    void printA() { std::cout << "BaseA: " << a << std::endl; }
};

class BaseB {
public:
    std::string b = "Hello";
    void printB() { std::cout << "BaseB: " << b << std::endl; }
};

class Outer7 {
public:
    int outerData = 70;

    class Inner7 : public BaseA, public BaseB {
    public:
        void printAll(const Outer7& outer) {
            printA();
            printB();
            std::cout << "Outer: " << outer.outerData << std::endl;
        }
    };
};

// Exercise 8: Inner Class with Multi-level Inheritance
class GrandBase {
public:
    int grandBaseData = 100;
    void printGrandBase() { std::cout << "GrandBase: " << grandBaseData << std::endl; }
};

class IntermediateBase : public GrandBase {
public:
    int intermediateData = 200;
    void printIntermediate() { std::cout << "Intermediate: " << intermediateData << std::endl; }
};

class Outer8 {
public:
    int outerData = 80;

    class Inner8 : public IntermediateBase {
    public:
        void printAll(const Outer8& outer) {
            printGrandBase();
            printIntermediate();
            std::cout << "Outer: " << outer.outerData << std::endl;
        }
    };
};

// Exercise 9: Inner Class with Virtual Multiple Inheritance
class VirtualBase {
public:
    int virtualData = 300;
    virtual void printVirtual() { std::cout << "VirtualBase: " << virtualData << std::endl; }
};

class DerivedVirtualA : public virtual VirtualBase {
public:
    void printVirtual() override { std::cout << "Derived Virtual A: " << virtualData << std::endl; }
};

class DerivedVirtualB : public virtual VirtualBase {
public:
    void printVirtual() override { std::cout << "Derived Virtual B: " << virtualData << std::endl; }
};

class Outer9 {
public:
    int outerData = 90;

    class Inner9 : public DerivedVirtualA, public DerivedVirtualB {
    public:
        void printAll(const Outer9& outer) {
            printVirtual();
            std::cout << "Outer: " << outer.outerData << std::endl;
        }
    };
};

int main() {
    // Exercise 7: Multiple Inheritance
    Outer7::Inner7 inner7;
    Outer7 outer7Instance;
    inner7.printAll(outer7Instance);

    // Exercise 8: Multi-level Inheritance
    Outer8::Inner8 inner8;
    Outer8 outer8Instance;
    inner8.printAll(outer8Instance);

    // Exercise 9: Virtual Multiple Inheritance
    Outer9::Inner9 inner9;
    Outer9 outer9Instance;
    inner9.printAll(outer9Instance);

    return 0;
}
