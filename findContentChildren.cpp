//
// Created by zyl on 2020/1/15.
//

#include "function_defs.h"

void Sort(vector<int>& nums) {
    if (nums.size() == 1)
        return;
    int end = int(nums.size() - 1);
    int temp = 0;
    while (end > 0) {
        for (int i = 1; i <= end; i++) {
            if (nums[i] <= nums[i-1]) {
                temp = nums[i];
                nums[i] = nums[i-1];
                nums[i-1] = temp;
            }
        }
        end--;
    }
}

vector<int> FastSort(vector<int>& nums) {
    if (nums.size() <= 1) {
        return nums;
    }
    vector<int> pivot_list;
    vector<int> less;
    vector<int> greater;
    int pivot = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] < pivot)
            less.push_back(nums[i]);
        else
            greater.push_back(nums[i]);
    }
    vector<int> sorted_less = FastSort(less);
    vector<int> sorted_greater = FastSort(greater);
    sorted_less.push_back(pivot);
    sorted_less.insert(sorted_less.end(), sorted_greater.begin(), sorted_greater.end());
    return sorted_less;
}

int Solution::findContentChildren(vector<int>& g, vector<int>& s) {
//        Sort(g);
//        Sort(s);
    g = FastSort(g);
    s = FastSort(s);
    int i = 0, j = 0;
    int result = 0;
    while (i < g.size() && j < s.size()) {
        if (g[i] <= s[j]) {
            result += 1;
            i++;
            j++;
        }
        else
            j++;
    }
    return result;
}