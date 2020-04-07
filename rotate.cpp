//
// Created by zyl on 2020/4/7.
//

#include "function_defs.h"

/***********************************************************************/
/* Description: Given an image represented by an N X N matrix, where
 * each pixel in the image is 4 bytes, write a method to rotate the
 * image by 90 degree. Can you do this in place */
/***********************************************************************/
void Solution::rotate(vector<vector<int> > &matrix) {
    int n = matrix.size();
    vector<vector<int>> result = matrix;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            result[j][n - 1 - i] = matrix[i][j];
    }
    matrix = result;
}