### **Adapter Design Pattern in C++: Concept, Implementation, and Use Case**

---

The **Adapter Design Pattern** is a **structural pattern** that allows two incompatible interfaces to work together by acting as a bridge between them. It converts the interface of a class into another interface the client expects, enabling the use of classes with incompatible interfaces without modifying their source code.

---

## **Use Case of Adapter Pattern**
Imagine you are building a **payment processing system** that must integrate multiple payment gateways. Each payment gateway should implement the `PaymentProcessor` interface. However, one of the gateways you want to use, `OldPaymentService`, has a different method signature. 

To avoid changing the client code or the `OldPaymentService` implementation, you can use the **Adapter Pattern** to bridge the incompatibility.

---

## **Implementation of the Adapter Pattern in C++**

Below is an example of using the **Adapter Pattern** to integrate the `OldPaymentService` into your payment system.

---

### **C++ Code Example**

```cpp
#include <iostream>
#include <string>

// Target Interface: The standard interface expected by your system.
class PaymentProcessor {
public:
    virtual void processPayment(double amount) const = 0;
};

// Adaptee Class: A legacy payment service with a different interface.
class OldPaymentService {
public:
    void makePayment(double amount) const {
        std::cout << "Payment of $" << amount << " processed using Old Payment Service." << std::endl;
    }
};

// Adapter Class: Adapts the OldPaymentService to the PaymentProcessor interface.
class PaymentAdapter : public PaymentProcessor {
private:
    OldPaymentService& oldService;

public:
    // Constructor to initialize the old payment service instance.
    PaymentAdapter(OldPaymentService& service) : oldService(service) {}

    // Implement the expected interface by calling the adaptee's method.
    void processPayment(double amount) const override {
        std::cout << "Adapting the old payment service to the new interface..." << std::endl;
        oldService.makePayment(amount);
    }
};

// Client Code: Uses the PaymentProcessor interface to process payments.
void processOrder(const PaymentProcessor& processor, double amount) {
    std::cout << "Processing order..." << std::endl;
    processor.processPayment(amount);
}

int main() {
    // Create an instance of OldPaymentService (Adaptee)
    OldPaymentService oldService;

    // Use the adapter to make the old service compatible with PaymentProcessor
    PaymentAdapter adapter(oldService);

    // Process an order using the adapted service
    processOrder(adapter, 100.50);

    return 0;
}
```

---

### **Explanation of the Code**

1. **PaymentProcessor (Target Interface):**  
   This interface defines the method `processPayment()` that all payment gateways in your system should implement.

2. **OldPaymentService (Adaptee):**  
   This is a legacy payment service with a method `makePayment()`. It doesn’t match the expected interface (`PaymentProcessor`), so it cannot be used directly by the client code.

3. **PaymentAdapter (Adapter):**  
   This class bridges the `OldPaymentService` to the `PaymentProcessor` interface by implementing the `processPayment()` method and internally calling the old service’s `makePayment()` method.

4. **Client Code:**  
   The `processOrder()` function only interacts with the `PaymentProcessor` interface. The client remains decoupled from the underlying `OldPaymentService`.

---

### **Output of the Program**

```
Processing order...
Adapting the old payment service to the new interface...
Payment of $100.5 processed using Old Payment Service.
```

---

## **Benefits of the Adapter Pattern**

1. **Reusability:** Reuse legacy code without modifying it.
2. **Flexibility:** Integrate new or third-party services with incompatible interfaces.
3. **Decoupling:** The client interacts with the interface, not the actual service, promoting loose coupling.

---

## **When to Use the Adapter Pattern**

- When you want to **reuse legacy code** but it doesn’t match the current system’s interface.
- When **third-party libraries or APIs** need to be integrated, but they don’t conform to your expected interfaces.
- When you want to **decouple client code** from specific implementations, allowing for easy replacement or extension of services in the future.

---

## **Key Takeaways**

The **Adapter Pattern** is useful when working with legacy systems or integrating external libraries. It allows systems to work together smoothly by **converting interfaces** without altering existing code. This approach ensures that your system remains **extensible and maintainable** while reducing dependencies between components.

This example illustrated how an **old payment service** with an incompatible interface was adapted to fit the standard payment processor interface. Using this approach, we were able to **seamlessly integrate** the old service into our payment system without changing any client code or the service itself.