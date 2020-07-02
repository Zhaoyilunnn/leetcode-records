//
// Created by zyl on 2020/5/27.
//

#include "function_defs.h"


/********************************************************************/
/*
 * Description: Given an array A of integers, return the number of
 * (contiguous, non-empty) subarrays that have a sum divisible by K.
 * */

/********************************************************************/
int Solution::subarraysDivByK(vector<int>& A, int K) {
    vector<int> remainders(2 * K - 1, 0);
    remainders[K - 1] = 1;
    int prefix = 0;
    int res = 0;
    for (int i : A) {
        prefix += i;
        int rem = prefix % K;
        res += remainders[rem + K - 1];
        if (rem > 0) res += remainders[rem - 1];
        else if (rem < 0) res += remainders[rem + 2 * K - 1];
        remainders[rem + K - 1]++;
    }
    return res;
}


/**********************************************************************/
/*
 * Description:
 * */
/**********************************************************************/
vector<int> Solution::dailyTemperatures(vector<int>& T) {
    vector<int> stores(71, -1);
    vector<int> res;
    for (int i = (int)T.size() - 1; i >= 0; i--) {
        stores[T[i] - 30] = i;
        int t = 0;
        int min_T = 30001;
        for (t = T[i] + 1; t <= 100; t++) {
            int temp = stores[t - 30];
            if (temp >= 0 && temp < min_T) min_T = temp;
        }
        if (min_T <= 30000) res.insert(res.begin(), min_T - i);
        else res.insert(res.begin(), 0);
    }
    return res;
}


/*******************************************************************************/
/*
 * Description: minimum continuous subarray, of which the sum is >= s
 * */
/*******************************************************************************/
int Solution::minSubArrayLen(int s, vector<int> &nums) {
    if (nums.empty()) return 0;
    int start = 0;
    int prefix = 0;
    int res = 0;
    vector<int> prefix_list(nums.size(), 0);
    for (int i = 0; i < nums.size(); i++) {
        if (i >= 1) prefix += nums[i - 1];
        prefix_list[i] = prefix;
        if (prefix_list[i] + nums[i] - prefix_list[start] >= s) {
            for (int j = start; j <= i; j++) {
                int temp = prefix_list[i] + nums[i] - prefix_list[j];
                if (temp >= s) {
                    res = i - j + 1;
                    start = j + 2;
                    if (start >= nums.size()) return res;
                } else break;
            }
        } else {
            if (res > 0) start++;
        }
    }
    return res;
}
