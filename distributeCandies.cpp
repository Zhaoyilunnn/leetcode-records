//
// Created by zyl on 2020/3/5.
//

#include "algorithms_data_structures.h"

vector<int> Solution::distributeCandies(int candies, int num_people) {
    vector<int> vctRes(num_people, 0);
    int num_now = 1;
    while (candies > 0) {
        for (int i = 0; i < num_people; i++) {
            if (candies > num_now) {
                candies -= num_now;
                vctRes[i] += num_now;
                num_now++;
            } else {
                vctRes[i] += candies;
                candies -= num_now;
                break;
            }
        }
    }
    return vctRes;
}
