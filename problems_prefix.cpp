//
// Created by zyl on 2020/5/27.
//

#include "function_defs.h"


/********************************************************************/
/*
 * Description: Given an array A of integers, return the number of
 * (contiguous, non-empty) subarrays that have a sum divisible by K.
 * */

/********************************************************************/
int Solution::subarraysDivByK(vector<int>& A, int K) {
    vector<int> remainders(2 * K - 1, 0);
    remainders[K - 1] = 1;
    int prefix = 0;
    int res = 0;
    for (int i : A) {
        prefix += i;
        int rem = prefix % K;
        res += remainders[rem + K - 1];
        if (rem > 0) res += remainders[rem - 1];
        else if (rem < 0) res += remainders[rem + 2 * K - 1];
        remainders[rem + K - 1]++;
    }
    return res;
}