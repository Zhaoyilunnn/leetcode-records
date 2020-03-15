//
// Created by zyl on 2020/3/15.
//

#include "function_defs.h"

vector<int> Solution::luckyNumbers(vector<vector<int> > &matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    vector<int> min_rows(m, 0);
    vector<int> max_columns(n, 0);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (j == 0)
                min_rows[i] = matrix[i][j];
            if (i == 0)
                max_columns[j] = matrix[i][j];
            if (matrix[i][j] < min_rows[i])
                min_rows[i] = matrix[i][j];
            if (matrix[i][j] > max_columns[j])
                max_columns[j] = matrix[i][j];
        }
    }
    vector<int> result;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (min_rows[i] == max_columns[j])
                result.push_back(matrix[i][j]);
        }
    }
    return result;
}
