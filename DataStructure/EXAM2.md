## **Exam2 Review**

### 1. **ADT Stack Operations**

- **`push`**: Adds an item to the top of the stack.
- **`pop`**: Removes the top entry from the stack.
- **`peek`**: Retrieves (but does not remove) the top entry of the stack.
- **`isEmpty`**: Checks if the stack is empty.

---

### 2. **Choosing Array vs Linked Stack Implementations**

**Question**: When is a linked-based stack implementation a better choice?

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
- **Question**: In a **linked-based list**, where is insertion fastest?
---

### 6. **Algorithm Efficiency and Big-O Complexity**

- **Question**: When does algorithm efficiency matter?
- **Question**: What is the time complexity when runtime is independent of input size?
- **Question**: What is the time complexity when runtime grows linearly with input size?
- **Question**: What is the time complexity for two nested loops over a list of size `n`?
- **O(1)**: Constant time, independent of input size.
- **O(n)**: Linear time, proportional to input size.
- **O(n²)**: Quadratic time, often caused by nested loops.
- **O(log n)**: Logarithmic time, typical in divide-and-conquer algorithms.

---

### 7. **ADT Sorted List Operations**

**Question**: How does the ADT Sorted List order its entries?

**Question**: Time complexity of `insertSorted`, `removeSorted`, and `getEntry` in a linked implementation?

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

---

### 9. **Can Programs Use ADT Stack Without Knowing Implementation?**

**Question**: True or False – Can a program use ADT Stack operations without knowing how they are implemented?

---

### 10. **Worst-Case Complexity of Stack and List Operations**

- **Question**: Worst-case time complexity of the `push` operation in a linked stack?
- **Question**: Worst-case time complexity of `insert` operation in an array-based list?
---

### 11. **Inserting and Removing Nodes in a Linked List**

#### **Inserting a Node After a Given Node**

**Question**: Write code to insert a node pointed to by `ptr` after the node

pointed to by `previous` in a linked list.

---

#### **Removing a Node from a Linked List**

**Question**: Write code to remove a node pointed to by `current` and free its memory. Assume `previous` points to the
node before `current`.

---

### 12. **Calculating the Sum of Entries in a List**

**Question**: Using the `ArrayList<int>` object, write code to calculate and display the sum of its entries.
---

### 13. **Summing Entries in a Stack**

**Question**: Using an `ArrayStack<int>` object, write code to print the sum of its integers.
---

### 14. **Adding a `contains` Method to `LinkedList`**

**Question**: Write the `contains` method for the linked list to determine if a given entry is in the list.

---

### 15. **Additional Key Takeaways for the Exam**

- **Linked List vs Array List**: Understand the benefits and drawbacks of each, particularly for insertion and deletion.
- **Stack Operations**: Practice working with both array and linked implementations of stacks.
- **Big-O Complexity**: Be comfortable identifying time complexities for operations on lists, stacks, and other data
  structures.
- **Recursive Functions**: Understand base and recursive cases in recursion.

---