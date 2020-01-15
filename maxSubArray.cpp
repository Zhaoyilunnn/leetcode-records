//
// Created by zyl on 2020/1/15.
//

#include "function_defs.h"


int maxNum(int a, int b) {
    if (a > b)
        return a;
    else
        return b;
}

int Solution::maxSubArray(vector<int>& nums) {
    if (nums.size() == 1)
        return nums[0];
    int maxSum = nums[0];
    int tmpSum = nums[0]; // when tmpSum == 0, reset start position

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] > 0) {
            if (tmpSum <= 0)
                tmpSum = nums[i];
            else
                tmpSum += nums[i];
            maxSum = maxNum(maxSum, tmpSum);
        }
        else {
            tmpSum += nums[i];
            maxSum = maxNum(maxSum, nums[i]);
        }
    }
    return maxSum;
}

