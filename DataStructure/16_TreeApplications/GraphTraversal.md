# Graph Traversal

## **Breadth-First Search (BFS) in Graphs**

### Concept

- BFS explores nodes **layer by layer**, starting from a given node and visiting all its neighbors before moving on to
  their neighbors.
- It uses a **queue (FIFO)** to store the nodes to be visited.

### Use Case

- **Shortest Path**: BFS is used to find the shortest path in an unweighted graph.
- **Web Crawlers**: BFS helps in traversing pages level-by-level.
- **Social Networks**: It can find the shortest relationship path between two people.

---

### **BFS Implementation in C++ (Graph)**

```cpp
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Function to perform BFS on a graph
void bfs(int start, const vector<vector<int>>& adjList, vector<bool>& visited) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        // Visit all adjacent nodes
        for (int neighbor : adjList[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    int n = 6; // Number of nodes
    vector<vector<int>> adjList(n);

    // Creating an undirected graph
    adjList[0] = {1, 2};
    adjList[1] = {0, 3, 4};
    adjList[2] = {0, 4};
    adjList[3] = {1, 5};
    adjList[4] = {1, 2, 5};
    adjList[5] = {3, 4};

    vector<bool> visited(n, false);

    cout << "BFS starting from node 0: ";
    bfs(0, adjList, visited);
    cout << endl;

    return 0;
}
```

### **Output**

```
BFS starting from node 0: 0 1 2 3 4 5
```

---

## **Depth-First Search (DFS) in Graphs**

### Concept

- **DFS** explores as far down a branch as possible before backtracking. It uses a **stack (LIFO)**, either explicitly
  or through **recursion**.

### Use Case

- **Pathfinding Algorithms**: DFS is often used in applications like **backtracking** (solving mazes, puzzles).
- **Topological Sorting**: DFS helps order tasks based on dependencies.
- **Cycle Detection**: DFS detects cycles in graphs.

---

### **DFS Implementation in C++ (Graph)**

```cpp
#include <iostream>
#include <vector>
using namespace std;

// Function to perform DFS on a graph
void dfs(int node, const vector<vector<int>>& adjList, vector<bool>& visited) {
    visited[node] = true;
    cout << node << " ";

    // Visit all adjacent nodes
    for (int neighbor : adjList[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adjList, visited);
        }
    }
}

int main() {
    int n = 6; // Number of nodes
    vector<vector<int>> adjList(n);

    // Creating an undirected graph
    adjList[0] = {1, 2};
    adjList[1] = {0, 3, 4};
    adjList[2] = {0, 4};
    adjList[3] = {1, 5};
    adjList[4] = {1, 2, 5};
    adjList[5] = {3, 4};

    vector<bool> visited(n, false);

    cout << "DFS starting from node 0: ";
    dfs(0, adjList, visited);
    cout << endl;

    return 0;
}
```

### **Output**

```
DFS starting from node 0: 0 1 3 5 4 2
```

---

## Key Differences Between BFS and DFS in Graphs

| **Aspect**           | **BFS**                              | **DFS**                              |
|----------------------|--------------------------------------|--------------------------------------|
| **Data Structure**   | Queue (FIFO)                         | Stack (LIFO) or Recursion            |
| **Traversal Order**  | Level-by-level                       | Deeper path first                    |
| **Path Discovery**   | Finds the shortest path (unweighted) | Explores paths in depth              |
| **Space Complexity** | Higher (stores all neighbors)        | Lower (only path nodes)              |
| **Use Case**         | Shortest path, network crawlers      | Topological sorting, cycle detection |

---

## Example Graph Visualization

Given the adjacency list in the code examples above:

```
    0
   / \
  1   2
 / \   \
3   4 - 5
```

- **BFS (0 → 1 → 2 → 3 → 4 → 5)**: Explores neighbors first.
- **DFS (0 → 1 → 3 → 5 → 4 → 2)**: Goes deep before backtracking.

---

## When to Use BFS vs DFS in Graphs

- **BFS**:
    - Use when you need to find the **shortest path**.
    - Best for problems where exploring nodes closer to the source first makes sense.

- **DFS**:
    - Use for **exhaustive search** or **backtracking** (e.g., puzzles).
    - Best for scenarios like **topological sorting** or **cycle detection**.