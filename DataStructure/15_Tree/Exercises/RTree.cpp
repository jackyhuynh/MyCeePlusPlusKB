#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <cmath>
#include <queue>

/*
* RTree Implementation:

## 1. Point Structure:
    * Represents a point in 2D space with x and y coordinates.

## 2. BoundingBox Structure:
    * Represents a Minimum Bounding Rectangle (MBR) with minX, minY, maxX, and maxY values.
    * Includes methods for:
        - contains(Point): Checks if a point is within the box.
        - contains(BoundingBox): Checks if another box is within the box.
        - overlaps(BoundingBox): Checks if two boxes overlap.
        - area(): Calculates the area of the box.
        - combine(BoundingBox, BoundingBox): Creates a new box that encompasses both input boxes.
        - intersect: returns the intersection of two bounding boxes
## 3. Node Structure:
    * Represents a node in the R-tree.
        - isLeaf: Boolean indicating whether the node is a leaf node.
        - boxes: Vector of bounding boxes for the children (internal nodes) or points (leaf nodes).
        - children: Vector of child node pointers (only for internal nodes).
        - points: Vector of points (only for leaf nodes).
        - The destructor ~Node() recursively deletes all child nodes to prevent memory leaks.
## 4. RTree Class:
    * root: Pointer to the root node of the R-tree.
    * maxChildren: Maximum number of children allowed per node (determines the tree's branching factor).
    * minChildren: Minimum number of children allowed per node
    * Helper Functions:
        - calculateBoundingBox(const std::vector<Point>&): Calculates the MBR for a set of points.
        - calculateBoundingBox(const std::vector<BoundingBox>&): Calculates the MBR for a set of bounding boxes.
        - chooseSubtree(Node*, const Point&): Selects the best subtree to insert a point.
        - chooseSubtree(Node*, const BoundingBox&): Selects the best subtree to insert a bounding box.
        - adjustTree(Node*): Adjusts the bounding boxes of parent nodes after insertion.
        - findParent(Node*, Node*): Finds the parent of a given node.
        - findChildIndex(Node* parent, Node* child): Finds the index of a child node within its parent's children vector.
        - pickSeeds(Node* node, int& index1, int& index2): Used in splitNode to select two entries to be the first entries in the two groups.
        - splitNode(Node*, const Point&, Node*&): Splits a node that has overflowed after insertion of a point.
        - splitNode(Node*, const BoundingBox&, Node*&): Splits a node that has overflowed after insertion of a bounding box.
        - getPointsAtIndexes: Returns a vector of points at the given indexes.
        - getBoxesAtIndexes: Returns a vector of bounding boxes at the given indexes.
    * Public Methods:
        - RTree(int): Constructor that initializes the R-tree with a maximum number of children.
        - ~RTree(): Destructor that deletes the entire tree to free memory.
        - insert(const Point&): Inserts a point into the R-tree.
        - search(const BoundingBox&): Searches for points within a given bounding box.
        - printTree(): Prints the structure of the R-tree (for debugging).
## 5. Main Function:
    * Creates an R-tree.
    * Inserts sample points.
    * Performs a search.
    * Prints the search results.

 * */
// Define a point in 2D space
struct Point {
    double x, y;
    Point(double _x = 0, double _y = 0) : x(_x), y(_y) {}
};

// Define a bounding box (MBR - Minimum Bounding Rectangle)
struct BoundingBox {
    double minX, minY, maxX, maxY;

    BoundingBox(double _minX = 0, double _minY = 0, double _maxX = 0, double _maxY = 0)
        : minX(_minX), minY(_minY), maxX(_maxX), maxY(_maxY) {}

    // Check if a point is within the bounding box
    bool contains(const Point& p) const {
        return p.x >= minX && p.x <= maxX && p.y >= minY && p.y <= maxY;
    }

    // Check if a box is within another box
    bool contains(const BoundingBox& other) const {
        return other.minX >= minX && other.maxX <= maxX && other.minY >= minY && other.maxY <= maxY;
    }

    // Check if two boxes overlap
    bool overlaps(const BoundingBox& other) const {
        return maxX >= other.minX && minX <= other.maxX && maxY >= other.minY && minY <= other.maxY;
    }

    // Calculate the area of the bounding box
    double area() const {
        return (maxX - minX) * (maxY - minY);
    }

    // Calculate the combined bounding box of two boxes
    static BoundingBox combine(const BoundingBox& a, const BoundingBox& b) {
        return {
            std::min(a.minX, b.minX),
            std::min(a.minY, b.minY),
            std::max(a.maxX, b.maxX),
            std::max(a.maxY, b.maxY)
        };
    }
     // Calculate the intersection of two bounding boxes.  Returns an empty box if they don't overlap
    static BoundingBox intersect(const BoundingBox& a, const BoundingBox& b) {
        double minX = std::max(a.minX, b.minX);
        double minY = std::max(a.minY, b.minY);
        double maxX = std::min(a.maxX, b.maxX);
        double maxY = std::min(a.maxY, b.maxY);

        if (minX <= maxX && minY <= maxY) {
            return {minX, minY, maxX, maxY};
        } else {
            return {0, 0, 0, 0}; // Return an "empty" box to indicate no intersection
        }
    }
};

// Node in the R-tree
struct Node {
    bool isLeaf;
    std::vector<BoundingBox> boxes;
    std::vector<Node*> children;
    std::vector<Point> points; // Only used in leaf nodes

    Node(bool leaf) : isLeaf(leaf) {}

    ~Node() {
        for (Node* child : children) {
            delete child;
        }
    }
};

class RTree {
private:
    Node* root;
    int maxChildren; // Maximum number of children per node
    int minChildren; // Minimum number of children per node

    // Helper functions
    BoundingBox calculateBoundingBox(const std::vector<Point>& points) {
        if (points.empty()) {
            return {0, 0, 0, 0}; // Return an empty box
        }
        double minX = std::numeric_limits<double>::infinity();
        double minY = std::numeric_limits<double>::infinity();
        double maxX = -std::numeric_limits<double>::infinity();
        double maxY = -std::numeric_limits<double>::infinity();

        for (const auto& p : points) {
            minX = std::min(minX, p.x);
            minY = std::min(minY, p.y);
            maxX = std::max(maxX, p.x);
            maxY = std::max(maxY, p.y);
        }

        return {minX, minY, maxX, maxY};
    }

    BoundingBox calculateBoundingBox(const std::vector<BoundingBox>& boxes) {
         if (boxes.empty()) {
            return {0, 0, 0, 0}; // Return an empty box
        }
        double minX = std::numeric_limits<double>::infinity();
        double minY = std::numeric_limits<double>::infinity();
        double maxX = -std::numeric_limits<double>::infinity();
        double maxY = -std::numeric_limits<double>::infinity();

        for (const auto& box : boxes) {
            minX = std::min(minX, box.minX);
            minY = std::min(minY, box.minY);
            maxX = std::max(maxX, box.maxX);
            maxY = std::max(maxY, box.maxY);
        }

        return {minX, minY, maxX, maxY};
    }

    Node* chooseSubtree(Node* node, const Point& point) {
        if (node->isLeaf) {
            return node;
        }

        int bestIndex = -1;
        double minArea = std::numeric_limits<double>::infinity();

        for (size_t i = 0; i < node->boxes.size(); ++i) {
            BoundingBox combined = BoundingBox::combine(node->boxes[i], {point.x, point.y, point.x, point.y});
            double areaIncrease = combined.area() - node->boxes[i].area();

            if (areaIncrease < minArea) {
                minArea = areaIncrease;
                bestIndex = static_cast<int>(i);
            }
        }
        if (bestIndex == -1)
            return node;
        return chooseSubtree(node->children[bestIndex], point);
    }

    Node* chooseSubtree(Node* node, const BoundingBox& box) {
        if (node->isLeaf) {
            return node;
        }

        int bestIndex = -1;
        double minArea = std::numeric_limits<double>::infinity();

        for (size_t i = 0; i < node->boxes.size(); ++i) {
            BoundingBox combined = BoundingBox::combine(node->boxes[i], box);
            double areaIncrease = combined.area() - node->boxes[i].area();

            if (areaIncrease < minArea) {
                minArea = areaIncrease;
                bestIndex = static_cast<int>(i);
            }
        }
        if(bestIndex == -1)
            return node;
        return chooseSubtree(node->children[bestIndex], box);
    }

    void adjustTree(Node* node) {
        if (node == root) {
            return;
        }

        Node* parent = findParent(root, node);
        if (parent == nullptr) return;

        int index = findChildIndex(parent, node);
        if(index == -1) return;
        parent->boxes[index] = node->isLeaf ? calculateBoundingBox(node->points) : calculateBoundingBox(node->boxes);

        adjustTree(parent);
    }

    Node* findParent(Node* current, Node* child) {
        if (current == nullptr || current->isLeaf) {
            return nullptr;
        }

        for (Node* c : current->children) {
            if (c == child) {
                return current;
            }
        }

        for (Node* c : current->children) {
            Node* result = findParent(c, child);
            if (result != nullptr) {
                return result;
            }
        }
        return nullptr;
    }

    int findChildIndex(Node* parent, Node* child) {
        if(parent == nullptr) return -1;
        for (size_t i = 0; i < parent->children.size(); ++i) {
            if (parent->children[i] == child) {
                return static_cast<int>(i);
            }
        }
        return -1;
    }
    //pickSeeds and splitNode are used to handle overflow when inserting.
    void pickSeeds(Node* node, int& index1, int& index2) {
        double maxWaste = -std::numeric_limits<double>::infinity();
        for (size_t i = 0; i < node->boxes.size(); ++i) {
            for (size_t j = i + 1; j < node->boxes.size(); ++j) {
                BoundingBox combinedBox = BoundingBox::combine(node->boxes[i], node->boxes[j]);
                double waste = combinedBox.area() - node->boxes[i].area() - node->boxes[j].area();
                if (waste > maxWaste) {
                    maxWaste = waste;
                    index1 = static_cast<int>(i);
                    index2 = static_cast<int>(j);
                }
            }
        }
    }

    void splitNode(Node* node, const Point& point, Node*& newNode) {
        // Implement the splitNode function.  This is complex.
        // 1. Create a new node.
        newNode = new Node(node->isLeaf);
        // 2. Create temporary arrays to hold the existing children/points and the new point.
        std::vector<BoundingBox> tempBoxes = node->boxes;
        std::vector<Node*> tempChildren = node->children;
        std::vector<Point> tempPoints = node->points;

        tempPoints.push_back(point);

        // 3. Pick two entries to be the first entries in the two groups.
        int seedIndex1 = -1, seedIndex2 = -1;
        pickSeeds(node, seedIndex1, seedIndex2);

        std::vector<int> group1Indexes, group2Indexes;
        group1Indexes.push_back(seedIndex1);
        group2Indexes.push_back(seedIndex2);

        // 4. Assign each remaining entry to one of the two groups.
        for (size_t i = 0; i < tempPoints.size(); ++i) {
            if (static_cast<int>(i) == seedIndex1 || static_cast<int>(i) == seedIndex2)
                continue;
            BoundingBox box1 = calculateBoundingBox({tempPoints[i]});
            BoundingBox box2 = calculateBoundingBox({tempPoints[i]});
            double areaIncrease1 = BoundingBox::combine(calculateBoundingBox(getPointsAtIndexes(tempPoints, group1Indexes)), box1).area() - calculateBoundingBox(getPointsAtIndexes(tempPoints, group1Indexes)).area();
            double areaIncrease2 = BoundingBox::combine(calculateBoundingBox(getPointsAtIndexes(tempPoints, group2Indexes)), box2).area() - calculateBoundingBox(getPointsAtIndexes(tempPoints, group2Indexes)).area();

            if (areaIncrease1 < areaIncrease2) {
                group1Indexes.push_back(i);
            } else if (areaIncrease2 < areaIncrease1) {
                group2Indexes.push_back(i);
            } else {
                //If tie, add to the group with smaller area
                if(calculateBoundingBox(getPointsAtIndexes(tempPoints, group1Indexes)).area() < calculateBoundingBox(getPointsAtIndexes(tempPoints, group2Indexes)).area()){
                    group1Indexes.push_back(i);
                }
                else{
                    group2Indexes.push_back(i);
                }
            }
        }
        //Clear original node
        node->points.clear();
        node->boxes.clear();

        //Assign points to the two nodes
        for(int index : group1Indexes){
            node->points.push_back(tempPoints[index]);
        }
        for(int index : group2Indexes){
            newNode->points.push_back(tempPoints[index]);
        }
        node->boxes.push_back(calculateBoundingBox(node->points));
        newNode->boxes.push_back(calculateBoundingBox(newNode->points));

    }
    //Overload splitNode for non-leaf nodes
    void splitNode(Node* node, const BoundingBox& box, Node*& newNode) {
        newNode = new Node(false);

        std::vector<BoundingBox> tempBoxes = node->boxes;
        std::vector<Node*> tempChildren = node->children;
        tempBoxes.push_back(box);

        int seedIndex1 = -1, seedIndex2 = -1;
        pickSeeds(node, seedIndex1, seedIndex2);

        std::vector<int> group1Indexes, group2Indexes;
        group1Indexes.push_back(seedIndex1);
        group2Indexes.push_back(seedIndex2);

        for (size_t i = 0; i < tempBoxes.size(); ++i) {
            if (static_cast<int>(i) == seedIndex1 || static_cast<int>(i) == seedIndex2)
                continue;
            double areaIncrease1 = BoundingBox::combine(calculateBoundingBox(getBoxesAtIndexes(tempBoxes, group1Indexes)), tempBoxes[i]).area() - calculateBoundingBox(getBoxesAtIndexes(tempBoxes, group1Indexes)).area();
            double areaIncrease2 = BoundingBox::combine(calculateBoundingBox(getBoxesAtIndexes(tempBoxes, group2Indexes)), tempBoxes[i]).area() - calculateBoundingBox(getBoxesAtIndexes(tempBoxes, group2Indexes)).area();

            if (areaIncrease1 < areaIncrease2) {
                group1Indexes.push_back(i);
            } else if (areaIncrease2 < areaIncrease1) {
                group2Indexes.push_back(i);
            } else {
                 if(calculateBoundingBox(getBoxesAtIndexes(tempBoxes, group1Indexes)).area() < calculateBoundingBox(getBoxesAtIndexes(tempBoxes, group2Indexes)).area()){
                    group1Indexes.push_back(i);
                }
                else{
                    group2Indexes.push_back(i);
                }
            }
        }
        node->boxes.clear();
        node->children.clear();

        for(int index : group1Indexes){
            node->boxes.push_back(tempBoxes[index]);
            node->children.push_back(tempChildren[index]);
        }
        for(int index : group2Indexes){
            newNode->boxes.push_back(tempBoxes[index]);
            newNode->children.push_back(tempChildren[index]);
        }
    }
    std::vector<Point> getPointsAtIndexes(const std::vector<Point>& points, const std::vector<int>& indexes) {
        std::vector<Point> result;
        for (int index : indexes) {
            if (index >= 0 && index < static_cast<int>(points.size())) {
                result.push_back(points[index]);
            }
        }
        return result;
    }
    std::vector<BoundingBox> getBoxesAtIndexes(const std::vector<BoundingBox>& boxes, const std::vector<int>& indexes) {
        std::vector<BoundingBox> result;
        for (int index : indexes) {
            if (index >= 0 && index < static_cast<int>(boxes.size())) {
                result.push_back(boxes[index]);
            }
        }
        return result;
    }

public:
    RTree(int maxChildren) : root(new Node(true)), maxChildren(maxChildren), minChildren(maxChildren / 2) {}

    ~RTree() {
        delete root;
    }

    void insert(const Point& point) {
        Node* leaf = chooseSubtree(root, point);

        if (leaf->points.size() < maxChildren) {
            leaf->points.push_back(point);
            leaf->boxes = {calculateBoundingBox(leaf->points)};
            adjustTree(leaf);
        } else {
            Node* newNode = nullptr;
            splitNode(leaf, point, newNode);
            Node* parent = findParent(root, leaf);

            if (parent == nullptr) {
                Node* newRoot = new Node(false);
                newRoot->children.push_back(leaf);
                newRoot->children.push_back(newNode);
                newRoot->boxes.push_back(calculateBoundingBox(leaf->points));
                newRoot->boxes.push_back(calculateBoundingBox(newNode->points));
                root = newRoot;
            } else {
                parent->children.push_back(newNode);
                parent->boxes.push_back(calculateBoundingBox(newNode->points));
                adjustTree(parent);
            }
        }
    }

    std::vector<Point> search(const BoundingBox& queryBox) {
        std::vector<Point> results;
        std::queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* node = q.front();
            q.pop();

            for (size_t i = 0; i < node->boxes.size(); ++i) {
                if (queryBox.overlaps(node->boxes[i])) {
                    if (node->isLeaf) {
                        for (const auto& point : node->points) {
                            if (queryBox.contains(point)) {
                                results.push_back(point);
                            }
                        }
                    } else {
                        q.push(node->children[i]);
                    }
                }
            }
        }
        return results;
    }
    void printTree() {
        printNode(root, 0);
    }

    void printNode(Node* node, int level) {
        for (int i = 0; i < level; ++i) {
            std::cout << "  ";
        }
        if (node->isLeaf) {
            std::cout << "Leaf Node: ";
            for (const auto& point : node->points) {
                std::cout << "(" << point.x << ", " << point.y << ") ";
            }
            std::cout << std::endl;
        } else {
            std::cout << "Internal Node: ";
            for (const auto& box : node->boxes) {
                std::cout << "[" << box.minX << ", " << box.minY << ", " << box.maxX << ", " << box.maxY << "] ";
            }
            std::cout << std::endl;
            for (Node* child : node->children) {
                printNode(child, level + 1);
            }
        }
    }
};

int main() {
    // Create an R-tree with a maximum of 4 children per node
    RTree rtree(4);

    // Insert some points
    rtree.insert({1, 2});
    rtree.insert({3, 4});
    rtree.insert({5, 6});
    rtree.insert({7, 8});
    rtree.insert({9, 10});
    rtree.insert({2, 3});
    rtree.insert({4, 5});
    rtree.insert({6, 7});
    rtree.insert({8, 9});
    rtree.insert({10, 11});

    // Print the R-tree structure
    std::cout << "R-tree Structure:" << std::endl;
    rtree.printTree();

    // Perform a search
    BoundingBox searchBox(2, 3, 8, 9);
    std::cout << "\nSearch results for box (2, 3, 8, 9):" << std::endl;
    std::vector<Point> results = rtree.search(searchBox);
    for (const auto& point : results) {
        std::cout << "(" << point.x << ", " << point.y << ") ";
    }
    std::cout << std::endl;

    return 0;
}
