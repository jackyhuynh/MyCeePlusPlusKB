# Chapter 12: Sorted Lists and Their Implementations

---

## **1. Specifying the ADT Sorted List**

An **ADT Sorted List** is a container that automatically maintains the order of its entries based on their values. Duplicate items are allowed in this list.

### **Operations Supported**:
- Adding items
- Removing items
- Locating items based on their values
- Operations like `getEntry`, `remove`, `clear`, `getLength`, and `isEmpty` are similar to ADT List operations.

---

## **2. Interface Template for the ADT Sorted List**

The ADT sorted list defines an interface that specifies these operations without allowing entries to be added or replaced at specific positions (i.e., the positions are determined by the sorting order).

### **Example Interface (C++):**

```cpp
template<class ItemType>
class SortedListInterface {
public:
    virtual bool insertSorted(const ItemType& newEntry) = 0;
    virtual bool removeSorted(const ItemType& anEntry) = 0;
    virtual int getPosition(const ItemType& anEntry) const = 0;
    virtual ItemType getEntry(int position) const = 0;
    virtual bool isEmpty() const = 0;
    virtual int getLength() const = 0;
    virtual void clear() = 0;
};
```

---

## **3. Link-Based Implementation of a Sorted List**

A common implementation of the sorted list is through a **linked chain of nodes**. This approach avoids the need to shift elements like in arrays. However, inserting elements in the correct position requires traversing the chain, which has a time complexity of **O(n)**.

### **Linked List Implementation Example:**

```cpp
template<class ItemType>
class LinkedSortedList {
private:
    std::shared_ptr<Node<ItemType>> headPtr;
    int itemCount;

public:
    LinkedSortedList() : headPtr(nullptr), itemCount(0) {}

    bool insertSorted(const ItemType& newEntry) {
        auto newNode = std::make_shared<Node<ItemType>>(newEntry);
        auto prevPtr = getNodeBefore(newEntry);
        if (!prevPtr) {  // Insert at head
            newNode->next = headPtr;
            headPtr = newNode;
        } else {
            newNode->next = prevPtr->next;
            prevPtr->next = newNode;
        }
        itemCount++;
        return true;
    }

    // Other methods such as removeSorted, getEntry, etc.
};
```

### **Use Case**:
This linked list-based implementation of the sorted list is ideal for situations where insertions and deletions are frequent, but direct access by index is not required. An example could be a priority queue where items need to stay sorted based on their priority.

---

## **4. Containment: Reusing ADT List Implementations**

Another approach to implementing the sorted list is **containment**, where the sorted list contains an instance of another list (like a linked list). This helps avoid duplicating the functionality provided by the ADT List.

### **Containment Example:**

```cpp
template<class ItemType>
class SortedListHasA {
private:
    LinkedList<ItemType> list;

public:
    bool insertSorted(const ItemType& newEntry) {
        int newPosition = getPosition(newEntry);
        return list.insert(newPosition, newEntry);
    }

    // Other methods like removeSorted, getPosition, etc.
};
```

### **Use Case**:
Containment is useful when you already have an existing linked list or vector implementation and want to reuse it to build more complex structures like a sorted list. For instance, a database might use this approach to maintain a sorted list of records without duplicating effort.

---

## **5. Public Inheritance**

Public inheritance can be used when there is an **is-a relationship** between the ADT Sorted List and an existing list class. For example, a **SortedListIsA** class can inherit from a `LinkedList` class and override methods as needed.

### **Public Inheritance Example:**

```cpp
template<class ItemType>
class SortedListIsA : public LinkedList<ItemType> {
public:
    bool insertSorted(const ItemType& newEntry) override {
        // Insert while keeping the list sorted
        return LinkedList<ItemType>::insert(getPosition(newEntry), newEntry);
    }

    // Override other methods like removeSorted, getPosition, etc.
};
```

### **Use Case**:
Inheritance is ideal for extending the functionality of a base list class, such as when creating a specialized list like a sorted or filtered list from a generic list implementation.

---

## **6. Efficiency Considerations**

- **Link-based implementation**: Insertion requires traversing the list to find the correct position, which is **O(n)**.
- **Containment** and **inheritance** implementations** leverage existing list structures, and their efficiency is based on the underlying list's operations.

### **Efficiency Example**:

| Operation         | Array-Based Implementation | Link-Based Implementation |
|-------------------|----------------------------|---------------------------|
| Insert            | O(n)                        | O(n)                       |
| Remove            | O(n)                        | O(n)                       |
| Access by Position| O(1)                        | O(n)                       |

---

## **Conclusion**

- The ADT Sorted List ensures entries are maintained in order based on their values.
- Various implementations are possible, including link-based structures, containment, and inheritance.
- The choice of implementation should depend on the specific use case, such as whether insertions, deletions, or access by position is more frequent.

---

This summary provides an overview of the different implementations of the ADT Sorted List, including code samples and practical use cases for each approach.