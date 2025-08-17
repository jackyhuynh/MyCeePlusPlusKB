# Chapter 10: Pointers

This chapter introduces the concept of **pointers**, which are variables that store memory addresses. Pointers provide
an alternative way to access and manipulate data in a program.

---

## 10.1 Pointers and the Address Operator

Every variable in a program is stored at a unique location in memory, which has a specific address. You can get the
memory address of a variable using the **address operator (`&`)**. The address of a memory location is a **pointer**.

---

## 10.2 Pointer Variables

A **pointer variable** is a variable specifically designed to hold a memory address. Pointers offer an alternative way
to access data stored in memory.

To define a pointer variable, you use the **indirection operator (`*`)**. The `*` indicates that the variable is a
pointer. For example, `int *intptr;` defines a variable named `intptr` that can hold the address of an `int`.

Once a pointer variable holds the address of another variable, you can use the indirection operator (`*`) again to
access the value at that address. For example, if `intptr` holds the address of `num`, `*intptr` refers to the value of
`num`.

---

## 10.3 The Relationship Between Arrays and Pointers

An array name is actually the starting address of the array in memory. For example, if `int vals[] = {4, 7, 11};` is
defined, `vals` is the starting address of the array. Because of this relationship, an array name can be used as a
pointer constant, and a pointer can be used as an array name.

You can access array elements using array notation (`vals[i]`) or pointer notation (`*(vals + i)`). Neither method
performs bounds checking, so it's possible to access memory outside the array's bounds.

---

## 10.4 Pointer Arithmetic

Some arithmetic operations can be performed on pointers.

* **Increment and Decrement**: The `++` and `--` operators can be used to move a pointer to the next or previous memory
  location of its data type.
* **Addition and Subtraction**: You can add or subtract an integer to a pointer to move it forward or backward by a
  specific number of memory locations. You can also subtract one pointer from another to find the number of elements
  between their addresses.

---

## 10.5 Initializing Pointers

You can initialize a pointer to `NULL` or `0` to indicate that it doesn't point to a valid memory location. You can also
initialize a pointer with the address of an existing variable, but the data types must match.

In C++ 11, the `nullptr` keyword is used to indicate an invalid memory location, and empty curly braces `{}` can be used
to initialize a pointer to its default value, which is `nullptr`.

---

## 10.6 Comparing Pointers

Relational operators can be used to compare the addresses stored in pointers. This is different from comparing the
values the pointers point to, which requires the use of the indirection operator (`*`).

---

## 10.7 Pointers as Function Parameters

A pointer can be used as a function parameter, providing a way to pass arguments by reference. When a function is
called, the address of the argument is passed to the pointer parameter. To access or modify the value at that address
within the function, the pointer must be explicitly dereferenced using the `*` operator. When an array is passed to a
function using a pointer parameter, you can access the array elements using either subscript notation or pointer
arithmetic.

---

## 10.8 Pointers to Constants and Constant Pointers

* **Pointer to a Constant**: A pointer that points to a constant value. You can change the address the pointer holds,
  but you cannot change the value at that address. The `const` keyword is placed before the data type.
* **Constant Pointer**: A pointer whose address cannot be changed after it is initialized. The `const` keyword is placed
  between the `*` and the pointer variable name. You must initialize a constant pointer when you define it.
* **Constant Pointer to a Constant**: A pointer that cannot change its address and points to a value that also cannot be
  changed.

---

## 10.9 Dynamic Memory Allocation

**Dynamic memory allocation** allows you to allocate storage for a variable while a program is running.

* **`new` operator**: Used to dynamically allocate a single variable or an array. It returns the address of the newly
  allocated memory.
* **`delete` operator**: Used to free memory that was dynamically allocated with `new`. Use `delete` for a single
  variable and `delete []` for an array. It should only be used on memory allocated with `new`.

If a pointer holds the address of memory that has been freed, it becomes a **dangling pointer**. A **memory leak**
occurs when dynamic memory is no longer needed but is not freed, making it unavailable for reuse.

---

## 10.10 Returning Pointers from Functions

A function can return a pointer. However, it should not return a pointer to a local variable that will be destroyed when
the function ends. A function should only return a pointer to data that was passed as an argument or to dynamically
allocated memory.

---

## 10.11 Pointers to Class Objects and Structures

You can create pointers to objects and structure variables. You can access a member of a structure or object using a
pointer with the dot operator (`(*ptr).member`), but a simpler way is to use the **structure pointer operator (`->`)**.
This operator dereferences the pointer and accesses the member in a single step.

---

## 10.12 Selecting Members of Objects

When a structure or object contains a pointer as a member, you can access the member using the `->` operator. For
example, if `testPtr` is a pointer to a structure that has a member `grades` which is a pointer, `testPtr->grades`
accesses the `grades` pointer, and `*testPtr->grades` accesses the value it points to.

---

## 10.13 Smart Pointers

Introduced in C++ 11, **smart pointers** are objects that behave like pointers but automatically manage dynamic memory,
helping to prevent issues like dangling pointers and memory leaks. You must include the `<memory>` header file to use
them.

### Types of Smart Pointers

* **`unique_ptr`**: A unique pointer has sole ownership of the dynamically allocated object it points to. Ownership can
  be transferred to another `unique_ptr` using the `move()` function. The memory is automatically deallocated when the
  `unique_ptr` goes out of scope or is reassigned.
* **`shared_ptr`**: A shared pointer allows multiple pointers to own the same dynamically allocated object. A control
  block tracks the number of owners (the reference count). The memory is deallocated only when the last `shared_ptr`
  that points to it is destroyed. To create a shared pointer, it's safer to use the `make_shared` function to ensure all
  references are tracked in a single control block.
* **`weak_ptr`**: (Not detailed in the provided content, but mentioned as a type of smart pointer).