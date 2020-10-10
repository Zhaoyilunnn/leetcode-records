//
// Created by zyl on 2020/3/11.
//

#include "include/algorithms_data_structures.h"

int sum(vector<int>& A) {
    int result = 0;
    for (int i : A)
        result += i;
    return result;
}

bool Solution::canThreePartsEqualSum(vector<int> &A) {
    int total = sum(A);
    int first = 0;
    int second = 0;
    int third = 0;
    int i = 0;
    int j = 0;
    while (i < A.size()) {
        first += A[i];
        if (total - first != 2 * first) {
             i++;
            continue;
        }
        second = 0;
        third = 0;
        for (j = i+1; j < A.size(); j++) {
            second += A[j];
            if (second == first && j < A.size()-1) {
                third = total - first - second;
                if (third == second)
                    return true;
            }
        }
        i++;
    }
    return false;
}
