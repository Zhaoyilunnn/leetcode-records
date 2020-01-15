//
//  main.cpp
//  leetcode
//
//  Created by zyl on 2019/11/1.
//  Copyright © 2019 zyl. All rights reserved.
//

#include "function_defs.h"



// 不同搜索二叉树|
int Solution::numTrees(int n) {
    vector<int> vctRes;
    int j = 0;
    int k = 0;
    int iTemp = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0)
            vctRes.push_back(1);
        else {
            j = 1;
            k = i+1;
            iTemp = 0;
            while (j <= k) {
                if (j == 1)
                    iTemp += 2 * vctRes[i-1];
                else if (j == k)
                    iTemp += vctRes[j-1-1] * vctRes[i-j];
                else
                    iTemp += 2 * vctRes[j-1-1] * vctRes[i-j-1];
                j++;
                k--;
            }
            vctRes.push_back(iTemp);
        }
    }
    return vctRes[n-1];
}


TreeNode* addTreeValue(int m, TreeNode* treeNode) {
    TreeNode* pRes = nullptr;
    if (nullptr != treeNode) {
        pRes = new TreeNode(treeNode->val + m);
        if (treeNode->left)
            pRes->left = addTreeValue(m, treeNode->left);
        if (treeNode->right)
            pRes->right = addTreeValue(m, treeNode->right);
    }
    return pRes;
}

// 不同搜索二叉树||
vector<TreeNode*> Solution::generateTrees(int n) {
    vector<vector<TreeNode*> > vctRes;
    vector<TreeNode*> vctTmpRes;
    if (n == 1) {
        auto* pNode = new TreeNode(1);
        vctTmpRes.push_back(pNode);
        return vctTmpRes;
    }
    TreeNode* pNode = nullptr;
    for (int i = 0; i < n; i++) {
        if (!vctTmpRes.empty())
            vctTmpRes.clear();
        if (i == 0) {
            pNode = new TreeNode(1);
            vctTmpRes.push_back(pNode);
        }
        else {
            for (int j = 1; j <= i+1; j++) {
                if (j == 1) {
                    for (int k = 0; k < vctRes[i-j].size(); k++) {
                        pNode = new TreeNode(j);
                        pNode->right = addTreeValue(j, vctRes[i-j][k]);
                        vctTmpRes.push_back(pNode);
                    }
                }
                else if (j == i+1) {
                    for (auto & k : vctRes[i-1]) {
                        pNode = new TreeNode(j);
                        pNode->left = addTreeValue(0, k);
                        vctTmpRes.push_back(pNode);
                    }
                }
                else {
                    for (int k = 0; k < vctRes[j-1-1].size(); k++) {
                        for (int m = 0; m < vctRes[i-j].size(); m++) {
                            pNode = new TreeNode(j);
                            pNode->left = addTreeValue(0, vctRes[j-1-1][k]);
                            pNode->right = addTreeValue(j, vctRes[i-j][m]);
                            vctTmpRes.push_back(pNode);
                        }
                    }
                }
            }
        }
        vctRes.push_back(vctTmpRes);
    }
    return vctRes[n-1];
}




