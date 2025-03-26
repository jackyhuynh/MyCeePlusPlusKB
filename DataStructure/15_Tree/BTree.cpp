#include <iostream>
#include <vector>
#include <algorithm>
#include <limits> // For numeric_limits

// Class for a node in the B-tree.
class BTreeNode {
public:
    int* keys;     // Array to store the keys in the node.
    BTreeNode** children; // Array to store the children of the node.
    int n;         // Current number of keys in the node.
    bool leaf;     // Boolean indicating whether the node is a leaf node.
    int t;       // Minimum degree

    // Constructor for the BTreeNode class.
    // t: The minimum degree of the B-tree.
    // leaf: Boolean indicating whether the node is a leaf node.
    BTreeNode(int t, bool leaf) : leaf(leaf), n(0), t(t) {
        keys = new int[2 * t - 1];       // Allocate memory for keys.
        children = new BTreeNode * [2 * t]; // Allocate memory for children.
    }

    // Destructor for the BTreeNode class.  This is important for releasing the
    // memory allocated for the keys and children of the node.  Note that
    // this destructor does NOT delete the child nodes themselves.  That is
    // handled by the BTree destructor.  This destructor only deletes the
    // arrays *within* the node.
    ~BTreeNode() {
        delete[] keys;       // Deallocate memory for keys.
        delete[] children; // Deallocate memory for children.
    }
};

// Class for the B-Tree.  This class manages the overall tree structure.
class BTree {
private:
    BTreeNode* root; // Pointer to the root node of the B-tree.
    int t;           // Minimum degree of the B-tree.  This determines the range of keys each node can hold.

public:
    // Constructor for the BTree class.
    // t: The minimum degree of the B-tree.
    BTree(int t) : root(nullptr), t(t) {}

    // Destructor for the BTree class.  This is important for releasing memory
    // allocated for the nodes of the B-tree to prevent memory leaks.  It
    // recursively deletes all nodes in the tree.
    ~BTree() {
        destroyTree(root);
    }

    // Function to recursively delete all nodes in the B-tree.  This is a helper
    // function for the destructor.
    // node: Pointer to the node to be deleted.
    void destroyTree(BTreeNode* node) {
        if (node) {
            for (int i = 0; i <= node->n; ++i) {
                destroyTree(node->children[i]); // Recursively delete children
            }
            delete node; // Delete the node itself
        }
    }

    // Function to search for a key in the B-tree.
    // k: The key to search for.
    // Returns: A pointer to the node containing the key, or nullptr if the key is not found.
    BTreeNode* search(int k) {
        return (root == nullptr) ? nullptr : search(root, k);
    }

    // Function to search for a key in a given node.  This is a recursive helper
    // function for the search function.
    // node: Pointer to the node to search in.
    // k: The key to search for.
    // Returns: A pointer to the node containing the key, or nullptr if the key is not found.
    BTreeNode* search(BTreeNode* node, int k) {
        int i = 0;
        // Find the first key in the node that is greater than or equal to k.
        while (i < node->n && k > node->keys[i]) {
            i++;
        }
        // If the key is found in the node, return the node.
        if (i < node->n && k == node->keys[i]) {
            return node;
        }
        // If the key is not found in the node and the node is a leaf node,
        // return nullptr.  Otherwise, recursively search in the appropriate child.
        if (node->leaf) {
            return nullptr;
        } else {
            return search(node->children[i], k);
        }
    }

    // Function to insert a key into the B-tree.
    // k: The key to insert.
    void insert(int k) {
        if (root == nullptr) {
            // If the tree is empty, create a new root node.
            root = new BTreeNode(t, true);
            root->keys[0] = k;
            root->n = 1;
        } else {
            // If the tree is not empty, and the root is full, split the root
            // before inserting the key.
            if (root->n == 2 * t - 1) {
                BTreeNode* newRoot = new BTreeNode(t, false);
                newRoot->children[0] = root;
                splitChild(newRoot, 0, root);
                int i = 0;
                if (newRoot->keys[0] < k) {
                    i++;
                }
                insertNonFull(newRoot->children[i], k);
                root = newRoot;
            } else {
                // If the root is not full, insert the key into the root.
                insertNonFull(root, k);
            }
        }
    }

    // Function to split a child of a node.  This is a helper function for
    // the insert function.
    // x: The parent node.
    // i: The index of the child to split.
    // y: The child node to split.
    void splitChild(BTreeNode* x, int i, BTreeNode* y) {
        // Create a new node to store the right half of the keys of y.
        BTreeNode* z = new BTreeNode(t, y->leaf);
        z->n = t - 1;

        // Copy the right half of the keys from y to z.
        for (int j = 0; j < t - 1; j++) {
            z->keys[j] = y->keys[j + t];
        }

        // Copy the right half of the children from y to z.
        if (!y->leaf) {
            for (int j = 0; j < t; j++) {
                z->children[j] = y->children[j + t];
            }
        }

        // Reduce the number of keys in y.
        y->n = t - 1;

        // Make space for the new child in x.
        for (int j = x->n; j >= i + 1; j--) {
            x->children[j + 1] = x->children[j];
        }
        x->children[i + 1] = z;

        // Make space for the median key in x.
        for (int j = x->n - 1; j >= i; j--) {
            x->keys[j + 1] = x->keys[j];
        }
        x->keys[i] = y->keys[t - 1];

        // Increment the number of keys in x.
        x->n = x->n + 1;
    }

    // Function to insert a key into a node that is not full.  This is a helper
    // function for the insert function.
    // x: The node to insert the key into.
    // k: The key to insert.
    void insertNonFull(BTreeNode* x, int k) {
        int i = x->n - 1;
        if (x->leaf) {
            // If x is a leaf node, find the correct position to insert the key.
            while (i >= 0 && x->keys[i] > k) {
                x->keys[i + 1] = x->keys[i];
                i--;
            }
            x->keys[i + 1] = k;
            x->n = x->n + 1;
        } else {
            // If x is not a leaf node, find the child to insert the key into.
            while (i >= 0 && x->keys[i] > k) {
                i--;
            }
            // If the child is full, split it before inserting the key.
            if (x->children[i + 1]->n == 2 * t - 1) {
                splitChild(x, i + 1, x->children[i + 1]);
                if (x->keys[i + 1] < k) {
                    i++;
                }
            }
            insertNonFull(x->children[i + 1], k);
        }
    }

    // Function to print the B-tree in inorder traversal.  This function is primarily
    // for debugging and visualization purposes.
    void print() {
        if (root)
            print(root);
    }

    // Function to print the B-tree in inorder traversal starting from a given node.
    // This is a recursive helper function for the print function.
    // node: The node to start printing from.
    void print(BTreeNode* node) {
        if (node) {
            int i;
            for (i = 0; i < node->n; i++) {
                if (!node->leaf)
                    print(node->children[i]);
                std::cout << node->keys[i] << " ";
            }
            if (!node->leaf)
                print(node->children[i]);
        }
    }

    // Function to get the minimum key in the B-tree
    int getMinimum() {
        if (root == nullptr) {
            return -1; // Or throw an exception: throw std::runtime_error("Tree is empty");
        }
        BTreeNode* current = root;
        while (!current->leaf) {
            current = current->children[0];
        }
        return current->keys[0];
    }

    // Function to get the maximum key in the B-tree
    int getMaximum() {
        if (root == nullptr) {
            return -1; // Or throw an exception: throw std::runtime_error("Tree is empty");
        }
        BTreeNode* current = root;
        while (!current->leaf) {
            current = current->children[current->n];
        }
        return current->keys[current->n - 1];
    }

    // Function to delete a key k from the B-Tree
    void deleteKey(int k) {
        if (!root) {
            std::cout << "The tree is empty\n";
            return;
        }

        deleteKey(root, k);

        if (root->n == 0) { // If root has 0 keys after deletion
            BTreeNode* tmp = root;
            if (root->leaf) {
                root = nullptr;
            } else {
                root = root->children[0];
            }
            delete tmp;
        }
        return;
    }

    void deleteKey(BTreeNode* x, int k) {
        int i = 0;
        while (i < x->n && k > x->keys[i])
            i++;

        if (i < x->n && x->keys[i] == k) { // Key found in node x
            if (x->leaf) {
                removeFromLeaf(x, i);
            } else {
                deleteFromNonLeaf(x, i, k);
            }
        } else { // If key not found in x
            if (x->leaf) {
                std::cout << "Key " << k << " does not exist in the tree\n";
                return;
            }

            bool found = (i == x->n);
            // Go to the child that could contain the key
            if (found) {
                deleteKey(x->children[i], k);
            } else {
                deleteKey(x->children[i], k);
            }


            // Ensure the child has at least t keys
            if (x->children[i]->n < t)
                fixChild(x, i);
        }
        return;
    }
    void removeFromLeaf(BTreeNode* x, int index) {
        for (int i = index + 1; i < x->n; ++i)
            x->keys[i - 1] = x->keys[i];
        x->n--;
        return;
    }
    void deleteFromNonLeaf(BTreeNode* x, int index, int k) {
        int key = x->keys[index];

        if (x->children[index]->n >= t) { // If the predecessor child has at least t keys
            int pred = getPred(x, index);
            x->keys[index] = pred;
            deleteKey(x->children[index], pred);
        } else if (x->children[index + 1]->n >= t) { // If the successor child has at least t keys
            int succ = getSucc(x, index);
            x->keys[index] = succ;
            deleteKey(x->children[index + 1], succ);
        } else { // Merge if both children have less than t keys.
            merge(x, index);
            deleteKey(x->children[index], k);
        }
        return;
    }

    int getPred(BTreeNode* x, int index) {
        BTreeNode* current = x->children[index];
        while (!current->leaf)
            current = current->children[current->n];
        return current->keys[current->n - 1];
    }

    int getSucc(BTreeNode* x, int index) {
        BTreeNode* current = x->children[index + 1];
        while (!current->leaf)
            current = current->children[0];
        return current->keys[0];
    }

    void merge(BTreeNode* x, int index) {
        BTreeNode* leftChild = x->children[index];
        BTreeNode* rightChild = x->children[index + 1];

        leftChild->keys[t - 1] = x->keys[index];

        for (int i = 0; i < rightChild->n; ++i)
            leftChild->keys[t + i] = rightChild->keys[i];

        if (!leftChild->leaf) {
            for (int i = 0; i <= rightChild->n; ++i)
                leftChild->children[t + i] = rightChild->children[i];
        }

        for (int i = index + 1; i < x->n; ++i)
            x->keys[i - 1] = x->keys[i];

        for (int i = index + 2; i <= x->n; ++i)
            x->children[i - 1] = x->children[i];

        leftChild->n += rightChild->n + 1;
        x->n--;

        delete rightChild;
        return;
    }
    void fixChild(BTreeNode* x, int index) {
        if (index != 0 && x->children[index - 1]->n >= t)
            borrowFromPrev(x, index);
        else if (index != x->n && x->children[index + 1]->n >= t)
            borrowFromNext(x, index);
        else {
            if (index != x->n)
                merge(x, index);
            else
                merge(x, index - 1);
        }
        return;
    }

    void borrowFromPrev(BTreeNode* x, int index) {
        BTreeNode* child = x->children[index];
        BTreeNode* sibling = x->children[index - 1];

        for (int i = child->n - 1; i >= 0; --i)
            child->keys[i + 1] = child->keys[i];

        if (!child->leaf) {
            for (int i = child->n; i >= 0; --i)
                child->children[i + 1] = child->children[i];
        }

        child->keys[0] = x->keys[index - 1];

        if (!child->leaf)
            child->children[0] = sibling->children[sibling->n];

        x->keys[index - 1] = sibling->keys[sibling->n - 1];

        child->n++;
        sibling->n--;
        return;
    }

    void borrowFromNext(BTreeNode* x, int index) {
        BTreeNode* child = x->children[index];
        BTreeNode* sibling = x->children[index + 1];

        child->keys[child->n] = x->keys[index];

        if (!child->leaf)
            child->children[child->n + 1] = sibling->children[0];

        x->keys[index] = sibling->keys[0];

        for (int i = 1; i < sibling->n; ++i)
            sibling->keys[i - 1] = sibling->keys[i];

        if (!sibling->leaf) {
            for (int i = 1; i <= sibling->n; ++i)
                sibling->children[i - 1] = sibling->children[i];
        }

        child->n++;
        sibling->n--;
        return;
    }
};



// Main function to test the B-tree implementation.
int main() {
    BTree t(3); // Create a B-tree with minimum degree 3.

    // Insert keys into the B-tree.
    t.insert(1);
    t.insert(3);
    t.insert(7);
    t.insert(10);
    t.insert(11);
    t.insert(13);
    t.insert(14);
    t.insert(15);
    t.insert(18);
    t.insert(16);
    t.insert(19);
    t.insert(24);
    t.insert(25);
    t.insert(26);
    t.insert(21);
    t.insert(4);
    t.insert(5);
    t.insert(20);
    t.insert(22);
    t.insert(2);
    t.insert(17);
    t.insert(12);
    t.insert(6);

    std::cout << "B-tree after insertion:\n";
    t.print();
    std::cout << std::endl;

    // Search for some keys.
    int keyToSearch = 10;
    if (t.search(keyToSearch) != nullptr) {
        std::cout << "Found key " << keyToSearch << std::endl;
    } else {
        std::cout << "Key " << keyToSearch << " not found" << std::endl;
    }

    keyToSearch = 22;
    if (t.search(keyToSearch) != nullptr) {
        std::cout << "Found key " << keyToSearch << std::endl;
    } else {
        std::cout << "Key " << keyToSearch << " not found" << std::endl;
    }

    keyToSearch = 99;
    if (t.search(keyToSearch) != nullptr) {
        std::cout << "Found key " << keyToSearch << std::endl;
    } else {
        std::cout << "Key " << keyToSearch << " not found" << std::endl;
    }

    // Get min and max
    std::cout << "Minimum key: " << t.getMinimum() << std::endl;
    std::cout << "Maximum key: " << t.getMaximum() << std::endl;

    // Delete some keys
    std::cout << "\nDeleting key 20\n";
    t.deleteKey(20);
    t.print();
    std::cout << std::endl;

    std::cout << "\nDeleting key 10\n";
    t.deleteKey(10);
    t.print();
    std::cout << std::endl;

    std::cout << "\nDeleting key 15\n";
    t.deleteKey(15);
    t.print();
    std::cout << std::endl;

    std::cout << "\nDeleting key 1\n";
    t.deleteKey(1);
    t.print();
    std::cout << std::endl;

    std::cout << "\nDeleting key 2\n";
    t.deleteKey(2);
    t.print();
    std::cout << std::endl;

    std::cout << "\nDeleting key 3\n";
    t.deleteKey(3);
    t.print();
    std::cout << std::endl;

    std::cout << "\nDeleting key 4\n";
    t.deleteKey(4);
    t.print();
    std::cout << std::endl;

    std::cout << "\nDeleting key 5\n";
    t.deleteKey(5);
    t.print();
    std::cout << std::endl;

    std::cout << "\nDeleting key 6\n";
    t.deleteKey(6);
    t.print();
    std::cout << std::endl;

    std::cout << "\nDeleting key 7\n";
    t.deleteKey(7);
    t.print();
    std::cout << std::endl;

    std::cout << "\nDeleting key 11\n";
    t.deleteKey(11);
    t.print();
    std::cout << std::endl;

    std::cout << "\nDeleting key 12\n";
    t.deleteKey(12);
    t.print();
    std::cout << std::endl;

    std::cout << "\nDeleting key 13\n";
    t.deleteKey(13);
    t.print();
    std::cout << std::endl;

    std::cout << "\nDeleting key 14\n";
    t.deleteKey(14);
    t.print();
    std::cout << std::endl;

    std::cout << "\nDeleting key 16\n";
    t.deleteKey(16);
    t.print();
    std::cout << std::endl;

    std::cout << "\nDeleting key 17\n";
    t.deleteKey(17);
    t.print();
    std::cout << std::endl;

    std::cout << "\nDeleting key 18\n";
    t.deleteKey(18);
    t.print();
    std::cout << std::endl;

    std::cout << "\nDeleting key 19\n";
    t.deleteKey(19);
    t.print();
    std::cout << std::endl;

    std::cout << "\nDeleting key 21\n";
    t.deleteKey(21);
    t.print();
    std::cout << std::endl;

    std::cout << "\nDeleting key 22\n";
    t.deleteKey(22);
    t.print();
    std::cout << std::endl;

    std::cout << "\nDeleting key 24\n";
    t.deleteKey(24);
    t.print();
    std::cout << std::endl;

    std::cout << "\nDeleting key 25\n";
    t.deleteKey(25);
    t.print();
    std::cout << std::endl;

    std::cout << "\nDeleting key 26\n";
    t.deleteKey(26);
    t.print();
    std::cout << std::endl;
    return 0;
}
