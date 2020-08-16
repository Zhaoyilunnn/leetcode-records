//
// Created by zyl on 2020/5/8.
//

#include "include/algorithms_data_structures.h"


/**********************************************************************/
/*
 * Description: Given a 2D binary matrix filled with 0 and 1, find
 * the largest square containing 1's and return its area
 *
 * To do: optimize using dp
 * */
/**********************************************************************/
bool isSquare(int row_pos, int col_pos, int len,  vector<vector<char>>& matrix) {
    for (int i = row_pos; i < row_pos + len; i++) {
        for (int j = col_pos; j < col_pos + len; j++) {
            if (matrix[i][j] != '1') return false;
        }
    }
    return true;
}

int Solution::maximalSquare(vector<vector<char> > &matrix) {
    if (matrix.empty()) return 0;
    int len = 0;
    int m = matrix.size(), n = matrix[0].size();
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            while (matrix[i][j] == '1' && i <= m - len - 1 && j <= n - len - 1) {
                if (isSquare(i, j, len + 1, matrix)) len++;
                else {
                    j += len;
                    break;
                }
            }
        }
    }
    return len * len;
}