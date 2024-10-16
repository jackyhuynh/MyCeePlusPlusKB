# Virtual Class

In C++ and computer science, the concept of a **virtual class** is closely related to **virtual functions** and *
*inheritance**, specifically focusing on allowing runtime polymorphism and proper handling of object hierarchies.

### Virtual Functions in C++

A **virtual function** is a function that is defined in a base class and is meant to be overridden in derived classes.
When a function is declared as `virtual` in a base class, C++ ensures that the function that gets called is the one in
the derived class, even when you're working with a pointer or reference to the base class. This allows for **runtime
polymorphism**.

#### Key Concepts of Virtual Functions:

1. **Dynamic dispatch**: The function that is executed is determined at runtime based on the actual type of the object,
   not the pointer/reference type.
2. **Overriding**: A derived class can provide its own implementation of a virtual function defined in the base class.

#### Example of Virtual Function:

```cpp
#include <iostream>
using namespace std;

class Animal {
public:
    virtual void sound() {
        cout << "Animal makes a sound" << endl;
    }
};

class Dog : public Animal {
public:
    void sound() override {
        cout << "Dog barks" << endl;
    }
};

class Cat : public Animal {
public:
    void sound() override {
        cout << "Cat meows" << endl;
    }
};

int main() {
    Animal* animalPtr;
    Dog dog;
    Cat cat;

    animalPtr = &dog;
    animalPtr->sound();  // Output: Dog barks

    animalPtr = &cat;
    animalPtr->sound();  // Output: Cat meows

    return 0;
}
```

In this example:

- The function `sound()` is declared as virtual in the base class `Animal`.
- Both `Dog` and `Cat` override `sound()` to provide their specific implementations.
- The correct function is called based on the actual object type, even when accessed through a base class pointer.

### Virtual Class (Pure Virtual Class or Abstract Class)

In C++, the term **virtual class** often refers to a class that contains one or more **pure virtual functions**, making
it an **abstract class**. You cannot instantiate an abstract class directly; instead, you must derive from it and
implement its pure virtual functions in the derived class.

#### Pure Virtual Function:

A pure virtual function is a virtual function that has no implementation in the base class and is defined by assigning
`= 0` in the base class.

#### Example of Pure Virtual Class (Abstract Class):

```cpp
#include <iostream>
using namespace std;

class Shape {
public:
    // Pure virtual function
    virtual void draw() = 0;
};

class Circle : public Shape {
public:
    void draw() override {
        cout << "Drawing Circle" << endl;
    }
};

class Rectangle : public Shape {
public:
    void draw() override {
        cout << "Drawing Rectangle" << endl;
    }
};

int main() {
    Shape* shapePtr;
    Circle circle;
    Rectangle rectangle;

    shapePtr = &circle;
    shapePtr->draw();  // Output: Drawing Circle

    shapePtr = &rectangle;
    shapePtr->draw();  // Output: Drawing Rectangle

    return 0;
}
```

In this example:

- `Shape` is an abstract class because it contains the pure virtual function `draw()`.
- `Circle` and `Rectangle` are derived classes that provide implementations for `draw()`.
- You cannot create an object of `Shape`, but you can create objects of `Circle` and `Rectangle`, which inherit from
  `Shape`.

### Virtual Classes in Computer Science

In broader computer science terms, **virtual classes** are used in the context of object-oriented programming and
inheritance hierarchies. They allow for flexible design and implementation of systems where specific behavior can be
defined in base classes and further specialized in derived classes.

Some important points about virtual classes in computer science:

1. **Abstraction**: Virtual (abstract) classes enable abstraction by providing an interface for other classes to follow,
   forcing derived classes to implement specific functionality.
2. **Polymorphism**: Virtual classes and functions support polymorphism, where different derived classes can be used
   interchangeably through a common base class interface.
3. **Design Patterns**: Virtual classes are fundamental in implementing many design patterns, such as the **Factory
   Pattern** or **Strategy Pattern**, by providing a common interface while allowing for dynamic selection of specific
   implementations at runtime.

### Summary:

- **Virtual functions** enable dynamic dispatch and runtime polymorphism.
- **Abstract classes** (or "virtual classes") in C++ contain pure virtual functions and cannot be instantiated directly.
- Virtual classes in general allow for abstraction and provide a framework for designing flexible and reusable software
  systems.