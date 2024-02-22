#include <vector>
#include <stack>
#include "../binTree.hpp"

std::vector<int> preorderTraversal(TreeNode* root) {
    std::vector<int> out;
    std::stack<TreeNode*> stack;
    stack.push(root);
    while(!stack.empty()) {
        auto curr = stack.top();
        stack.pop();
        out.push_back(curr->val);
        stack.push(curr->right);
        stack.push(curr->left);
    }
    return out;
}

static void preorder(TreeNode* root, std::vector<int>& vec) {
    if (root == nullptr) return;
    vec.push_back(root->val);
    preorder(root->left, vec);
    preorder(root->right, vec);
}

//std::vector<int> preorderTraversal(TreeNode* root) {
//    std::vector<int> out;
//    preorder(root, out);
//    return out;
//}
