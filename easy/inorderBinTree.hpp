#include <vector>
#include <stack>
#include "../binTree.hpp"

std::vector<int> inorderTraversal(TreeNode* root) {
    std::vector<int> out;
    std::stack<TreeNode*> stack;
    TreeNode* curr = root;
    while(curr != nullptr || !stack.empty()) {
        while (curr != nullptr) {
            stack.push(curr);
            curr = curr->left;
        }
        curr = stack.top();
        stack.pop();
        out.push_back(curr->val);
        curr = curr->right;
    }
    return out;
}

static void inorder(TreeNode* root, std::vector<int>& vec) {
    if (root == nullptr) return;
    inorder(root->left, vec);
    vec.push_back(root->val);
    inorder(root->right, vec);
}

//std::vector<int> inorderTraversal(TreeNode* root) {
//    std::vector<int> out;
//    inorder(root, out);
//    return out;
//}
