# Chapter 9: List Implementations

---
## Resources:
- [Other Uses Case of List](./Others.md)

## **1. Array-Based Implementation of the ADT List**

### **Concept**
An **array-based implementation** is a common choice for the ADT list because both an array and a list identify their items by a number. However, an ADT list requires operations like `getLength`, which arrays do not provide. In this approach, you must manually keep track of the number of entries.

### **Code Example:**

```cpp
class ArrayList {
private:
    int items[MAX_SIZE];
    int itemCount;

public:
    ArrayList() : itemCount(0) {}

    bool isEmpty() const {
        return itemCount == 0;
    }

    int getLength() const {
        return itemCount;
    }

    void insert(int position, int newEntry) {
        if (position >= 0 && position <= itemCount && itemCount < MAX_SIZE) {
            for (int i = itemCount; i > position; i--) {
                items[i] = items[i - 1];
            }
            items[position] = newEntry;
            itemCount++;
        }
    }

    int getEntry(int position) const {
        if (position >= 0 && position < itemCount) {
            return items[position];
        }
        return -1;  // Error value
    }
};
```

### **Use Case:**
In applications where the number of elements is known in advance and memory constraints are manageable (e.g., small datasets), array-based implementations are efficient and allow quick access by index.

---

## **2. Link-Based Implementation of the ADT List**

### **Concept**
A **link-based implementation** uses pointers instead of arrays to manage elements. The main advantage is that insertion and removal do not require shifting elements, unlike arrays. However, you must traverse the list to access specific elements.

### **Code Example:**

```cpp
class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;
    int length;

public:
    LinkedList() : head(nullptr), length(0) {}

    bool isEmpty() const {
        return head == nullptr;
    }

    int getLength() const {
        return length;
    }

    void insert(int position, int newEntry) {
        Node* newNode = new Node(newEntry);
        if (position == 0) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* prevNode = getNodeAt(position - 1);
            newNode->next = prevNode->next;
            prevNode->next = newNode;
        }
        length++;
    }

    Node* getNodeAt(int position) const {
        Node* current = head;
        for (int i = 0; i < position; i++) {
            current = current->next;
        }
        return current;
    }
};
```

### **Use Case:**
A linked list is ideal for applications where frequent insertions and deletions are required (e.g., implementing undo functionality in text editors) and where resizing an array would be inefficient.

---

## **3. Recursion in Linked List Operations**

### **Concept**
Recursion can simplify some operations on linked lists. For example, adding a node recursively involves adding it to the first node and then continuing down the chain until the appropriate position is found.

### **Code Example (Recursive Insertion):**

```cpp
void insertRecursively(Node*& node, int newEntry) {
    if (node == nullptr) {
        node = new Node(newEntry);
    } else {
        insertRecursively(node->next, newEntry);
    }
}
```

### **Use Case:**
Recursion simplifies the logic for tasks like inserting or traversing linked lists, making the code more concise, though it may not always be the most efficient approach for larger lists due to stack limitations.

---

## **4. Comparing Array-Based vs. Link-Based Implementations**

### **Array-Based Implementation:**
- **Advantages**: Direct access to elements by index, constant time for access.
- **Disadvantages**: Insertion and removal require shifting elements, which is inefficient for large lists.

### **Link-Based Implementation:**
- **Advantages**: Insertion and removal are efficient as no shifting is required.
- **Disadvantages**: Accessing elements requires traversal, making it slower than arrays for random access.

### **Time Complexity Comparison:**

| Operation      | Array-Based       | Link-Based       |
|----------------|-------------------|------------------|
| **Access**     | O(1)              | O(n)             |
| **Insertion**  | O(n) (due to shift)| O(1) (at head)   |
| **Deletion**   | O(n) (due to shift)| O(1) (at head)   |

---

## **5. Use Cases for Each Implementation**

### **Array-Based Implementation:**
- **Use Case**: Efficient when the list size is fixed or rarely changes, such as in games that store predefined levels or settings.

### **Link-Based Implementation:**
- **Use Case**: Suitable for cases with dynamic resizing and frequent insertions/removals, like maintaining a playlist in a music player.

---

## **Conclusion**

Both array-based and link-based implementations of lists have their advantages and disadvantages. The choice of which implementation to use depends on the specific requirements of the application—whether fast random access or frequent insertions and deletions are prioritized.