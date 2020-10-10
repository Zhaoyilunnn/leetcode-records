//
// Created by zyl on 2020/10/4.
//

#include "include/algorithms_data_structures.h"


/**
 * https://leetcode-cn.com/problems/daily-temperatures/
 * Solutions: 1. Binary search (stupid)
 *            2. Back traverse
 *            3. Single order stack
 * @param T
 * @return
 */
int binSearch(int target, vector<int>& nums) {
    if (nums.empty()) return -1;
    int l = 0, r = nums.size() - 1;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (nums[mid] > target) {
            r = mid - 1;
            if (l == r) return nums[r] > target ? r : mid;
        } else {
            l = mid + 1;
            if (l == r) return nums[l] > target ? l : l + 1;
        }
    }
    return nums[l] > target ? l : l + 1;
}

vector<int> Solution::dailyTemperatures(vector<int>& T) {
    /* Binary search */
    /*vector<vector<int>> t(71, vector<int>());
    for (int i = 0; i < T.size(); i++) {
        for (int j = 30; j < T[i]; j++) {
            t[j - 30].push_back(i);
        }
    }
    vector<int> res(T.size(), 0);
    for (int i = 0; i < T.size(); i++) {
        int idx = binSearch(i, t[T[i] - 30]);
        if (idx >= 0 && idx < t[T[i] - 30].size()) res[i] = t[T[i] - 30][idx] - i;
    }
    return res;*/

    /* Back traverse */
    /*int n = (int) T.size();
    vector<int> res(n, 0);
    vector<int> next(71, -1);
    for (int i = n - 1; i >= 0; i--) {
        next[T[i] - 30] = i;
        int min_idx = i;
        for (int j = T[i] + 1; j <= 100; j++) {
            if (next[j - 30] > 0) {
                min_idx = min_idx == i ? next[j - 30] : min(min_idx, next[j - 30]);
            }
        }
        res[i] = min_idx - i;
    }
    return res;*/

    /* Single order stack */
    stack<int> store;
    int n = (int) T.size();
    vector<int> res(n, 0);
    for (int i = 0; i < n; i++) {
        if (store.empty()) {
            store.push(i);
            continue;
        }
        while (!store.empty() && T[i] > T[store.top()]) {
            res[store.top()] = i - store.top();
            store.pop();
        }
        store.push(i);
    }
    return res;
}


/**
 * https://leetcode-cn.com/problems/trapping-rain-water/
 * Solutions: 1. naive method
 *            2. single order stack
 *            3. double pointer
 * @param height
 * @return
 */
int Solution::trap(vector<int> &height) {
    /* naive method */
    /*int result = 0;
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
    return result;*/

    /* double pointer */
    /*if (height.empty()) return 0;
    int res = 0;
    int l = 0, r = (int) height.size() - 1;
    while (!height[l] && l < height.size() - 1) l++;
    while (l < r) {
        int i = l + 1;
        while (height[l] < height[r] && l < r) {
            if (height[i] < height[l]) res += height[l] - height[i];
            else l = i;
            i++;
        }
        i = r - 1;
        while (height[l] >= height[r] && l < r) {
            if (height[i] < height[r]) res += height[r] - height[i];
            else r = i;
            i--;
        }
    }
    return res;*/

    /* single order stack */
    int ans = 0, current = 0;
    stack<int> st;
    while (current < height.size()) {
        while (!st.empty() && height[current] > height[st.top()]) {
            int top = st.top();
            st.pop();
            if (st.empty())
                break;
            int distance = current - st.top() - 1;
            int bounded_height = min(height[current], height[st.top()]) - height[top];
            ans += distance * bounded_height;
        }
        st.push(current++);
    }
    return ans;
}