#include <iostream>
#include <vector>

class TreeNode {
public:
    int value;
    std::vector<TreeNode*> children;

    TreeNode(int value) : value(value) {}
    
    void addChild(TreeNode* child) {
        children.push_back(child);
    }
};

void printTree(TreeNode* root, int level = 0) {
    if (root == nullptr) return;
    std::cout << std::string(level, ' ') << root->value << "\n";
    for (auto child : root->children) {
        printTree(child, level + 1);
    }
}

int main() {
    TreeNode* root = new TreeNode(1);
    TreeNode* child1 = new TreeNode(2);
    TreeNode* child2 = new TreeNode(3);
    TreeNode* child6 = new TreeNode(6);

    root->addChild(child1);
    root->addChild(child2);
    child2->addChild(child6);
    printTree(root);
    
    // Clean up (not shown for brevity)
}
