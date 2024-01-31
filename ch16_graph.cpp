#include <iostream>
#include <vector>
#include <unordered_map>

class GraphNode {
public:
    int value;
    std::vector<GraphNode*> neighbors;
    
    GraphNode(int value) : value(value) {}
    
    void addNeighbor(GraphNode* neighbor) {
        neighbors.push_back(neighbor);
    }
};

void printGraph(GraphNode* node, std::unordered_map<GraphNode*, bool>& visited) {
    if (visited[node]) return;
    visited[node] = true;
    std::cout << node->value << " ";
    for (auto neighbor : node->neighbors) {
        printGraph(neighbor, visited);
    }
}

int main() {
    GraphNode* node1 = new GraphNode(1);
    GraphNode* node2 = new GraphNode(2);
    GraphNode* node3 = new GraphNode(3);
    
    node1->addNeighbor(node2);
    node2->addNeighbor(node3);
    node3->addNeighbor(node1); // Creates a cycle
    
    std::unordered_map<GraphNode*, bool> visited;
    printGraph(node1, visited);
    
    // Clean up
    delete node1;
    delete node2;
    delete node3;
}
