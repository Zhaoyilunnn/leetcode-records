//
// Created by zyl on 2020/3/18.
//

#include "include/algorithms_data_structures.h"

bool Solution::isRectangleOverlap(vector<int> &rect1, vector<int> &rect2) {
    /* 0 --> Left
     * 2 --> Right
     * 1 --> Low
     * 3 --> High*/
    return !(rect1[2] <= rect2[0] || rect1[0] >= rect2[2]) && !(rect1[3] <= rect2[1] || rect1[1] >= rect2[3]);
}
