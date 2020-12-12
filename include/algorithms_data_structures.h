//
// Created by zyl on 2020/1/13.
//

#ifndef LEETCODE_RECORD_ALGORITHMS_DATA_STRUCTURES_H
#define LEETCODE_RECORD_ALGORITHMS_DATA_STRUCTURES_H

#include "common_libs.h"


class Solution {
public:
    // 分发饼干
    int findContentChildren(vector<int>& g, vector<int>& s);


    /**************************************************************************/
    /* Problems about tree */
    // 从中序与后序遍历序列构造二叉树
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder);
    // 二叉树的锯齿型层次遍历
    vector<vector<int>> zigzagLevelOrder(TreeNode* root);
    // 两颗二叉搜索树中的所有元素
    vector<int>getAllElements(TreeNode* root1, TreeNode* root2);
    // Diameter of Binary Tree
    int diameterOfBinaryTree(TreeNode* root);
    // 不同搜索二叉树|
    int numTrees(int n);
    // 不同搜索二叉树||
    vector<TreeNode*> generateTrees(int n);
    // The maximum depth of binary tree
    int maxDepth(TreeNode* root);
    // Binary Tree Right Side View
    vector<int> rightSideView(TreeNode* root);
    // Validate Binary Search Tree
    bool isValidBST(TreeNode* root);
    // Subtree of Another Tree
    bool isSubtree(TreeNode* s, TreeNode* t);
    // Symmetric Tree
    bool isSymmetric(TreeNode* root);
    // Recover a Tree From Preorder Traversal
    TreeNode* recoverFromPreorder(const string& S);
    // Convert Sorted Array to Binary Search Tree
    TreeNode* sortedArrayToBST(vector<int>& nums);
    // Lowest Common Ancestor of a Binary Tree
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q);
    // Path Sum
    bool hasPathSum(TreeNode* root, int sum);
    // Recover Binary Search Tree
    void recoverTree(TreeNode* root);
    // Balanced Binary Tree
    bool isBalanced(TreeNode* root);
    // Convert Sorted List to Binary Search Tree
    TreeNode* sortedListToBST(ListNode* head);
    // Minimum Depth of Binary Tree
    int minDepth(TreeNode* root);
    // Binary Tree Paths
    vector<string> binaryTreePaths(TreeNode* root);
    // Binary Tree Level Order Traversal ||
    vector<vector<int>> levelOrderBottom(TreeNode* root);
    // Average of Levels in Binary Tree
    vector<double> averageOfLevels(TreeNode* root);
    // Sum of Left Leaves
    int sumOfLeftLeaves(TreeNode* root);
    // Path Sum ||
    vector<vector<int>> pathSum(TreeNode* root, int sum);
    // Convert BST to Greater Tree
    TreeNode* convertBST(TreeNode* root);
    // Lowest Common Ancestor of a Binary Search Tree
    TreeNode* lowestCommonAncestorBST(TreeNode* root, TreeNode* p, TreeNode* q);
    // Binary Tree Maximum Path Sum
    int maxPathSum(TreeNode* root);
    // Minimum Absolute Difference BST
    int getMinimumDifference(TreeNode* root);
    // Insert Interval
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval);
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
    // Supper Egg Drop
    int superEggDrop(const int& K, const int& N);
    // Jump Game
    bool canJump(vector<int>& nums);
    // Jump Game II
    int jump(vector<int>& nums);
    // Container with Most Water
    int maxArea(vector<int>& height);
    // Count The Repetitions
    int getMaxRepetitions(const string& s1, int n1, const string& s2, int n2);
    // Count Number of Nice Subarrays
    int numberOfSubarrays(vector<int>& nums, int k);
    // 数组中的逆序对
    int reversePairs(vector<int>& nums);
    // Combination Sum
    vector<vector<int>> combinationSum(vector<int>& candidates, int target);
    // Longest Substring Without Repeating Characters
    int lengthOfLongestSubstring(const string& s);
    // Minimum Cost For Tickets
    int mincostTickets(vector<int>& days, vector<int>& costs);
    // Maximum Product of Subarray
    int maxProduct(vector<int>& nums);
    // Largest Rectangle in Histogram
    int largestRectangleArea(vector<int>& heights);
    // New 21 Game
    double new21Game(int N, int K, int W);
    // 把数字翻译成字符串
    int translateNum(int num);
    // Best Sightseeing Pair
    int maxScoreSightseeingPair(vector<int>& A);
    // Maximum Length of Repeated Subarray
    int findLength(vector<int>& A, vector<int>& B);
    // Longest Valid Parentheses
    int longestValidParentheses(const string& s);
    // Wildcard Matching
    bool isMatchPro(const string& s, const string& p);
    // Regular Expression Matching
    bool isMatch(const string& s_r, const string& p_r);
    // Best Time to Buy and Sell Stock I
    int maxProfitI(vector<int>& prices);
    // Best Time to Buy and Sell Stock with Cooldown
    int maxProfit(vector<int>& prices);
    // Dungeon Game
    int calculateMinimumHP(vector<vector<int>>& dungeon);
    // Split Array Largest Sum
    int splitArray(vector<int>& nums, int m);
    // Is Subsequence
    bool isSubsequence(const string& s, const string& t);
    // Burst Balloon
    int maxCoins(vector<int>& nums);
    // 寻宝
    int minimalSteps(vector<string>& maze);
    // Increasing Subsequences
    vector<vector<int>> findSubsequences(vector<int>& nums);
    // Predict the Winner
    bool PredictTheWinner(vector<int>& nums);
    // Find the Longest Substring Containing Vowels in Even Counts
    int findTheLongestSubstring(const string& s);
    // Longest Increasing Subsequence
    int lengthOfLIS(vector<int>& nums);
    // Longest Common Subsequence
    int longestCommonSubsequence(const string& text1, const string& text2);
    // 秋叶收藏集
    int minimumOperations(const string& leaves);
    // 最长回文子串
    string longestPalindrome(string s);
    // Video Stitching
    int videoStitching(vector<vector<int>>& clips, int T);
    // Next Permutation
    void nextPermutation(vector<int>& nums);
    // Remove K Digits
    string removeKDigits(const string& num, int k);
    // Task Scheduler
    int leastInterval(vector<char>& tasks, int n);
    // Wiggle Subsequence
    int wiggleMaxLength(vector<int>& nums);
    /*******************************************************************/


    // Valid Mountain Array
    bool validMountainArray(vector<int>& A);

    // 24 Game
    bool judgePoint24(vector<int>& nums);

    // Partition Array Into Three Parts With Equal Sum
    bool canThreePartsEqualSum(vector<int>& A);

    // Palindrome Number
    bool isPalindrome(int x);

    // Intersection of Two Arrays
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2);

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
    // 0 1 matrix
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix);
    // Surrounded regions
    void solve(vector<vector<char>>& board);
    // Clone Graph
    Node* cloneGraph(Node* node);
    // Remove Boxes
    int removeBoxes(vector<int>& boxes);
    // Flood Fill
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor);
    // Minesweeper
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click);
    // Keys and Rooms
    bool canVisitAllRooms(vector<vector<int>>& rooms);
    // Combination Sum III
    vector<vector<int>> combinationSum3(int k, int n);
    // Word Search
    bool exist(vector<vector<char>>& board, const string& word);
    // Permutations II
    vector<vector<int>> permuteUnique(vector<int>& nums);
    /************************************************************/


    /************************************************************/
    /* String problems */
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
    // Decode string
    string decodeString(const string& s);
    // Valid Palindrome
    bool isPalindrome(const string& s);
    // Add string
    string addString(const string& num1, const string& num2);
    // Restore IP address
    vector<string> restoreIpAddress(const string& s);
    // Multiply String
    string multiply(const string& num1, const string& num2);
    // Valid Parentheses
    bool isValid(const string& s);
    // Palindromic Substrings
    int countSubstrings(const string& s);
    // Repeated substring
    bool repeatedSubstring(const string &s);
    // Letter Combinations of a Phone Number
    vector<string> letterCombinations(const string& digits);
    // Reverse Words in a String |||
    string reverseWordsIII(const string& s);
    // Shortest Palindrome
    string shortestPalindrome(const string& s);
    // Permutation Sequence
    string getPermutation(int n, int k);
    // Longest Palindrome
    int longestPalindromeII(string s);
    /************************************************************/

    /************************************************************/
    /* Backtracking problems */
    // Generate Parentheses
    vector<string> generateParenthesis(int n);
    // N-Queens
    vector<vector<string>> solveNQueens(int n);
    // N-Queens II
    int totalQueens(int n);
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

    // Gas Station
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost);



    /****************************************************************************/
    /* Problems using sorting algorithm */
    // Sort an Array
    vector<int> sortArray(vector<int>& nums);
    // Kth Largest element in an array
    int findKthLargest(vector<int>& nums, int k);
    // Kth smallest element in a sorted matrix
    int kthSmallest(vector<vector<int>>& matrix, int k);
    // Top K Frequent Elements
    vector<int> topKFrequent(vector<int>& nums, int k);
    // 4 Sum
    vector<vector<int>> fourSum(vector<int>& nums, int target);
    // Sort Colors
    void sortColors(vector<int>& nums);
    // Squares of a Sorted Array
    vector<int> sortedSquares(vector<int>& A);
    // Sort Array By Parity II
    vector<int> sortArrayByParityII(vector<int>& A);
    // Matrix Cells in Distance Order
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0);
    // Sort List
    ListNode* sortList(ListNode* head);
    /****************************************************************************/

    /****************************************************************************/
    /* problems using stack */
    // Trapping Rain Water
    int trap(vector<int>& height);
    // Daily Temperatures
    vector<int> dailyTemperatures(vector<int>& T);
    /****************************************************************************/

    // Game of life
    void gameOfLife(vector<vector<int>>& board);

    // 机器人运动的范围
    int movingCount(int m, int n, int k);

    // Intersection LCCI
    vector<double> intersection(const vector<int>& start1, const vector<int>& end1, const vector<int>& start2,
            const vector<int>& end2);

    // Merge Intervals
    vector<vector<int>> merge(vector<vector<int>>& intervals);

    /********************************************************/
    /* Binary search */
    // Search in Rotated Sorted Array
    int search(vector<int>& nums, int target);
    // Sum of mutated array closed to target
    int findBestValue(vector<int>& arr, int target);
    // Search Insert Position
    int searchInsert(vector<int>& nums, int target);
    // Two Sum || - Input Array is sorted
    vector<int> twoSumPro(vector<int>& numbers, int target);
    // 旋转数组的最小数字
    int minArray(vector<int>& numbers);
    // Find First and Last Position of Element in Sorted Array
    vector<int> searchRange(vector<int>& nums, int target);
    /********************************************************/

    // Two Sum
    vector<int> twoSum(vector<int>& nums, int target);

    // Maximal Square
    int maximalSquare(vector<vector<char>>& matrix);



    // Subarray Sum Equals K
    int subarraySum(vector<int>& nums, int k);

    // Valid Palindrome ||
    bool validPalindrome(const string& s);

    // Product of Array Except Self
    vector<int> productExceptSelf(vector<int>& nums);

    // Satisfiability of Equality Equations
    bool equationPossible(vector<string>& equations);

    // TODO: 3Sum
    vector<vector<int>> threeSum(vector<int>& nums);

    // TODO: 3Sum Closest
    int threeSumClosest(vector<int>& nums, int target);

    // TODO: Word Break
    bool wordBreak(string s, vector<string>& wordDict);

    // First Missing Positive
    int firstMissingPositive(vector<int>& nums);

    /**********************************************************/
    /* Math problems */
    // Rotate Matrix LCCI
    void rotate(vector<vector<int>>& matrix);
    // Permutations
    vector<vector<int>> permute(vector<int>& nums);
    // Happy Number
    bool isHappy(int n);
    // Pow(x, n)
    double myPow(double x, int n);
    // 顺时针打印矩阵
    vector<int> spiralOrder(vector<vector<int>>& matrix);
    /**********************************************************/

    /*************************************************************************/
    /* bit-wise operation */
    // 数组中数字出现的次数
    vector<int> singleNumbers(vector<int>& nums);
    // Bitwise AND of Numbers Range
    int rangeBitwiseAnd(int m, int n);
    // Subsets
    vector<vector<int>> subsets(vector<int>& nums);
    /*************************************************************************/

    /******************************************************/
    /* General List problems */
    // Middle of the linked list
    ListNode* middleNode(ListNode* head);
    // Swap Nodes in Pairs
    ListNode* swapPairs(ListNode* head);
    // Add two lists II
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
    // Merge K lists
    ListNode* mergeKLists(vector<ListNode*>& lists);
    // Linked List Cycle
    bool hasCycle(ListNode* head);
    // Linked List Cycle II
    ListNode* detectCycle(ListNode* head);
    // Merge Two Sorted Lists
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);
    // Reverse Nodes in k-Group
    ListNode* reverseKGroup(ListNode* head, int k);
    // Remove duplicate node
    ListNode* removeDuplicateNodes(ListNode* head);
    // Add Two Numbers
    ListNode* addTwoNumbersII(ListNode* l1, ListNode* l2);
    // Remove Nth Node From End of List
    ListNode* removeNthFromEnd(ListNode* head, int n);
    /******************************************************/

    /******************************************************/
    /* Graph Algorithms */
    // Course schedule
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites);
    // Course Schedule ||
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites);
    // Redundant Connection ||
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges);
    /******************************************************/

    /******************************************************/
    /* Prefix */
    // Subarray Sums Divisible by K
    int subarraysDivByK(vector<int>& A, int K);
    // Minimum Size Subarray Sum
    int minSubArrayLen(int s, vector<int>& nums);
    // Count Binary Substrings
    int countBinarySubstrings(const string& s);
    /******************************************************/
};




#endif //LEETCODE_RECORD_ALGORITHMS_DATA_STRUCTURES_H
