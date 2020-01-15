//
// Created by zyl on 2020/1/15.
//

#include "function_defs.h"

int Solution::uniquePaths(int m, int n) {
    vector<vector<int>> res;
    vector<int> col(n, 0);
    for (int i = 0; i < m; i++)
        res.push_back(col);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 || j == 0)
                res[i][j] = 1;
            else
                res[i][j] = res[i-1][j] + res[i][j-1];
        }
    }
    return res[m-1][n-1];
}

int Solution::uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    if (obstacleGrid.empty())
        return 0;
    if (obstacleGrid[0][0] == 1)
        return 0;
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    long res = 0;
    vector<int> temp;
    vector<int> temp_temp;
    bool stop_row = false;
    bool stop_col = false;
    for (int i = 0; i < m; i++) {
        temp.clear();
        res = 0;
        for (int j = 0; j < n; j++) {
            if (i == 0) {
                if (stop_row) {
                    temp.push_back(0);
                    res = 0;
                }
                else if (obstacleGrid[i][j] == 1){
                    temp.push_back(0);
                    res = 0;
                    stop_row = true;
                }
                else {
                    temp.push_back(1);
                    res = 1;
                }
            }
            else if (j == 0) {
                if (stop_col) {
                    temp.push_back(0);
                    res = 0;
                }
                else if (obstacleGrid[i][j] == 1){
                    temp.push_back(0);
                    res = 0;
                    stop_col = true;
                }
                else {
                    temp.push_back(1);
                    res = 1;
                }
            }
            else if (obstacleGrid[i][j] == 0){
                res += temp_temp[j];
                temp.push_back(res);
            }
            else {
                res = 0;
                temp.push_back(0);
            }
        }
        temp_temp = temp;
    }
    return int(res);
}