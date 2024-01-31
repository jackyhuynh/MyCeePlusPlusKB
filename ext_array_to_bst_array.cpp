#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BST {
private:
    vector<TreeNode*> nodes;

public:
    BST() {}

    void insert(int val) {
        TreeNode* newNode = new TreeNode(val);
        if (nodes.empty()) {
            nodes.push_back(newNode);
            return;
        }

        TreeNode* curr = nodes[0];
        while (true) {
            if (val < curr->val) {
                if (curr->left == nullptr) {
                    curr->left = newNode;
                    nodes.push_back(newNode);
                    return;
                }
                curr = curr->left;
            } else {
                if (curr->right == nullptr) {
                    curr->right = newNode;
                    nodes.push_back(newNode);
                    return;
                }
                curr = curr->right;
            }
        }
    }

    TreeNode* search(int val) {
        for (TreeNode* node : nodes) {
            if (node->val == val)
                return node;
        }
        return nullptr;
    }
};

int main() {
    BST bst;
    bst.insert(5);
    bst.insert(3);
    bst.insert(7);
    bst.insert(1);
    bst.insert(4);
    bst.insert(6);
    bst.insert(8);

    TreeNode* foundNode = bst.search(4);
    if (foundNode != nullptr)
        cout << "Node found with value 4" << endl;
    else
        cout << "Node not found" << endl;

    return 0;
}
