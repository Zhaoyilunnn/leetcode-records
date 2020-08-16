//
// Created by zyl on 2020/7/13.
//

#include "include/algorithms_data_structures.h"


/**
 * https://leetcode-cn.com/problems/intersection-of-two-arrays-ii/
 * @param nums1
 * @param nums2
 * @return
 */
vector<int> Solution::intersect(vector<int> &nums1, vector<int> &nums2) {
    unordered_map<int, int> map1;
    for (int i : nums1) {
        auto it = map1.find(i);
        if (it != map1.end()) it->second++;
        else map1.emplace(i, 1);
    }
    vector<int> res;
    for (int i : nums2) {
        auto it = map1.find(i);
        if (it != map1.end() and it->second > 0) {
            res.push_back(it->first);
            it->second--;
        }
    }
    return res;
}