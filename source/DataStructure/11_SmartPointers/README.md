# C++ Interlude 4: Safe Memory Management Using Smart Pointers

---
## Resources: 
If you run into some warning, run this. You will need C++ 14 and above to run this.
```bash
g++ -std=c++14 -o smart_pointers_example smart_pointers_example.cpp
./smart_pointers_example
```


## **1. Raw Pointers**

### **Concept**:
In C++, raw pointers are used to allocate memory dynamically using the `new` operator. These pointers store references to objects in memory. However, they come with several risks:
- **Memory leaks**: Forgetting to deallocate memory with `delete` leads to wasted memory.
- **Dangling pointers**: Using pointers to deallocated memory can cause crashes.

### **Key Issues**:
- The programmer must **manually track** how many pointers reference an object.
- Failure to manage memory correctly can lead to **dangling pointers** and **memory leaks**.

### **Example**:
```cpp
int* ptr = new int(10);  // Allocate memory
delete ptr;              // Deallocate memory
ptr = nullptr;           // Avoid dangling pointer
```

---

## **2. Smart Pointers**

C++ introduced **smart pointers** for automatic memory management. These are template classes that behave like raw pointers but also handle memory deallocation when the pointer goes out of scope.

### **Types of Smart Pointers**:
1. **`shared_ptr`**: Allows shared ownership of an object.
2. **`unique_ptr`**: Exclusive ownership of an object; no other pointer can reference the same object.
3. **`weak_ptr`**: Observes an object managed by a `shared_ptr` without owning it.

---

## **3. Using Shared Pointers**

A **`shared_ptr`** automatically keeps track of the number of aliases (references) to an object. When the reference count drops to zero, it deallocates the memory.

### **Code Example**:
```cpp
#include <memory>
#include <iostream>

int main() {
    std::shared_ptr<int> p1 = std::make_shared<int>(10);
    std::shared_ptr<int> p2 = p1;  // Shared ownership

    std::cout << *p1 << std::endl;  // Output: 10
    std::cout << p1.use_count() << std::endl;  // Output: 2
}
```

### **Use Case**:
Shared pointers are ideal for managing objects that multiple parts of a program need to share, such as a game engine that needs shared access to game assets like textures or models.

---

## **4. Using Unique Pointers**

A **`unique_ptr`** ensures that only one pointer can reference an object at a time. Ownership can be transferred using the `std::move` function, but a `unique_ptr` cannot be copied.

### **Code Example**:
```cpp
#include <memory>
#include <iostream>

int main() {
    std::unique_ptr<int> p1 = std::make_unique<int>(20);
    std::unique_ptr<int> p2 = std::move(p1);  // Transfer ownership

    if (!p1) {
        std::cout << "p1 is empty!" << std::endl;
    }
    std::cout << *p2 << std::endl;  // Output: 20
}
```

### **Use Case**:
Unique pointers are best for managing resources where ownership must be clear, such as file handles or hardware resources in embedded systems.

---

## **5. Using Weak Pointers**

A **`weak_ptr`** provides a way to reference an object managed by a `shared_ptr` without increasing its reference count. This is useful in preventing **circular references** (where two objects refer to each other, preventing memory deallocation).

### **Code Example**:
```cpp
#include <memory>
#include <iostream>

int main() {
    std::shared_ptr<int> p1 = std::make_shared<int>(30);
    std::weak_ptr<int> wp = p1;  // Weak reference

    if (auto sp = wp.lock()) {  // Converts weak_ptr to shared_ptr
        std::cout << *sp << std::endl;  // Output: 30
    }
}
```

### **Use Case**:
Weak pointers are commonly used in situations where you need to break reference cycles, such as in **graph structures** or **observer patterns**, to prevent memory leaks.

---

## **6. Revised Node and LinkedList Classes Using Smart Pointers**

Smart pointers can be used in **linked data structures** like linked lists to ensure memory is correctly managed.

### **Code Example (Revised Node with `shared_ptr`)**:
```cpp
#include <memory>

class Node {
public:
    int data;
    std::shared_ptr<Node> next;

    Node(int value) : data(value), next(nullptr) {}
};
```

Using `shared_ptr` in the linked list ensures that nodes are correctly deallocated when no longer needed, without manual memory management.

### **Use Case**:
Smart pointers prevent memory leaks in data structures like **linked lists** or **trees** where multiple nodes are dynamically allocated and deallocated.

---

## **7. Other Smart Pointer Features**

- **`reset()`**: Resets a smart pointer, deallocating its memory.
- **`get()`**: Returns the raw pointer.
- **`use_count()`**: For `shared_ptr`, returns the number of references to the managed object.
- **`release()`**: For `unique_ptr`, releases ownership without deallocating.

---

## **Conclusion**

C++ smart pointers (`shared_ptr`, `unique_ptr`, `weak_ptr`) offer a robust solution for safe memory management, reducing risks of memory leaks and dangling pointers. They should be used in modern C++ development to ensure that memory is automatically deallocated when it is no longer needed.

--- 

This summary includes an overview of raw and smart pointers, code examples for each type of smart pointer, and practical use cases where smart pointers prevent common memory management issues.