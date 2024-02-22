#include <vector>
#include <stack>
#include "../binTree.hpp"

std::vector<int> postorderTraversal(TreeNode* root) {
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

static void postorder(TreeNode* root, std::vector<int>& vec) {
    if (root == nullptr) return;
    postorder(root->left, vec);
    postorder(root->right, vec);
    vec.push_back(root->val);
}

//std::vector<int> postorderTraversal(TreeNode* root) {
//    std::vector<int> out;
//    postorder(root, out);
//    return out;
//}
