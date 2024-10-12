# Solid Design Pattern

## Tech
- `namespace boost`
- `boost::lexical_cast`
- `const string& filename`, the expression represents a **constant reference** to a `string` object in C++. Passing a `const string&` avoids copying and modify the `string` object.

## Introduce
The **SOLID design principles** are a set of five guidelines in object-oriented design that improve the maintainability, flexibility, and scalability of a system. They were introduced by Robert C. Martin and are highly influential in writing clean and effective object-oriented code. These principles are often used in conjunction with design patterns to create robust software architectures.

Here's a breakdown of each SOLID principle and how they relate to specific design patterns in C++:

### 1. **Single Responsibility Principle (SRP)**

**Definition**: A class should have only one reason to change, meaning it should only have one responsibility or one job.

- **In Design Patterns**:
  - **Facade Pattern**: Simplifies the interface for a complex system by introducing a Facade class that provides a single entry point, separating concerns and responsibilities across subsystems.
  - **Repository Pattern**: Used in data access layers, where the responsibility of querying or persisting data is handled by a dedicated repository class.
  - **Separation of Concerns**: For example, in a journal class that handles logging entries, saving those entries to a file is a different concern. In your earlier example, using a `PersistenceManager` to save data follows SRP.

### 2. **Open/Closed Principle (OCP)**

**Definition**: Software entities (classes, modules, functions) should be **open for extension** but **closed for modification**. This means that you should be able to extend the behavior of a class without modifying its source code.

- **In Design Patterns**:
  - **Decorator Pattern**: Adds new functionality to an object dynamically without changing its structure. For example, a `Stream` class can be extended with new features (like compression or encryption) via decorators, without modifying the `Stream` class itself.
  - **Strategy Pattern**: Defines a family of algorithms and makes them interchangeable. This allows extending functionality by adding new strategies rather than modifying the existing codebase.
  - **Observer Pattern**: You can add new observers without modifying the subject, thus adhering to the Open/Closed Principle.

### 3. **Liskov Substitution Principle (LSP)**

**Definition**: Objects of a superclass should be replaceable with objects of its subclasses without affecting the correctness of the program. In other words, derived classes must be substitutable for their base classes.

- **In Design Patterns**:
  - **Template Method Pattern**: Allows subclasses to override certain methods of a base class, ensuring that the base class and the derived class are interchangeable, adhering to LSP.
  - **Factory Method Pattern**: Encourages creating objects via a common interface or superclass, ensuring derived types can replace base types.
  - **Polymorphism**: In inheritance hierarchies, LSP ensures derived classes extend the base class behavior in a way that remains consistent with expectations.

### 4. **Interface Segregation Principle (ISP)**

**Definition**: Clients should not be forced to depend on interfaces they do not use. This principle encourages breaking down large interfaces into smaller, more specific ones so that classes implement only what they need.

- **In Design Patterns**:
  - **Adapter Pattern**: Helps break large interfaces by creating an adapter that implements a more focused interface, translating calls from a client to a legacy system.
  - **Facade Pattern**: Provides a simplified interface to a complex subsystem, ensuring that clients interact with only the features they need.
  - **Command Pattern**: Each command encapsulates a specific behavior, avoiding large or bloated interfaces for handling different actions.
  
### 5. **Dependency Inversion Principle (DIP)**

**Definition**: High-level modules should not depend on low-level modules. Both should depend on abstractions (e.g., interfaces). Additionally, abstractions should not depend on details; details should depend on abstractions.

- **In Design Patterns**:
  - **Dependency Injection**: Commonly implemented with the **Factory Pattern** or **Inversion of Control (IoC)** containers, it ensures that dependencies are passed into a class via interfaces, decoupling high-level classes from their low-level details.
  - **Abstract Factory Pattern**: Allows the creation of objects through interfaces, decoupling the creation logic from the usage logic. It adheres to DIP by making both high-level and low-level modules depend on abstractions.
  - **Service Locator Pattern**: Helps manage dependencies in a central registry, allowing decoupling between service consumers and providers.

---

### Example: Using SOLID Principles with the Strategy Pattern in C++

Here's an example that adheres to several SOLID principles using the **Strategy Pattern** in C++.

```cpp
#include <iostream>
#include <memory>

// Abstract base class for strategies
class PaymentStrategy {
public:
    virtual void pay(int amount) const = 0;
    virtual ~PaymentStrategy() = default;
};

// Concrete strategy: Credit card payment
class CreditCardPayment : public PaymentStrategy {
public:
    void pay(int amount) const override {
        std::cout << "Paid " << amount << " using Credit Card." << std::endl;
    }
};

// Concrete strategy: PayPal payment
class PayPalPayment : public PaymentStrategy {
public:
    void pay(int amount) const override {
        std::cout << "Paid " << amount << " using PayPal." << std::endl;
    }
};

// Context class that uses a payment strategy
class ShoppingCart {
private:
    std::unique_ptr<PaymentStrategy> strategy;
public:
    ShoppingCart(std::unique_ptr<PaymentStrategy> s) : strategy(std::move(s)) {}

    void checkout(int amount) {
        strategy->pay(amount);  // Delegates the payment responsibility to the strategy
    }
};

// Main function to demonstrate the pattern
int main() {
    std::unique_ptr<PaymentStrategy> paypal = std::make_unique<PayPalPayment>();
    std::unique_ptr<PaymentStrategy> creditCard = std::make_unique<CreditCardPayment>();

    ShoppingCart cart1(std::move(paypal));
    cart1.checkout(100);  // Output: Paid 100 using PayPal.

    ShoppingCart cart2(std::move(creditCard));
    cart2.checkout(200);  // Output: Paid 200 using Credit Card.

    return 0;
}
```

### SOLID Principles in Action:

- **SRP**: The `PaymentStrategy` interface and its concrete implementations (`CreditCardPayment` and `PayPalPayment`) handle different payment methods, while the `ShoppingCart` class only handles the shopping logic.
- **OCP**: You can add new payment methods (e.g., `BitcoinPayment`) without modifying the existing classes.
- **LSP**: Subtypes (`CreditCardPayment`, `PayPalPayment`) can replace the `PaymentStrategy` base type without affecting the correctness of the program.
- **ISP**: The `PaymentStrategy` interface is small and specific to payments, adhering to the ISP by not forcing classes to implement methods they don’t need.
- **DIP**: The `ShoppingCart` class depends on the `PaymentStrategy` abstraction rather than concrete implementations, following the Dependency Inversion Principle.
