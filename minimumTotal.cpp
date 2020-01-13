//
// Created by zyl on 2020/1/13.
//

#include "function_defs.h"

pair<int, set<int>> minTemp(vector<int>& Vec, set<int>& Index) {
    set<int> temp;
    int val = Vec[*Index.begin()];
    set<int>::iterator it;
    pair<int, set<int>> result;
    for (it = Index.begin(); it != Index.end(); it++) {
        if (Vec[*it] < val) {
            val = Vec[*it];
            if (!temp.empty())
                temp.clear();
            temp.insert(*it);
            temp.insert(*it+1);
        }
        else if (Vec[*it] == val) {
            temp.insert(*it);
            temp.insert(*it+1);
        }
    }
    result = make_pair(val, temp);
    return result;
}

int Solution::minimumTotal(vector<vector<int>>& triangle) {
    pair<int, set<int>> TempInfo;
    set<int> temp;
    vector<pair<int, set<int>>> result;
    int res = 0;
    for (int i = 0; i < triangle.size(); i++) {
        if (i == 0) {
            temp.insert(0);
            temp.insert(1);
            TempInfo = make_pair(triangle[0][0], temp);
            result.push_back(TempInfo);
        }
        else {
            TempInfo = minTemp(triangle[i], result[i-1].second);
            result.push_back(TempInfo);
        }
    }
    for (auto & i : result) {
        res += i.first;
    }
    return res;
}

