//
// Created by zyl on 2020/4/30.
//

#include "algorithms_data_structures.h"


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


/*************************************************************************/
/*
 * Description: Implement pow(x, n), which calculates x raised to the
 * power n (x^n)
 * */
/*************************************************************************/
double Solution::myPow(double x, int n) {
    if (x > 0) return exp(n * log(x));
    if (x == 0) return 0;
    if (n % 2) return -exp(n * log(-x));
    else return exp(n * log(-x));
}


/***********************************************************************/
/*
 * Description: 顺时针打印矩阵元素
 * */
/***********************************************************************/
vector<int> Solution::spiralOrder(vector<vector<int> > &matrix) {
    if (matrix.empty()) return {};
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> passed(m, vector<int> (n, 0));
    vector<int> res;
    int i = 0, j = 0;
    int direct = 0;
    while (true) {
        res.push_back(matrix[i][j]);
        passed[i][j] = 1;
        if (res.size() == m * n) break;
        if (i == 0 && j == 0) {
            if (j < n - 1) {
                j++;
                direct = 0;
            } else if (i < m - 1) {
                i++;
                direct = 1;
            }
        } else {
            switch (direct) {
                case 0:
                    if (j < n - 1 && !passed[i][j+1]) j++;
                    else {
                        i++;
                        direct = 1;
                    }
                    break;
                case 1:
                    if (i < m - 1 && !passed[i+1][j]) i++;
                    else {
                        j--;
                        direct = 2;
                    }
                    break;
                case 2:
                    if (j > 0 && !passed[i][j-1]) j--;
                    else {
                        i--;
                        direct = 3;
                    }
                    break;
                case 3:
                    if (i > 0 && !passed[i-1][j]) i--;
                    else {
                        j++;
                        direct = 0;
                    }
                default:
                    break;
            }
        }
    }
    return res;
}