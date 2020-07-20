//
// Created by zyl on 2020/6/27.
//

#include "algorithms_data_structures.h"


/**************************************************************/
/*
 * Given an array of integers, find the smallest missing positive
 * */
/**************************************************************/
int Solution::firstMissingPositive(vector<int>& nums) {
    int N = nums.size();
    for (int i = 0; i < N; i++) {
        if (nums[i] < N && nums[i] > 0) nums[i] = -nums[i];
        else nums[i] = N + 1;
    }
    for (int i : nums) {
        if (i > 0 && i < N) return i;
    }
    return N + 1;
}