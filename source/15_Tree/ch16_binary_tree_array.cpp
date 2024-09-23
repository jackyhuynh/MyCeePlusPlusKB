#include <iostream>
#include <vector>

class ArrayBinaryTree {
private:
    std::vector<int> tree;
public:
    // Function to insert a new node at the first empty position
    void insert(int value) {
        tree.push_back(value);
    }
    
    // Function to get the index of the parent node
    int parent(int index) {
        if (index == 0) {
            std::cout << "Root node doesn't have a parent." << std::endl;
            return -1;
        }
        return (index - 1) / 2;
    }

    // Function to get the index of the left child
    int leftChild(int index) {
        int left = 2 * index + 1;
        if (left >= tree.size()) {
            return -1; // No left child
        }
        return left;
    }

    // Function to get the index of the right child
    int rightChild(int index) {
        int right = 2 * index + 2;
        if (right >= tree.size()) {
            return -1; // No right child
        }
        return right;
    }

    // Function to print the tree (for demonstration purposes, prints the array)
    void printTree() {
        for (int i = 0; i < tree.size(); i++) {
            std::cout << tree[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    ArrayBinaryTree tree;
    
    // Inserting nodes
    tree.insert(1);
    tree.insert(2);
    tree.insert(3);
    tree.insert(4);
    tree.insert(5);
    tree.insert(6);
    tree.insert(7);
    tree.insert(1);
    tree.insert(2);
    tree.insert(3);
    tree.insert(4);
    tree.insert(5);
    tree.insert(6);
    tree.insert(7);

    // Printing the tree
    std::cout << "Binary Tree (Array Representation): ";
    tree.printTree();

    // Example operations
    int index = 2; // Example index
    std::cout << "Parent of index " << index << ": " << tree.parent(index) << std::endl;
    std::cout << "Left child of index " << index << ": " << tree.leftChild(index) << std::endl;
    std::cout << "Right child of index " << index << ": " << tree.rightChild(index) << std::endl;

    return 0;
}
