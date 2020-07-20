//
// Created by zyl on 2020/6/13.
//

#include "algorithms_data_structures.h"


/******************************************************************************/
/*
 * Description: Given an array nums of n integers, are there elements a, b, c
 * in nums such that a + b + c = 0? Find all unique triplets in the array
 * which gives the sum of zero.
 * TODO: Revise current implementation
 * */
/******************************************************************************/
vector<vector<int>> Solution::threeSum(vector<int> &nums) {
    unordered_map<int, int> num_num;
    for (int i : nums) {
        auto it = num_num.find(i);
        if (it == num_num.end()) num_num.emplace(i, 1);
        else it->second++;
    }
    vector<vector<int>> res;
    for (int i = 0; i < nums.size(); i++) {
        auto it_first = num_num.find(nums[i]);
        if (it_first == num_num.end() || it_first->second == 0) {
            if (it_first != num_num.end()) num_num.erase(it_first);
            continue;
        }
        it_first->second--;
        for (int j = i + 1; j < nums.size(); j++) {
            auto it_second = num_num.find(nums[j]);
            if (it_second == num_num.end() || it_second->second == 0) {
                if (it_second != num_num.end()) num_num.erase(it_second);
                continue;
            }
            it_second->second--;
            int target = 0 - nums[i] - nums[j];
            auto it_third = num_num.find(target);
            if (it_third != num_num.end()) {
                if (it_third->second > 0) {
                    res.push_back({nums[i], nums[j], target});
                    it_third->second--;
                } else num_num.erase(it_third);
            } else it_second->second++;
        }
    }
    return res;
}