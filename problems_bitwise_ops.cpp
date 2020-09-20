//
// Created by zyl on 2020/4/28.
//

#include "include/algorithms_data_structures.h"


/*********************************************************/
/* Description: two number appear once, others appear twice
 * */
/*********************************************************/
vector<int> Solution::singleNumbers(vector<int> &nums) {
    int ret = 0;
    for (int i : nums) ret ^= i;
    int div = 1;
    while (!(div & ret)) div <<= 1;
    int a = 0, b = 0;
    for (int i : nums) {
        if (div & i) a ^= i;
        else b ^= i;
    }
    return vector<int>{a, b};
}


/**
 * https://leetcode-cn.com/problems/bitwise-and-of-numbers-range/
 * @param m
 * @param n
 * @return
 */
int Solution::rangeBitwiseAnd(int m, int n) {
    /*if (m == 0) return 0;
    if (m == n) return m;
    int i = (int) log2(m), j = (int) log2(n);
    if (i == j) return (int) pow(2, i) + rangeBitwiseAnd(m - (int) pow(2, i), n - (int) pow(2, j));
    else return 0;*/
    int shift = 0;
    // 找到公共前缀
    while (m < n) {
        m >>= 1;
        n >>= 1;
        ++shift;
    }
    return m << shift;
}


/**
 * https://leetcode-cn.com/problems/subsets/
 * @param nums
 * @return
 */
vector<vector<int>> Solution::subsets(vector<int> &nums) {
    vector<vector<int>> res;
    int n = nums.size();
    for (int i = 0; i < (int) pow(2, n); i++) {
        vector<int> temp;
        int comp = 1;
        for (int j = 1; j <= n; j++) {
            int flag = comp & i;
            if (flag) temp.push_back(nums[j - 1]);
            comp *= 2;
        }
        res.push_back(temp);
    }
    return res;
}