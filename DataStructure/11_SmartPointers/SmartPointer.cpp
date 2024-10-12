#include <iostream>
#include <memory>  // For smart pointers

// Demonstrating raw pointers
void rawPointerExample() {
    int* ptr = new int(10);  // Allocate memory for an integer
    std::cout << "Raw pointer value: " << *ptr << std::endl;

    delete ptr;  // Manually deallocate memory
    ptr = nullptr;  // Avoid dangling pointer
}

// Demonstrating shared_ptr
void sharedPointerExample() {
    std::shared_ptr<int> p1 = std::make_shared<int>(10);  // Shared ownership
    std::shared_ptr<int> p2 = p1;  // Another shared pointer to the same object
    std::shared_ptr<int> p3 = p1;  // Another shared pointer to the same object
    
    std::cout << "Shared pointer value: " << *p1 << std::endl;
    std::cout << "Shared pointer reference count: " << p1.use_count() << std::endl;
}

// Demonstrating unique_ptr
void uniquePointerExample() {
    std::unique_ptr<int> p1 = std::make_unique<int>(20);  // Unique ownership
    std::unique_ptr<int> p2 = std::move(p1);  // Transfer ownership to p2

    if (!p1) {
        std::cout<<p1<<std::endl;
        std::cout << "p1 is empty after transfer!" << std::endl;
    }
    std::cout << "Unique pointer value: " << *p2 << std::endl;
}

// Demonstrating weak_ptr
void weakPointerExample() {
    std::shared_ptr<int> p1 = std::make_shared<int>(30);  // Shared ownership
    std::weak_ptr<int> wp = p1;  // Weak reference to the object

    if (auto sp = wp.lock()) {  // Convert weak_ptr to shared_ptr
        std::cout << "Weak pointer locked value: " << *sp << std::endl;
    } else {
        std::cout << "Object no longer exists!" << std::endl;
    }
}

// Demonstrating smart pointers in a Node structure (for linked list)
class Node {
public:
    int data;
    std::shared_ptr<Node> next;

    Node(int value) : data(value), next(nullptr) {}
};

void smartPointerLinkedListExample() {
    // Create two linked nodes using shared_ptr
    std::shared_ptr<Node> head = std::make_shared<Node>(1);
    head->next = std::make_shared<Node>(2);

    std::cout << "Linked list head node value: " << head->data << std::endl;
    std::cout << "Linked list second node value: " << head->next->data << std::endl;
}

int main() {
    std::cout << "=== Raw Pointer Example ===" << std::endl;
    rawPointerExample();
    
    std::cout << "\n=== Shared Pointer Example ===" << std::endl;
    sharedPointerExample();
    
    std::cout << "\n=== Unique Pointer Example ===" << std::endl;
    uniquePointerExample();
    
    std::cout << "\n=== Weak Pointer Example ===" << std::endl;
    weakPointerExample();
    
    std::cout << "\n=== Smart Pointer LinkedList Example ===" << std::endl;
    smartPointerLinkedListExample();
    
    /*
    Explanation:
        Raw Pointers: Allocates memory manually using new and deallocates it using delete.
        shared_ptr: Demonstrates shared ownership of an integer.
        unique_ptr: Shows unique ownership and transferring ownership using std::move.
        weak_ptr: Shows weak reference management, preventing ownership, and detecting if the object still exists.
        Smart Pointer with Linked List: Demonstrates using shared_ptr for linked nodes in a simple linked list. 
    */
    return 0;
}
