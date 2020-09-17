//
// Created by zyl on 2020/1/13.
//
#include "include/algorithms_data_structures.h"
#include "include/objects_oriented.h"


int main(int argc, const char * argv[]) {
    // insert code here...
    Solution solution;

    vector<int> nums = {1, 1, 1, 2, 2, 3};
    vector<int> res = solution.topKFrequent(nums, 2);

    return 0;
}
