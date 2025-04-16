#include <iostream>
#include <algorithm>

// Node structure for the AVL tree
struct Node {
    int key;
    Node *left;
    Node *right;
    int height;

    Node(int k) : key(k), left(nullptr), right(nullptr), height(1) {}
};

// Function to get the height of a node
int height(Node *n) {
    if (n == nullptr)
        return 0;
    return n->height;
}

// Function to get the balance factor of a node
int balanceFactor(Node *n) {
    if (n == nullptr)
        return 0;
    return height(n->left) - height(n->right);
}

// Function to update the height of a node
void updateHeight(Node *n) {
    if (n != nullptr) {
        n->height = 1 + std::max(height(n->left), height(n->right));
    }
}

// Left rotate subtree rooted with y
Node* leftRotate(Node* y) {
    Node* x = y->right;
    Node* T2 = x->left;

    // Perform rotation
    x->left = y;
    y->right = T2;

    // Update heights
    updateHeight(y);
    updateHeight(x);

    // Return new root
    return x;
}

// Right rotate subtree rooted with x
Node* rightRotate(Node* x) {
    Node* y = x->left;
    Node* T2 = y->right;

    // Perform rotation
    y->right = x;
    x->left = T2;

    // Update heights
    updateHeight(x);
    updateHeight(y);

    // Return new root
    return y;
}

// Function to insert a key into the AVL tree
Node* insert(Node* root, int key) {
    // 1. Perform standard BST insert
    if (root == nullptr)
        return new Node(key);

    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);
    else // Duplicate keys not allowed
        return root;

    // 2. Update height of the current node
    updateHeight(root);

    // 3. Get the balance factor to check if this node became unbalanced
    int balance = balanceFactor(root);

    // Left Left Case
    if (balance > 1 && key < root->left->key)
        return rightRotate(root);

    // Right Right Case
    if (balance < -1 && key > root->right->key)
        return leftRotate(root);

    // Left Right Case
    if (balance > 1 && key > root->left->key) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Left Case
    if (balance < -1 && key < root->right->key) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    // Return the (unchanged) node pointer
    return root;
}

// Function to find the node with the minimum key in a subtree
Node* minValueNode(Node* node) {
    Node* current = node;
    while (current->left != nullptr)
        current = current->left;
    return current;
}

// Function to delete a key from the AVL tree
Node* deleteNode(Node* root, int key) {
    if (root == nullptr)
        return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        // Node with only one child or no child
        if ((root->left == nullptr) || (root->right == nullptr)) {
            Node* temp = root->left ? root->left : root->right;

            // No child case
            if (temp == nullptr) {
                temp = root;
                root = nullptr;
            } else // One child case
                *root = *temp; // Copy the contents of the non-empty child
            delete temp;
        } else {
            // Node with two children: Get the inorder successor (smallest
            // in the right subtree)
            Node* temp = minValueNode(root->right);

            // Copy the inorder successor's data to this node
            root->key = temp->key;

            // Delete the inorder successor
            root->right = deleteNode(root->right, temp->key);
        }
    }

    // If the tree had only one node then return
    if (root == nullptr)
        return root;

    // Update the height of the current node
    updateHeight(root);

    // Get the balance factor of this node
    int balance = balanceFactor(root);

    // Left Left Case
    if (balance > 1 && balanceFactor(root->left) >= 0)
        return rightRotate(root);

    // Left Right Case
    if (balance > 1 && balanceFactor(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 && balanceFactor(root->right) <= 0)
        return leftRotate(root);

    // Right Left Case
    if (balance < -1 && balanceFactor(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Function to perform inorder traversal of the AVL tree
void inorder(Node* root) {
    if (root != nullptr) {
        inorder(root->left);
        std::cout << root->key << " ";
        inorder(root->right);
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

    std::cout << "Inorder traversal of the constructed AVL tree: ";
    inorder(root);
    std::cout << std::endl;

    root = deleteNode(root, 30);

    std::cout << "Inorder traversal after deleting 30: ";
    inorder(root);
    std::cout << std::endl;

    return 0;
}
