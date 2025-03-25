//**Explanation:**
//
//1.  **Simple Inner Class (Outer1):**
//    * Demonstrates basic access to the outer class's public members from the inner class.
//2.  **Inner Class with Private Access (Outer2):**
//    * Shows how inner classes can access private members of the outer class.
//3.  **Inner Class with Outer Class Methods (Outer3):**
//    * Illustrates how inner classes can call methods of the outer class.
//4.  **Nested Inner Classes (Outer4):**
//    * Explores nested inner classes, showing how inner classes can be nested within other inner classes.
//5.  **Inner Class with Templates (Outer5):**
//    * Introduces templates, allowing inner classes to work with generic types.
//6.  **Inner Class with Inheritance and Virtual Functions (Outer6):**
//    * Covers inheritance and virtual functions, demonstrating how inner classes can be derived and override virtual methods. This exercise includes both derived outer and inner classes.

#include <iostream>
#include <vector>
#include <string>

// Exercise 1: Simple Inner Class
class Outer1 {
public:
    int outerData = 10;

    class Inner1 {
    public:
        void printOuterData(const Outer1& outer) {
            std::cout << "Outer data from inner: " << outer.outerData << std::endl;
        }
    };
};

// Exercise 2: Inner Class with Private Access
class Outer2 {
private:
    int outerPrivateData = 20;

public:
    class Inner2 {
    public:
        void printOuterData(const Outer2& outer) {
            std::cout << "Outer private data from inner: " << outer.outerPrivateData << std::endl;
        }
    };
};

// Exercise 3: Inner Class with Outer Class Methods
class Outer3 {
public:
    int outerData = 30;

    void outerMethod() {
        std::cout << "Outer method called." << std::endl;
    }

    class Inner3 {
    public:
        void callOuterMethod(Outer3& outer) {
            outer.outerMethod();
            std::cout << "Inner class using outer data: " << outer.outerData << std::endl;
        }
    };
};

// Exercise 4: Nested Inner Classes
class Outer4 {
public:
    int outerData = 40;

    class Inner4A {
    public:
        void printOuterData(const Outer4& outer) {
            std::cout << "Inner A using outer data: " << outer.outerData << std::endl;
        }

        class Inner4B {
        public:
            void printOuterData(const Outer4& outer) {
                std::cout << "Inner B using outer data: " << outer.outerData << std::endl;
            }
        };
    };
};

// Exercise 5: Inner Class with Templates
template <typename T>
class Outer5 {
public:
    T outerData;

    Outer5(T data) : outerData(data) {}

    template <typename U>
    class Inner5 {
    public:
        void printOuterData(const Outer5<T>& outer, U innerData) {
            std::cout << "Outer data from inner: " << outer.outerData << ", Inner data: " << innerData << std::endl;
        }
    };
};

// Exercise 6: Inner Class with Inheritance and Virtual Functions
class Outer6 {
public:
    virtual void outerMethod() {
        std::cout << "Base outer method." << std::endl;
    }

    class Inner6 {
    public:
        virtual void innerMethod(Outer6& outer) {
            outer.outerMethod();
        }
    };
};

class DerivedOuter6 : public Outer6 {
public:
    void outerMethod() override {
        std::cout << "Derived outer method." << std::endl;
    }
};

class DerivedInner6 : public Outer6::Inner6 {
public:
    void innerMethod(Outer6& outer) override {
        outer.outerMethod();
        std::cout << "Derived inner method." << std::endl;
    }
};

int main() {
    // Exercise 1
    Outer1::Inner1 inner1;
    Outer1 outer1Instance;
    inner1.printOuterData(outer1Instance);

    // Exercise 2
    Outer2::Inner2 inner2;
    Outer2 outer2Instance;
    inner2.printOuterData(outer2Instance);

    // Exercise 3
    Outer3::Inner3 inner3;
    Outer3 outer3Instance;
    inner3.callOuterMethod(outer3Instance);

    // Exercise 4
    Outer4::Inner4A::Inner4B inner4b;
    Outer4 outer4Instance;
    inner4b.printOuterData(outer4Instance);

    // Exercise 5
    Outer5<std::string>::Inner5<int> inner5;
    Outer5<std::string> outer5Instance("Hello");
    inner5.printOuterData(outer5Instance, 123);

    // Exercise 6
    DerivedOuter6 derivedOuter6Instance;
    DerivedInner6 derivedInner6Instance;
    derivedInner6Instance.innerMethod(derivedOuter6Instance);

    return 0;
}
