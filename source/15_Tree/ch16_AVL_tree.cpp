#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int key;
    Node* left;
    Node* right;
    int height;
};

// Calculate height of a node
int height(Node* N) {
    if (N == nullptr)
        return 0;
    return N->height;
}

// Calculate maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Create a new node
Node* newNode(int key) {
    Node* node = new Node();
    node->key = key;
    node->left = nullptr;
    node->right = nullptr;
    node->height = 1; // New node is initially a leaf
    return node;
}

// Right rotation
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

// Left rotation
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

// Get balance factor of a node
int getBalance(Node* N) {
    if (N == nullptr)
        return 0;
    return height(N->left) - height(N->right);
}

// Insert a node into the AVL tree
Node* insert(Node* root, int key) {
    if (root == nullptr)
        return newNode(key);

    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);
    else
        return root; // Duplicate keys are not allowed

    // Update height of current node
    root->height = 1 + max(height(root->left), height(root->right));

    // Get balance factor and perform rotations if needed
    int balance = getBalance(root);

    // Left-Left Rotation
    if (balance > 1 && key < root->left->key)
        return rightRotate(root);

    // Right-Right Rotation
    if (balance < -1 && key > root->right->key)
        return leftRotate(root);

    // Left-Right Rotation
    if (balance > 1 && key > root->left->key) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right-Left Rotation
    if (balance < -1 && key < root->right->key) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Inorder traversal (for testing)
void inorder(Node* root) {
    if (root == nullptr)
        return;
    inorder(root->left);
    cout << root->key << " ";
    inorder(root->right);
}

// Print stuff in the tree order.
void printLevelOrder(Node* root) {
    if (!root) return;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        int levelSize = q.size();
        for (int i = 0; i < levelSize; i++) {
            Node* node = q.front();
            q.pop();
            cout << node->key << " ";
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        cout << endl; // New line for each level
    }
}

int main() {
    Node* root = nullptr;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);
    root = insert(root, 101);
    root = insert(root, 220);
    root = insert(root, 130);
    root = insert(root, 140);
    root = insert(root, 502);
    root = insert(root, 252);
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);
    root = insert(root, 101);
    root = insert(root, 220);
    root = insert(root, 130);
    root = insert(root, 140);
    root = insert(root, 502);
    root = insert(root, 252);

    cout << "Inorder traversal of AVL tree: ";
    inorder(root);
    cout << endl;

    printLevelOrder(root);
    cout << endl;

    return 0;
}
