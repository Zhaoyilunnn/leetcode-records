//
// Created by zyl on 2020/3/6.
//

#include "include/algorithms_data_structures.h"

vector<vector<int>> Solution::findContinuousSequence(int target) {
    vector<vector<int>> result;
    int m = 0;  // m should be larger than n;
    int start = 0;
    vector<int> seq;
    int sum = target * 2;
    for (int n = 2; sum*2 / n > n; n++) {
        if (sum % n == 0) {
            m = sum / n;
            if ((m+1-n) % 2 == 0 && (m+1-n) / 2 > 0) {
                if (!seq.empty())
                    seq.clear();
                start = (m + 1 - n) / 2;
                for (int i = start; i < start + n; i++)
                    seq.push_back(i);
                result.insert(result.begin(), seq);
            }
        }
    }
    return result;
}