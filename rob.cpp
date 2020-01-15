//
// Created by zyl on 2020/1/15.
//

#include "function_defs.h"

int Solution::rob(vector<int>& nums) {
    if (nums.empty())
        return 0;
    if (nums.size() == 1)
        return nums[0];
    int res_prev = 0;
    int res = nums[0];
    int end = 0;
    int temp = 0;
    for (int i = 1; i < nums.size(); i++) {
        if (i == 1) {
            if (nums[i] > res) {
                res_prev = res;
                res = nums[i];
                end = i;
            }
            else
                res_prev = res;
        }
        else {
            if (end == i-1) {
                if (nums[i] + res_prev > res) {
                    temp = res;
                    res = nums[i] + res_prev;
                    end = i;
                    res_prev = temp;
                }
                else {
                    res_prev = res;
                }
            }
            else {
                res_prev = res;
                res += nums[i];
                end = i;
            }
        }
    }
    return res;
}