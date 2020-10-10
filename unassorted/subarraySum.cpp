//
// Created by zyl on 2020/5/16.
//

#include "include/algorithms_data_structures.h"

/*******************************************************************************/
/*
 * Description: Given an array of integers and an integer k, you need to find
 * the total number of continuous subarrays whose sum equals to k.
 * */
/*******************************************************************************/
int Solution::subarraySum(vector<int> &nums, int k) {
    unordered_map<int, int> mp;  // key is previous sum, value is number
                                 // pre[j-1] = pre[i] - k, we need to find how
                                 // many j (0 <= j <= i) satisfy this equation
    mp[0] = 1;
    int count = 0, pre = 0;
    for (auto& x:nums) {
        pre += x;
        if (mp.find(pre - k) != mp.end()) count += mp[pre - k];
        mp[pre]++;
    }
    return count;
}
