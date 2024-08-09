# Exam review

**IF YOU SHOW UP AND TRY TO ANSWER ALL MY QUESTIONS, I WILL GIVE YOU AT LEAST 50% SCORE**

## Production Resource for C++

- Testing framework [GoogleTest for C++](https://google.github.io/googletest/)
- [C++ Developer Roadmap](https://roadmap.sh/cpp)

## Run into error with g++:

- Please use the command to run each file since they use newer version of C++ (eg: c++11, c++13, c++17)

```bash
g++ -std=c++17 ch5_recursion_problem_solving.cpp -o driver
```

## Exam1 review:

### 1. OOP (Concept Only)

Object-oriented programming (OOP) is a programming paradigm that uses "objects" to design software. Objects are
instances of classes, which can contain both data in the form of fields (often known as attributes or properties) and
code in the form of procedures (often known as methods). OOP focuses on the concepts of encapsulation, inheritance, and
polymorphism. Encapsulation allows bundling data and methods that work on that data within one unit, inheritance enables
a class to inherit characteristics from another class, and polymorphism allows methods to do different things based on
the object it is acting upon. This approach aims to increase the flexibility and maintainability of code by organizing
software design around data, or objects, rather than functions and logic.

### 2. Linked List:

- Single (InsertAtBeginning (or the Ends), Update, Delete, IsEmpty )
- Double(InsertAtBeginning (or the Ends), Update, Delete, IsEmpty )
- Head, Tails concepts

In the context of a linked list, the "head" and "tails" pointers (though typically it's singular "tail") are references
used to efficiently manage the list.

    - **Head Pointer**: The head pointer points to the first node in a linked list. It is the primary entry point to the list, allowing access to every other node by traversing from the head through each node's next pointer until the end of the list is reached. In an empty list, the head pointer is typically set to null.

    - **Tail Pointer**: The tail pointer points to the last node in a linked list. Having a tail pointer is particularly useful in singly linked lists when you want to append elements efficiently. Without a tail pointer, appending an element would require traversing the entire list to find the last node. In an empty list, the tail pointer, like the head, is set to null.

Using head and tail pointers simplifies operations such as insertion and deletion at both the beginning and the end of
the list, enhancing the performance of these operations.

### 3. Recursive:

- Recursive:
    - Recursive refers to a method or process that solves a problem by breaking it down into smaller, more manageable
      problems of the same type. In programming, a recursive function is one that calls itself within its own code. This
      approach is particularly useful for tasks that can be divided into similar subtasks, such as sorting algorithms (
      e.g., quicksort, mergesort), navigating tree structures (e.g., searching in binary trees), or calculating
      mathematical sequences (e.g., Fibonacci numbers).

    - A key feature of a recursive function is the presence of a base case, which is a condition that stops the
      recursion to prevent it from continuing indefinitely. Each recursive call should bring the current problem closer
      to the base case, eventually terminating the recursion.

- Basic Recursive concept: In recursion, a function calls itself to solve a problem by breaking it down into smaller,
  more manageable sub-problems. This process is defined by two essential components: the base case and the recursive
  case.
    - Base Case: The base case is a condition that stops the recursion from continuing indefinitely. It defines the
      simplest instance of the problem, which can be solved directly without further recursion. The base case acts as a
      termination point for the recursive function, ensuring that it eventually ends. When the function encounters a
      base case, it returns a value without making any more recursive calls.
    - Recursive case: The recursive case is the part of the function that includes the recursive call. It breaks down
      the problem into smaller instances, moving the problem closer to the base case with each recursive step. The
      recursive case must eventually lead to the base case to prevent infinite loops and stack overflow errors.

### 4. OOP Fundamental:

- Polymorphism (Many form):
    - Compile-Time Polymorphism (Method Overloading): This occurs when there are multiple methods in the same scope with
      the same name but different parameters (number of parameters, types of parameters, or both). The correct method to
      be executed is determined at compile time based on the method signature. This is also known as method overloading.

    - Runtime Polymorphism (Method Overriding): This is achieved through inheritance and virtual functions (or methods).
      In this case, a method in a base class is overridden by a method in a derived class. The determination of which
      method to call is made at runtime based on the type of the object that invokes the method. This allows objects of
      different classes to be treated as objects of a common superclass, with each object responding to common methods
      in its own way. This is also known as method overriding.
- Class and Object: getter and setter, private, public, protected class(concept + code)
- virtual methods? (Concept + code): A virtual method is a function or method in a base class that can be overridden in
  derived classes. Declaring a method as virtual allows it to be dynamically dispatched, meaning that the method call is
  resolved at runtime based on the object's actual type, not its declared type. This capability is crucial for
  implementing polymorphism, allowing objects of different classes to be treated as objects of a common base class while
  still behaving according to their actual class.
- abstract class? (Concept + code): An abstract class is a class that cannot be instantiated on its own and is designed
  to be subclassed. It often contains one or more abstract methods, which are methods declared in the abstract class but
  must be implemented by its subclasses. While not directly called "virtual classes," abstract classes serve a similar
  conceptual purpose by providing a blueprint for other classes.
- Inheritance: Inheritance is a fundamental concept in Object-Oriented Programming (OOP) that allows a class to inherit
  properties (attributes/fields) and methods (functions) from another class. The class that inherits the properties and
  methods is known as the child class, subclass, or derived class, while the class from which the properties and methods
  are inherited is called the parent class, superclass, or base class. Inheritance enables a hierarchy of classes that
  can share, extend, and modify behavior and attributes from parent classes to child classes. This mechanism promotes
  code reusability, making it easier to create and maintain applications by allowing developers to build new classes
  upon existing classes without having to rewrite code from scratch.There are several types of inheritance in OOP,
  including:

    - Single Inheritance: A child class inherits from one parent class.
    - Multiple Inheritance: A child class inherits from more than one parent class. (Note: Not all programming languages
      support multiple inheritance directly, e.g., Java uses interfaces to achieve a similar effect.) (Concept + Code)

    ```cplus
    // In multiple inheritance, a class can inherit from more than one class.
    #include <iostream>
    using namespace std;

    class ClassA {
    public:
        void displayA() { cout << "Class A content.\n"; }
    };

    class ClassB {
    public:
        void displayB() { cout << "Class B content.\n"; }
    };

    class ClassC : public ClassA, public ClassB {
    };

    int main() {
        ClassC objC;
        objC.displayA();
        objC.displayB();
        return 0;
    }

    ```
    - Multilevel Inheritance: A form of inheritance where a class is derived from a child class, making it a grandchild
      class.
    ```cplus
    // In multilevel inheritance, a class is derived from a class which is also derived from another class.

    #include <iostream>
    using namespace std;

    class ClassA {
    public:
        void displayA() { cout << "Class A content.\n"; }
    };

    class ClassB : public ClassA {
    public:
        void displayB() { cout << "Class B content.\n"; }
    };

    class ClassC : public ClassB {
    public:
        void displayC() { cout << "Class C content.\n"; }
    };

    int main() {
        ClassC objC;
        objC.displayA();
        objC.displayB();
        objC.displayC();
        return 0;
    }

    ```
    - Hierarchical Inheritance: Multiple classes inherit from a single parent class.
    ```cplus
    // In hierarchical inheritance, several classes are derived from a single base class.

    #include <iostream>
    using namespace std;

    class BaseClass {
    public:
        void displayBase() { cout << "Base class content.\n"; }
    };

    class DerivedClass1 : public BaseClass {
    public:
        void displayDerived1() { cout << "Derived Class 1 content.\n"; }
    };

    class DerivedClass2 : public BaseClass {
    public:
        void displayDerived2() { cout << "Derived Class 2 content.\n"; }
    };

    int main() {
        DerivedClass1 obj1;
        DerivedClass2 obj2;
        obj1.displayBase();
        obj1.displayDerived1();
        obj2.displayBase();
        obj2.displayDerived2();
        return 0;
    }

    ```
    - Hybrid Inheritance: A combination of two or more types of inheritance.
    ```cplus
    // Hybrid inheritance is a combination of two or more types of inheritance. 
    #include <iostream>
    using namespace std;

    class ClassA {
    public:
        void displayA() { cout << "Class A content.\n"; }
    };

    class ClassB : public ClassA {
    public:
        void displayB() { cout << "Class B content.\n"; }
    };

    class ClassC : public ClassA {
    public:
        void displayC() { cout << "Class C content.\n"; }
    };

    class ClassD : public ClassB, public ClassC {
    public:
        void displayD() { cout << "Class D content.\n"; }
    };

    int main() {
        ClassD objD;
        objD.displayB(); // From ClassB
        objD.displayC(); // From ClassC
        objD.displayD();
        // Note: objD.displayA() is ambiguous without further specification due to the diamond problem
        return 0;
    }

    ```
- Inheritance allows for the specification of generic types and behaviors in the parent class, which can be inherited or
  overridden by child classes to provide more specific implementations. This is crucial for implementing polymorphism
  and encouraging a modular and structured approach to programming.
- Multiple inheritance?

### 5. Exception Handling (Concept+ Code):

- try block
- catch block
- thrown statement

### 6. Sorted List (Concept + Code):

- Linked List Implementation (Concept + Code) (insert)
- Array Implementation (Concept + Code) (insert)

### 7. Stack (CC):

- ADT Stack
- Stack Node functions (Push, Pop, Peek, Is_empty)

### 8. Friends

- Code LOGIC ONLY
- Understand how to use friend (review and learn use case)

### 9. Queue and Priority Queue

- ch13_queue.cpp (code + logic)
- ch13_priority_queue (logic)
- What are some popular use cases for queue and priority queues?

### 10. Overload Operator

- ch13_overload_operator.cpp (logic)
- ch13_overload_operator_array.cpp (code + logic)
- What is an overload operator:  Overloaded operators allow you to define custom behavior for operators (such as +, -,
- *, /, etc.) when they're applied to instances of your custom classes.

### 11. Graph:

- ch16_graph.cpp (code + logic)
- What are some popular use cases for Graph data structure?

### 12. Tree:

- ch16_tree.cpp (code+logic)
- ch16_binary_tree_array.cpp (code+logic)
- ch16_binary_search_tree.cpp (logic)
- ch16_AVL_tree (logic)

#### A. Concept

Tree data structures are fundamental in computer science, used for hierarchically organizing data. There are several
types of tree data structures, each with its unique properties and use cases. Here are some of the most commonly used
types:

1. **Binary Tree**: A tree where each node has at most two children, referred to as the left child and the right child.
2. **Binary Search Tree (BST)**: A binary tree where for each node, all elements in the left subtree are less than the
   node, and all elements in the right subtree are greater. This property enables efficient searching, insertion, and
   deletion operations.
3. **AVL Tree**: A self-balancing binary search tree where the height of the two child subtrees of any node differs by
   no more than one. If at any time they differ by more than one, balancing is done to restore this property.
4. **Red-Black Tree**: Another type of self-balancing binary search tree where each node contains an extra bit for
   denoting the color of the node, either red or black. It enforces balancing constraints that ensure the tree remains
   balanced, leading to good worst-case guarantees for insertion, deletion, and lookup operations.
5. **Heap**: Although not a tree in the traditional sense of a hierarchical data structure, heaps are often implemented
   as binary trees. They are used to implement priority queues, with the heap property ensuring that the parent node is
   either greater than or equal to (in a max heap) or less than or equal to (in a min-heap) its child nodes.

#### B. Tree Elements

The elements of a tree in data structures are metaphors borrowed from natural trees, helping to conceptualize the
hierarchical organization of data. Here's an overview of the primary elements:

1. **Node**: A tree node is a fundamental part of a tree structure. It represents an individual element or a point in
   the tree. Each tree node can store data (such as values or information) and has pointers or references to other
   nodes. These pointers define the relationship between nodes in the tree. Specifically, in a tree structure:

    - **Root Node**: The top node in a tree. It is the only node without a parent.
    - **Parent Node**: A node that has one or more child nodes.
    - **Child Node**: A node that has a parent node to which it is connected.
    - **Siblings**: Nodes that share the same parent.

2. **Root**: The **root** is the topmost element of a tree, serving as the origin from which all other elements branch
   out. There is exactly one root per tree, and it is the only element without a parent. The root serves as the entry
   point to access any other element within the tree. Nodes in a tree structure are connected in a way that they start
   from the root node and branch out. The connection between nodes is typically represented by pointers (in languages
   like C or C++) or references (in languages like Java or Python).

3. **Leaves (Leaf Nodes)**; Leaf nodes are the nodes in a tree that do not have any children. They are the end points of
   the tree, where the structure terminates. Leaves are important because they represent the simplest form of nodes in
   the tree, containing data but not leading to any further nodes. In a metaphorical sense, just as leaves on a real
   tree are at the ends of branches, leaf nodes in a data structure tree are at the ends of the branches of the tree.

4. **Branch**: A **branch** is not usually defined as a standalone element in data structures but rather as the
   connections between nodes. In a more abstract sense, a branch can refer to a part of the tree that extends from one
   node to its children. It symbolizes the relationship and hierarchy between different parts of the tree.

5. **Edge**: An **edge** is a connection between two nodes in the tree. It represents the parent-child relationship. The
   number of edges in a tree is always one less than the number of nodes because every node, except the root, is
   connected by exactly one incoming edge from its parent.

#### C. Properties and Importance

- **Hierarchical Structure**: Trees are hierarchical data structures. The tree starts with a root node and expands into
  more nodes, branching out into leaves.
- **Path**: In a tree, there is exactly one unique path from the root node to any node in the tree, including to any
  leaf node.
- **Depth and Height**: The depth of a node is the number of edges from the root node to the node. The height of a tree
  is the maximum depth among all leaf nodes. Leaf nodes have a depth that can vary depending on their position in the
  tree and a height of 0.

#### D. Applications

Both nodes and leaves are crucial for understanding and working with trees in computer science. They play key roles in
various applications, including:

- **File Systems**: Representing directories (nodes) and files (leaves).
- **Decision Trees**: In machine learning, where decisions (nodes) lead to outcomes (leaves).
- **DOM (Document Object Model)**: In web development, where HTML elements are nodes, and text nodes are leaves.
- **Parsing Expressions**: In compilers, where operators and operands form nodes in an expression tree, and operands are
  often leaf nodes.

Understanding these basic concepts is essential for navigating more complex data structures and algorithms, such as
binary trees, AVL trees, and B-trees, where the arrangement and operations on nodes and leaves determine the efficiency
of data storage, retrieval, and manipulation.

### 13. Tree Traversal

[Tree Traversal](https://www.youtube.com/watch?v=9RHO6jU--GU)

#### A. Bread-First Traversals: (LOGIC)

**Level-order Traversal**:

- Visit nodes level by level from top to bottom.
- This method is useful for printing the tree in level order or solving problems that require visiting nodes in a
  level-wise manner.

#### B. Depth-First Traversals: (CODE + LOGIC)

1. **In-order Traversal**:
    - Visit the left subtree.
    - Visit the root node.
    - Visit the right subtree.
    - This traversal method is commonly used because, for binary search trees, it retrieves data in sorted order.

2. **Pre-order Traversal**:
    - Visit the root node.
    - Visit the left subtree.
    - Visit the right subtree.
    - This method is useful for creating a copy of the tree or prefix notation expressions.

3. **Post-order Traversal**:
    - Visit the left subtree.
    - Visit the right subtree.
    - Visit the root node.
    - Useful for deleting the tree (since you delete children before the parent) or for postfix notation expressions.

#### C. AVL Tree Balance Factor

The balance factor of a node in an AVL (Adelson-Velsky and Landis) tree is calculated as the height of its left subtree
minus the height of its right subtree. This balancing factor is used to maintain the AVL tree's balance property,
ensuring that the difference in heights of the left and right subtrees of any node is no more than 1. The balance factor
can be -1, 0, or +1 for a balanced AVL tree, indicating that the right subtree is taller, both subtrees are of equal
height, or the left subtree is taller, respectively.

#### D. Formula:

Here's the formula for calculating the balance factor BF of a node:

      BF(node)=Height(LeftSubtree)−Height(RightSubtree)

#### E. Calculating Heights:

To apply this formula, you first need a way to calculate the height of a subtree. The height of a subtree is the length
of the longest path from the root of the subtree to a leaf node. A leaf node (a node with no children) has a height of
0, and a null pointer (indicating no subtree) has a height of -1 by convention to simplify calculations.

- [AVL Trees Simply Rotation](https://www.youtube.com/watch?v=zP2xbKerIds&list=PLhXWHUoid1m3zVo6FxctHykQr81reE9hX)

### 13. Structure of Graph & Tree family

```
/**
 * .
`-- Graph/
    `-- Tree/
        `-- Binary Tree/ (balance, complete, B(n)<=1)
            `-- Binary Search Tree/ (left data < right data)
               |-- Traversal/
               |   |-- Bread First Traversal
               |   `-- Depth First Traversal/
               |       |-- In-order Traversal: Left - Root - Right (LEFT, DATA, RIGHT)
               |       |-- Pre-order Traversal: Root - Left - Right (DATA, LEFT, RIGHT)
               |       `-- Post-order Traversal: Left - Right - Root (LEFT, RIGHT, DATA)
               `-- AVL Tree/ (left data < right data + self rotation)
                  |-- Traversal/
                  |   |-- Bread First Traversal
                  |   `-- Depth First Traversal
                  `-- Tree Rotations/ (B(n)>1)
                     |-- Left Heavy/
                     |  |-- Right Rotation (-2,-1)
                     |  `-- Left-Right Rotation
                     `-- Right Heavy/
                        |-- Left Rotation
                        `-- Right-Left Rotation
*/
```

### 14. Heap:

- ch17_heap_array.cpp (logic only)
- Heap?
- Max Heap, Min Heap
- Heap Sort?
- https://www.codingdrills.com/tutorial/heap-data-structure/introduction-to-heap-data-structure
- https://www.youtube.com/watch?v=Dvq-YKeuO9Y

### 15. Hashing

- ch18_hashing.cpp
- ch18_hashingtable.cpp (code + logic)

#### A. What is Hashing?

Hashing is a process used to transform a given input into a fixed-size string of bytes, known as the hash value, digest,
or hash code. This string typically represents the input data uniquely and is used in various applications like data
retrieval, integrity verification, and cryptography.

#### B. Map vs. Unordermap

In C++, both `std::map` and `std::unordered_map` are associative containers that store elements formed by a combination
of a key value and a mapped value, following a specific order. However, there are fundamental differences in their
internal workings, performance characteristics, and the order in which elements are stored.

##### `std::map`

- **Internal Structure**: `std::map` is typically implemented as a balanced binary tree (like a Red-Black Tree).
- **Ordering**: It stores elements in a sorted order based on the key. The sorting criteria can be specified by a
  comparison function (less than by default).
- **Search Time**: Lookup operations (find, insert, delete) have logarithmic complexity (`O(log n)`).
- **Usage Scenario**: Use `std::map` when you need ordered data, or you frequently perform operations that require the
  container to be sorted.

##### `std::unordered_map`

- **Internal Structure**: `std::unordered_map` is implemented using a hash table.
- **Ordering**: It does not store elements in any specific order. The order depends on the hash function and may change
  when rehashing occurs.
- **Search Time**: Provides average constant-time complexity (`O(1)`) for search operations, although this can degrade
  to linear (`O(n)`) in the worst case if there are many hash collisions.
- **Usage Scenario**: Use `std::unordered_map` when you need faster access and insertion and the order of elements is
  not important.

#### C. Hash Table vs Dictionary:

The terms "hash table" and "dictionary" are often used interchangeably in the context of data structures, but they can
have distinct meanings depending on the programming language or the specific implementation context. Here's a breakdown
of how they are generally understood and used:

##### `Hash Table`

- **Definition**: A hash table is a data structure that implements an associative array abstract data type, a structure
  that can map keys to values. It uses a hash function to compute an index into an array of buckets or slots, from which
  the desired value can be found.
- **Key Characteristics**:
    - Uses a hash function to determine where to store each key-value pair.
    - Handles collisions through various methods like chaining (where each bucket is a linked list of entries that hash
      to the same index) or open addressing (where a collision triggers a search for another bucket according to a
      predefined sequence).
    - Efficiency: Ideally offers \(O(1)\) average time complexity for insert, delete, and search operations, although
      this can degrade to \(O(n)\) in the worst case (e.g., when all keys hash to the same index).
- **Use Cases**: Used internally by many programming languages for their dictionary or map implementations. Directly
  used in low-level programming or when specific customizations are needed.

##### `Dictionary`

- **Definition**: A dictionary is an abstract data type that represents a collection of keys and values, with each key
  being unique within the collection. In many languages, dictionaries are implemented using hash tables, but this is not
  universally true.
- **Key Characteristics**:
    - Provides a high-level interface to add, remove, and access elements by keys.
    - The implementation may vary: while many languages use hash tables, others might use trees or other data structures
      to ensure order or provide different performance guarantees.
    - Efficiency: The performance of a dictionary depends on its underlying implementation but often aims for \(O(1)\)
      average time complexity for standard operations.
- **Use Cases**: Dictionaries are used in a wide range of applications, from storing simple configurations to complex
  data processing. They are a fundamental data structure in many high-level programming languages like Python (`dict`),
  JavaScript (objects as associative arrays), and C# (`Dictionary`).

#### D. Collision Handling

- Double hashing uses a second hash function to determine the step size after a collision.
- Quadratic probing reduces clustering by using a quadratic function to calculate the probe sequence.
- Linear probing resolves collisions by moving sequentially through the hash table until an empty slot is found.

#### E. Questions and Considerations:

- **Dictionary Mechanism**:
    - A variant of hashing that puts a key into a hash function to create a memory location.
- **Understanding Hash Functions**:
    - What they are and how they can achieve O(1) time complexity.
- **Collision Detection and Handling**:
    - Strategies for dealing with hash collisions, including pseudocode examples.
- **Use of Prime Numbers in Hashing**:
    - Why prime numbers are often used in the design of hash functions.

### 16. Sort Algorithms:

- sort_implementation.cpp (logic)
- Only do merge sort and linear sort
- Solve the Sort by hand.

### 17. Search Algorithms:

- sort_implementation.cpp (Code + logic)
- Solve the Search by hand.

#### A. Binary Search:

- **Precondition**:
    - The array or vector must be sorted.
- **Logic**:
  ```python
  def binary_search(array, value):
      if not array:
          return -1

      left, right = 0, len(array) - 1

      while left <= right:
          midpoint = left + (right - left) // 2
          if array[midpoint] == value:
              return midpoint
          elif array[midpoint] < value:
              left = midpoint + 1
          else:
              right = midpoint - 1

      return -1
  ```

#### B. Linear Search (Code + Logic)

- **Time Complexity**: O(n)
- **Example of nested loops**:
  ```cpp
  for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
          for (int k = 0; k < n; k++) {
              // Operation with time complexity of O(n^3)
          }
      }
  }
  ```

#### C. Tree Search

- **Depth First Search**:(Code + Logic):
    - **In-order Traversal**: Traverses left subtree, root, then right subtree.
    - **Pre-order Traversal**: Traverses root, left subtree, then right subtree.
    - **Post-order Traversal**: Traverses left subtree, right subtree, then root.
