# C++ Chapter 14: Interlude 5: Class Relationships and Reuse

---

## Resources:

- [Friend in C++](Friend/README)
- [Overload Operator in C++](OverloadOperator/README)

## **1. Inheritance Revisited**

Inheritance allows for the reuse of code by creating new classes based on existing ones. It establishes an **is-a
relationship** between classes.

### **Multiple Inheritance**:

- A class can inherit from more than one base class.
- This can lead to complex hierarchies but provides flexibility for reuse.

### **Code Example**:

```cpp
class PlainBox {
public:
    void display() { std::cout << "This is a plain box." << std::endl; }
};

class MagicBox : public PlainBox {
public:
    void display() { std::cout << "This is a magic box." << std::endl; }
};
```

### **Use Case**:

Inheritance is commonly used to build specialized versions of general classes. For example, a `MagicBox` inherits the
properties of `PlainBox` but can add or modify behaviors like magic-specific functions.

---

## **2. Late Binding and Polymorphism**

Polymorphism allows objects of different types to be treated as objects of a base class. **Late binding** (or **dynamic
binding**) occurs when the method to call is determined at runtime, allowing for different behaviors in derived classes.

### **Virtual Methods**:

- A virtual method can be overridden in a derived class.
- The method that is executed is determined by the object’s actual type at runtime.

### **Code Example**:

```cpp
class Base {
public:
    virtual void display() { std::cout << "Base class display" << std::endl; }
};

class Derived : public Base {
public:
    void display() override { std::cout << "Derived class display" << std::endl; }
};

int main() {
    Base* basePtr = new Derived();
    basePtr->display();  // Outputs: "Derived class display"
}
```

### **Use Case**:

Polymorphism is used when you want to write flexible and reusable code that can work with objects of different types,
such as managing different types of UI components in a graphical application.

---

## **3. Public, Private, and Protected Sections**

- **Public**: Members are accessible from outside the class.
- **Private**: Members are only accessible from within the class.
- **Protected**: Members are accessible from within the class and derived classes.

### **Access in Inheritance**:

- **Public inheritance**: Derived classes inherit public and protected members of the base class.
- **Private inheritance**: Public and protected members of the base class become private in the derived class.
- **Protected inheritance**: Public and protected members of the base class become protected in the derived class.

### **Use Case**:

These access control specifiers allow for encapsulation and control over how class members are accessed and modified,
which is crucial in large-scale software development.

---

## **4. Containment: Has-a Relationships**

Containment, also called **has-a relationship**, is when one class contains an object of another class as a data member.
This relationship provides composition, allowing complex classes to be built from simpler ones.

### **Execution Order**:

1. The base class constructor is called first.
2. Constructors of member objects are called next in the order they are declared.
3. The body of the derived class constructor is executed last.

### **Code Example**:

```cpp
class Pen {
public:
    void write() { std::cout << "Writing..." << std::endl; }
};

class Notebook {
private:
    Pen pen;  // Notebook "has a" Pen

public:
    void usePen() { pen.write(); }
};
```

### **Use Case**:

Containment is used to model real-world relationships where one object contains another, such as a `Car` class that
contains `Engine` and `Wheel` objects.

---

## **5. Abstract Base Classes**

An **abstract base class** defines an interface for derived classes. It contains at least one pure virtual method, which
means it cannot be instantiated but must be overridden by derived classes.

### **Code Example**:

```cpp
class AbstractBox {
public:
    virtual void display() = 0;  // Pure virtual function
};

class ConcreteBox : public AbstractBox {
public:
    void display() override { std::cout << "Concrete box display" << std::endl; }
};
```

### **Use Case**:

Abstract base classes are used to define interfaces that must be implemented by derived classes, such as in GUI
frameworks where an abstract `Widget` class defines common behavior for all widgets.

---

## **Conclusion**

- **Inheritance** and **polymorphism** allow for code reuse and flexible design.
- Access control mechanisms like **public**, **private**, and **protected** enable proper encapsulation.
- **Containment** and **abstract base classes** provide ways to design complex and modular systems.

---

This summary provides an overview of the concepts covered in C++ Interlude 5, such as inheritance, polymorphism, and
abstract classes, with practical use cases and code examples.