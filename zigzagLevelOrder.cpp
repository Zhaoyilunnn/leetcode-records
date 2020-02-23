//
// Created by zyl on 2020/2/23.
//

#include "function_defs.h"

vector<vector<int>> Solution::zigzagLevelOrder(TreeNode* root) {
    if (!root)
        return {};
    vector<TreeNode*> vctStack1;
    vector<TreeNode*> vctStack2;
    vctStack1.push_back(root);
    vector<int> temp;
    vector<vector<int>> result;
    TreeNode* top = NULL;
    bool Flag = false;
    while (!vctStack1.empty() || !vctStack2.empty()) {
        if (vctStack2.empty() && Flag) {
            Flag = false;
            if (!temp.empty()) {
                result.push_back(temp);
                temp.clear();
            }
        }
        if (vctStack1.empty() && !Flag) {
            Flag = true;
            if (!temp.empty()) {
                result.push_back(temp);
                temp.clear();
            }
        }
        if (Flag) {
            top = vctStack2[vctStack2.size()-1];
            vctStack2.pop_back();
            temp.push_back(top->val);
            if (top->right)
                vctStack1.push_back(top->right);
            if (top->left)
                vctStack1.push_back(top->left);
        }
        else {
            top = vctStack1[vctStack1.size()-1];
            vctStack1.pop_back();
            temp.push_back(top->val);
            if (top->left)
                vctStack2.push_back(top->left);
            if (top->right)
                vctStack2.push_back(top->right);
        }
    }
    if (!temp.empty())
        result.push_back(temp);
    return result;
}