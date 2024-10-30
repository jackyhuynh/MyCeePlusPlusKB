# Rotations

In an **AVL Tree**, rotations are necessary to maintain the height balance after insertion or deletion. The balance factor of a node is calculated as:

## Balance Factor
```
Balance Factor = height(left subtree) - height(right subtree)
```

If the balance factor is:

- **1, 0, or -1**: The node is balanced.
- **< -1 or > 1**: The node is unbalanced, and we need rotations.

### **Types of Rotations:**
1. **Right Rotation (Single Rotation):** Occurs in a **left-heavy** situation.
2. **Left Rotation (Single Rotation):** Occurs in a **right-heavy** situation.
3. **Left-Right Rotation (Double Rotation):** Occurs in a **left-right-heavy** situation.
4. **Right-Left Rotation (Double Rotation):** Occurs in a **right-left-heavy** situation.

Below is a guide on when to use each case based on the **balance factor** and the direction of imbalance.

---

### **1. Right Rotation (LL Rotation)**

**Use When:**  
- The imbalance occurs in the **left subtree** of the **left child** (left-heavy tree).
- The insertion was made in the **left subtree** of the left child.

**Example:**  
Inserting 10, then 5, then 2 causes an LL imbalance.

```
      10                    5
     /      Right         /  \
    5     --------->     2   10
   /
  2
```

**Trigger:**  
- Balance factor of the parent node becomes **> 1**.
- Example: `balance = 2, key < parent->left->key`.
- The balance of each level: 2, 1, 0 (Left Heavy & Right Rotation)

---

### **2. Left Rotation (RR Rotation)**

**Use When:**  
- The imbalance occurs in the **right subtree** of the **right child** (right-heavy tree).
- The insertion was made in the **right subtree** of the right child.

**Example:**  
Inserting 10, then 15, then 20 causes an RR imbalance.

```
      10                    15
        \      Left        /  \
        15   --------->   10   20
          \
           20
```

**Trigger:**  
- Balance factor of the parent node becomes **< -1**.
- Example: `balance = -2, key > parent->right->key`.
- The balance of each level: -2, -1, 0 (Right heavy & Left Rotation)

---

### **3. Left-Right Rotation (LR Rotation)**

**Use When:**  
- The imbalance occurs in the **left subtree** of the **right child** (mixed imbalance).
- The insertion was made in the **right subtree** of the left child.

**Example:**  
Inserting 10, then 5, then 8 causes an LR imbalance.

```
      10                  10                   8
     /      Left        /      Right         /   \
    5     --------->   8     --------->     5    10
      \              /
       8            5
```

**Trigger:**  
- Balance factor of the parent node becomes **> 1**, but the new key was inserted into the **right subtree** of the left child.
- Example: `balance = 2, key > parent->left->key`.
- The balance of each level: 0, -1, 2 (Left Heavy, Left-Right Rotation) 

**Fix:**  
- Perform a **left rotation** on the left child, followed by a **right rotation** on the parent.

---

### **4. Right-Left Rotation (RL Rotation)**

**Use When:**  
- The imbalance occurs in the **right subtree** of the **left child** (mixed imbalance).
- The insertion was made in the **left subtree** of the right child.

**Example:**  
Inserting 10, then 15, then 13 causes an RL imbalance.

```
      10                  10                  13
        \      Right       \      Left       /  \
        15   --------->    13   --------->  10  15
       /                    \
      13                     15
```

**Trigger:**  
- Balance factor of the parent node becomes **< -1**, but the new key was inserted into the **left subtree** of the right child.
- Example: `balance = -2, key < parent->right->key`.
- The balance of each level: 0, 1, -2 (Left Heavy, Right-Left Rotation) 
**Fix:**  
- Perform a **right rotation** on the right child, followed by a **left rotation** on the parent.

---

## **Summary of When to Use Each Rotation**

| **Case**            | **Condition**                                               | **Rotation(s) Required** |
|---------------------|--------------------------------------------------------------|--------------------------|
| **LL Rotation**     | Imbalance in the left child’s left subtree (left-heavy)      | Right Rotation           |
| **RR Rotation**     | Imbalance in the right child’s right subtree (right-heavy)   | Left Rotation            |
| **LR Rotation**     | Imbalance in the left child’s right subtree (mixed)          | Left Rotation + Right Rotation |
| **RL Rotation**     | Imbalance in the right child’s left subtree (mixed)          | Right Rotation + Left Rotation |

---

## **Visualization of Imbalances and Fixes**

1. **LL Case:**  
   - Path: Insertions go **left → left**.
   - Fix: **Right Rotation**.

2. **RR Case:**  
   - Path: Insertions go **right → right**.
   - Fix: **Left Rotation**.

3. **LR Case:**  
   - Path: Insertions go **left → right**.
   - Fix: **Left Rotation on left child**, followed by **Right Rotation on parent**.

4. **RL Case:**  
   - Path: Insertions go **right → left**.
   - Fix: **Right Rotation on right child**, followed by **Left Rotation on parent**.

---

## **1. Right Rotation (LL Rotation)**
Occurs when there is a left-heavy imbalance.

### **C++ Code for Right Rotation**
```cpp
struct Node {
    int key;
    Node* left;
    Node* right;
    int height;
};

// Utility function to get the height of a node
int height(Node* node) {
    return (node == nullptr) ? 0 : node->height;
}

// Right Rotation
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = std::max(height(y->left), height(y->right)) + 1;
    x->height = std::max(height(x->left), height(x->right)) + 1;

    // Return new root
    return x;
}
```

---

## **2. Left Rotation (RR Rotation)**
Occurs when there is a right-heavy imbalance.

### **C++ Code for Left Rotation**
```cpp
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = std::max(height(x->left), height(x->right)) + 1;
    y->height = std::max(height(y->left), height(y->right)) + 1;

    // Return new root
    return y;
}
```

---

## **3. Left-Right Rotation (LR Rotation)**
Occurs when there is a **left-right-heavy** imbalance.

### **C++ Code for Left-Right Rotation**
First, perform a **left rotation** on the left child, then a **right rotation** on the node.

```cpp
Node* leftRightRotate(Node* node) {
    node->left = leftRotate(node->left);
    return rightRotate(node);
}
```

---

## **4. Right-Left Rotation (RL Rotation)**
Occurs when there is a **right-left-heavy** imbalance.

### **C++ Code for Right-Left Rotation**
First, perform a **right rotation** on the right child, then a **left rotation** on the node.

```cpp
Node* rightLeftRotate(Node* node) {
    node->right = rightRotate(node->right);
    return leftRotate(node);
}
```

---

## **Balance Factor Calculation**
To maintain the AVL property, calculate the balance factor and apply rotations as needed.

### **C++ Code to Calculate Balance Factor**
```cpp
int getBalance(Node* node) {
    if (node == nullptr) return 0;
    return height(node->left) - height(node->right);
}
```

---

## **Complete Insertion Function with Rotations**
```cpp
Node* insert(Node* node, int key) {
    if (node == nullptr) {
        Node* newNode = new Node{key, nullptr, nullptr, 1};
        return newNode;
    }

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node; // No duplicate keys allowed

    // Update the height of this ancestor node
    node->height = 1 + std::max(height(node->left), height(node->right));

    // Get the balance factor to check if this node became unbalanced
    int balance = getBalance(node);

    // Perform rotations if necessary

    // Left Left Case (LL Rotation)
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // Right Right Case (RR Rotation)
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // Left Right Case (LR Rotation)
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case (RL Rotation)
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node; // Return the unchanged node pointer
}
```

---

## **Usage Example**
```cpp
int main() {
    Node* root = nullptr;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30); // RR rotation occurs here
    root = insert(root, 40);
    root = insert(root, 50); // RR rotation occurs here
    root = insert(root, 25); // RL rotation occurs here

    return 0;
}
```