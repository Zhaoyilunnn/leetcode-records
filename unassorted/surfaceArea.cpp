//
// Created by zyl on 2020/3/25.
//

#include "include/algorithms_data_structures.h"

int Solution::surfaceArea(vector<vector<int> > &grid) {
    int res = 0;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            if (grid[i][j] > 0) {
                res += grid[i][j] * 4 + 2;
                int temp = 0;
                if (i > 0) {
                    if (grid[i - 1][j] > grid[i][j])
                        temp = grid[i][j];
                    else
                        temp = grid[i - 1][j];
                    res -= temp * 2;
                }
                if (j > 0) {
                    if (grid[i][j-1] > grid[i][j])
                        temp = grid[i][j];
                    else
                        temp = grid[i][j-1];
                    res -= temp * 2;
                }
            }
        }
    }
    return res;
}
