//
// Created by zyl on 2020/1/13.
//
#include "function_defs.h"
#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    vector<vector<int>> result;
    Solution solution;
    result = solution.zigzagLevelOrder(root);

    cout << "finished: " << endl;
    return 0;
}
