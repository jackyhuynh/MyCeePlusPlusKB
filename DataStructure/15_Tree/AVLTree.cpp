#include <iostream>
#include <queue>
#include <algorithm> // For std::max

using namespace std;

// Definition for a node in the AVL tree
class AVLNode {
public:
    int data;           // The value stored in the node
    AVLNode* left;      // Pointer to the left child
    AVLNode* right;     // Pointer to the right child
    int height;         // Height of the node in the tree

    // Constructor for creating a new node
    AVLNode(int val) : data(val), left(nullptr), right(nullptr), height(1) {}
};

// Helper function to get the height of a node
int getHeight(AVLNode* node) {
    return (node == nullptr) ? 0 : node->height;
}

// Helper function to update the height of a node
void updateHeight(AVLNode* node) {
    if (node != nullptr) {
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    }
}

// Helper function to get the balance factor of a node
// Balance factor = height(left subtree) - height(right subtree)
int getBalanceFactor(AVLNode* node) {
    return (node == nullptr) ? 0 : getHeight(node->left) - getHeight(node->right);
}

// Helper function to perform a right rotation
//        y                             x
//       / \                           / \
//      x   T3   --rightRotate(y)-->  T1  y
//     / \                               / \
//    T1  T2                             T2  T3
AVLNode* rightRotate(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights of y and x
    updateHeight(y);
    updateHeight(x);

    // Return the new root
    return x;
}

// Helper function to perform a left rotation
//        x                             y
//       / \                           / \
//      T1  y    --leftRotate(x)-->   x   T3
//         / \                       / \
//        T2  T3                     T1  T2
AVLNode* leftRotate(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights of x and y
    updateHeight(x);
    updateHeight(y);

    // Return the new root
    return y;
}

// Function to insert a new key into the AVL tree
AVLNode* insertNode(AVLNode* root, int key) {
    // 1. Perform standard BST insert
    if (root == nullptr) {
        return new AVLNode(key);
    }

    if (key < root->data) {
        root->left = insertNode(root->left, key);
    } else if (key > root->data) {
        root->right = insertNode(root->right, key);
    } else {
        // Duplicate keys are not allowed in AVL trees
        return root;
    }

    // 2. Update the height of the current node
    updateHeight(root);

    // 3. Get the balance factor of this node to check if it became unbalanced
    int balance = getBalanceFactor(root);

    // 4. If the node is unbalanced, then there are four cases

    // Left Left Case
    if (balance > 1 && key < root->left->data) {
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 && key > root->right->data) {
        return leftRotate(root);
    }

    // Left Right Case
    if (balance > 1 && key > root->left->data) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Left Case
    if (balance < -1 && key < root->right->data) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    // Return the (possibly) new root of the subtree
    return root;
}

// Function to perform inorder traversal of the AVL tree (for sorted output)
void inorderTraversal(AVLNode* root) {
    if (root != nullptr) {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

// Function to perform level order traversal of the AVL tree (for tree structure visualization)
void printLevelOrder(AVLNode* root) {
    if (root == nullptr) {
        return;
    }

    queue<AVLNode*> nodeQueue;
    nodeQueue.push(root);

    while (!nodeQueue.empty()) {
        int levelSize = nodeQueue.size();
        for (int i = 0; i < levelSize; ++i) {
            AVLNode* current = nodeQueue.front();
            nodeQueue.pop();
            cout << current->data << " ";

            if (current->left != nullptr) {
                nodeQueue.push(current->left);
            }
            if (current->right != nullptr) {
                nodeQueue.push(current->right);
            }
        }
        cout << endl; // Move to the next level
    }
}

int main() {
    AVLNode* root = nullptr;

    cout << "Inserting elements into the AVL tree..." << endl;
    root = insertNode(root, 10);
    root = insertNode(root, 20);
    root = insertNode(root, 30);
    root = insertNode(root, 40);
    root = insertNode(root, 50);
    root = insertNode(root, 25);
    root = insertNode(root, 101);
    root = insertNode(root, 220);
    root = insertNode(root, 130);
    root = insertNode(root, 140);
    root = insertNode(root, 502);
    root = insertNode(root, 252);
    // Inserting duplicates to show they are handled (no change in tree)
    root = insertNode(root, 10);
    root = insertNode(root, 20);
    root = insertNode(root, 30);
    root = insertNode(root, 40);
    root = insertNode(root, 50);
    root = insertNode(root, 25);
    root = insertNode(root, 101);
    root = insertNode(root, 220);
    root = insertNode(root, 130);
    root = insertNode(root, 140);
    root = insertNode(root, 502);
    root = insertNode(root, 252);

    cout << "\nInorder traversal of the balanced AVL tree (sorted order): ";
    inorderTraversal(root);
    cout << endl;

    cout << "\nLevel order traversal of the balanced AVL tree (visual structure):" << endl;
    printLevelOrder(root);
    cout << endl;

    return 0;
}
