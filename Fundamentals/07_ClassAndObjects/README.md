# Chapter 7: Introduction to Classes and Objects

This chapter introduces the fundamental concepts of object-oriented programming (OOP) in C++, focusing on classes,
objects, and their associated components.

-----

## 7.1 Abstract Data Types (ADTs)

An **Abstract Data Type (ADT)** is a programmer-created data type that specifies the legal values and the operations
that can be performed on them. Users of an ADT do not need to know the implementation details, such as how the data is
stored or how the operations are carried out. This concept, known as **abstraction**, lets a programmer design a
solution and use data without worrying about how the data is implemented. For example, when you use the `pow` function
in C++, you only need to know what inputs it expects and the type of result it produces; you don't need to know how the
function works internally.

-----

## 7.2 Object-Oriented Programming (OOP)

In contrast to procedural programming, where data and functions are separate, **Object-Oriented Programming (OOP)** is
centered on **objects**. An object is a software entity that combines data and the functions that operate on that data
into a single unit.

### Terminology

* **Attributes:** The data items of an object, stored in **member variables**.
* **Member functions (methods):** The procedures or functions that operate on the object's attributes.
* **Data hiding:** The practice of restricting access to an object's data to only its member functions. This provides a
  layer of protection against accidental or deliberate data corruption.
* **Encapsulation:** The bundling of an object's data and procedures into one single entity.

A simple example is a `Square` object, which might have a single data item `side` and member functions like `setSide` to
change the side's value and `getSide` to retrieve it.

-----

## 7.3 Introduction to Classes

A **class** is a programmer-defined data type used as a blueprint or pattern for creating objects. For example, when you
declare `string fName, lName;`, you are creating two objects of the `string` class.

The basic format for a class declaration is:

```cpp
class className
{
  declaration;
  declaration;
}; // Note the required semicolon
```

### Access Specifiers

**Access specifiers** control access to the members of a class.

* **public:** Members can be accessed by functions outside the class.
* **private:** Members can only be accessed or called by functions that are also members of the class.

By default, class members are private if no access specifier is used. It's a common convention to make member variables
private and accessor/mutator functions public.

-----

## 7.4 Creating and Using Objects

An object is an **instance** of a class. You create an object just like you define other variables. For example,
`Square sq1, sq2;` creates two objects of the `Square` class. You access an object's members using the **dot operator
** (`.`).

```cpp
sq1.setSide(5);
cout << sq1.getSide();
```

### Member Functions

Member functions can be categorized as:

* **Accessor (getter):** A function that uses but doesn't modify a member variable, like `getSide`.
* **Mutator (setter):** A function that modifies a member variable, like `setSide`.

-----

## 7.5 Defining Member Functions

Member functions are part of a class declaration. You can define them in one of two ways:

1. **Inside the class declaration:** These are known as **inline functions**. It's recommended to only use this for very
   short functions to reduce function call overhead.
2. **After the class declaration:** You place the function prototype inside the class and define the function later. In
   the function definition, you must precede the function name with the class name and the **scope resolution operator
   ** (`::`).

-----

## 7.6 Constructors

A **constructor** is a special public member function that is automatically called when a class object is created. It's
primarily used to initialize data members. A constructor must have the same name as the class and cannot have a return
type.

### Overloading and Default Constructors

A class can have multiple constructors, as long as each has a unique parameter list. A **default constructor** is one
that takes no arguments. If you define any constructors for a class, you should also define a default constructor.

### Member Initialization List

Starting with C++ 11, you can initialize member variables using a member initialization list. This is a comma-separated
list of member variables and their initial values that comes after the constructor's header and before its body. This
can make the constructor body empty, but the curly braces `{}` are still required. You can also initialize member
variables directly in the class declaration, which provides default values for all objects.

### Constructor Delegation

Also new in C++ 11, **constructor delegation** allows one constructor to call another constructor in the same class. The
notation is similar to a member initialization list.

-----

## 7.7 Destructors

A **destructor** is a public member function that is automatically called when an object is destroyed. Its purpose is to
perform any necessary cleanup before the object's memory is deallocated. A destructor's name is the class name preceded
by a tilde (`~`), it has no return type, and it takes no arguments. Unlike constructors, a class can only have one
destructor (it cannot be overloaded).

-----

## 7.8 Private Member Functions

A private member function can only be called by another member function of the same class. They are used for internal
processing that should not be accessible from outside the class.

-----

## 7.9 Passing Objects to Functions

You can pass a class object as an argument to a function.

* **Pass-by-value:** A local copy of the object is created, and the original object is not affected. This can be
  inefficient for large objects.
* **Pass-by-reference:** The function receives a reference to the original object, allowing it to be modified. To
  prevent unwanted modifications while still gaining the performance benefit, you can use a **`const` reference
  parameter**.

A function can also **return an object**. The function must create a local object to return.

-----

## 7.10 Object Composition

**Object composition** is a design technique where an object is a member variable of another object. This is useful for
designing complex objects from simpler ones. For instance, a `Carpet` class might have a `Rectangle` object as a member
to represent its dimensions.

-----

## 7.11 Separating Class Files

For good design, it's recommended to separate a class's declaration, member function definitions, and the client code
that uses the class into different files.

* **Header file (`.h`):** Contains the class declaration and serves as the class specification file (e.g., `Square.h`).
  Use **include guards** to prevent the file from being included more than once.
* **Implementation file (`.cpp`):** Contains the definitions of the member functions (e.g., `Square.cpp`). This file
  should `#include` the corresponding header file.
* **Client program file:** The program that uses the class. It must `#include` the header file and be compiled and
  linked with the implementation file.

-----

## 7.12 Structures

A **structure** is a programmer-defined data type that groups multiple variables together. By default, all members of a
structure are **public**. You declare a structure using the `struct` keyword, followed by the structure name, and then a
block of member declarations.

### Accessing Members and Initialization

To define a structure variable, use the structure name as the type, for example, `Student s1;`. You access the members
of a structure variable using the **dot operator (`.`)**.

Structure members cannot be initialized directly within the structure declaration. You can initialize them when a
variable is created using either an **initialization list** or a **constructor**. A constructor for a structure is
similar to a class constructor: it has the same name as the `struct`, no return type, and is used to initialize data
members.

### Nested Structures

A structure can have another structure as a member. To access members of a nested structure, you use the dot operator
multiple times.

### Structures as Function Arguments

You can pass an entire structure variable to a function. Similar to classes, passing by value is less efficient, while a
`const` reference parameter is ideal for saving time and protecting data from modification. A function can also return a
structure.

-----

## 7.13 More About Enumerated Data Types

An **enumerated data type** allows you to declare a set of named integer constants.

* You can define a data type and a variable in a single statement (e.g., `enum Tree {ASH, ELM, OAK} tree1, tree2;`).
* You can assign an `int` value to an `enum` variable using `static_cast` (e.g., `tree1 = static_cast<Tree>(1);`).
* You can assign an `enum` variable to an `int` (e.g., `int thisTree = tree1;`).

-----

## 7.15 Introduction to Object-Oriented Analysis and Design

**Object-Oriented Analysis (OOA)** is the phase of program development where a program's functionality is determined
from its requirements. This involves:

* Identifying classes and objects.
* Defining each class's attributes (what it needs to know).
* Defining each class's behaviors (what it needs to do).
* Defining the relationships between classes.

A common technique for finding candidate classes is to write a description of the problem and then list all the nouns,
noun phrases, and pronouns. The goal of this process is to create well-defined classes that can be reused in multiple
programs, which shortens development time.

-----

## 7.16 Screen Control

Basic output in C++ displays text starting from the top-left corner of the screen, moving left-to-right and
line-by-line. However, operating systems allow programs to access any part of the screen. In Windows, this is achieved
by including `<windows.h>` and using specific functions to set the cursor position based on row and column coordinates.
The screen can be thought of as a grid of rows and columns, with cell coordinates identified by their row and column
numbers.