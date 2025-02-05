
## **1️⃣ Linking Objects Together**
### **Explanation:**
In C++, objects can be linked together using pointers, forming a **custom linked structure**.

### **Exercise:**
Create a `Person` class where each person **points to another person** (like a simple chain).

#### **Task:**
1. Define a class `Person` with a name and a pointer to another `Person`.
2. Create 3 objects dynamically and link them together.
3. Print the chain.
4. Clean up

```cpp
#include <iostream>
#include <memory>
using namespace std;

class Person {
public:
    string name;
    Person* next;

    Person(string n) : name(n), next(nullptr) {}
};

int main() {
   // Create person
    Person* p1 = new Person("Alice");

    // Link objects together

    // Traverse and print


    // Free memory

    return 0;
}
```

---

## **2️⃣ Singly Linked List**
### **Explanation:**
A **singly linked list** is a chain of nodes where each node **points to the next**.

### **Exercise:**
1. Implement a `Node` struct.
2. Add function `insertAtBegining` and `deleteAtEnd` methods.
3. Use a pointer to traverse the list in a loop.

```cpp
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;

    LinkedList() : head(nullptr) {}

    void insert(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }

   //Define void insertAtBegining(){}
   
   //Define void DeleteAtEnd(){}
    
    void display() {
        for (Node* temp = head; temp; temp = temp->next)
            cout << temp->data << " -> ";
        cout << "nullptr\n";
    }
};

int main() {
    LinkedList list;
    list.insert(10);
    list.insert(20);
    list.insert(30);

    cout << "Singly Linked List:\n";
    list.display();
    
    return 0;
}
```

---

## **3️⃣ Doubly Linked List**
### **Explanation:**
A **doubly linked list** has nodes that store **two pointers**:
- One **to the next node**.
- One **to the previous node**.

### **Exercise:**
1. Implement a `DoublyNode` struct.
2. Write a function to `insertAtBegining`, `displayBackward` and `deleteAtEnd`

### **Addition: Delete a Node in Doubly Linked List**
1. Implement a `deleteNode(int value)` function in the `DoublyLinkedList` class.

```cpp
#include <iostream>
using namespace std;

struct DoublyNode {
   // Do Something here
};

class DoublyLinkedList {
public:
    DoublyNode* head;

    DoublyLinkedList() : head(nullptr) {}

    void insert(int value) {
        DoublyNode* newNode = new DoublyNode(value);
        if (!head) {
            head = newNode;
            return;
        }
        DoublyNode* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }

    void displayForward() {
        cout << "Forward: ";
        for (DoublyNode* temp = head; temp; temp = temp->next)
            cout << temp->data << " <-> ";
        cout << "nullptr\n";
    }

};

int main() {
    DoublyLinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insertAtBegining(10);
    list.deleteAtEnd();

    list.displayForward();
    list.displayBackward();
    
    return 0;
}
```

---

## **4️⃣ Circular Linked List**
### **Explanation:**
A **circular linked list** is a variation of a singly linked list where the **last node points back to the head**.

### **Exercise:**
1. Implement a `CircularNode` struct.
2. Implement a `CircularLinkedList` class.
3. Traverse it with a pointer.

```cpp
#include <iostream>
using namespace std;

struct CircularNode {

};

class CircularLinkedList {
public:
    CircularNode* head;

    CircularLinkedList() : head(nullptr) {}

    void insert(int value) {}

    void display() {}
};

int main() {
    CircularLinkedList list;
    list.insert(5);
    list.insert(10);
    list.insert(15);

    cout << "Circular Linked List:\n";
    list.display();
    
    return 0;
}
```

---

## **5️⃣ Using Pointers to Traverse in a For Loop**
### **Explanation:**
Instead of using a `while` loop, we can use **a `for` loop with pointers**.

### **Exercise:**
Modify the singly linked list traversal **to use a for loop**.

```cpp
void displayWithForLoop(Node* head) {

}

int main() {
    LinkedList list;
    list.insert(100);
    list.insert(200);
    list.insert(300);

    displayWithForLoop(list.head);
    
    return 0;
}
```

---

## **Challenge Exercise: Detect and Remove Loop in Linked List**

1. Create a function `detectLoop()` that detects if a cycle exists in a linked list using Floyd’s Cycle Detection
   Algorithm.
2. If a loop is found, write a function `removeLoop()` to remove it.

---

## **📌 Summary**
- **🔗 Linking Objects Together**: Simple object chaining with pointers.
- **🔁 Singly Linked List**: Each node has a pointer to the next.
- **🔄 Doubly Linked List**: Each node has pointers to both **next and previous**.
- **🔃 Circular Linked List**: The **last node points back to the head**.
- **🔍 Using Pointers in a For Loop**: Simplifies list traversal.