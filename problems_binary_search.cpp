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


/**************************************************************************************/
/*
 * Description: given an array of integers and a target, return an integer if we change
 * all the elements larger than it to the integer value, the sum of the array is most
 * close to the target
 * */
/**************************************************************************************/
int sumWithThreshold(vector<int>& arr, int threshold) {
    int res = 0;
    for (int i : arr) {
        res += i > threshold ? threshold : i;
    }
    return res;
}

int Solution::findBestValue(vector<int> &arr, int target) {
    int max_val = INT32_MIN;
    int min_val = INT32_MAX;
    for (int i : arr) {
        if (i > max_val) max_val = i;
        if (i < min_val) min_val = i;
    }
    int size = (int)arr.size();
    if (min_val * size > target) {
        int average = target / size;
        if (abs(average * size - target) > abs((average + 1) * size) - target) return average + 1;
        else return average;
    }
    int curr_res = 0, mid = 0;
    while (min_val < max_val) {
        mid = (min_val + max_val) / 2;
        curr_res = sumWithThreshold(arr, mid);
        if (curr_res > target) max_val = mid;
        else if (curr_res < target) min_val = mid + 1;
        else return mid;
    }
    if (curr_res < target) {
        if (abs(sumWithThreshold(arr, mid + 1) - target) < target - curr_res) return mid + 1;
        else return mid;
    } else {
        if (abs(sumWithThreshold(arr, mid - 1) - target) <= curr_res - target) return mid - 1;
        else return mid;
    }
}


