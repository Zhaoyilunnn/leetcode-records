//
// Created by zyl on 2020/4/27.
//

#include "algorithms_data_structures.h"


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


/**
 * https://leetcode-cn.com/problems/search-insert-position/
 * @param nums
 * @param target
 * @return
 */
int Solution::searchInsert(vector<int> &nums, int target) {
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (nums[mid] == target) return mid;
        else if (nums[mid] > target) {
            r = mid - 1;
            if (l > r) {
                if (r >= 0) return nums[r] > target ? r : r + 1;
                else return 0;
            }
        }
        else {
            l = mid + 1;
            if (l > r) return l;
        }
    }
    return 0;
}


/**
 * https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted/
 * Solution 1. binary search
 *          2. two pointers
 * @param numbers
 * @param target
 * @return
 */
vector<int> Solution::twoSumPro(vector<int> &numbers, int target) {
    /* 1. binary search */
    /*for (int i = 0; i < numbers.size(); i++) {
        int l = i + 1, r = numbers.size() - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (numbers[mid] == target - numbers[i]) return {i + 1, mid + 1};
            else if (numbers[mid] < target - numbers[i]) l = mid + 1;
            else r = mid - 1;
        }
    }
    return {0, 0};*/

    /* 2. two pointers */
    int i = 0, j = numbers.size() - 1;
    while (i < j) {
        int sum_two = numbers[i] + numbers[j];
        if (sum_two == target) return {i + 1, j + 1};
        else if (sum_two < target) i++;
        else j--;
    }
    return {0, 0};
}