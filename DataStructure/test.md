### 8. **Summing List Elements in C++**

Given:

```cpp
ArrayList<int> aList;
```

**Code to Sum Entries:**

```cpp
int sum = 0;
for (int i = 1; i <= aList.getLength(); ++i) {
    sum += aList.getEntry(i);
}
cout << "Sum: " << sum << endl;
```

---

### 9. **Summing Stack Elements in C++**

Given:

```cpp
ArrayStack<int> aStack;
```

**Code to Sum Stack Entries:**

```cpp
int sum = 0;
while (!aStack.isEmpty()) {
    sum += aStack.peek();
    aStack.pop();
}
cout << "Sum: " << sum << endl;
```

---

### 10. **Creating a `contains` Method for Linked List**

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

### 11. **Worst-case Time Complexity of Stack and List Operations**

- **Push operation in linked stack**: **O(1)** (constant time).
- **Insert operation in array-based list**: **O(n)** (shifting elements can take linear time).

---

This review guide covers the key topics needed for your exam. Let me know if you need clarification on any specific
section!