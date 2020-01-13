//
// Created by zyl on 2020/1/13.
//
#include "function_defs.h"
#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> g = {10, 9, 8, 7};
    vector<int> s = {5, 6, 7, 8};
    Solution solution;
//    int result = slt.findContentChildren(g, s);
//    int result = slt.numTrees(3);
//    vector<TreeNode*> result = solution.generateTrees(3);
    vector<vector<int>> testVec;
    vector<int> R1;
    R1.push_back(2);
    testVec.push_back(R1);
    vector<int> R2;
    R2.push_back(3);
    R2.push_back(4);
    testVec.push_back(R2);
    vector<int> R3;
    R3.push_back(6);
    R3.push_back(5);
    R3.push_back(7);
    testVec.push_back(R3);
    vector<int> R4;
    R4.push_back(4);
    R4.push_back(1);
    R4.push_back(8);
    R4.push_back(3);
    testVec.push_back(R4);
    int result = solution.minimumTotal(testVec);
    cout << "finished: " << endl;
    return 0;
}
