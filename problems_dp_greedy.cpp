//
// Created by zyl on 2020/3/8.
//

#include "include/algorithms_data_structures.h"

/****************************************************************/
/* Given an integer array nums, find the contiguous subarray
 * (containing at least one number) which has the largest sum
 * and return its sum */
/****************************************************************/
int Solution::maxSubArray(vector<int>& nums) {
    int curr_sum = 0, max_sum = nums[0];
    for (int i : nums) {
        curr_sum += i;
        if (curr_sum > max_sum) max_sum = curr_sum;
        curr_sum = curr_sum <= 0 ? 0 : curr_sum;
    }
    return max_sum;
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
    int res_prev_prev = 0;
    int res_prev = 0;
    int res;
    for (int i = 0; i < nums.size(); i++) {
        if (i == 0) res = nums[i];
        else if (i == 1) {
            res_prev = res;
            res = nums[i] > nums[i - 1] ? nums[i] : nums[i - 1];
        } else {
            res_prev_prev = res_prev;
            res_prev = res;
            if (nums[i] + res_prev_prev > res_prev) res = nums[i] + res_prev_prev;
        }
    }
    return res;
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

/**
 * A robot is located at the top-left corner of a m x n grid
 * the robot can only move either down or right at any point in time
 * Consider if some obstacles added to the grids. How many unique paths would there be
 * @param obstacleGrid
 * @return
 */
int Solution::uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<int> row(n, 0);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 && j != 0) row[j] = obstacleGrid[i][j] ? 0 : row[j - 1];
            else if (j == 0 && i != 0) row[j] = obstacleGrid[i][j] ? 0 : row[0];
            else if (j == 0 && i == 0) row[j] = obstacleGrid[i][j] ? 0 : 1;
            else row[j] = obstacleGrid[i][j] ? 0 : row[j - 1] + row[j];
        }
    }
    return row[n - 1];
}


/**
 * https://leetcode-cn.com/problems/triangle/
 * TODO: Using only O(n) extra space, n is the total number of rows in the triangle
 * @param triangle
 * @return
 */
int Solution::minimumTotal(vector<vector<int>>& triangle) {
    vector<vector<int>> store = triangle;
    int m = triangle.size();
    for (int i = m - 1; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            if (i == m - 1) store[i][j] = triangle[i][j];
            else store[i][j] = triangle[i][j] + min(store[i + 1][j], store[i + 1][j + 1]);
        }
    }
    return store[0][0];
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


/************************************************************************/
/* reach the last index in the minumum number of jumps */
/************************************************************************/
int Solution::jump(vector<int> &nums) {
    int res = 0;
    int max_pos = 0;
    int step_max = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (i > step_max) {
            res++;
            step_max = max_pos;
        }
        max_pos = (i + nums[i]) > max_pos ? (i + nums[i]) : max_pos;
    }
    return res;
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


/****************************************************************************************/
/* Description: 数组中两个数字如果前一个大于后一个就是一个逆序对 */
/****************************************************************************************/
int Solution::reversePairs(vector<int> &nums) {
    if (nums.empty()) return 0;
    int l = nums.size();
    int max_num = nums[0];
    vector<int> results(l, 0);
    int result = 0;
    map<int, int> positions;
    positions.emplace(nums[0], 0);
    for (int i = 1; i < l; i++) {
        /* store the maximum number */
        if (nums[i] > max_num) max_num = nums[i];

        /* store the first position of nums[i] */
        auto it = positions.find(nums[i]);
        if (positions.end() == it) positions.emplace(nums[i], i);

        /* find the smallest number that is larger than current number */
        int pos = -1;
        for (int j = nums[i] + 1; j <= max_num; j++) {
            it = positions.find(j);
            if (positions.end() != it) {
                pos = it->second;
                break;
            }
        }

        /* calculate current result */
        if (pos >= 0) {
            int curr_res = results[pos];
            for (int j = pos; j < i; j++) {
                if (nums[j] > nums[i]) curr_res++;
            }
            results[i]  = curr_res;
        } else results[i] = 0;
        result += results[i];
    }
    return result;
}


/********************************************************************************/
/* Description: candidates without duplicates, and a target number, return all
 * combinations
 * Solution 1: recurrence */
/********************************************************************************/
vector<vector<int>> Solution::combinationSum(vector<int> &candidates, int target) {
    vector<vector<int>> results;
    for (int c : candidates) {
        int new_target = target - c;
        if (new_target == 0) results.push_back({c});
        if (new_target < 0) continue;
        vector<vector<int>> temp_combination = combinationSum(candidates, new_target);
        if (temp_combination.empty()) continue;
        for (vector<int> comb : temp_combination) {
            if (*(comb.end() - 1) <= c) {
                comb.push_back(c);
                results.push_back(comb);
            }
        }
    }
    return results;
}


/*******************************************************************************/
/* Description: "abcabcbb" --> abc */
/*******************************************************************************/
int Solution::lengthOfLongestSubstring(const string& s) {
    int res = 0, curr_res = 0;
    unordered_map<char, int> store;
    for (int i = 0; i < s.size(); i++) {
        auto it = store.find(s[i]);
        if (it == store.end()) {
            store.emplace(s[i], i);
            curr_res++;
        } else {
            if (curr_res >= res) res = curr_res;
            for (int j = i - curr_res; j < it->second; j++) {
                store.erase(store.find(s[j]));
            }
            curr_res = i - it->second;
            it->second = i;
        }
    }
    if (curr_res >= res) res = curr_res;
    return res;
}


/*****************************************************************************/
/* Description: The days that you will travel is given as an array days. Each
 * day is an integer from 1 to 365
 * Train tickets are sold in 3 different ways
 *  1. a 1-day pass is sold for costs[0] dollars
 *  2. a 7-day pass is sold for costs[1] dollars
 *  3. a 30-day pass is sold for costs[2] dollars
 * Return the minimum number of dollars you need to travel every day in the
 * given list of days */
/*****************************************************************************/
int Solution::mincostTickets(vector<int> &days, vector<int> &costs) {
    int delta_7 = costs[1] / costs[0];
    int delta_30 = costs[2] / costs[0];
    vector<int> results(days.size(), 0);
    results[0] = min(costs[0], min(costs[1], costs[2]));
    for (int i = 1; i < days.size(); i++) {
        int i_7 = i - delta_7;
        int i_30 = i - delta_30;
        int r1 = -1, r2 = -1, r3 = -1;
        r1 = results[i - 1] + costs[0];
        if (i_7 >= 0 && days[i] - days[i_7] < 7) {
            while (i_7 >= 0 && days[i] - days[i_7] < 7) i_7--;
            i_7++;
            r2 = (i_7 > 0 ? results[i_7 - 1] : 0) +  costs[1];
        }
        if (i_30 >= 0 && days[i] - days[i_30] < 30) {
            while (i_30 >= 0 && days[i] - days[i_30] < 30) i_30--;
            i_30++;
            r3 = (i_30 > 0 ? results[i_30 - 1] : 0) +  costs[2];
        }
        int res = r1;
        if (r2 > 0 && r2 < res) res = r2;
        if (r3 > 0 && r3 < res) res = r3;
        results[i] = res;
    }
    return results[days.size() - 1];
}


/************************************************************/
/*
 *
 * */
/************************************************************/
int Solution::maxProduct(vector<int> &nums) {
    int curr_product = 1;
    int result = INT32_MIN;
    for (int i : nums) {
        if (curr_product == 1 || curr_product == 0) curr_product = i;
        else curr_product *= i;
        if (curr_product >= result) result = curr_product;
    }
    return result;
}


/**********************************************************/
/*
 * Given non-negative integers representing the histogram's
 * bar height the width of each bar is 1, find the area of
 * largest rectangle in the histogram
 * */
/**********************************************************/
int Solution::largestRectangleArea(vector<int> &heights) {
    vector<pair<int, int>> store_prev;   // a list that stores previous candidates rectangles
    vector<pair<int, int>> store_curr;
    int largest;
    for (int i = 0; i < heights.size(); i++) {
        if (!store_curr.empty()) store_curr.clear();
        if (i == 0) {
            store_curr.emplace_back(heights[i], 1);
            largest = heights[i] * 1;
            store_prev = store_curr;
        } else {
            bool flag = true;
            int longest = 0;
            for (auto pair : store_prev) {
                if (heights[i] > pair.first) {
                    pair.second++;
                    store_curr.push_back(pair);
                    if (pair.first * pair.second > largest) largest = pair.first * pair.second;
                } else {
                    flag = false;
                    if (++pair.second > longest) longest = pair.second;
                }
            }
            if (flag) {
                store_curr.emplace_back(heights[i], 1);
                if (heights[i] > largest) largest = heights[i];
            }
            if (longest > 0) {
                store_curr.emplace_back(heights[i], longest);
                if (heights[i] * longest > largest) largest = heights[i] * longest;
            }
            store_prev = store_curr;
        }
    }
    return largest;
}


/**
 * https://leetcode-cn.com/problems/new-21-game/
 * @param N
 * @param K
 * @param W
 * @return
 */
double Solution::new21Game(int N, int K, int W) {
    return 0.0;
}


/*****************************************************************************/
/*
 * 把数字翻译成字符串, 0 --> a, 1 --> b (不超过26)
 * */
/*****************************************************************************/
int Solution::translateNum(int num) {
    vector<int> digits;
    int div = 10;

    // First construct a vector that contains each digit
    while (num > 0) {
        int digit = num % 10;
        digits.insert(digits.begin(), digit);
        num = (num - digit) / 10;
    }
    int prev = 1;
    int res = 1;
    for (int i = 0; i < digits.size(); i++) {
        int temp = prev;
        prev = res;
        if (i == 0) res = 1;
        else if (digits[i - 1] > 0 && digits[i - 1] * 10 + digits[i] < 26)
            res += temp;
    }
    return res;
}


/*********************************************************************************/
/*
 * Description: Given an array A of positive integers, A[i] represents the value
 * of the i-th sightseeing spot, and two sightseeing spots i and j have distance
 * j - i between them.
 * The score of a pair (i < j) of sightseeing spots is (A[i] + A[j] + i - j) :
 * the sum of the values of the sightseeing spots, minus the distance between them.
 * Return the maximum score of a pair of sightseeing spots.
 * */
/*********************************************************************************/
int Solution::maxScoreSightseeingPair(vector<int> &A) {
    int res = 0;
    int prev = A[0];
    int pos = 0;
    res = A[1] + A[0] - 1;
    for (int i = 2; i < A.size(); i++) {
        prev--;
        if (prev < A[i-1]) {
            prev = A[i-1];
            pos = i-1;
        }
        if (A[pos] + A[i] + pos - i > res) res = A[pos] + A[i] + pos - i;
    }
    return res;
}


/*************************************************************************************/
/*
 * Description: Given two integer arrays A and B, return the maximum length of an
 * subarray that appears in both arrays.
 * */
/*************************************************************************************/
int Solution::findLength(vector<int> &A, vector<int> &B) {
    int m = A.size();
    int n = B.size();
    int res = 0;
    vector<int> store(n, 0);
    for (int i = 0; i < m; i++) {
        vector<int> curr(n, 0);
        for (int j = 0; j < n; j++) {
            if ((j == 0 || i == 0) && A[i] == B[j]) {
                curr[j] = 1;
                if (curr[j] > res) res = curr[j];
            } else if (A[i] == B[j]) {
                curr[j] = store[j - 1] + 1;
                if (curr[j] > res) res = curr[j];
            }
        }
        store = curr;
    }
    return res;
}


/***********************************************************************************/
/*
 * Description: Given a string containing just the characters '(' and ')', find the
 * length of the longest valid (well-formed) parentheses substring.
 *
 * */
/***********************************************************************************/
int Solution::longestValidParentheses(const string& s) {
    int res = 0;
    vector<int> dp(s.size() + 1, 0);
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') dp[i + 1] = 0;
        else if (i - 1 >= 0 && s[i - 1] == '(') dp[i + 1] = dp[i - 1] + 2;
        else if (i - 1 - dp[i] >= 0 && s[i - 1 - dp[i]] == '(')
                dp[i + 1] = dp[i] + 2 + dp[i - dp[i] - 1];
        res = dp[i + 1] > res ? dp[i + 1] : res;
    }
    return res;
}


/**
 * Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?'
 * and '*'
 * '?' matches any single character
 * '*' matches any sequence of characters
 * @param s
 * @param p
 * @return
 */
bool Solution::isMatchPro(const string &s, const string &p) {
    if (s.empty() && (p == "*" || p.empty())) return true;
    else if (s.empty()) return false;
    int m = s.size(), n = p.size();
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

    // initialize
    dp[0][0] = true;
    int start = 0;
    for (start = 0; start < n; start++) if (p[start] != '*') break;
    for (int j = 0; j < start; j++) {
        for (int i = 0; i < m + 1; i++) {
            dp[i][j + 1] = true;
        }
    }
    if (s[0] == p[0] || p[0] == '?') dp[1][1] = true;

    for (int i = 1; i < m + 1; i++) {
        for (int j = start + 1; j < n + 1; j++) {
            if (p[j - 1] == '*') dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
            else if (p[j - 1] == '?' || p[j - 1] == s[i - 1]) dp[i][j] = dp[i - 1][j - 1];
        }
    }
    return dp[m][n];
}


/*************************************************************************************************/
/*
 * Description: '.' Matches any single character. '*' Matches zero or more of the preceding element
 * */
/*************************************************************************************************/
bool Solution::isMatch(const string& s, const string& p) {
    string s_r = " " + s;
    string p_r = " " + p;
    vector<vector<bool>> dp(s_r.size() + 1, vector<bool>(p_r.size() + 1, false));
    dp[0][0] = true;
    for (int i = 1; i <= s_r.size(); i++) {
        for (int j = 1; j <= p_r.size(); j++) {
            if (p_r[j - 1] != '*') {
                if (s_r[i - 1] == p_r[j - 1] || p_r[j - 1] == '.') dp[i][j] = dp[i - 1][j - 1];
            } else {
                if (s_r[i - 1] != p_r[j - 2] && p_r[j - 2] != '.') dp[i][j] = dp[i][j - 2];
                else dp[i][j] = dp[i][j - 1] || dp[i][j - 2] || dp[i - 1][j];
            }
        }
    }
    return dp[s_r.size()][p_r.size()];
}


/**
 * https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/
 * @param prices
 * @return
 */
int Solution::maxProfitI(vector<int> &prices) {
    int inf = 1e9;
    int min_price = inf, max_profit = 0;
    for (int price: prices) {
        max_profit = max(max_profit, price - min_price);
        min_price = min(price, min_price);
    }
    return max_profit;
}


/**
 * ith element is the price of a given stock on day i
 * After you sell your stock, you cannot buy stock on next day. (i.e. cooldown 1 day)
 *
 * @param prices
 * @return
 */
int Solution::maxProfit(vector<int> &prices) {
    /* DP */
    /*if (prices.empty()) {
        return 0;
    }

    int n = prices.size();
    // f[i][0]: 手上持有股票的最大收益
    // f[i][1]: 手上不持有股票，并且处于冷冻期中的累计最大收益
    // f[i][2]: 手上不持有股票，并且不在冷冻期中的累计最大收益
    vector<vector<int>> f(n, vector<int>(3));
    f[0][0] = -prices[0];
    for (int i = 1; i < n; ++i) {
        f[i][0] = max(f[i - 1][0], f[i - 1][2] - prices[i]);
        f[i][1] = f[i - 1][0] + prices[i];
        f[i][2] = max(f[i - 1][1], f[i - 1][2]);
    }
    return max(f[n - 1][1], f[n - 1][2]);*/

    /* Optimize space */
    if (prices.empty()) {
        return 0;
    }

    int n = prices.size();
    int f0 = -prices[0];
    int f1 = 0;
    int f2 = 0;
    for (int i = 1; i < n; ++i) {
        int new_f0 = max(f0, f2 - prices[i]);
        int new_f1 = f0 + prices[i];
        int new_f2 = max(f1, f2);
        f0 = new_f0;
        f1 = new_f1;
        f2 = new_f2;

        // Optimized code for C++11
        /*tie(f0, f1, f2) = make_tuple(max(f0, f2 - prices[i]), f0 + prices[i], max(f1, f2));*/
    }

    return max(f1, f2);
}


/**
 * https://leetcode-cn.com/problems/dungeon-game/
 * dp from right bottom to left top !!
 * @param dungeon
 * @return
 */
int Solution::calculateMinimumHP(vector<vector<int> > &dungeon) {
     int m = dungeon.size(), n = dungeon[0].size();
     vector<int> dp_curr(n, 1), dp_pre(n, 1);
     for (int i = m - 1; i >= 0; i--) {
         for (int j = n - 1; j >= 0; j--) {
             if (j == n - 1) dp_curr[j] = dp_pre[j] - dungeon[i][j] > 0 ? dp_pre[j] - dungeon[i][j] : 1;
             else if (i == m - 1) dp_curr[j] = dp_curr[j + 1] - dungeon[i][j] > 0 ? dp_curr[j + 1] - dungeon[i][j] : 1;
             else {
                 int temp = min(dp_pre[j], dp_curr[j + 1]);
                 dp_curr[j] = temp - dungeon[i][j] > 0 ? temp - dungeon[i][j] : 1;
             }
         }
         dp_pre = dp_curr;
     }
    return dp_curr[0];
}


/**
 * https://leetcode-cn.com/problems/split-array-largest-sum/
 * @param nums
 * @param m
 * @return
 */
int Solution::splitArray(vector<int> &nums, int m) {
    // The state transition equation is as follows
    // Consider that dp(i, j) denote the result of dividing i elements to j segments
    // Then dp(i, j) = min ( max(dp(k, j - 1), sub(k+1, i)) ) for k in range(i)
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(m + 1, 0));
    vector<int> prefix(n, 0);
    int curr_sum = 0;
    for (int i = 0; i < n; i++) {
        curr_sum += nums[i];
        prefix[i] = curr_sum;
        dp[i][1] = prefix[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 2; j < m + 1 && j <= i + 1; j++) {
            int min_k = INT32_MAX;
            for (int k = 0; k < i; k++) {
                min_k = min(min_k, max(dp[k][j - 1], prefix[i] - prefix[k]));
            }
            dp[i][j] = min_k;
        }
    }
    return dp[n - 1][m];
}


/**
 * https://leetcode-cn.com/problems/is-subsequence/
 * Optimization: double pointer
 * @param s
 * @param t
 * @return
 */
bool Solution::isSubsequence(const string &s, const string &t) {
/*    if (s.empty()) return true;
    else if (!s.empty() && t.empty()) return false;

    int m = s.size(), n = t.size();
    vector<vector<bool>> dp(m, vector<bool>(n, false));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0) dp[i][j] = s[i] == t[j];
            else if (i == 0) dp[i][j] = dp[i][j - 1] || s[i] == t[j];
            else if (j == 0) dp[i][j] = false;
            else {
                if (s[i] == t[j]) dp[i][j] = dp[i - 1][j - 1];
                else dp[i][j] = dp[i][j - 1];
            }
        }
    }
    return dp[m - 1][n - 1];*/
    int i = 0, j = 0;
    while (i < s.size() && j < t.size()) {
        if (s[i] == t[j]) {
            i++;
            j++;
        } else j++;
    }
    return i == s.size();
}


/**
 * https://leetcode-cn.com/problems/burst-balloons/
 * @param nums
 * @return
 */
int Solution::maxCoins(vector<int> &nums) {
    // 暴力方法
    /*if (nums.empty()) return 0;
    if (nums.size() == 1) return nums[0];
    vector<int> sub_nums;
    int curr_res = 0;
    int curr_product = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (i == 0) curr_product = nums[i] * nums[i + 1];
        else if (i == nums.size() - 1) curr_product = nums[i - 1] * nums[i];
        else curr_product = nums[i - 1] * nums[i] * nums[i + 1];
        sub_nums.clear();
        sub_nums.insert(sub_nums.begin(), nums.begin(), nums.begin() + i);
        sub_nums.insert(sub_nums.end(), nums.begin() + i + 1, nums.end());
        curr_res = max(curr_res, maxCoins(sub_nums) + curr_product);
    }
    return curr_res;*/

    // dp
    // dp(i, j) 把位置i, j全部填满能得到的最大的硬币数量
    //
    nums.insert(nums.begin(), 1);
    nums.insert(nums.end(), 1);
    int n = (int) nums.size() - 2;
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i + 2; j <= n + 1; j++) {
            for (int k = i + 1; k < j; k++) {
                int sum = nums[i] * nums[j] * nums[k] + dp[i][k] + dp[j][k];
                dp[i][j] = max(sum, dp[i][j]);
            }
        }
    }
    return dp[0][n + 1];
}


/**
 * https://leetcode-cn.com/problems/xun-bao/
 * Solution: d(i, j)表示第i个M到第j个M经过某一个O的最短距离，n表示机关的数量，不大于16，因此可以使用一个16位的二进制数表示状态
 *           这个二进制数的第i位为1表示第i个M已经触发，为0表示第i个M还未被触发，记这个二进制数为mask。
 *           f(mask, i)表示当前在第i个M处，触发状态为mask的最小步数，如果当前mask代表已触发集合为T，未触发集合为U-T，则我们可以推出这样的
 *           动态规划转移方程：
 *           f(mask, i) = min_{j in T && j != i} (f(mask xor 2^i, j) + d(j, i))
 *           TODO: Finish this problem
 *           Note: 本题是一个非常经典的状态压缩动态规划模型
 * @param maze
 * @return
 */
int Solution::minimalSteps(vector<string> &maze) {

}


/**
 * https://leetcode-cn.com/problems/increasing-subsequences/
 * @param nums
 * @return
 */
vector<vector<int>> Solution::findSubsequences(vector<int> &nums) {
//    set<vector<int>> store;
    set<vector<int>> store;
    vector<vector<int>> res;
    for (int i = 0; i < nums.size(); i++) {
        if (!res.empty()) {
            int size = res.size(), c = 0;
            for (int k = 0; k < size; k++) {
                if (nums[i] >= res[k][res[k].size() - 1]) {
                    vector<int> temp = res[k];
                    temp.push_back(nums[i]);
                    if (store.find(temp) == store.end()) {
                        store.insert(temp);
                        res.push_back(temp);
                    }
                }
            }
        }
        for (int j = 0; j < i; j++) {
            if (nums[i] >= nums[j]) {
                vector<int> temp = {nums[j], nums[i]};
                if (store.find(temp) == store.end()) {
                    store.insert(temp);
                    res.push_back(temp);
                }
            }
        }
    }
    return res;
}


/**
 * https://leetcode-cn.com/problems/predict-the-winner/
 * @param nums
 * @return
 */
bool Solution::PredictTheWinner(vector<int> &nums) {

}


/**
 * https://leetcode-cn.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/
 * Remark: Can use bits to encode status!!
 * @param s
 * @return
 */
int getPermIndex(vector<int>& count) {
    int idx = 0;
    for (int i : count) {
        if (i % 2 == 0) idx += 1;
        idx *= 2;
    }
    return idx / 2;
}

int Solution::findTheLongestSubstring(const string &s) {
    vector<int> vowel_count(5, 0);
    vector<int> store(32, -1);   // store each first kind of permutation of even and odd
    store[31] = 0;
    int res = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'a') vowel_count[0]++;
        else if (s[i] == 'e') vowel_count[1]++;
        else if (s[i] == 'i') vowel_count[2]++;
        else if (s[i] == 'o') vowel_count[3]++;
        else if (s[i] == 'u') vowel_count[4]++;
        int idx = getPermIndex(vowel_count);
        if (store[idx] < 0) store[idx] = i + 1;
        int cur_res = i + 1 - store[idx];
        res = max(cur_res, res);
    }
    return res;
}


/**
 * https://leetcode-cn.com/problems/longest-increasing-subsequence/
 * TODO: 数学上证明O(nlog(n))可以找到最优解，思考如何通过O(nlog(n))得到子序列？
 * @param nums
 * @return
 */
int binarySearch(int target, vector<int>& nums) {
    int l = 0, r = nums.size() - 1;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (nums[mid] == target) return mid;
        else if (nums[mid] > target) {
            r = mid - 1;
            if (r == l) return nums[r] > target ? r : mid;
        }
        else {
            l = mid + 1;
            if (l == r) return nums[l] > target ? l : l + 1;
        }
    }
    return l;
}

int Solution::lengthOfLIS(vector<int> &nums) {
    /* O(n^2) method dp[i] = arg_max(dp[j] + 1) */
    /*if (nums.empty()) return 0;
    int n = nums.size();
    vector<int> dp(n, 1);
    int res = 1;
    for (int i = 1; i < n; i++) {
        int temp = 0;
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) temp = max(temp, dp[j]);
        }
        dp[i] = max(temp + 1, dp[i]);
        res = max(res, dp[i]);
    }
    return res;*/

    /* O(nlog(n)) method, greedy with binary search */
    if (nums.empty()) return 0;
    vector<int> seq;
    int res = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (i == 0 || nums[i] > seq[seq.size() - 1]) {
            seq.push_back(nums[i]);
            res++;
        } else {
            int idx = binarySearch(nums[i], seq);
            seq[idx] = nums[i];
        }
    }
    return res;
}


/**
 * https://leetcode-cn.com/problems/longest-common-subsequence/
 * @param text1
 * @param text2
 * @return
 */
int Solution::longestCommonSubsequence(const string &text1, const string &text2) {
    int m = text1.size(), n = text2.size();
    int dp[m + 1][n + 1];
    for (int i = 0; i < m + 1; i++) {
        for (int j = 0; j < n + 1; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
                continue;
            }
            if (text1[i - 1] == text2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }
    return dp[m][n];
}


/**
 * https://leetcode-cn.com/problems/UlBDOe/
 * @param leaves
 * @return
 */
int Solution::minimumOperations(const string &leaves) {
    int n = leaves.size();
    vector<vector<int>> dp(n, vector<int>(3, INT32_MAX));
    for (int i = 0; i < n; i++) {
        int is_red = leaves[i] == 'r';
        int is_yellow = leaves[i] == 'y';
        if (i == 0) {
            dp[i][0] = leaves[0] == 'r' ? 0 : 1;
        } else {
            dp[i][0] = dp[i - 1][0] + is_yellow;
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + is_red;
            if (i >= 2) dp[i][2] = min(dp[i - 1][1], dp[i - 1][2]) + is_yellow;
        }
    }
    return dp[n - 1][2];
}


bool checkPal(string s) {
    int i = 0;
    while (i <= s.size()-i-1) {
        if (s[i] != s[s.size()-i-1])
            return false;
        i++;
    }
    return true;
}

/**
 * https://leetcode-cn.com/problems/longest-palindromic-substring/
 * TODO: Manacher Algorithm
 * @param s
 * @return
 */
pair<int, int> expandAroundCenter(const string& s, int left, int right) {
    while (left >= 0 && right < s.size() && s[left] == s[right]) {
        --left;
        ++right;
    }
    return {left + 1, right - 1};
}

string Solution::longestPalindrome(string s) {
    int start = 0, end = 0;
    for (int i = 0; i < s.size(); ++i) {
        auto [left1, right1] = expandAroundCenter(s, i, i);
        auto [left2, right2] = expandAroundCenter(s, i, i + 1);
        if (right1 - left1 > end - start) {
            start = left1;
            end = right1;
        }
        if (right2 - left2 > end - start) {
            start = left2;
            end = right2;
        }
    }
    return s.substr(start, end - start + 1);
}


/**
 * https://leetcode-cn.com/problems/video-stitching/
 * @param clips
 * @param T
 * @return
 */
int Solution::videoStitching(vector<vector<int>> &clips, int T) {
    unordered_map<int, int> map_clips;
    for (auto c : clips) {
        auto it = map_clips.find(c[0]);
        if (it != map_clips.end()) {
            if (it->second < c[1]) it->second = c[1];
        } else map_clips[c[0]] = c[1];
    }
    int res = 0;
    int cur = 0, prev = 0, next = 0;
    if (map_clips.find(0) == map_clips.end()) return -1;
    cur = map_clips[0];
    while (cur < T) {
        for (int j = prev; j <= cur; j++) {
            next = max(next, map_clips[j]);
        }
        if (cur == next) return -1;
        prev = cur;
        cur = next;
        res += 1;
    }
    return res;
}

/**
 * https://leetcode-cn.com/problems/next-permutation/
 * @param nums
 */
void Solution::nextPermutation(vector<int> &nums) {
    int i = (int) nums.size() - 2, j = (int) nums.size() - 1;
    while (i >= 0) {
        if (nums[i] < nums[i + 1]) {
            while (j >= 0) {
                if (nums[j] > nums[i]) {
                    swap(nums[i], nums[j]);
                    reverse(nums.begin() + i + 1, nums.end());
                    return;
                }
                j--;
            }
        }
        i--;
    }
    reverse(nums.begin(), nums.end());
}

/**
 * https://leetcode-cn.com/problems/remove-k-digits/
 * @param num
 * @param k
 * @return
 */
string Solution::removeKDigits(const string &num, int k) {
    vector<char> single_stack;
    int n = num.size(), i = 0, count = 0;
    while (i < n) {
        if (single_stack.empty()) {
            single_stack.push_back(num[i]);
            i++;
        } else {
            char top = single_stack[single_stack.size() - 1];
            int num_i = num[i] - '0';
            int top_d = top - '0';
            if (num_i >= top_d) {
                single_stack.push_back(num[i]);
                i++;
            } else {
                if (count < k) {
                    single_stack.pop_back();
                    ++count;
                } else {
                    single_stack.push_back(num[i]);
                    i++;
                }
            }
        }
    }
    string res;
    int j = 0;
    while (j < single_stack.size() && single_stack[j] == '0') {
        j++;
    }
    for (; j < n - k; j++) {
        res.push_back(single_stack[j]);
    }
    if (res.empty()) return "0";
    return res;
}


/**
 * https://leetcode-cn.com/problems/task-scheduler/
 * TODO: Understand and implementation
 * @param tasks
 * @param n
 * @return
 */
int Solution::leastInterval(vector<char> &tasks, int n) {
    unordered_map<char, int> freq;
    for (char ch: tasks) {
        ++freq[ch];
    }

    // 任务总数
    int m = freq.size();
    vector<int> nextValid, rest;
    for (auto [_, v]: freq) {
        nextValid.push_back(1);
        rest.push_back(v);
    }

    int time = 0;
    for (int i = 0; i < tasks.size(); ++i) {
        ++time;
        int minNextValid = INT32_MAX;
        for (int j = 0; j < m; ++j) {
            if (rest[j]) {
                minNextValid = min(minNextValid, nextValid[j]);
            }
        }
        time = max(time, minNextValid);
        int best = -1;
        for (int j = 0; j < m; ++j) {
            if (rest[j] && nextValid[j] <= time) {
                if (best == -1 || rest[j] > rest[best]) {
                    best = j;
                }
            }
        }
        nextValid[best] = time + n + 1;
        --rest[best];
    }

    return time;
}

/**
 * https://leetcode-cn.com/problems/wiggle-subsequence/
 * @param nums
 * @return
 */
int Solution::wiggleMaxLength(vector<int> &nums) {
    if (nums.empty()) {
        return 0;
    }
    int n = nums.size();
    if (n < 2) {
        return 1;
    }
    int count_peak = 0;
    bool flag = false;
    bool flag_flag = false;
    int peak_id = 0;
    for (int i = 1; i < n - 1; i++) {
        if (nums[i] != nums[i - 1] || nums[i] != nums[i + 1]) {
            flag_flag = true;
        }
        int a = nums[i] - nums[peak_id];
        int b = nums[i + 1] - nums[i];
        if (min(a, b) < a + b && a + b < max(a, b)) {
            peak_id = i;
            count_peak++;
            flag = true;
        }
    }
    return flag ? count_peak + 2 : (flag_flag ? 2 : 1);
}