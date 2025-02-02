# Tree Traversal

## 1. **Breadth-First Search (BFS)**

### Concept

- **BFS** explores nodes level-by-level. It starts at the root node and explores all its neighbors before moving to the
  next level.
- Uses a **queue** data structure (FIFO) to keep track of nodes to visit next.

### Use Case

- **Shortest Path**: BFS finds the shortest path in an unweighted graph or tree.
- **Web Crawlers**: Visiting websites and collecting data level-by-level.
- **Social Network Graphs**: Finding the shortest connection between two people.

---

### BFS Implementation in C++

```cpp
#include <iostream>
#include <queue>
using namespace std;

// Node structure for the binary tree
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

// Function to perform BFS (level-order traversal)
void bfs(Node* root) {
    if (root == nullptr) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        cout << current->data << " ";

        if (current->left != nullptr) {
            q.push(current->left);
        }
        if (current->right != nullptr) {
            q.push(current->right);
        }
    }
}

int main() {
    // Creating the tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "BFS (Level-Order Traversal): ";
    bfs(root);
    cout << endl;

    return 0;
}
```

### **Output**

```
BFS (Level-Order Traversal): 1 2 3 4 5
```

---

## 2. **Depth-First Search (DFS)**

### Concept

- **DFS** explores as far down one branch as possible before backtracking. It uses recursion or a **stack** (LIFO) data
  structure.
- There are three main DFS traversal types:
    1. **In-order Traversal** (Left, Root, Right)
    2. **Pre-order Traversal** (Root, Left, Right)
    3. **Post-order Traversal** (Left, Right, Root)

### Use Case

- **Pathfinding**: DFS can explore paths in a maze or graph.
- **Topological Sorting**: Used in dependency graphs to determine the correct order of tasks.
- **Detecting Cycles**: Detects cycles in directed graphs.

---

### DFS Implementation in C++

```cpp
#include <iostream>
using namespace std;

// Node structure for the binary tree
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

// Pre-order DFS Traversal
void dfsPreOrder(Node* node) {
    if (node == nullptr) return;

    cout << node->data << " ";
    dfsPreOrder(node->left);
    dfsPreOrder(node->right);
}

// In-order DFS Traversal
void dfsInOrder(Node* node) {
    if (node == nullptr) return;

    dfsInOrder(node->left);
    cout << node->data << " ";
    dfsInOrder(node->right);
}

// Post-order DFS Traversal
void dfsPostOrder(Node* node) {
    if (node == nullptr) return;

    dfsPostOrder(node->left);
    dfsPostOrder(node->right);
    cout << node->data << " ";
}

int main() {
    // Creating the tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "DFS Pre-Order: ";
    dfsPreOrder(root);
    cout << endl;

    cout << "DFS In-Order: ";
    dfsInOrder(root);
    cout << endl;

    cout << "DFS Post-Order: ";
    dfsPostOrder(root);
    cout << endl;

    return 0;
}
```

### **Output**

```
DFS Pre-Order: 1 2 4 5 3
DFS In-Order: 4 2 5 1 3
DFS Post-Order: 4 5 2 3 1
```

---

## Key Differences Between BFS and DFS

| **Aspect**       | **BFS**                                  | **DFS**                                        |
|------------------|------------------------------------------|------------------------------------------------|
| Data Structure   | Queue (FIFO)                             | Stack (LIFO) or Recursion                      |
| Path Discovery   | Finds the shortest path (unweighted)     | Explores deeper paths first                    |
| Space Complexity | High (stores all nodes at current level) | Low (only stores path nodes)                   |
| Use Case         | Shortest path problems                   | Pathfinding, topological sort, cycle detection |
| Traversal        | Level-order                              | Pre-order, In-order, Post-order                |

---

### When to Use BFS vs DFS

- **BFS** is better for finding the shortest path in unweighted graphs and trees.
- **DFS** is useful for exploring all paths in depth or in applications like **backtracking algorithms** or *
  *topological sorting**.