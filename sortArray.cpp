//
// Created by zyl on 2020/3/31.
//

#include "function_defs.h"

void fastSort(vector<int>& nums, int low, int high) {
    if (low >= high)
        return;
    int i = low;
    int j = high;
    int key = nums[low];
    while (i < j) {
        while (i < j && nums[j] >= key)
            j--;
        nums[i] = nums[j];
        while (i < j && nums[i] < key)
            i++;
        nums[j] = nums[i];
    }
    nums[i] = key;
    fastSort(nums, low, i-1);
    fastSort(nums, i+1, high);
}

vector<int> Solution::sortArray(vector<int> &nums) {
    if (nums.empty())
        return {};
    if (nums.size() == 1)
        return nums;
    fastSort(nums, 0, (int)nums.size()-1);
    return nums;
}