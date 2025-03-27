#include <iostream>
#include <string>

// Exercise 7: Inner Class with Multiple Inheritance
class BaseA {
public:
    int a;
    BaseA() : a(10) {}
    void printA() { std::cout << "BaseA: " << a << std::endl; }
};

class BaseB {
public:
    std::string b;
    BaseB() : b("Hello") {}
    void printB() { std::cout << "BaseB: " << b << std::endl; }
};

class Outer7 {
public:
    int outerData;
    Outer7() : outerData(70) {}

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
    int grandBaseData;
    GrandBase() : grandBaseData(100) {}
    void printGrandBase() { std::cout << "GrandBase: " << grandBaseData << std::endl; }
};

class IntermediateBase : public GrandBase {
public:
    int intermediateData;
    IntermediateBase() : intermediateData(200) {}
    void printIntermediate() { std::cout << "Intermediate: " << intermediateData << std::endl; }
};

class Outer8 {
public:
    int outerData;
    Outer8() : outerData(80) {}

    class Inner8 : public IntermediateBase {
    public:
        void printAll(const Outer8& outer) {
            printGrandBase();
            printIntermediate();
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

    return 0;
}