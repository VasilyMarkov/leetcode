#include <vector>
#include <stack>
#include "../binTree.hpp"

std::vector<int> inorderTraversal(TreeNode* root) {
    TreeNode* stack_node = root;
    std::stack<TreeNode*> stack;
    stack.push(root);
    while(!stack.empty()) {
        auto pop = stack.top();
        stack.pop();
        stack.push(pop->left);
        stack.push(pop->right);
    }
}

static void inorder(TreeNode* root, std::vector<int>& vec) {
    if(root) {
        inorder(root->left, vec);
        vec.push_back(root->val);
        inorder(root->right, vec);
    }
}

std::vector<int> inorderTraversal(TreeNode* root) {
    std::vector<int> out;
    inorder(root, out);
    return out;
}
