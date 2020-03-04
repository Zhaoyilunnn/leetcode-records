//
// Created by zyl on 2020/3/4.
//

#include "function_defs.h"

int Solution::orangesRotting(vector<vector<int>>& grid) {
    vector<vector<int>> result = grid;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            if (grid[i][j] == 2)
                result[i][j] = 0;
            else if (grid[i][j] == 0)
                result[i][j] = -2;
            else
                result[i][j] = -1;
        }
    }
    bool flag = true;
    bool t_flag = true;
    vector<int> temp;
    int m = result.size();
    int n = result[0].size();
    while (flag) {
        flag = false;
        t_flag = false;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!temp.empty())
                    temp.clear();
                if (result[i][j] != -2 && result[i][j] != 0) {
                    if (result[i][j] == -1)
                        t_flag = true;
                    if (i > 0) {
                        if (result[i-1][j] >= 0)
                            temp.push_back(result[i-1][j]+1);
                    }
                    if (i < m-1) {
                        if (result[i+1][j] >= 0)
                            temp.push_back(result[i+1][j]+1);
                    }
                    if (j > 0) {
                        if (result[i][j-1] >= 0)
                            temp.push_back(result[i][j-1]+1);
                    }
                    if (j < n-1) {
                        if (result[i][j+1] >= 0)
                            temp.push_back(result[i][j+1]+1);
                    }
                    if (!temp.empty()) {
                        int min = temp[0];
                        for (int k : temp) {
                            if (k <= min)
                                min = k;
                        }
                        if (min != result[i][j]) {
                            result[i][j] = min;
                            flag = true;  // the flag that this value is updated
                        }
                    }
                }
            }
        }
        if (!t_flag)
            break;
    }
    if (t_flag)
        return -1;
    else {
        int max = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (result[i][j] >= max)
                    max = result[i][j];
            }
        }
        return max;
    }
}
