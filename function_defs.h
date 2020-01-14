//
// Created by zyl on 2020/1/13.
//

#ifndef LEETCODE_RECORD_FUNCTION_DEFS_H
#define LEETCODE_RECORD_FUNCTION_DEFS_H

#include <vector>
#include <set>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


class Solution {
public:
    void Sort(vector<int>& nums);

    vector<int> FastSort(vector<int>& nums);

    int findContentChildren(vector<int>& g, vector<int>& s);

    // 不同搜索二叉树|
    int numTrees(int n);

    // 不同搜索二叉树||
    vector<TreeNode*> generateTrees(int n);

    TreeNode* addTreeValue(int m, TreeNode* treeNode);

    // 三角形最小路径和
    int minimumTotal(vector<vector<int>>& triangle);
};
#endif //LEETCODE_RECORD_FUNCTION_DEFS_H
