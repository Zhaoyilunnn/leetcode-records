    //
// Created by zyl on 2020/1/13.
//
#include "function_defs.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution solution;

    /*test orangeRotting*/
/*
    vector<vector<int>> vctTest;
    vector<int> vct_1 = {2, 1, 1};
    vector<int> vct_2 = {1, 1, 0};
    vector<int> vct_3 = {0, 1, 1};
    vector<int> vct_4 = {2, 2};
    vector<int> vct_5 = {1, 0};
    vector<int> vct_6 = {1, 1};
    vector<int> vct_7 = {0, 1};
    vector<int> vct_8 = {2, 2};
    vector<int> vct_9 = {1, 2};
    vector<int> vct_10 = {0, 2};
    vctTest.push_back(vct_1);
    vctTest.push_back(vct_2);
    vctTest.push_back(vct_3);
    vctTest.push_back(vct_4);
    vctTest.push_back(vct_5);
    vctTest.push_back(vct_6);
    vctTest.push_back(vct_7);
    vctTest.push_back(vct_8);
    vctTest.push_back(vct_9);
    vctTest.push_back(vct_10);
    int res = solution.orangesRotting(vctTest);
    int res = solution.orangesRotting(vctTest);
*/

    /*test FindContinuousSequence*/
/*
    vector<vector<int>> res = solution.findContinuousSequence(9);
*/

    /*test coinChange*/
/*
    vector<int> coins = {186, 419, 83, 408};
    int res = solution.coinChange(coins, 6249);
*/

    /*test diameterOfTree*/
/*
    auto* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    int res = solution.diameterOfBinaryTree(root);
*/

    /*test canThreePartsEqualSum*/
/*
    vector<int> vctTest = {0, 2, 1, -6, 6, -7, 9, 1, 2, 0, 1};
    bool res = solution.canThreePartsEqualSum(vctTest);
*/

    /*test gcdOfStrings*/
/*
    string res = solution.gcdOfStrings("ABCABC", "ABC");
*/

    /*test openLock*/
/*
    vector<string> deadends = {"0201","0101","0102","1212","2002"};
    string target = "0202";
    string t = "0009";
    t[3]--;
    int res = solution.openLock(deadends, target);
*/

    /*test lengthOfLIS*/
/*
    vector<int> nums = {3,5,6,2,5,4,19,5,6,7,12};
    int res = solution.lengthOfLIS(nums);
*/

    /*test numIsLand*/
/*
    vector<vector<char> > grid =
            {{'1', '1', '0', '0', '0'},
             {'1', '1', '0', '0', '0'},
             {'0', '0', '1', '0', '0'},
             {'0', '0', '0', '1', '1'}};
    int res = solution.numIsLands(grid);
*/
    /*test islandPerimeter*/
/*
    vector<vector<int>> grid = {{1, 1}, {1, 1}};
    int res = solution.islandPerimeter(grid);
*/

    /*test isRectangleOverlap*/
/*
    vector<int> rect1 = {0, 0, 1, 1};
    vector<int> rect2 = {1, 0, 2, 1};
    bool res = solution.isRectangleOverlap(rect1, rect2);
*/

    /*test longestPalindrome*/
    /*int res = solution.longestPalindromeII("abccccdd");
    */

    /*test getLeastNumbers*/
    /*vector<int> test = {0,0,2,3,3,5,6,0,3,4,4,4,3,0,9,14,4,17,6,4,10,18,21,13,8,4,12,6,19,11,8,12,14,7,16,34,19,18,15,14,22,41,32,23,27,37,2,30,14,12,23,41,39,2,21,32,22,1,12,25,6,46,7,61,13,64,54,56,29,41,51,2,9,65,17,28,34,41,1,62,23,14,60,14,22,17,67,86,81,45,78,9,27,17,30,54,35,42,72,94};
    vector<int> res = solution.getLeastNumbers(test, 21);
*/

    /*test canMeasureWater*/
    /*bool res = solution.canMeasureWater(104681, 104683, 54);
    return 0;*/

    /*test minIncrementForUnique*/
    /*vector<int> test = {7,2,7,2,1,4,3,1,4,8};
    int res = solution.minIncrementForUnique(test);
    */

    /*test swapList*/
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
//    head->next->next->next = new ListNode(4);
    ListNode* new_head = solution.swapPairs(head);


    return 0;
}
