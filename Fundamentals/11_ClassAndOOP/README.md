# Chapter 11: More about Classes and Object-Oriented Programming

This chapter dives deeper into advanced concepts of class design and object-oriented programming in C++, including
special pointers, static members, and inheritance. 🧐

---

## 11.1 The `this` Pointer and Constant Member Functions

The **`this` pointer** is an implicit parameter passed to every member function of a class. It's a pointer that points
to the specific object calling the function. The `this` pointer can be used to access members of the object, especially
when a member variable is hidden by a function parameter with the same name.

A **constant member function** is a function that does not modify the object it belongs to. This is declared by placing
the `const` keyword after the parameter list in the function's prototype and header. When `const` is placed in the
parameter list, it prevents the function from modifying that specific parameter.

---

## 11.2 Static Members

**Static member variables** are shared among all objects of a class; there's only a single instance of the variable for
the entire class. They must be declared with the `static` keyword inside the class and defined outside the class. Any
modification by one object is visible to all other objects of that class.

**Static member functions** can be used to access static member variables. They can be called even before any class
objects are created, by using the class name and the scope resolution operator (e.g., `IntVal::getValCount()`). Because
they aren't tied to a specific object, the `this` pointer cannot be used inside a static member function.

---

## 11.3 Friends of Classes

A **friend function** is a function that isn't a member of a class but has special access to its private members. A
friend function can be a standalone function or a member function of another class. It is declared using the `friend`
keyword within the class definition.

An entire class can also be declared a **friend class**. If `frClass` is a friend of `aClass`, all member functions of
`frClass` have unrestricted access to all members of `aClass`, including its private members.

---

## 11.4 Memberwise Assignment

**Memberwise assignment** is the default behavior when you use the assignment operator (`=`) to assign one object to
another. C++ automatically copies each member variable from the source object to the destination object. This works well
for simple objects but can cause problems when objects contain pointers to dynamic memory.

---

## 11.5 Copy Constructors

A **copy constructor** is a special constructor that's automatically used when a new object is initialized with the data
from an existing object of the same class. The default copy constructor performs a shallow copy, which means it copies
the addresses of dynamic memory members, leading to shared storage and potential issues like dangling pointers when a
destructor is called.

To fix this, a **programmer-defined copy constructor** can be created. This constructor takes a reference to another
object as a parameter and performs a **deep copy**. A deep copy allocates new, separate memory for the new object's
dynamic members and copies the data, not the pointers, from the original object.

A copy constructor is called when:

* An object is initialized from another object of the same class.
* An object is passed by value to a function.
* An object is returned from a function by value.

---

## 11.6 Operator Overloading

**Operator overloading** allows you to redefine standard operators like `+` or `=` for use with objects of a class. The
function for an overloaded operator is named `operator` followed by the operator symbol (e.g., `operator+`).

* **Instance member functions**: When overloaded as a member, a binary operator only needs one parameter for the
  right-hand operand, as the left-hand operand is the calling object (accessible via the `this` pointer).
* **Friend functions**: Overloading as a standalone or friend function is often used for stream operators (`<<`, `>>`).

Overloading the assignment operator (`=`) is particularly important for objects with dynamic memory to prevent the
issues of shallow copying.

---

## 11.7 Rvalue References and Move Operations

Introduced in C++ 11, **rvalue references** and **move operations** provide a more efficient way to handle temporary,
unnamed values (**rvalues**). An rvalue is a temporary value that exists only for a single expression, like the result
of `pow(3.0, 2)`.

An **rvalue reference** is a reference variable that can bind to an rvalue. Declaring an rvalue reference with `&&`
gives a name to the temporary location, making it accessible.

**Move constructors** and **move assignment operators** use rvalue references to "steal" the dynamic memory from a
temporary object rather than performing a resource-intensive copy operation. They are much more efficient for objects
with dynamic memory because they simply transfer ownership of the memory, rather than allocating new memory and copying
the data.

---

## 11.8 Type Conversion Operators

**Type conversion operators** are special member functions that instruct the compiler how to convert an object of a
class type to another type (e.g., an `int`). They are automatically used by the compiler in assignments,
initializations, and when passing parameters. The operator's name is the name of the type it converts to, and it doesn't
specify a return type.

## 11.9 Convert Constructors

A **convert constructor** is a constructor that takes a single parameter of a type different from the class itself. They
are automatically invoked by the compiler to create a class object from a value of another type. This allows for
implicit conversions, such as initializing a `string` object with a C-style string literal.

---

## 11.10 Aggregation and Composition

**Aggregation** describes a "has-a" relationship where an object of one class owns an object of another class. *
*Composition** is a form of aggregation where the owning class controls the lifetime of the owned object.

When using aggregation or composition, a **member initialization list** is used in the constructor of the owning class
to pass arguments to the constructor of the owned class.

---

## 11.11 Inheritance

**Inheritance** is a mechanism for creating a new class (**derived class**) from an existing class (**base class**). The
derived class inherits all the members of the base class and can add new members or modify existing functionality. This
models the "is-a" relationship, where a derived class "is a" type of the base class.

---

## 11.12 Protected Members and Class Access

A **`protected`** member of a class is accessible to member functions of derived classes in addition to members of the
same class. This provides more access than `private` but maintains some encapsulation.

**Base class access specification** (public, protected, or private) determines how members inherited from the base class
appear in the derived class.

* **`public` inheritance**: Public members of the base class become public in the derived class, and protected members
  become protected.
* **`protected` inheritance**: Public and protected members of the base class both become protected in the derived
  class.
* **`private` inheritance**: Public and protected members of the base class both become private in the derived class.

---

## 11.13 Constructors, Destructors, and Inheritance

When a derived class object is created, the base class's constructor is always executed first, followed by the derived
class's constructor. Conversely, when the object is destroyed, the derived class's destructor is called first, then the
base class's destructor.

You can explicitly pass arguments to a base class constructor from the derived class constructor's heading, which is
necessary if the base class doesn't have a default constructor.

---

## 11.14 Overriding Base Class Functions

**Overriding** occurs when a function in a derived class has the same name and parameter list as a function in the base
class. This is different from overloading, which requires different parameter lists. Overriding is used to replace a
base class function's behavior in the derived class. You can still access the original base class function using the
scope resolution operator (`::`) if needed.