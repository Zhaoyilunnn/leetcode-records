//
// Created by zyl on 2020/1/13.
//
#include "include/algorithms_data_structures.h"
#include "include/objects_oriented.h"


int main(int argc, const char * argv[]) {
    // insert code here...
    Solution solution;

    vector<int> test = {4, 2, 0, 2, 3, 2, 0};
    solution.nextPermutation(test);

    bool res = solution.validMountainArray(test);



    return 0;
}
