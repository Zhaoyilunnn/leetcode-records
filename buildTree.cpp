//
// Created by zyl on 2020/2/22.
//
#include "function_defs.h"


TreeNode* Solution::buildTree(vector<int>& inOrder, vector<int>& postOrder) {
    TreeNode* root = new TreeNode(postOrder[postOrder.size() - 1]);
    if (inOrder.size() == 1)
        return root;
    vector<int> new_inOrder;
    vector<int> new_postOrder;
    for (int i = 0; i < inOrder.size(); i++) {
        if (inOrder[i] == postOrder[postOrder.size() - 1]) {
            if (i > 0) {
                new_inOrder.assign(inOrder.begin(), inOrder.begin()+i);
                new_postOrder.assign(postOrder.begin(), postOrder.begin()+i);
                root->left = buildTree(new_inOrder, new_postOrder);
            }
            if (!new_inOrder.empty())
                new_inOrder.clear();
            if (!new_postOrder.empty())
                new_postOrder.clear();
            if (i < postOrder.size()-1) {
                new_inOrder.assign(inOrder.begin()+i+1, inOrder.end());
                new_postOrder.assign(postOrder.begin()+i, postOrder.end()-1);
                root->right = buildTree(new_inOrder, new_postOrder);
            }
        }
    }
    return root;
}