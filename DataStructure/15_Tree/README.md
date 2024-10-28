# Chapter 15: Trees

---

## **1. Overview of Trees**

A **tree** is a non-linear data structure used to represent hierarchical relationships. Unlike lists, stacks, and
queues (which are linear structures), trees allow for **parent-child** relationships between nodes.

### **Key Components**:

- **Node**: A single element in the tree.
- **Edge**: The connection between two nodes.
- **Root**: The topmost node.
- **Leaf**: A node with no children.
- **Subtree**: A tree formed by a node and its descendants.

### **Example**:

```
    Root
   /    \
Child  Child
```

### **Use Case**:

Trees are widely used in representing hierarchical data such as organizational structures, file systems, and XML/HTML
document structures.

---

## **2. Types of Trees**

### **General Tree**:

- A tree where nodes can have any number of children.

### **Binary Tree**:

- A tree where each node has at most two children (left and right).

### **Binary Search Tree (BST)**:

- A binary tree where the left subtree contains values less than the root, and the right subtree contains values greater
  than the root.

### **Code Example (Binary Tree Node)**:

```cpp
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};
```

### **Use Case**:

Binary trees are used in algorithms for searching and sorting, such as **binary search**, and in expressions like *
*expression trees** used in compilers.

---

## **3. Height of a Tree**

The **height** of a tree is the number of nodes on the longest path from the root to a leaf. A tree’s height affects its
efficiency:

- **Max height**: A tree with `n` nodes can have a maximum height of `n` (like a linked list).
- **Min height**: A balanced binary tree has a minimum height of `log(n)`.

---

## **4. Full, Complete, and Balanced Binary Trees**

- **Full Binary Tree**: Every node except the leaves has exactly two children.
- **Complete Binary Tree**: All levels are filled except possibly the last, which is filled from left to right.
- **Balanced Binary Tree**: The heights of the two subtrees of any node differ by no more than one.

### **Use Case**:

Balanced binary trees like **AVL trees** or **Red-Black trees** are used in databases to ensure efficient retrieval
times.

---

## **5. Traversals of a Binary Tree**

Tree traversal refers to visiting each node in a tree systematically. The most common traversal methods are:

- **Preorder**: Visit the root first, then the left subtree, and then the right subtree.
- **Inorder**: Visit the left subtree, then the root, and then the right subtree. This traversal of a **binary search
  tree** results in sorted order.
- **Postorder**: Visit the left subtree, then the right subtree, and then the root.

### **Code Example (Inorder Traversal)**:

```cpp
void inorderTraversal(TreeNode* root) {
    if (root != nullptr) {
        inorderTraversal(root->left);
        std::cout << root->data << " ";
        inorderTraversal(root->right);
    }
}
```

### **Use Case**:

Inorder traversal is especially useful in **binary search trees** to output the elements in sorted order.

---

## **6. The ADT Binary Tree**

The **Abstract Data Type (ADT) Binary Tree** supports the following operations:

- **Add**: Add a node to the tree.
- **Remove**: Remove a node from the tree.
- **Set**: Set or modify data in a node.
- **Retrieve**: Get the data from a node.
- **Traversal**: Visit each node in the tree.

### **ADT Binary Tree Operations**:

- **Preorder traversal**
- **Inorder traversal**
- **Postorder traversal**

- Criteria:
    - at most 2 children
    - Exactly 1 Root
    - Exactly 1 path between the Root and any Node     

---

## **7. The ADT Binary Search Tree**

A **Binary Search Tree (BST)** is a type of binary tree with the property that:

- The value of each node is greater than all values in its left subtree and less than all values in its right subtree.

This property makes search operations very efficient.

### **Code Example (Inserting into a BST)**:

```cpp
TreeNode* insert(TreeNode* root, int value) {
    if (root == nullptr) {
        return new TreeNode(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    return root;
}
```

### **Use Case**:

BSTs are used to implement sets and maps efficiently, providing an average time complexity of **O(log n)** for search,
insert, and delete operations.

---

## **8. Efficiency of Binary Search Tree Operations**

The efficiency of BST operations depends on the height of the tree:

- **Balanced trees**: Insertion, search, and removal are **O(log n)**.
- **Unbalanced trees**: These operations can degrade to **O(n)** if the tree becomes skewed (like a linked list).

### **Use Case**:

BSTs are commonly used in applications requiring dynamic sorted data, like in-memory databases or priority scheduling
systems.

---

## **Conclusion**

- Trees are essential data structures that represent hierarchical relationships.
- Binary Search Trees (BSTs) are widely used for efficient searching and sorting.
- Traversal methods (inorder, preorder, postorder) are critical in tree-based algorithms.
- Keeping trees balanced is key to maintaining efficient operations.
- **Learn**: Search for the technical Interview 

--- 

This summary provides an overview of tree structures, their types, traversal methods, and the binary search tree (BST)
with practical examples and use cases.
