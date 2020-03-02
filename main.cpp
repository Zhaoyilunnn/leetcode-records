//
// Created by zyl on 2020/1/13.
//
#include "function_defs.h"
#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    TreeNode* root1 = new TreeNode(1);
    root1->right = new TreeNode(8);
    TreeNode* root2 = new TreeNode(8);
    root2->left = new TreeNode(1);
    Solution solution;
    vector<int> vctRes = solution.getAllElements(root1, root2);
    cout << "finished: " << endl;
    return 0;
}
