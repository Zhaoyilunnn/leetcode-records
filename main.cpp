//
// Created by zyl on 2020/1/13.
//
#include "function_defs.h"
#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> g = {9, 3, 15, 20, 7};
    vector<int> s = {9, 15, 7, 20, 3};
    Solution solution;
    TreeNode* res = solution.buildTree(g, s);

    cout << "finished: " << endl;
    return 0;
}
