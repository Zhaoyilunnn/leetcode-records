//
// Created by zyl on 2020/4/2.
//

#include "algorithms_data_structures.h"

/**************************************************************************/
/* Description: Given a board with m by n cells, each cell has an initial
 * state live (1) or dead (0). Each cell interacts with its eight neighbors
 * (horizontal, vertical, diagonal) using the following four rules (taken
 * from the above Wikipedia article):
 *
 * Any live cell with fewer than two live neighbors dies, as if caused
 * by under-population.
 * Any live cell with two or three live neighbors lives on to the next
 * generation.
 * Any live cell with more than three live neighbors dies, as if by
 * over-population..
 * Any dead cell with exactly three live neighbors becomes a live cell,
 * as if by reproduction.*/
/**************************************************************************/
void Solution::gameOfLife(vector<vector<int> > &board) {
    vector<vector<int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1},
                                      {1, -1}, {1, 1}, {-1, 1}, {-1, -1}};
    vector<vector<int>> prev = board;
    int m = board.size();
    int n = board[0].size();
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int live = 0;
            for (auto direct : directions) {
                int x = i + direct[0];
                int y = i + direct[1];
                if (0 <= x && x <= m-1 && y >= 0 && y <= n-1) {
                    if (prev[x][y])
                        live++;
                }
            }
            if ((live < 2 || live > 3) && board[i][j])
                board[i][j] = 0;
            if (live == 3 && !board[i][j])
                board[i][j] = 1;
        }
    }
}