# Data Structure

I use this Data Structure material to teach students at College and University Level.

## Resources

- **Testing Framework**: [GoogleTest for C++](https://google.github.io/googletest/)
- **Developer Roadmap**: [C++ Developer Roadmap](https://roadmap.sh/cpp)

---

## Common Errors with `g++`

To avoid errors related to C++ version compatibility, use the following command to compile with the correct standard (e.g., `C++11`, `C++17`):
```bash
g++ -std=c++17 some_source.cpp -o driver
```

---

## Exam Topics Overview

### 1. Object-Oriented Programming (OOP) - Concepts

OOP is a paradigm based on "objects," encapsulating data (fields) and behaviors (methods). Core concepts:
- **Encapsulation**: Bundles data and behavior into one unit.
- **Inheritance**: Allows one class to inherit from another.
- **Polymorphism**: Methods adapt based on the object they're acting upon.

### 2. Linked Lists

- **Singly Linked List**: `InsertAtBeginning`, `InsertAtEnd`, `Update`, `Delete`, `IsEmpty`
- **Doubly Linked List**: Similar operations with additional backward links for efficient bidirectional traversal.
- **Head and Tail Concepts**: Head points to the first node; tail points to the last node.

### 3. Recursion

- **Concept**: A method that calls itself, often breaking down problems into smaller parts.
- **Key Components**:
  - **Base Case**: Stops the recursion.
  - **Recursive Case**: Calls the function within itself, reducing the problem scope each time.

### 4. OOP Fundamentals

- **Polymorphism**:
  - **Compile-Time (Method Overloading)**: Different methods with the same name but different parameters.
  - **Runtime (Method Overriding)**: Base class methods overridden in derived classes.
- **Classes and Access Modifiers**: `getter`, `setter`, `public`, `private`, `protected`
- **Virtual Methods**: Functions that can be overridden in derived classes.
- **Abstract Classes**: Define methods that must be implemented in subclasses.
- **Inheritance**: Types include single, multiple, multilevel, hierarchical, and hybrid inheritance. Code examples provided.

### 5. Exception Handling

- Use `try`, `catch`, and `throw` to handle errors and control program flow during runtime.

### 6. Sorted Lists

- **Linked List**: Insertion logic and code for maintaining order.
- **Array Implementation**: Similar insertion logic applied to arrays.

### 7. Stack (Abstract Data Type)

- **Operations**: `Push`, `Pop`, `Peek`, `IsEmpty`
- **ADT Stack**: Understand basic stack functionality and application.

### 8. Friend Functions

- Allows certain functions to access private data of a class. **Code logic only**.

### 9. Queue and Priority Queue

- **Queue**: Linear data structure with FIFO ordering.
- **Priority Queue**: Ordered based on priority rather than FIFO.
- **Use Cases**: Process scheduling, task management.

### 10. Operator Overloading

- Overloaded operators define custom behaviors for standard operators (`+`, `-`, etc.) with classes.

### 11. Graphs

- **Example**: `ch16_graph.cpp`
- **Applications**: Network routing, social networks, pathfinding.

### 12. Trees

- **Tree Concepts**:
  - **Binary Tree**: Each node has up to two children.
  - **Binary Search Tree (BST)**: Nodes are organized based on value order.
  - **AVL Tree**: Balanced BST with height differences of 1 or less.
  - **Tree Elements**: Node, Root, Leaf, Edge.
  - **Applications**: File systems, decision trees, DOM (Document Object Model).

#### Tree Traversal Types
- **Breadth-First Traversal**: Level-order.
- **Depth-First Traversal**:
  - **In-order**: Left, root, right.
  - **Pre-order**: Root, left, right.
  - **Post-order**: Left, right, root.

#### AVL Tree Balance Factor
- Balance Factor (BF) formula:
  ```
  BF(node) = Height(LeftSubtree) - Height(RightSubtree)
  ```

### 13. Graph and Tree Structures

```c++
// Graph and Tree hierarchy example.
`-- Graph/
    `-- Tree/
        `-- Binary Tree/
            `-- Binary Search Tree/
               `-- AVL Tree/
```

### 14. Heaps

- **Concepts**: Max Heap, Min Heap, Heap Sort
- **Use Case**: Priority queue implementation.

### 15. Hashing

- **Concept**: Maps keys to values for efficient data retrieval.
- **Collision Handling**: Techniques include double hashing, quadratic probing, and linear probing.
- **Difference**:
  - **Map vs. Unordered Map**: `std::map` is ordered, `std::unordered_map` uses a hash table.
  - **Hash Table vs Dictionary**: Both offer key-value storage, but implementation may vary.

### 16. Sorting Algorithms

- **Sort Implementations**: Merge Sort and Linear Sort
- **Manual Sorting Practice**: Solve sorting problems by hand for exam preparation.

### 17. Search Algorithms

- **Binary Search**:
  - **Precondition**: Array must be sorted.
  - **Algorithm**: Divide and conquer for quick value lookup.
- **Linear Search**: Sequential search with `O(n)` complexity.


### Implementation
- Apache Spark
- Hadoop Cluster
- MongoDB
- Amazon Neptune