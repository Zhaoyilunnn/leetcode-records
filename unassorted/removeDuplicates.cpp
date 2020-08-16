//
// Created by zyl on 2020/3/5.
//

#include "include/algorithms_data_structures.h"

int Solution::removeDuplicates(vector<int> &nums) {
    if (nums.empty())
        return 0;
    if (nums.size() == 1)
        return 1;
    int new_end = 0;
    int temp = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] != temp) {
            nums[++new_end] = nums[i];
            temp = nums[i];
        }
    }
    return new_end+1;
}
