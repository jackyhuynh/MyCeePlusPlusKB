# Chapter 8: Lists

### Resources:

- [List in Other programming languages](./Others.md)

### **Overview of ADT List**

A list is an Abstract Data Type (ADT) that allows us to manage a collection of items of the same type. Common real-life
examples include:

- Grocery lists
- To-do lists
- Address books

In programming, a **list** can contain objects that:

1. Are of the **same data type**.
2. Have a **finite number** of objects.
3. Are **ordered by position** as determined by the client.

---

### **Basic List Operations**

Here are the common operations that can be performed on a list:

- **Count items**: Find how many elements are in the list.
- **Add/remove items**: Insert or delete elements.
- **Retrieve items**: Access specific items by their position.

### **Example: Grocery List**

Imagine a grocery list where each item is a string:

```cpp
std::list<std::string> groceryList;
groceryList.push_back("Milk");
groceryList.push_back("Eggs");
groceryList.push_back("Bread");
```

#### **Expected Output:**

```
Initial Grocery List:
Milk
Eggs
Bread
```

---

### **UML Diagram of ADT List**

The UML diagram for the ADT list illustrates the structure and operations supported by the list. It provides a visual
representation of the relationship between the list and the operations that can be performed.

---

### **Axioms for the ADT List**

Axioms define the basic properties that any list implementation must satisfy:

- A list has a **finite** number of items.
- The **order** of elements matters, with each element having a unique **position**.
- The items are not necessarily distinct.

---

### **Using List Operations**

#### **Displaying Items in a List:**

```cpp
for (const auto& item : groceryList) {
    std::cout << item << std::endl;
}
```

#### **Replacing an Item in a List:**

```cpp
auto it = std::find(groceryList.begin(), groceryList.end(), "Milk");
if (it != groceryList.end()) {
    *it = "Almond Milk";  // Replacing "Milk" with "Almond Milk"
}
```

#### **Expected Output After Replacement:**

```
Updated Grocery List:
Almond Milk
Eggs
Bread
```

---

### **Interface Template for ADT List**

In C++, you can define an interface for a list using an abstract class. Here's a simplified example:

```cpp
template<class ItemType>
class ListInterface {
public:
    virtual bool isEmpty() const = 0;
    virtual int getLength() const = 0;
    virtual bool insert(int position, const ItemType& newEntry) = 0;
    virtual bool remove(int position) = 0;
    virtual ItemType getEntry(int position) const = 0;
    virtual ~ListInterface() { }
};
```

This interface defines basic operations like checking if the list is empty, getting the length, inserting, removing, and
retrieving items.

#### **Use Case: To-Do List Application**

In a task management app, you could implement this interface to handle tasks as list items. The interface would allow:

- Adding new tasks.
- Removing completed tasks.
- Checking how many tasks are left.

---

### **Conclusion**

In this chapter, we learned about the ADT list, its structure, and its basic operations. Lists provide a versatile way
to manage collections of items where order is important, and items are accessed by their position in the collection.

---

# List VS Vector

### **What is a `list` in C++?**

In C++, a `list` is a **doubly linked list** provided by the Standard Template Library (STL). It allows for efficient
insertions and deletions at both ends as well as in the middle of the list. The C++ STL list is defined in the `<list>`
header.

#### **Key Characteristics of `std::list`**

- **Doubly Linked List:** Each element has pointers to both the previous and next elements.
- **Dynamic Size:** Can grow or shrink dynamically.
- **Efficient Insertions/Deletions:** Insertions and deletions in the middle of the list are **O(1)** if we have an
  iterator to the position.
- **Sequential Access:** Accessing elements requires traversal (`O(n)` for random access).

#### **Example Usage of `std::list`**

```cpp
#include <iostream>
#include <list>

int main() {
    std::list<int> myList = {10, 20, 30, 40};

    myList.push_back(50); // Insert at the end
    myList.push_front(5); // Insert at the beginning

    // Iterate through the list
    for (int num : myList) {
        std::cout << num << " ";
    }
    return 0;
}
```

---

### **Comparison: `std::vector` vs `std::list`**

| Feature                                                          | `std::vector` (Dynamic Array)                          | `std::list` (Doubly Linked List)                                   |
|------------------------------------------------------------------|--------------------------------------------------------|--------------------------------------------------------------------|
| **Underlying Structure**                                         | Dynamic array                                          | Doubly linked list                                                 |
| **Memory Usage**                                                 | Contiguous memory (less overhead)                      | Extra memory for pointers (prev & next)                            |
| **Random Access**                                                | **O(1)** (Direct indexing)                             | **O(n)** (Sequential traversal)                                    |
| **Insertion/Deletion at End (`push_back` & `pop_back`)**         | **O(1)** (Amortized)                                   | **O(1)**                                                           |
| **Insertion/Deletion at Beginning (`push_front` & `pop_front`)** | **O(n)** (Requires shifting elements)                  | **O(1)**                                                           |
| **Insertion/Deletion in the Middle**                             | **O(n)** (Requires shifting elements)                  | **O(1)** (If iterator is known)                                    |
| **Iteration Performance**                                        | **Cache-friendly & Faster** (due to contiguous memory) | **Slower** (due to pointer dereferencing)                          |
| **Sorting (`sort()` method)**                                    | **O(n log n)** (Internally optimized)                  | **O(n log n)** (Implemented as a member function using merge sort) |

---

### **When to Use `std::list` vs `std::vector`**

✅ **Use `std::vector` when:**

- You need fast random access (`O(1)`) using `[]` or `.at()`.
- You perform a lot of insertions/removals at the **end**.
- Memory overhead is a concern (as `std::list` stores extra pointers).

✅ **Use `std::list` when:**

- You frequently insert or delete elements **in the middle or at the beginning**.
- You don't need random access.
- Performance degradation due to shifting elements in `std::vector` is a concern.

---

### **Conclusion**

- `std::vector` is **better** for most general-purpose applications due to its **cache efficiency** and **fast random
  access**.
- `std::list` is useful **only when you need frequent insertions and deletions at arbitrary positions** without worrying
  about random access.
