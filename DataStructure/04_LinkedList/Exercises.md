---

## **Pointers Exercises**
### **Exercise 1: Pointer Basics**
Write a C++ program that:
1. Declares an integer variable and a pointer to it.
2. Assigns a value to the integer and prints it using both the variable and pointer.
3. Modifies the value using the pointer and prints it again.

```cpp
#include <iostream>
using namespace std;

int main() {
    int num = 10;
    int *ptr = &num;

    cout << "Value of num: " << num << endl;
    cout << "Value using pointer: " << *ptr << endl;

    *ptr = 20; // Modify using pointer
    cout << "New value of num: " << num << endl;

    return 0;
}
```

### **Exercise 2: Array and Pointers**
Write a program that:
1. Declares an array of 5 integers.
2. Uses a pointer to iterate through the array and print its elements.

```cpp
#include <iostream>
using namespace std;

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int *ptr = arr;

    cout << "Array elements using pointer: ";
    for (int i = 0; i < 5; i++) {
        cout << *(ptr + i) << " ";
    }

    return 0;
}
```

---

## **Singly Linked List Exercises**
### **Exercise 3: Implement a Singly Linked List**
Create a `Node` struct with an `int` value and a pointer to the next node. Implement a class `LinkedList` with the following functions:
1. `insertAtEnd(int)`: Adds a new node at the end.
2. `display()`: Prints all elements in the list.

```cpp
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;
public:
    LinkedList() {
        head = nullptr;
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    LinkedList list;
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.display();
    return 0;
}
```

### **Exercise 4: Insert a Node at the Beginning**
Modify the previous linked list to add:
1. `insertAtBeginning(int)`: Inserts a node at the start.

---

### **Exercise 5: Delete a Node by Value**
Write a function `deleteNode(int value)` in `LinkedList` class that:
1. Removes the first occurrence of the given value.
2. Handles cases like deleting the head or deleting a non-existing node.

---

## **Doubly Linked List Exercises**
### **Exercise 6: Implement a Doubly Linked List**
Create a `DoublyLinkedList` class with:
1. `insertAtEnd(int)`: Inserts at the end.
2. `insertAtBeginning(int)`: Inserts at the beginning.
3. `displayForward()`: Prints list from head to tail.
4. `displayBackward()`: Prints list from tail to head.

```cpp
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    void displayForward() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void displayBackward() {
        Node* temp = tail;
        while (temp) {
            cout << temp->data << " <-> ";
            temp = temp->prev;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    DoublyLinkedList list;
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);

    cout << "Forward: ";
    list.displayForward();

    cout << "Backward: ";
    list.displayBackward();
    return 0;
}
```

---

### **Exercise 7: Delete a Node in Doubly Linked List**
Implement a `deleteNode(int value)` function in the `DoublyLinkedList` class.

---

## **Challenge Exercise: Detect and Remove Loop in Linked List**
1. Create a function `detectLoop()` that detects if a cycle exists in a linked list using Floyd’s Cycle Detection Algorithm.
2. If a loop is found, write a function `removeLoop()` to remove it.

---