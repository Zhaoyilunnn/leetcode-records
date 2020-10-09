//
// Created by zyl on 2020/5/27.
//

#include "include/algorithms_data_structures.h"


/**
 * https://leetcode-cn.com/problems/subarray-sums-divisible-by-k/
 * Solution: let subarray(i, j) denote A[i:j], if subarray(i, j) could be divided by K
 *           Then it means: (k1 * K + r1) - (k2 * K + r2) could be divided by K
 *           Then (k1 - k2) * K + (r1 - r2) could be divided by K
 *           Since that (k1 - k2) * K is times of K, r1 should equal r2
 * @param A
 * @param K
 * @return
 */
int Solution::subarraysDivByK(vector<int>& A, int K) {
    vector<int> remainders(K, 0);
    int prefix = 0;  // current prefix while traversing
    int res = 0;  // result
    for (int i : A) {
        prefix += i;
        int rem = prefix % K;
        if (rem < 0) rem += K;  // revise the remainder to positive
        res += remainders[rem];
        if (rem == 0) res++;
        remainders[rem]++;
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


/**
 * https://leetcode-cn.com/problems/count-binary-substrings/
 * @param s
 * @return
 */
int Solution::countBinarySubstrings(const string &s) {
    vector<int> prefix(s.size() + 1, 1);
    prefix[0] = 0;
    int res = 0;
    int count = 1;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == s[i - 1]) {
            count++;
            if (prefix[i - prefix[i]] >= count) res++;
        } else {
            count = 1;
            res++;
        }
        prefix[i + 1] = count;
    }
    return res;
}