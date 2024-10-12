# Template <typename T>

A `template <typename T>` in C++ is a feature that allows you to write generic and reusable code that works with different data types. It enables you to create classes, functions, or even variables where the type (`T`) is a placeholder for an actual data type (such as `int`, `float`, `string`, etc.) that will be specified later when the template is instantiated. This promotes code reusability and flexibility, as the same piece of code can work with various types without needing to rewrite it for each type.

### Key Concepts:

- **`typename T`**: `T` is a placeholder for a type. The keyword `typename` tells the compiler that `T` will be a type, and it could be replaced with any valid data type when the template is used.
- Templates allow you to write code **once** and use it for **multiple data types**, reducing redundancy.

### Types of Templates:
1. **Function Templates**: Functions that can operate on any data type.
2. **Class Templates**: Classes that can store or operate on any data type.

---

### 1. **Function Template Example**

A **function template** is used when you want the same function to work with multiple data types.

#### Example: Template Function for Swapping Two Values
```cpp
#include <iostream>
using namespace std;

// Define a function template to swap two values of any type
template <typename T>
void swapValues(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 10, y = 20;
    cout << "Before Swap: x = " << x << ", y = " << y << endl;
    
    // Call the template function with int types
    swapValues(x, y);
    cout << "After Swap: x = " << x << ", y = " << y << endl;

    double d1 = 1.5, d2 = 2.5;
    cout << "Before Swap: d1 = " << d1 << ", d2 = " << d2 << endl;

    // Call the same template function with double types
    swapValues(d1, d2);
    cout << "After Swap: d1 = " << d1 << ", d2 = " << d2 << endl;

    return 0;
}
```

**Explanation**:
- The function `swapValues` can work with any data type, such as `int` or `double`.
- `template <typename T>` defines the function as a template.
- When you call `swapValues(x, y)`, `T` is automatically deduced as `int`. Similarly, `T` is deduced as `double` when calling `swapValues(d1, d2)`.

---

### 2. **Class Template Example**

A **class template** is used when you want a class to operate on different data types.

#### Example: Template Class for a Simple Generic Container
```cpp
#include <iostream>
using namespace std;

// Define a class template
template <typename T>
class Box {
public:
    T value;

    Box(T val) : value(val) {}

    void printValue() {
        cout << "Value: " << value << endl;
    }
};

int main() {
    // Create an instance of Box with int type
    Box<int> intBox(123);
    intBox.printValue();  // Output: Value: 123

    // Create an instance of Box with string type
    Box<string> strBox("Hello, World!");
    strBox.printValue();  // Output: Value: Hello, World!

    return 0;
}
```

**Explanation**:
- `template <typename T>` defines a generic class `Box` that can hold any type `T`.
- When creating an instance of `Box<int>`, `T` is replaced with `int`.
- Similarly, `Box<string>` replaces `T` with `string`.

---

### Why Use `template <typename T>`?

1. **Code Reusability**: Instead of writing separate functions or classes for each data type, you write it once and reuse it for multiple types.
2. **Type Flexibility**: You can use the same logic for different data types, making your code more adaptable.
3. **Reduce Code Duplication**: Templates reduce the need for writing the same code for different types (e.g., separate `swap` functions for `int`, `float`, `double`, etc.).

### How Templates Work:
When you use a template with a specific type (e.g., `Box<int>` or `swapValues(5, 10)`), the compiler **instantiates** the template by generating a concrete version of the class or function, replacing `T` with the specified type. This happens at compile time, so there is no runtime overhead associated with templates.

---

### Template Specialization:
Sometimes you may want to write a specific version of the template for a certain type. This is called **template specialization**.

#### Example: Specialized Version for `char*` (C-Strings)
```cpp
#include <iostream>
using namespace std;

template <typename T>
void printValue(T value) {
    cout << "Generic Value: " << value << endl;
}

// Specialization for char*
template <>
void printValue<char*>(char* value) {
    cout << "String Value: " << value << endl;
}

int main() {
    printValue(123);        // Output: Generic Value: 123
    printValue(12.34);      // Output: Generic Value: 12.34
    printValue("Hello");    // Output: String Value: Hello

    return 0;
}
```

In this example, we have specialized the `printValue` function for `char*` to handle strings differently from other types.

---

### Summary:

- **`template <typename T>`** allows you to write **generic** code that can work with any type.
- Templates can be used for both **functions** and **classes**.
- Templates make code more reusable, flexible, and reduce redundancy.
- Specialization allows you to customize behavior for certain types when needed.

Let me know if you'd like to explore more advanced aspects of templates!