//
// Created by zyl on 2020/4/30.
//

#include "function_defs.h"


/***********************************************************************/
/* Description: Given an image represented by an N X N matrix, where
 * each pixel in the image is 4 bytes, write a method to rotate the
 * image by 90 degree. Can you do this in place */
/***********************************************************************/
void Solution::rotate(vector<vector<int> > &matrix) {
    int n = matrix.size();
    vector<vector<int>> result = matrix;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            result[j][n - 1 - i] = matrix[i][j];
    }
    matrix = result;
}


/**********************************************************************************************/
/* Description: Given a collection of distinct integers, return all possible permutations */
/**********************************************************************************************/
vector<vector<int>> permuteIndex(int k) {
    if (k == 1) return {{0}};
    vector<vector<int>> result;
    vector<vector<int>> sub_result = permuteIndex(k - 1);
    for (const auto& sub_res : sub_result) {
        for (int i = 0; i < k; i++) {
            vector<int> temp = sub_res;
            temp.insert(temp.begin() + i, k - 1);
            result.push_back(temp);
        }
    }
    return result;
}

vector<vector<int>> Solution::permute(vector<int> &nums) {
    if (nums.empty()) return {};
    vector<vector<int>> result = permuteIndex(nums.size());
    for (auto & i : result) {
        for (int & j : i) j = nums[j];
    }
    return result;
}


/***********************************************************************/
/* Description: A happy number is a number defined by the following
 * process: Starting with any positive integer, replace the number by
 * the sum of the squares of its digits, and repeat the process until
 * the number equals 1 (where it will stay), or it loops endlessly in
 * a cycle which does not include 1. Those numbers for which this
 * process ends in 1 are happy numbers. */
/***********************************************************************/
bool Solution::isHappy(int n) {
    unordered_set<int> cycle_members = {4, 16, 37, 58, 89, 145, 42, 20};
    while (n != 1 && cycle_members.find(n) == cycle_members.end()) {
        int total_sum = 0;
        while (n > 0) {
            int digit = n % 10;
            total_sum += digit * digit;
            n = n / 10;
        }
        n = total_sum;
    }
    return n == 1;
}