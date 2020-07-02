    //
// Created by zyl on 2020/1/13.
//
#include "function_defs.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution solution;

    vector<vector<int>> matrix = {
            {1, 2},
            {1, 3},
    };
    int res = solution.kthSmallest(matrix, 4);

    return 0;
}
