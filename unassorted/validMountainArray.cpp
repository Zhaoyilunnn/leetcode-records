//
// Created by zyl on 2020/11/3.
//

#include "../include/algorithms_data_structures.h"


/**
 * https://leetcode-cn.com/problems/valid-mountain-array/
 * @param A
 * @return
 */
bool Solution::validMountainArray(vector<int> &A) {
    int state = 0, n = A.size();
    for (int i = 1; i < n; i++) {
        switch (state) {
            case 0:
                if (A[i] > A[i - 1]) {
                    state = 1;
                } else {
                    return false;
                }
                break;
            case 1:
                if (A[i] < A[i - 1]) {
                    state = 2;
                } else if (A[i] == A[i - 1]) {
                    return false;
                }
                break;
            case 2:
                if (A[i] >= A[i - 1]) {
                    return false;
                }
            default:
                break;
        }
    }
    return state == 2;
}
