    //
// Created by zyl on 2020/1/13.
//
#include "algorithms_data_structures.h"
#include "objects_oriented.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution solution;

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->left->right = new TreeNode(2);
    solution.recoverTree(root);

    return 0;
}
