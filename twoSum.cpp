//
// Created by zyl on 2020/5/2.
//

#include "function_defs.h"


/*********************************************************************/
/* Description: Given an array of integers, return indices of the
 * two numbers such that they add up to the target number*/
/*********************************************************************/
vector<int> Solution::twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> mapValPos;
    for (int i = 0; i < nums.size(); i++) {
        if (mapValPos.find(nums[i]) == mapValPos.end()) mapValPos.emplace(nums[i], i);
        int remain = target - nums[i];
        auto it = mapValPos.find(remain);
        if (it != mapValPos.end() && it->second != i) return {i, it->second};
    }
    return {0, 0};
}