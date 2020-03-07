//
// Created by zyl on 2020/3/4.
//

#include "function_defs.h"

// still need to optimize
int Solution::orangesRotting(vector<vector<int>>& grid) {
    bool flag = true;
    int m = grid.size();
    int n = grid[0].size();
    int res = 0;
    while (flag) {
        flag = false;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    if (i > 0 && grid[i - 1][j] == 1) {
                        grid[i - 1][j] = 2;
                        flag = true;
                    }
                    if (i < m - 1 && grid[i + 1][j] == 1) {
                        grid[i + 1][j] = 2;
                        flag = true;
                    }
                    if (j > 0 && grid[i][j - 1] == 1) {
                        grid[i][j - 1] = 2;
                        flag = true;
                    }
                    if (j < n - 1 && grid[i][j + 1] == 1) {
                        grid[i][j + 1] = 2;
                        flag = true;
                    }
                    if (flag)
                        res++;
                }
            }
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1)
                return -1;
        }
    }
    return res;
}
