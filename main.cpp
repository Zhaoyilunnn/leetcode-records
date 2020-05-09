    //
// Created by zyl on 2020/1/13.
//
#include "function_defs.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution solution;

    auto* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
//    root->left->left = new TreeNode(6);
//    root->left->right = new TreeNode(2);
//    root->right->left = new TreeNode(0);
//    root->right->right = new TreeNode(8);
//    root->left->right->left = new TreeNode(7);
//    root->left->right->right = new TreeNode(4);
    TreeNode* res = solution.lowestCommonAncestor(root, root->left, root->right);

    return 0;
}
