//
// Created by zyl on 2020/1/13.
//
#include "include/algorithms_data_structures.h"
#include "include/objects_oriented.h"


int main(int argc, const char * argv[]) {
    // insert code here...
    Solution solution;

    vector<int> test = {3, 3, 4}, cost  ={3, 4, 4};
    int res = solution.canCompleteCircuit(test, cost);

    return 0;
}
