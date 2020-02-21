//
// Created by zyl on 2020/1/13.
//

#ifndef LEETCODE_RECORD_FUNCTION_DEFS_H
#define LEETCODE_RECORD_FUNCTION_DEFS_H

#include <vector>
#include <string>
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
    // 分发饼干
    int findContentChildren(vector<int>& g, vector<int>& s);

    // 不同搜索二叉树|
    int numTrees(int n);

    // 不同搜索二叉树||
    vector<TreeNode*> generateTrees(int n);

    // 三角形最小路径和
    int minimumTotal(vector<vector<int>>& triangle);

    // 最长回文子串
    string longestPalindrome(string s);

    // 最大子序和
    int maxSubArray(vector<int>& nums);

    // 不同路径
    int uniquePaths(int m, int n);

    // 不同路径||
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid);

    // 爬楼梯
    int climbStairs(int n);

    // 打家劫舍
    int rob(vector<int>& nums);

    // 从中序与后序遍历序列构造二叉树
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder);
};
#endif //LEETCODE_RECORD_FUNCTION_DEFS_H
