## **A* Search Algorithm**

**A*** (pronounced "A-star") is a graph traversal and pathfinding algorithm. It is an extension of Dijkstra’s algorithm
with an additional **heuristic function** that guides the search to explore more promising nodes first, improving
efficiency. A* guarantees the shortest path if the heuristic is **admissible** (i.e., it never overestimates the
distance to the goal).

---

### **Concept of A* Search**

- A* uses a **priority queue** (or min-heap) to explore the most promising path first.
- It evaluates nodes using:
  \[ f(n) = g(n) + h(n) \]
    - \(f(n)\): Estimated total cost of the path through node \(n\).
    - \(g(n)\): Actual cost from the start to node \(n\).
    - \(h(n)\): Heuristic estimate from node \(n\) to the goal.

The **heuristic function** guides A* to find the shortest path faster than uninformed algorithms like BFS or DFS.

---

### **Use Cases**

- **Game Development**: Used for pathfinding (e.g., NPCs navigating a map).
- **Robotics and Autonomous Vehicles**: Finding the shortest path to a target.
- **Navigation Systems**: GPS systems use A* to calculate the shortest routes.
- **Artificial Intelligence (AI)**: Planning and decision-making in AI systems.

---

### **A* Search Algorithm Implementation in C++**

Below is a simple A* implementation for finding the shortest path on a **grid-based graph**.

```cpp
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <unordered_map>
using namespace std;

// Structure to represent a point (x, y) in the grid
struct Point {
    int x, y;
    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }
};

// Hash function for the Point structure
struct PointHash {
    size_t operator()(const Point& p) const {
        return p.x * 31 + p.y;
    }
};

// Heuristic function (Euclidean distance)
double heuristic(const Point& a, const Point& b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

// Directions for moving up, down, left, and right
vector<Point> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

// A* Search algorithm
vector<Point> aStarSearch(const Point& start, const Point& goal, const vector<vector<int>>& grid) {
    priority_queue<pair<double, Point>, vector<pair<double, Point>>, greater<>> openSet;
    unordered_map<Point, Point, PointHash> cameFrom;
    unordered_map<Point, double, PointHash> gScore;
    
    openSet.push({0.0, start});
    gScore[start] = 0.0;

    while (!openSet.empty()) {
        Point current = openSet.top().second;
        openSet.pop();

        if (current == goal) {
            vector<Point> path;
            while (cameFrom.count(current)) {
                path.push_back(current);
                current = cameFrom[current];
            }
            path.push_back(start);
            reverse(path.begin(), path.end());
            return path;
        }

        for (const auto& dir : directions) {
            Point neighbor = {current.x + dir.x, current.y + dir.y};
            if (neighbor.x < 0 || neighbor.x >= grid.size() ||
                neighbor.y < 0 || neighbor.y >= grid[0].size() ||
                grid[neighbor.x][neighbor.y] == 1)  // 1 represents obstacles
                continue;

            double tentative_gScore = gScore[current] + 1.0;

            if (tentative_gScore < gScore[neighbor] || !gScore.count(neighbor)) {
                cameFrom[neighbor] = current;
                gScore[neighbor] = tentative_gScore;
                double fScore = tentative_gScore + heuristic(neighbor, goal);
                openSet.push({fScore, neighbor});
            }
        }
    }

    return {};  // Return empty path if no path is found
}

int main() {
    vector<vector<int>> grid = {
        {0, 0, 0, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 0, 0}
    };

    Point start = {0, 0};
    Point goal = {4, 4};

    vector<Point> path = aStarSearch(start, goal, grid);

    if (!path.empty()) {
        cout << "Path found: ";
        for (const auto& p : path) {
            cout << "(" << p.x << "," << p.y << ") ";
        }
        cout << endl;
    } else {
        cout << "No path found." << endl;
    }

    return 0;
}
```

---

### **Explanation**

1. **Grid Representation**:
    - `0` represents walkable space.
    - `1` represents obstacles.

2. **Data Structures Used**:
    - **Priority Queue**: Keeps nodes with the lowest `f(n)` at the top.
    - **Hash Maps**: Stores the `gScore` and tracks the parent of each node (for path reconstruction).

3. **Heuristic Function**:
    - We use **Euclidean distance** as the heuristic to estimate the distance to the goal.

4. **Directions**: The algorithm allows movement in 4 directions: up, down, left, and right.

5. **Path Reconstruction**: If a path is found, the algorithm backtracks from the goal to the start using the `cameFrom`
   map.

---

### **Output**

```
Path found: (0,0) (1,0) (2,0) (2,1) (2,2) (2,3) (2,4) (3,4) (4,4) 
```

---

### **Key Features of A***:

- **Completeness**: A* guarantees finding a path if one exists.
- **Optimality**: A* finds the shortest path if the heuristic is **admissible**.
- **Performance**: A* is more efficient than BFS or DFS, especially in large search spaces.

---

### **Time and Space Complexity**

- **Time Complexity**: \(O(b^d)\) where \(b\) is the branching factor and \(d\) is the depth of the solution.
- **Space Complexity**: Also \(O(b^d)\), as A* stores all generated nodes in memory.

---

### **When to Use A* Search**

- **Maze Solvers / Games**: A* is widely used for pathfinding in games.
- **Autonomous Navigation**: Self-driving cars and robotics use A* for real-time path planning.
- **Navigation Apps**: A* helps find the best routes in GPS navigation systems.