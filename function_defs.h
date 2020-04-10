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
#include <map>
#include <stack>
#include <numeric>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    // 分发饼干
    int findContentChildren(vector<int>& g, vector<int>& s);

    // 最长回文子串
    string longestPalindrome(string s);
    // Longest Palindrome
    int longestPalindromeII(string s);


    /**************************************************************************/
    /* Problems about tree */
    // 从中序与后序遍历序列构造二叉树
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder);
    // 二叉树的锯齿型层次遍历
    vector<vector<int>> zigzagLevelOrder(TreeNode* root);
    // 两颗二叉搜索树中的所有元素
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2);
    // Diameter of Binary Tree
    int diameterOfBinaryTree(TreeNode* root);
    // 不同搜索二叉树|
    int numTrees(int n);
    // 不同搜索二叉树||
    vector<TreeNode*> generateTrees(int n);
    // The maximum depth of binary tree
    int maxDepth(TreeNode* root);
    /**************************************************************************/


    // 分发糖果||
    vector<int> distributeCandies(int candies, int num_people);

    // 删除排序数组中的重复项
    int removeDuplicates(vector<int>& nums);

    // 和为s的连续正数序列
    vector<vector<int>> findContinuousSequence(int target);


    /********************************************************************/
    /* Problems that are solved by dynamic programming */
    // 最大子序和
    int maxSubArray(vector<int>& nums);
    // 爬楼梯
    int climbStairs(int n);
    // 打家劫舍
    int rob(vector<int>& nums);
    // 零钱兑换
    int coinChange(vector<int>& coins, int amount);
    // The Masseuse LCCI
    int massage(vector<int>& nums);
    // 不同路径
    int uniquePaths(int m, int n);
    // 不同路径||
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid);
    // 三角形最小路径和
    int minimumTotal(vector<vector<int>>& triangle);
    // Edit Distance
    int minDistance(const string& word1, const string& word2);
    /*******************************************************************/

    // Partition Array Into Three Parts With Equal Sum
    bool canThreePartsEqualSum(vector<int>& A);

    // Longest Increasing Subsequence
    int lengthOfLIS(vector<int>& nums);

    /************************************************************/
    /*The following problems are general BFS or DFS based*/
    // 岛屿数量
    int numIsLands(vector<vector<char>>& grid);
    // Max Area of Island
    int maxAreaOfIsland(vector<vector<int>> &grid);
    // Island Perimeter
    int islandPerimeter(vector<vector<int>>& grid);
    // 腐烂的橘子
    int orangesRotting(vector<vector<int>>& grid);
    // Open the lock
    int openLock(vector<string>& deadends, string target);
    // As Far from Land as Possible
    int maxDistance(vector<vector<int>>& grid);
    /************************************************************/


    /************************************************************/
    /*String problems*/
    // Greatest Common Divisor of Strings
    string gcdOfStrings(string str1, string str2);
    // Compress String LCCI
    string compressString(string S);
    // Find Words That Can Be Formed by Characters
    int countCharacters(vector<string>& words, string chars);
    // Short Encoding of Words
    int minimumLengthEncoding(vector<string>& words);
    // Maximum Nesting Depth of Two Valid Parentheses Strings
    vector<int> maxDepthAfterSplit(string seq);
    // String to integer (atoi)
    int myAtoi(const string& str);
    // Reverse Words in a String
    string reverseWords(const string& s);
    /************************************************************/

    /************************************************************/
    /* Backtracking problems */
    // Generate Parentheses
    vector<string> generateParenthesis(int n);
    /************************************************************/


    // 矩阵中的幸运数
    vector<int> luckyNumbers(vector<vector<int>>& matrix);

    // Rectangle Overlap
    bool isRectangleOverlap(vector<int>& rect1, vector<int>& rect2);

    // Minimum K number
    vector<int> getLeastNumbers(vector<int>& arr, int k);

    // Water and Jug Problem
    bool canMeasureWater(int x, int y, int z);

    // Minimum Increment to Make Array Unique
    int minIncrementForUnique(vector<int>& A);

    // Surface Area of 3D Shapes
    int surfaceArea(vector<vector<int>>& grid);

    // Available Captures for Rook
    int numRookCaptures(vector<vector<char>>& board);

    // X of a Kind in a Deck of Cards
    bool hasGroupsSizeX(vector<int>& deck);

    // 圈中最后剩下的数字
    int lastRemaining(int n, int m);

    // Sort an Array
    vector<int> sortArray(vector<int>& nums);

    // Game of life
    void gameOfLife(vector<vector<int>>& board);

    // Trapping Rain Water
    int trap(vector<int>& height);

    // Rotate Matrix LCCI
    void rotate(vector<vector<int>>& matrix);

    // 机器人运动的范围
    int movingCount(int m, int n, int k);


    /******************************************************/
    /* General List problems */
    // Middle of the linked list
    ListNode* middleNode(ListNode* head);
    // Swap Nodes in Pairs
    ListNode* swapPairs(ListNode* head);
    /******************************************************/

    /******************************************************/
    /* Topology sort */
    // Course schedule
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites);
    /******************************************************/
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

/*********************************************************************************/
/* Description: Design and implement a data structure for Least Frequently Used
 * (LFU) cache. It should support the following operations: get and put get(key)
 * - Get the value (will always be positive) of the key if the key exists in the
 * cache, otherwise return -1. put(key, value) - Set or insert the value if the
 * key is not already present. When the cache reaches its capacity, it should
 * invalidate the least frequently used item before inserting a new item.
 *
 * For the purpose of this problem, when there is a tie (i.e., two or more
 * keys that have the same frequency), the least recently used key would be
 * evicted.Note that the number of times an item is used is the number of
 * calls to the get and put functions for that item since it was inserted.
 * This number is set to zero when the item is removed.
 *
 * Solution 1: use map<int, vector<int>> to store the frequency and the
 * corresponding keys */
/*********************************************************************************/
// LFU Cache
class LFUCache {
    struct keyInfo {
        int frequency; // record the times of usage
        int value; // record the value of key
        int time; // most recently used time
    };
    map<int, keyInfo> m_key_info;    // connect key with its information
    map<int, map<int, int>> m_count_key;       // connect frequency with key (least recently used),
    // the first element of vector stores the least recently used key
    int m_current_num = 0;  // record the number of keys currently
    int m_capacity = 0;  // the capacity of Cache
    int m_least_count = 0;  // the least count of current keys
    int m_time = 0;  // store the time of current operation
public:
    LFUCache(int capacity) {
        m_capacity = capacity;
    }

    void insertCountKey(int key, keyInfo& information) {
        auto count_pos = m_count_key.find(information.frequency);
        if (count_pos != m_count_key.end()) count_pos->second.insert(make_pair(information.time, key));
        else {
            map<int, int> temp;
            temp.insert(make_pair(information.time, key));
            m_count_key.insert(make_pair(information.frequency, temp));
        }
    }

    void deleteCountKey(int key, keyInfo& information) {
        auto count_pos = m_count_key.find(information.frequency);
        auto time_pos = count_pos->second.find(information.time);
        count_pos->second.erase(time_pos);
        if (count_pos->second.empty()) {
            m_count_key.erase(count_pos);
            if (information.frequency == m_least_count) m_least_count++;
        }
    }

    int get(int key) {
        auto key_pos = m_key_info.find(key);
        if (m_key_info.end() != key_pos) {
            /* 从原来的使用次数对应的数组中删除当前的key */
            deleteCountKey(key, key_pos->second);

            /* 使用次数加一并更新使用次数-key表的信息 */
            key_pos->second.frequency++;
            key_pos->second.time = m_time;
            insertCountKey(key, key_pos->second);
            m_time++;
            return key_pos->second.value;
        } else return -1;
    }

    void put(int key, int value) {
        if (m_capacity == 0)
            return;
        auto key_pos = m_key_info.find(key);
        if (m_key_info.end() == key_pos) {
            keyInfo temp = {1, value, m_time};
            if (m_current_num == m_capacity) {
                m_current_num--;  // 为了和最后的++兼容

                /* remove least recently used key */
                auto count_pos = m_count_key.find(m_least_count);
                m_key_info.erase(count_pos->second.begin()->second);
                count_pos->second.erase(count_pos->second.begin());
                if (count_pos->second.empty()) m_count_key.erase(count_pos);
            }

            /* 插入新的key并使当前key数量加一 */
            m_key_info.insert(make_pair(key, temp));
            m_current_num++;
            insertCountKey(key, temp);
            m_least_count = 1;
        } else {
            /* 从原来的使用次数对应的数组中删除当前的key */
            deleteCountKey(key, key_pos->second);

            /* 使用次数加一，并更新次数-key表中的信息 */
            key_pos->second.frequency++;
            key_pos->second.value = value;
            key_pos->second.time = m_time;
            insertCountKey(key, key_pos->second);
        }
        m_time++;
    }
};

#endif //LEETCODE_RECORD_FUNCTION_DEFS_H
