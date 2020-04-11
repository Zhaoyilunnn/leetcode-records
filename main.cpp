    //
// Created by zyl on 2020/1/13.
//
#include "function_defs.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution solution;

    vector<int> v1 = {1,0};
    vector<int> v2 = {1,1};
    vector<int> v3 = {-1,0};
    vector<int> v4 = {3,2};
    vector<double> res = solution.intersection(v1, v2, v3, v4);

    return 0;
}
