# **Factory Design Pattern**

The **Factory Design Pattern** is a **creational design pattern** that provides an interface or method to create objects in a superclass but allows subclasses to alter the type of objects that will be created. It encapsulates the object creation logic, promoting flexibility and reusability while following the **Open/Closed Principle** (i.e., code is open for extension but closed for modification).

### **When to Use the Factory Pattern:**
- When you need to centralize object creation logic to avoid repeating it throughout your code.
- When the type of the object to be created depends on some input or configuration.
- When you want to decouple client code from specific classes, promoting **loose coupling**.

---

## **Simple Example of Factory Design Pattern in C++**

Let’s walk through a **Factory Method** example where we create different types of objects (like `Engineer` and `Manager`) based on input.

### **Code Example:**

```cpp
#include <iostream>
#include <memory>
#include <string>
using namespace std;

// Base class
class Employee {
public:
    virtual void work() const = 0;  // Pure virtual function
    virtual ~Employee() {}          // Virtual destructor
};

// Concrete class: Engineer
class Engineer : public Employee {
public:
    void work() const override {
        cout << "Engineer is working on technical tasks.\n";
    }
};

// Concrete class: Manager
class Manager : public Employee {
public:
    void work() const override {
        cout << "Manager is overseeing the team.\n";
    }
};

// Factory class to create Employee objects
class EmployeeFactory {
public:
    static unique_ptr<Employee> create_employee(const string& type) {
        if (type == "engineer") {
            return make_unique<Engineer>();
        } else if (type == "manager") {
            return make_unique<Manager>();
        } else {
            return nullptr;  // Return nullptr for unknown types
        }
    }
};

// Main function
int main() {
    // Create an Engineer
    auto engineer = EmployeeFactory::create_employee("engineer");
    if (engineer) engineer->work();

    // Create a Manager
    auto manager = EmployeeFactory::create_employee("manager");
    if (manager) manager->work();

    return 0;
}
```

---

### **Explanation:**

1. **Abstract Base Class (`Employee`):** 
   - It defines a common interface for different types of employees (e.g., `Engineer`, `Manager`).
   - It has a pure virtual function `work()` that must be implemented by all derived classes.

2. **Concrete Classes (`Engineer` and `Manager`):**
   - These classes provide their specific implementations of the `work()` method.

3. **Factory Class (`EmployeeFactory`):**
   - The static method `create_employee()` is responsible for creating `Engineer` or `Manager` objects based on the input type.
   - It returns a smart pointer (`unique_ptr`) to manage the memory efficiently.

4. **Usage in `main()` Function:** 
   - We use the factory to create instances of `Engineer` and `Manager` based on the provided string input.

---

### **Output:**
```
Engineer is working on technical tasks.
Manager is overseeing the team.
```

---

### **Advantages of Factory Pattern:**
- **Encapsulation:** The creation logic is hidden inside the factory, reducing complexity in client code.
- **Flexibility:** It becomes easy to introduce new types by modifying the factory, without changing the existing client code.
- **Reusability:** The object creation logic is centralized and can be reused across the system.

### **Disadvantages:**
- If not designed carefully, it can increase the complexity of the system by introducing too many classes.
- It may require maintenance when new types are frequently added.

This pattern is commonly used in applications where there is a need to create instances of related or dependent objects dynamically, based on some configuration or input.