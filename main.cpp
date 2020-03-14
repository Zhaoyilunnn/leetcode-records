    //
// Created by zyl on 2020/1/13.
//
#include "function_defs.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution solution;

    // ----------------------- test orangeRotting-------------------------------
//    vector<vector<int>> vctTest;
//    vector<int> vct_1 = {2, 1, 1};
//    vector<int> vct_2 = {1, 1, 0};
//    vector<int> vct_3 = {0, 1, 1};
//    vector<int> vct_4 = {2, 2};
//    vector<int> vct_5 = {1, 0};
//    vector<int> vct_6 = {1, 1};
//    vector<int> vct_7 = {0, 1};
//    vector<int> vct_8 = {2, 2};
//    vector<int> vct_9 = {1, 2};
//    vector<int> vct_10 = {0, 2};
//    vctTest.push_back(vct_1);
//    vctTest.push_back(vct_2);
//    vctTest.push_back(vct_3);
//    vctTest.push_back(vct_4);
//    vctTest.push_back(vct_5);
//    vctTest.push_back(vct_6);
//    vctTest.push_back(vct_7);
//    vctTest.push_back(vct_8);
//    vctTest.push_back(vct_9);
//    vctTest.push_back(vct_10);
//    int res = solution.orangesRotting(vctTest);
//    int res = solution.orangesRotting(vctTest);
    // -------------------------- test orangeRotting end ---------------------------

    // -------------------------- test FindContinuousSequence ------------------------
//    vector<vector<int>> res = solution.findContinuousSequence(9);
    // -------------------------- test FindContinuousSequence end ---------------------

    // -------------------------- test coinChange -------------------------------------
//    vector<int> coins = {186, 419, 83, 408};
//    int res = solution.coinChange(coins, 6249);
    // --------------------------- test coinChange end --------------------------------

    // ---------------------------- test diameterOfTree ----------------------
//    auto* root = new TreeNode(1);
//    root->left = new TreeNode(2);
//    root->right = new TreeNode(3);
//    root->left->left = new TreeNode(4);
//    root->left->right = new TreeNode(5);
//    int res = solution.diameterOfBinaryTree(root);
    // ---------------------------- test diameterOfTree ----------------------

    // ------------------------------ test canThreePartsEqualSum -------------
//    vector<int> vctTest = {0, 2, 1, -6, 6, -7, 9, 1, 2, 0, 1};
//    bool res = solution.canThreePartsEqualSum(vctTest);
    //-------------------------------- test canThreePartsEqualSum -----------

    // -------------------------------- test gcdOfStrings -----------------------
//    string res = solution.gcdOfStrings("ABCABC", "ABC");
    // -------------------------------- test gcdOfStrings -----------------------

    // -------------------------------- test openLock ---------------------------
//    vector<string> deadends = {"0201","0101","0102","1212","2002"};
//    string target = "0202";
//    string t = "0009";
//    t[3]--;
//    int res = solution.openLock(deadends, target);
    // -------------------------------- test openLock ---------------------------

    // --------------------------------- test lengthOfLIS --------------------------
//    vector<int> nums = {3,5,6,2,5,4,19,5,6,7,12};
//    int res = solution.lengthOfLIS(nums);
    // --------------------------------- test lengthOfLIS --------------------------

    // --------------------------------- test numIsLand ---------------------------
    vector<vector<char> > grid =
            {{'1', '1', '0', '0', '0'},
             {'1', '1', '0', '0', '0'},
             {'0', '0', '1', '0', '0'},
             {'0', '0', '0', '1', '1'}};
    int res = solution.numIsLands(grid);
    // --------------------------------- test numIsLand ---------------------------
    return 0;
}
