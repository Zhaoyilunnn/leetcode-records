//
// Created by zyl on 2020/4/27.
//

#include "function_defs.h"


/***************************************************/
/* Description: Suppose an array sorted in ascending
 * order is rotated at some pivot unknown to you
 * beforehand */
/***************************************************/
int Solution::search(vector<int> &nums, int target) {
    int left = 0;
    int right = (int)nums.size() - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (nums[mid] < target) {
            if (nums[mid] < nums[left] && target > nums[left]) right = mid - 1;
            else if (target == nums[left]) return left;
            else left = mid + 1;
        } else if (nums[mid] > target) {
            if (nums[mid] > nums[right] && target < nums[left]) left = mid + 1;
            else if (target == nums[left]) return left;
            else right = mid - 1;
        } else return mid;
    }
    return -1;
}