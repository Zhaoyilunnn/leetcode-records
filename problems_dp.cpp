//
// Created by zyl on 2020/3/8.
//

#include "function_defs.h"

/****************************************************************/
/* To do: replace with the optimized solution */
/****************************************************************/
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


/*****************************************************************/
/* Description: Climb stairs, each step could climb one or two,
 * output the number of ways to climb stairs */
/*****************************************************************/
int Solution::climbStairs(int n) {
    std::vector<int> result;
    for (int i = 0; i < n; i++) {
        if (i == 0)
            result.push_back(1);
        else if (i == 1)
            result.push_back(2);
        else
            result.push_back(result[i-1] + result[i-2]);
    }
    return result[result.size()-1];
}


/*********************************************************************************************/
/* Description: You are a professional robber planning to rob houses along a street. Each house
 * has a certain amount of money stashed, the only constraint stopping you from robbing each of
 * them is that adjacent houses have security system connected and it will automatically contact
 * the police if two adjacent houses were broken into on the same night.
 * Given a list of non-negative integers representing the amount of money of each house,
 * determine the maximum amount of money you can rob tonight without alerting the police.
 *
 * Note that this problem is the same as massage*/
/*********************************************************************************************/

int Solution::rob(vector<int>& nums) {
    if (nums.empty())
        return 0;
    if (nums.size() == 1)
        return nums[0];
    int prev = nums[0];
    int curr = prev;
    if (nums[1] > prev)
        curr = nums[1];
    for (int i = 2; i < nums.size(); i++) {
        int temp = nums[i] + prev;
        if (temp > curr) {
            prev = curr;
            curr = temp;
        } else
            prev = curr;
    }
    return curr;
}


/********************************************************************/
/* Solution: Keys --> the result must be the one of the
 *                    results[amount-i], i belongs to coins, add 1
 *           Sub problem --> compute the results of coinChange(coins, amount-i)
 *           Steps
 *              for amount_sub = 1 : amount;
 *                  for coin : coins;
 *                      temp = find minimum results[i-coin]
 *                      results[i] = temp + 1
 *                  end for
 *              end for
 *                                                                  */
/********************************************************************/
int Solution::coinChange(vector<int>& coins, int amount) {
    if (coins.empty())
        return -1;
    vector<int> results;
    int result = 0;
    int temp = 0;
    for (int  i = 0;  i < amount+1; ++ i) {
        result = 0;
        if (i == 0) {
            results.push_back(result);
            continue;
        }
        result = -1;
        temp = 0;
        for (int coin : coins) {
            if (i - coin >= 0 && results[i - coin] >= 0) {
                temp = results[i - coin] + 1;
                if (result <= 0 || temp < result)
                    result = temp;
            }
        }
        results.push_back(result);
    }
    return results[results.size()-1];
}


/******************************************************************************************************************/
/* Description: A popular masseuse receives a sequence of back-to-back appointment requests and is debating
 * which ones to accept. She needs a break between appointments and therefore she cannot accept any adjacent
 * requests. Given a sequence of back-to-back appointment requests, find the optimal (highest total booked minutes)
 * set the masseuse can honor. Return the number of minutes.
 *
 * Solution:    Dynamic programming
 *              1. initialize previous result and current result
 *              2. traverse nums, while nums[i] + previous > current, update */
/******************************************************************************************************************/
int Solution::massage(vector<int> &nums) {
    if (nums.empty())
        return 0;
    if (nums.size() == 1)
        return nums[0];
    int pre = nums[0];
    int curr = pre;
    if (nums[1] > pre)
        curr = nums[1];
    for (int i = 2; i < nums.size(); i++) {
        int temp = nums[i] + pre;
        if (temp > curr) {
            pre = curr;
            curr = temp;
        } else
            pre = curr;
    }
    return curr;
}


int Solution::uniquePaths(int m, int n) {
    vector<vector<int>> res;
    vector<int> col(n, 0);
    for (int i = 0; i < m; i++)
        res.push_back(col);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 || j == 0)
                res[i][j] = 1;
            else
                res[i][j] = res[i-1][j] + res[i][j-1];
        }
    }
    return res[m-1][n-1];
}

int Solution::uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    if (obstacleGrid.empty())
        return 0;
    if (obstacleGrid[0][0] == 1)
        return 0;
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    long res = 0;
    vector<int> temp;
    vector<int> temp_temp;
    bool stop_row = false;
    bool stop_col = false;
    for (int i = 0; i < m; i++) {
        temp.clear();
        res = 0;
        for (int j = 0; j < n; j++) {
            if (i == 0) {
                if (stop_row) {
                    temp.push_back(0);
                    res = 0;
                }
                else if (obstacleGrid[i][j] == 1){
                    temp.push_back(0);
                    res = 0;
                    stop_row = true;
                }
                else {
                    temp.push_back(1);
                    res = 1;
                }
            }
            else if (j == 0) {
                if (stop_col) {
                    temp.push_back(0);
                    res = 0;
                }
                else if (obstacleGrid[i][j] == 1){
                    temp.push_back(0);
                    res = 0;
                    stop_col = true;
                }
                else {
                    temp.push_back(1);
                    res = 1;
                }
            }
            else if (obstacleGrid[i][j] == 0){
                res += temp_temp[j];
                temp.push_back(res);
            }
            else {
                res = 0;
                temp.push_back(0);
            }
        }
        temp_temp = temp;
    }
    return int(res);
}


int Solution::minimumTotal(vector<vector<int>>& triangle) {
    vector<vector<int>> results;
    vector<int> temp;
    int length = triangle.size();
    if (length == 1)
        return triangle[0][0];
    for (int i = 0; i < length-1; i++) {
        if (!temp.empty())
            temp.clear();
        for (int j = 0; j < length-1-i; j++) {
            if (i == 0) {
                if (triangle[length-1-i][j] < triangle[length-1-i][j+1])
                    temp.push_back(triangle[length-1-i][j] + triangle[length-2-i][j]);
                else
                    temp.push_back(triangle[length-1-i][j+1] + triangle[length-2-i][j]);
            }
            else {
                if (results[i - 1][j] < results[i - 1][j + 1])
                    temp.push_back(results[i - 1][j] + triangle[length - 2 - i][j]);
                else
                    temp.push_back(results[i - 1][j + 1] + triangle[length - 2 - i][j]);
            }
        }
        results.push_back(temp);
    }
    return results[length-2][0];
}


/*************************************************************************/
/* Description: Given n non-negative integers representing an elevation
 * map where the width of each bar is 1, compute how much water it is
 * able to trap after raining.*/
/*************************************************************************/
int Solution::trap(vector<int> &height) {
    int result = 0;
    int start = 0;
    while (height[start] == 0)
        start++;
    for (int i = start+1; i < height.size(); i++) {
        int high = (height[i] >= height[start]) ? height[start] : height[i];
        for (int j = i-1; j >= start; j--) {
            if (height[j] < high) {
                result += high - height[j];
                height[j] = high;
            } else
                break;
        }
        if (height[i] >= height[start]) start = i;
    }
    return result;
}

