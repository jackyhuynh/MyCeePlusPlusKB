# Template <Typename T> Pointer
In C++, creating a pointer to a template class or function follows the same general principles as creating a pointer to any other class or function, but with the addition of specifying the template argument. 

Here's a simple step-by-step guide on how to create a pointer for a template class in C++:

### Example 1: Template Class Pointer

1. **Define a template class**:
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
   ```

   In this example, `MyClass` is a generic class that stores a value of type `T` (which could be `int`, `double`, `string`, etc.).

2. **Create a pointer to the template class**:
   To create a pointer of this template class, you must specify the template argument (the type that will replace `T`).

   ```cpp
   int main() {
       // Create an object of the template class with int
       MyClass<int>* ptr = new MyClass<int>(10);

       // Use the pointer to access the class methods and members
       ptr->printValue();  // Output: Value: 10

       // Don't forget to free the memory
       delete ptr;

       return 0;
   }
   ```

   - Here, `MyClass<int>* ptr` declares a pointer to a `MyClass` object, where `T` is replaced with `int`.
   - `new MyClass<int>(10)` creates an instance of `MyClass<int>` with the value `10` and assigns it to the pointer `ptr`.
   - The `->` operator is used to access the member function `printValue()` via the pointer.

### Example 2: Template Function Pointer

If you want to create a pointer to a **template function**, the process is similar.

1. **Define a template function**:
   ```cpp
   template <typename T>
   void display(T value) {
       std::cout << "Value: " << value << std::endl;
   }
   ```

2. **Create a pointer to the template function**:
   You need to explicitly specify the type when assigning the function pointer.

   ```cpp
   int main() {
       // Create a pointer to the template function with int as the template parameter
       void (*funcPtr)(int) = &display<int>;

       // Call the function via the pointer
       funcPtr(42);  // Output: Value: 42

       return 0;
   }
   ```

### Explanation:

- **For a class**:
  - You specify the template type (e.g., `int`, `double`) when creating the pointer: `MyClass<int>*`.
  - Use `new` to dynamically allocate an instance and assign it to the pointer.
  
- **For a function**:
  - You specify the template type when assigning the function to a pointer, like `&display<int>`.

[Prev](./README.md)