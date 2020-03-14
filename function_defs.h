//
// Created by zyl on 2020/1/13.
//

#ifndef LEETCODE_RECORD_FUNCTION_DEFS_H
#define LEETCODE_RECORD_FUNCTION_DEFS_H

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <queue>

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

    // 二叉树的锯齿型层次遍历
    vector<vector<int>> zigzagLevelOrder(TreeNode* root);

    // 两颗二叉搜索树中的所有元素
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2);

    // 腐烂的橘子
    int orangesRotting(vector<vector<int>>& grid);

    // 分发糖果||
    vector<int> distributeCandies(int candies, int num_people);

    // 删除排序数组中的重复项
    int removeDuplicates(vector<int>& nums);

    // 和为s的连续正数序列
    vector<vector<int>> findContinuousSequence(int target);

    // 零钱兑换
    int coinChange(vector<int>& coins, int amount);

    // Diameter of Binary Tree
    int diameterOfBinaryTree(TreeNode* root);

    // Partition Array Into Three Parts With Equal Sum
    bool canThreePartsEqualSum(vector<int>& A);

    // Greatest Common Divisor of Strings
    string gcdOfStrings(string str1, string str2);

    // Open the lock
    int openLock(vector<string>& deadends, string target);

    // Longest Increasing Subsequence
    int lengthOfLIS(vector<int>& nums);
};

// 队列的最大值
class MaxQueue {
public:
    vector<int> queue;
    vector<pair<int, int>> queue_max;  // first store value, second store push
    int push = 0;
    int pop = 0;

    MaxQueue() {

    }

    int max_value() {
        if (queue.empty())
            return -1;
        return queue_max[0].first;
    }

    void push_back(int value) {
        pair<int, int> temp;
        if (queue.empty()) {
            queue.push_back(value);
            push++;
            temp = make_pair(value, push);
            queue_max.push_back(temp);
            return;
        }
        queue.push_back(value);
        push++;
        for (int i = 0; i < queue_max.size(); i++) {
            if (value >= queue_max[i].first) {
                temp = make_pair(value, push);
                queue_max.erase(queue_max.begin()+i, queue_max.end());
                queue_max.push_back(temp);
                break;
            }
            else if (i == queue_max.size()-1) {
                temp = make_pair(value, push);
                queue_max.push_back(temp);
            }
        }
    }

    int pop_front() {
        if (queue.empty())
            return -1;
        int res = queue[0];
        queue.erase(queue.begin());
        pop++;
        if (pop >= queue_max[0].second)
            queue_max.erase(queue_max.begin());
        return res;
    }
};
#endif //LEETCODE_RECORD_FUNCTION_DEFS_H
