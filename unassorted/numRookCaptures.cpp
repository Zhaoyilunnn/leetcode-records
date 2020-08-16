//
// Created by zyl on 2020/3/26.
//

#include "include/algorithms_data_structures.h"


/******************************************************************************/
/* To do: 使用方向数组进行优化 */
/******************************************************************************/
int Solution::numRookCaptures(vector<vector<char> > &board) {
    int i = 0;
    int j = 0;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            if (board[i][j] == 'R')
                break;
        }
        if (j != 8)
            break;
    }
    int res = 0;
    if (i > 0) {
        for (int m = i-1; m >= 0; m--) {
            if (board[m][j] == 'B')
                break;
            if (board[m][j] == 'p') {
                res++;
                break;
            }
        }
    }
    if (i < 7) {
        for (int m = i+1; m < 8; m++) {
            if (board[m][j] == 'B')
                break;
            if (board[m][j] == 'p') {
                res++;
                break;
            }
        }
    }
    if (j > 0) {
        for (int m = j-1; m >= 0; m--) {
            if (board[i][m] == 'B')
                break;
            if (board[i][m] == 'p') {
                res++;
                break;
            }
        }
    }
    if (j < 7) {
        for (int m = j+1; m < 8; m++) {
            if (board[i][m] == 'B')
                break;
            if (board[i][m] == 'p') {
                res++;
                break;
            }
        }
    }
    return res;
}