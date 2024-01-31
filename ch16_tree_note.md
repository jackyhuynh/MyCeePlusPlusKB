
## Introduction
Tree data structures are fundamental in computer science, used for organizing data in a hierarchical manner. There are several types of tree data structures, each with its unique properties and use cases. Here are some of the most commonly used types:

1. **Binary Tree**: A tree where each node has at most two children, referred to as the left child and the right child.

2. **Binary Search Tree (BST)**: A binary tree where for each node, all elements in the left subtree are less than the node, and all elements in the right subtree are greater. This property enables efficient searching, insertion, and deletion operations.

3. **AVL Tree**: A self-balancing binary search tree where the height of the two child subtrees of any node differ by no more than one. If at any time they differ by more than one, rebalancing is done to restore this property.

4. **Red-Black Tree**: Another type of self-balancing binary search tree where each node contains an extra bit for denoting the color of the node, either red or black. It enforces balancing constraints that ensure the tree remains balanced, leading to good worst-case guarantees for insertion, deletion, and lookup operations.

5. **B-Tree**: A self-balancing tree data structure that maintains sorted data and allows searches, sequential access, insertions, and deletions in logarithmic time. It's widely used in databases and filesystems.

6. **B+ Tree**: A type of B-tree where all records are stored at the leaf level of the tree; thus, the leaf nodes form a linked list. It's particularly useful for range queries and is extensively used in databases and filesystems.

7. **Trie (Prefix Tree)**: A tree-like data structure that proves efficient for dynamic set or associative array where the keys are usually strings. It is used for retrieving a key in a dataset of strings with a common prefix.

8. **Segment Tree**: A tree data structure used for storing information about intervals or segments. It allows querying which segments contain a given point efficiently. It's often used in competitive programming and geometric queries.

9. **Fenwick Tree (Binary Indexed Tree)**: A data structure that provides efficient methods for calculating the prefix sum of a mutable array. It's used in scenarios where there's a need for frequent updates as well as prefix sum calculations.

10. **Splay Tree**: A self-balancing binary search tree with the additional property that recently accessed elements are quick to access again. It performs basic operations such as insertion, lookup, and removal in amortized O(log n) time.

11. **Heap**: Although not a tree in the traditional sense of a hierarchical data structure, heaps are often implemented as binary trees. They are used to implement priority queues, with the heap property ensuring that the parent node is either greater than or equal to (in a max heap) or less than or equal to (in a min heap) its child nodes.

12. **Suffix Tree**: A compressed trie containing all the suffixes of the given text as their keys and positions in the text as their values. Suffix trees are used in various string operations and pattern matching problems.

13. **N-ary Tree**: A tree where each node can have at most N children. It's a generalization of a binary tree for cases where more than two child nodes are required.

14. **Quadtree**: Used primarily in two-dimensional spatial data analysis, a quadtree is a tree where each internal node has exactly four children. It's commonly used in image processing, geographical information systems (GIS), and more.

15. **Octree**: Similar to a quadtree but for three-dimensional space. Each internal node has eight children. It's used in 3D graphics, spatial indexing, and other applications involving 3D space.

Each of these tree structures is designed to solve specific problems, such as enhancing search efficiency, maintaining sorted data, handling multi-dimensional data, or optimizing for space and update operations.

In a binary tree, there are primarily three types of depth-first traversal methods, each serving different purposes based on the order in which nodes are visited. Additionally, there's a breadth-first traversal method. Here's a brief overview of each:

## Tree Elements

In the context of data structures, these are fundamental elements of a tree

### Node

A tree node is a fundamental part of a tree structure. It represents an individual element or a point in the tree. Each tree node can store data (such as values or information) and has pointers or references to other nodes. These pointers define the relationship between nodes in the tree. Specifically, in a tree structure:

- **Root Node**: The top node in a tree. It is the only node without a parent.
- **Parent Node**: A node that has one or more child nodes.
- **Child Node**: A node that has a parent node to which it is connected.
- **Siblings**: Nodes that share the same parent.

### Root

- The **root** is the topmost element of a tree, serving as the origin from which all other elements branch out. There is exactly one root per tree, and it is the only element without a parent. The root serves as the entry point to access any other element within the tree.

Nodes in a tree structure are connected in a way that they start from the root node and branch out. The connection between nodes is typically represented by pointers (in languages like C or C++) or references (in languages like Java or Python).

### Leaves (Leaf Nodes)

Leaf nodes are the nodes in a tree that do not have any children. They are the end points of the tree, where the structure terminates. Leaves are important because they represent the simplest form of nodes in the tree, containing data but not leading to any further nodes. In a metaphorical sense, just as leaves on a real tree are at the ends of branches, leaf nodes in a data structure tree are at the ends of the branches of the tree.

The elements of a tree in data structures are metaphors borrowed from natural trees, helping to conceptualize the hierarchical organization of data. Here's an overview of the primary elements:


### Branch

- A **branch** is not usually defined as a standalone element in data structures but rather as the connections between nodes. In a more abstract sense, a branch can refer to a part of the tree that extends from one node to its children. It symbolizes the relationship and hierarchy between different parts of the tree.

### Edge

- An **edge** is a connection between two nodes in the tree. It represents the parent-child relationship. The number of edges in a tree is always one less than the number of nodes because every node, except the root, is connected by exactly one incoming edge from its parent.

### Depth

- The **depth** of a node is the number of edges from the root to the node. The root node has a depth of 0.

### Height

- The **height** of a node is the number of edges on the longest path from the node to a leaf. The height of the tree itself is the height of its root node.

Understanding these elements is crucial for working with trees in computer science, whether implementing them for storing data hierarchically, traversing data structures, or solving complex algorithms that require hierarchical data representations.
### Properties and Importance

- **Hierarchical Structure**: Trees are hierarchical data structures. The tree starts with a root node and expands into more nodes, branching out into leaves.
- **Path**: In a tree, there is exactly one unique path from the root node to any node in the tree, including to any leaf node.
- **Depth and Height**: The depth of a node is the number of edges from the root node to the node. The height of a tree is the maximum depth among all leaf nodes. Leaf nodes have a depth that can vary depending on their position in the tree and a height of 0.

### Applications

Both nodes and leaves are crucial for understanding and working with trees in computer science. They play key roles in various applications, including:

- **File Systems**: Representing directories (nodes) and files (leaves).
- **Decision Trees**: In machine learning, where decisions (nodes) lead to outcomes (leaves).
- **DOM (Document Object Model)**: In web development, where HTML elements are nodes, and text nodes are leaves.
- **Parsing Expressions**: In compilers, where operators and operands form nodes in an expression tree, and operands are often leaf nodes.

Understanding these basic concepts is essential for navigating more complex data structures and algorithms, such as binary trees, AVL trees, and B-trees, where the arrangement and operations on nodes and leaves determine the efficiency of data storage, retrieval, and manipulation.

## Tree Traversal
### Depth-First Traversals

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

### Breadth-First Traversal

**Level-order Traversal**:
   - Visit nodes level by level from top to bottom.
   - This method is useful for printing the tree in level order or solving problems that require visiting nodes in a level-wise manner.

Each traversal method offers a different view of the tree's nodes and can be chosen based on the specific needs of the problem you are trying to solve. Depth-first traversals are often implemented using recursion, while breadth-first traversal is typically implemented using a queue.

### AVL Tree Balance Factor
The balance factor of a node in an AVL (Adelson-Velsky and Landis) tree is calculated as the height of its left subtree minus the height of its right subtree. This balance factor is used to maintain the AVL tree's balance property, ensuring that the difference in heights of the left and right subtrees of any node is no more than 1. The balance factor can be -1, 0, or +1 for a balanced AVL tree, indicating that the right subtree is taller, both subtrees are of equal height, or the left subtree is taller, respectively.

#### Formula:
Here's the formula for calculating the balance factor BF of a node:

      BF(node)=Height(LeftSubtree)−Height(RightSubtree)

#### Calculating Heights:
To apply this formula, you first need a way to calculate the height of a subtree. The height of a subtree is the length of the longest path from the root of the subtree to a leaf node. A leaf node (a node with no children) has a height of 0, and a null pointer (indicating no subtree) has a height of -1 by convention to simplify calculations.

![AVL Trees Simply Rotation](https://www.youtube.com/watch?v=zP2xbKerIds&list=PLhXWHUoid1m3zVo6FxctHykQr81reE9hX)

### Structure of Graph & Tree family
```
/**
 * .
`-- Graph/
    `-- Tree/
        `-- Binary Tree/ (balance, complete, B(n)<=1)
            |-- Traversal/
            |   |-- Bread First Traversal
            |   `-- Depth First Traversal/
            `-- Binary Search Tree/ (left data < right data)
               |-- Traversal/
               |   |-- Bread First Traversal
               |   `-- Depth First Traversal/
               |       |-- In-order Traversal: Left - Root - Right (LEFT, DATA, RIGHT) (SORTED LIST)
               |       |-- Pre-order Traversal: Root - Left - Right (DATA, LEFT, RIGHT)
               |       `-- Post-order Traversal: Left - Right - Root (LEFT, RIGHT, DATA)
               `-- AVL Tree/ (left data < right data; self rotation)
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

## References: 
1. [Tree Traversal](https://www.youtube.com/watch?v=9RHO6jU--GU)