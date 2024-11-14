## **Exam 1 Review**

### 1. **Abstract Data Type (ADT)**

- **Question:** What do the specifications of an ADT's operations indicate? (interface, headerfile)
- **Key Concept:** Understand that ADT specifications describe *what* the operations do, not how they are implemented.

### 2. **Interfaces in Programming**

- **Question:** A(n) ______ allows two modules to communicate with each other.
- **Key Concept:** Learn that **interfaces** provide a communication pathway between modules without needing to know the
  implementation details.

### 3. **C++ Class**

- **Question:** A(n) ______ is a C++ construct that enables a programmer to define a new data type.
- **Key Concept:** Focus on the **class** concept and how it encapsulates data and methods.

### 4. **C++ Class Components**

- **Question:** What are the components of a C++ class?
- **Key Concept:** Review the distinction between data members (fields) and methods (functions) in C++.

### 5. **Objects in C++**

- **Question:** What is an instance of a class called?
- **Key Concept:** Understand that an **object** is a concrete instance of a class in C++.

### 6. **Abstract Data Type (ADT) Bag**

- **Question:** What must a programmer know about ADT Bag to use it?
- **Key Concept:** Emphasize knowing the **interface** of the bag, not the implementation.

### 7. **Recursion**

- **Question:** What terminates recursive processing?
- **Key Concept:** A **base case** is the condition that stops the recursion.

### 8. **Link-Based Implementation**

- **Question:** In a link-based implementation, what node do we have direct access to?
- **Key Concept:** In linked lists, we have direct access only to the first node.

### 9. **Shallow Copy vs. Deep Copy**

- **Question:** When copying an object involves only copying the values of its data members, the copy is called
  a ______.
- **Key Concept:** A *shallow copy* just copies data members, while a deep copy duplicates the object’s referenced
  objects as well.

### 10. **Link-Based Implementation Advantage**

- **Question:** What is a key reason for using a link-based implementation of a bag?
- **Key Concept:** Focus on the flexibility of a linked list that doesn’t have a fixed size.

### 11. **Infix Expressions**

- **Question:** In what type of expression does an operator come between its operands?
- **Key Concept:** Review *infix* notation, where the operator is between operands.

### 12. **Recursive Function without Base Case**

- **Question:** What happens if a recursive function never reaches a base case?
- **Key Concept:** A recursive function without a base case results in infinite recursion and will eventually cause the
  program to abort.

### 13. **Module Cohesion**

- **Question:** When a module performs one well-defined task, we say that it is ______.
- **Key Concept:** A *cohesive* module focuses on a single task.

### 14. **Modules**

- **Question:** Which of the following is not a module?
- **Key Concept:** A *data member* is part of a class but isn’t considered a standalone module.

### 15. **C++ Class Creation (Essay)**

- **Question:** Write a C++ class called `InventoryItem` with specific member functions.
- **Key Concept:** Practice writing C++ class definitions and method prototypes, understanding accessors, mutators, and
  how to handle encapsulation properly.

### 16. **ArrayBag Display Method (Essay)**

- **Question:** Implement a display method for the `ArrayBag` class template.
- **Key Concept:** Learn how to iterate over an array and display its contents within a class.

### 17. **ArrayBag Declaration (Essay)**

- **Question:** Write the declaration of an `ArrayBag` object for integers and add an element.
- **Key Concept:** Practice working with class templates and their specific type instantiations in C++.

### 18. **Dynamic Memory Allocation (Essay)**

- **Question:** Dynamically allocate an `ArrayBag` object and store its address in a pointer.
- **Key Concept:** Review dynamic memory allocation and the use of pointers in C++.

### 19. **Recursive Function Analysis (Essay)**

- **Question:** Analyze the recursive function provided.
- **Key Concept:** Understand how recursion works, identify base and recursive cases, and trace the function's behavior.

### 20. **Node Class and Linked List Manipulation (Essay)**

- **Question:** Remove the first node from a linked list and free the memory used by that node.
- **Key Concept:** Learn how to manipulate linked lists in C++, including proper memory management.

### 21. **ArrayBag Entry Storage (Essay)**

- **Question:** Where are entries stored in the `ArrayBag`?
- **Key Concept:** Understand the internal structure of the `ArrayBag` class and where items are stored.

### 22. **Error Handling**

- **Question:** According to the textbook, what is a good way to handle an unusual condition detected in a method?
- **Key Concept:** Review how to handle errors by returning error values or throwing exceptions.

## **Exam2 Review**

### 1. **ADT Stack Operations**

- **`push`**: Adds an item to the top of the stack.
- **`pop`**: Removes the top entry from the stack.
- **`peek`**: Retrieves (but does not remove) the top entry of the stack.
- **`isEmpty`**: Checks if the stack is empty.

---

### 2. **Choosing Array vs Linked Stack Implementations**

**Question**: When is a linked-based stack implementation a better choice?

- **Answer**: When the stack size can be **large** and fluctuates.
    - **Reason**: Linked stacks grow dynamically, unlike arrays which have a fixed size.

#### b. **Implementation of ADT Stack**

- **Array-based**: Fixed size, better when stack size is known.
- **Linked-based**: Ideal when stack size varies since it grows dynamically.

---

### 3. **ADT List Concepts**

- **Predecessors**: The first entry in a list has no predecessor.
- **Insertion**:
    - **Array-based list**: Fastest insertion is at the **end**.
    - **Linked-based list**: Fastest insertion is at the **beginning**.

---

### 4. **ADT List - Predecessors and Valid Insertions**

**Question**: Which entry has no unique predecessor?

- **Answer**: The **first entry**

**Question**: If a list holds 12 entries, which insertion index is invalid?

- **Answer**: **13** (since the valid range is 1–13)

---

### 5. **Fastest Insertion Positions in Lists**

- **Question**: In an **array-based list**, where is insertion fastest?
    - **Answer**: **End of the list** (no shifting required).

- **Question**: In a **linked-based list**, where is insertion fastest?
    - **Answer**: **Beginning of the list** (only head pointer changes).

---

### 6. **Algorithm Efficiency and Big-O Complexity**

- **Question**: When does algorithm efficiency matter?
    - **Answer**: For **large problems** (Big-O analysis is most relevant here).

- **Question**: What is the time complexity when runtime is independent of input size?
    - **Answer**: **O(1)** (constant time)

- **Question**: What is the time complexity when runtime grows linearly with input size?
    - **Answer**: **O(n)**

- **Question**: What is the time complexity for two nested loops over a list of size `n`?
    - **Answer**: **O(n²)**

- **O(1)**: Constant time, independent of input size.
- **O(n)**: Linear time, proportional to input size.
- **O(n²)**: Quadratic time, often caused by nested loops.
- **O(log n)**: Logarithmic time, typical in divide-and-conquer algorithms.

---

### 7. **ADT Sorted List Operations**

**Question**: How does the ADT Sorted List order its entries?

- **Answer**: By **value**

**Question**: Time complexity of `insertSorted`, `removeSorted`, and `getEntry` in a linked implementation?

- **Answer**: **O(n)** (due to traversal of nodes)

---

### 8. **C++ Code Behavior: ArrayStack Example**

Given code:

```cpp
ArrayStack<char> myStack;
myStack.push('P');
myStack.push('I');
myStack.push('E');
while (!myStack.isEmpty()) {
    cout << myStack.peek();
    myStack.pop();
}
```

**Question**: What does this code print?

- **Answer**: **"EIP"** (LIFO – Last In, First Out)

---

### 9. **Can Programs Use ADT Stack Without Knowing Implementation?**

**Question**: True or False – Can a program use ADT Stack operations without knowing how they are implemented?

- **Answer**: **True**

---

### 10. **Worst-Case Complexity of Stack and List Operations**

- **Question**: Worst-case time complexity of the `push` operation in a linked stack?
    - **Answer**: **O(1)** (since it only changes the head pointer).

- **Question**: Worst-case time complexity of `insert` operation in an array-based list?
    - **Answer**: **O(n)** (shifting elements in worst case).

---

### 11. **Inserting and Removing Nodes in a Linked List**

#### **Inserting a Node After a Given Node**

**Question**: Write code to insert a node pointed to by `ptr` after the node

pointed to by `previous` in a linked list.

**Answer**:

```cpp
ptr->setNext(previous->getNext());
previous->setNext(ptr);
```

---

#### **Removing a Node from a Linked List**

**Question**: Write code to remove a node pointed to by `current` and free its memory. Assume `previous` points to the
node before `current`.

**Answer**:

```cpp
previous->setNext(current->getNext());
delete current;
current = nullptr;
```

---

### 12. **Calculating the Sum of Entries in a List**

**Question**: Using the `ArrayList<int>` object, write code to calculate and display the sum of its entries.  
**Answer**:

```cpp
int sum = 0;
for (int i = 1; i <= aList.getLength(); ++i) {
    sum += aList.getEntry(i);
}
cout << "Sum: " << sum << endl;
```

---

### 13. **Summing Entries in a Stack**

**Question**: Using an `ArrayStack<int>` object, write code to print the sum of its integers.  
**Answer**:

```cpp
int sum = 0;
while (!aStack.isEmpty()) {
    sum += aStack.peek();
    aStack.pop();
}
cout << "Sum: " << sum << endl;
```

---

### 14. **Adding a `contains` Method to `LinkedList`**

**Question**: Write the `contains` method for the linked list to determine if a given entry is in the list.

**Answer**:

```cpp
template <class ItemType>
bool LinkedList<ItemType>::contains(const ItemType& anEntry) const {
    Node<ItemType>* current = headPtr;
    while (current != nullptr) {
        if (current->getItem() == anEntry) {
            return true;
        }
        current = current->getNext();
    }
    return false;
}
```

---

### 15. **Additional Key Takeaways for the Exam**

- **Linked List vs Array List**: Understand the benefits and drawbacks of each, particularly for insertion and deletion.
- **Stack Operations**: Practice working with both array and linked implementations of stacks.
- **Big-O Complexity**: Be comfortable identifying time complexities for operations on lists, stacks, and other data
  structures.
- **Recursive Functions**: Understand base and recursive cases in recursion.

---

## **Exam3 Review**

1. **Question**: Explain why algorithm efficiency, measured in Big-O notation, is generally a concern. What types of problems benefit most from this analysis?

2. **Question**: Describe the worst-case time complexity of a binary search algorithm when searching a sorted array. What factors influence this complexity?

3. **Question**: Compare the time complexity of inserting an item into a SortedList ADT and a balanced binary search tree. What are the key differences?

4. **Question**: Discuss how the number of comparisons needed for a retrieval operation in a binary search tree can be determined. What structural aspect of the tree is most relevant to this comparison?

5. **Question**: Identify and explain an operation that is not typically part of the standard ADT Queue operations. Justify why it would or wouldn’t be included.

6. **Question**: In a priority queue, what determines the order in which items are removed? Provide an example to illustrate this behavior.

7. **Question**: When designing a simple word processor that allows a user to backspace and correct typing errors, what ADT would you choose to implement this functionality? Explain your reasoning.

8. **Question**: Provide an example of a real-life scenario that can be modeled using a queue. How does this ADT reflect the behavior observed in your example?

9. **Question**: What is the Big-O worst-case time complexity of the sequential search algorithm? Describe a situation where this search method would be used and how the time complexity impacts performance.

10. **Question**: Explain the worst-case time complexity of the bubble sort algorithm. Discuss when using this sorting algorithm might still be appropriate despite its complexity.

11. **Data Structure to Review**: What is Big O Operation on, Binary Search, Sorted List, Tree, Stack, Queue, Binary Tree, priority Queue, Tree Traversal, Sorting Algorithms (Buble, Merge, Insertion, Selection, Quick), Heap, Linear, Tree, Hashing, Dictionary