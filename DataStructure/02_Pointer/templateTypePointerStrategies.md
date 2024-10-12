# Template <typename T> Pointer Strategies

developers can directly define a template pointer in C++, but you must always specify the **template argument** when creating the pointer or using the template class or function. You cannot define a pointer to a template without specifying the type `T`, because templates are essentially "blueprints" and must be instantiated with a specific type before they can be used.

### Key Points:
1. **Templates** are not concrete types until you provide a specific type for the template parameter.
2. **Template pointers** must have the type `T` specified at the time of pointer definition.

Let’s go over what you can and cannot do, with examples.

### 1. **Direct Template Pointer Definition (with Type Specified)**

You **can** directly define a pointer to a template class or function **once the type is specified** for the template parameter.

#### Example: Template Class Pointer
```cpp
template <typename T>
class MyClass {
public:
    T value;
    MyClass(T val) : value(val) {}
    void printValue() {
        std::cout << "Value: " << value << std::endl;
    }
};

int main() {
    // Correct: Define a pointer to MyClass<int>
    MyClass<int>* ptr = nullptr;  // Pointer to MyClass<int>
    
    // Dynamically allocate memory for MyClass<int>
    ptr = new MyClass<int>(10);  // Create an object of MyClass<int>

    // Use the pointer to call the method
    ptr->printValue();  // Output: Value: 10

    // Clean up memory
    delete ptr;

    return 0;
}
```

Here, `MyClass<int>* ptr` is a valid pointer because we have specified `int` as the template argument. You can then assign the pointer to an object of type `MyClass<int>`.

#### Example: Template Function Pointer
You can also define a pointer to a **template function**, but again, you must specify the template type.

```cpp
template <typename T>
void display(T value) {
    std::cout << "Value: " << value << std::endl;
}

int main() {
    // Correct: Define a pointer to the template function with a specific type (int in this case)
    void (*funcPtr)(int) = &display<int>;

    // Use the function pointer
    funcPtr(42);  // Output: Value: 42

    return 0;
}
```

In this case, `funcPtr` is a pointer to the `display<int>` function.

### 2. **Why You Cannot Define a Template Pointer Without Specifying the Type**

Templates are like **blueprints** in C++, and they are not actual "types" until the template parameter is specified.

For example, this is **not allowed**:
```cpp
template <typename T>
class MyClass;

// Invalid: This does not work because the type for T is not specified.
MyClass<T>* ptr;  // ERROR: T is not defined!
```

The compiler doesn’t know what `T` is, so it cannot define a pointer to `MyClass<T>`. To make this work, you must instantiate the template with a specific type, like `MyClass<int>` or `MyClass<double>`.

### 3. **Using Typedef or Aliases with Templates**

You can use `typedef` or `using` to simplify template pointer definitions. For instance, if you frequently use the template class with the same type, you can create an alias:

```cpp
template <typename T>
class MyClass {
public:
    T value;
    MyClass(T val) : value(val) {}
    void printValue() {
        std::cout << "Value: " << value << std::endl;
    }
};

// Alias for MyClass<int>
using MyClassInt = MyClass<int>;

int main() {
    // Define a pointer using the alias
    MyClassInt* ptr = new MyClassInt(100);

    ptr->printValue();  // Output: Value: 100

    delete ptr;

    return 0;
}
```

### Conclusion:
You cannot directly define a template pointer without specifying the template type (e.g., `T`), as the template needs to be instantiated with a specific type like `int`, `double`, etc. Once the type is specified, you can define the pointer just like you would with any regular class or function.

[Prev](./README.md)