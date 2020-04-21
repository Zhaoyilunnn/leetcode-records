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


/*****************************************************************************/
/* Description: Given two words word1 and word2, find the minimum number of
 * operations required to convert word1 to word2. You have the following 3
 * operations permitted on a word: Insert a character Delete a character
 * Replace a character
 *
 * Solution: */
/*****************************************************************************/
int Solution::minDistance(const string& word1, const string& word2) {
    int m = word1.length();
    int n = word2.length();
    vector<int> init(n + 1, 0);
    vector<vector<int>> results(m + 1, init);
    for (int i = 0; i < m + 1; i++) {
        for (int j = 0; j < n+1; j++) {
            if (i == 0) results[i][j] = j;
            else if (j == 0) results[i][j] = i;
            else {
                int r0 = results[i-1][j-1] + (word1[i-1] == word2[j-1] ? 0 : 1);
                int r1 = results[i-1][j] + 1;
                int r2 = results[i][j-1] + 1;
                int temp = r0;
                if (r1 < temp) temp = r1;
                if (r2 < temp) temp = r2;
                results[i][j] = temp;
            }
        }
    }
    return results[m][n];
}


/***********************************************************************************/
/* Description: You are given K eggs, and you have access to a building with N
 * floors from 1 to N. 
 * Each egg is identical in function, and if an egg breaks,
 * you cannot drop it again. You know that there exists a floor F with 0 <= F <= N
 * such that any egg dropped at a floor higher than F will break, and any egg
 * dropped at or below floor F will not break. Each move, you may take an egg
 * (if you have an unbroken one) and drop it from any floor X (with 1 <= X <= N). 
 *
 * Your goal is to know with certainty what the value of F is. What is the minimum
 * number of moves that you need to know with certainty what F is, regardless
 * of the initial value of F?
 *
 * Solution:    DP:
 */
/***********************************************************************************/
int Solution::superEggDrop(const int& K, const int& N) {
    int results[K+1][N+1];
    for (int i = 0; i < K + 1; i++) {
        for (int j = 0; j < N + 1; j++)
            results[i][j] = j;
    }
    for (int m = 2; m < K+1; m++) {
        for (int n = 1; n < N+1; n++) {
            for (int i = 1; i < N+1; i++)
                results[m][n] = min(results[m][n], max(results[m-1][i-1], results[m][n-i]));
        }
    }
    return results[K][N];
}


/****************************************************************************************/
/* Description: Given an array of non-negative integers, you are initially positioned
 * at the first index of the array.
 * Each element in the array represents your maximum jump length at that position.
 * Determine if you are able to reach the last index. */
/****************************************************************************************/
bool Solution::canJump(vector<int> &nums) {
    vector<bool> results(nums.size(), false);
    results[0] = true;
    for (int i = 1; i < nums.size(); i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (results[j] && nums[j] >= i - j) {
                results[i] = true;
                break;
            }
        }
    }
    return results[nums.size() - 1];
}


/*******************************************************************************************/
/* Description: Given n non-negative integers a1, a2, ..., an , where each represents a
 * point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of
 * line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a
 * container, such that the container contains the most water.
 *
 * Solution: double pointer
 * */
/*******************************************************************************************/
int Solution::maxArea(vector<int> &height) {
    int start = 0;
    int end = (int) height.size() - 1;
    int result = 0;
    int temp = 0;
    while (start < end) {
        temp = min(height[start], height[end]) * (end - start);
        result = temp > result ? temp : result;
        height[start] > height[end] ? end-- : start++;
    }
    return result;
}


/********************************************************************************************/
/* Description: Define S = [s,n] as the string S which consists of n connected strings s.
 * For example, ["abc", 3] ="abcabcabc".
 * */
/********************************************************************************************/
/* Compute how many s2 can be obtained from s1 */
int numSecond(const string& s1, const string& s2) {
    int res = 0;
    int i = 0, j = 0;
    while (i < s1.size()) {
        if (s1[i] == s2[j]) {
            j++;
            if (j == s2.size()) {
                j = 0;
                res++;
            }
        }
        i++;
    }
    return res;
}

int Solution::getMaxRepetitions(const string& s1, int n1, const string& s2, int n2) {
    int temp = numSecond(s1, s2);
    if (temp > 0) return temp * n1 / n2;
    string s1_plus = s1;
    int i = 1;
    while (s1.size() * i % n2 != 0) i++;
    for (int j = 2; j <= i; j++) s1_plus += s1;
    return 0;
}


/************************************************************************************************/
/* Description: Given an array of integers nums and an integer k. A subarray is called nice if
 * there are k odd numbers on it
 * Solution: Dynamic programming,  Store the positions of odd numbers
 *           start --> current start position
 *           result <-- result + positions[start] - positions[start - 1]*/
/************************************************************************************************/
int Solution::numberOfSubarrays(vector<int> &nums, int k) {
    vector<int> positions;
    int count = 0;
    int start = -1;
    int result = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] % 2 == 1) {
            positions.push_back(i);
            count < k ? count++ : count;
        }
        if (count == k) {
            nums[i] % 2 == 1 ? start++ : start;
            result += positions[start] - (start == 0 ? -1 : positions[start - 1]);
        }
    }
    return result;
}