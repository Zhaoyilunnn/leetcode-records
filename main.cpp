//
// Created by zyl on 2020/1/13.
//
#include "include/algorithms_data_structures.h"
#include "include/objects_oriented.h"


int main(int argc, const char * argv[]) {
    // insert code here...
    Solution solution;

    vector<vector<int>> test = {{4, 2}, {1, 5}, {5, 2}, {5, 3}, {2, 4}};
    vector<int> res = solution.findRedundantDirectedConnection(test);

    return 0;
}
