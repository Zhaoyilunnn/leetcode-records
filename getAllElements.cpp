//
// Created by zyl on 2020/3/2.
//

#include "function_defs.h"


void inOrder(TreeNode* root, vector<int>& vctRes) {
    if (root->left)
        inOrder(root->left, vctRes);
    vctRes.push_back(root->val);
    if (root->right)
        inOrder(root->right, vctRes);
}


vector<int> getVecTree(TreeNode* root) {
    if (!root)
        return {};
    vector<int> vctRes;
    inOrder(root, vctRes);
    return vctRes;
}

vector<int> Solution::getAllElements(TreeNode *root1, TreeNode *root2) {
    vector<int> vctTree1 = getVecTree(root1);
    vector<int> vctTree2 = getVecTree(root2);
    if (vctTree1.empty())
        return vctTree2;
    if (vctTree2.empty())
        return vctTree1;
    vector<int> vctRes;
    int i, j;
    i = 0;
    j = 0;
    while (i < vctTree1.size() || j < vctTree2.size()) {
        if (j == vctTree2.size())
            vctRes.push_back(vctTree1[i++]);
        else if (i == vctTree1.size())
            vctRes.push_back(vctTree2[j++]);
        else if (vctTree1[i] < vctTree2[j])
            vctRes.push_back(vctTree1[i++]);
        else
            vctRes.push_back(vctTree2[j++]);
    }
    return vctRes;
}
