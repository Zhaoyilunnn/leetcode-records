//
// Created by zyl on 2020/4/8.
//

#include "include/algorithms_data_structures.h"


/********************************************************************************/
/* Description: 地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。一个机器人从
 * 坐标 [0, 0] 的格子开始移动，它每次可以向左、右、上、下移动一格（不能移动到方格外），
 * 也不能进入行坐标和列坐标的数位之和大于k的格子。例如，当k为18时，机器人能够进入
 * 方格 [35, 37] ，因为3+5+3+7=18。但它不能进入方格 [35, 38]，因为3+5+3+8=19。
 * 请问该机器人能够到达多少个格子？
 *
 * Naive solution: BFS */
/********************************************************************************/
int Solution::movingCount(int m, int n, int k) {
    if (k == 0)
        return 1;
    queue<pair<int, int>> stores;
    stores.push(make_pair(0, 0));
    vector<vector<int>> direction = {{1, 0},
                                    {0, 1},
                                    {-1, 0},
                                    {0, -1}};
    vector<int> init(n, 0);
    vector<vector<int>> visited(m, init);
    visited[0][0] = 1;
    int count = 0;
    while (!stores.empty()) {
        int size = stores.size();
        for (int i = 0; i < size; i++) {
            int x = stores.front().first;
            int y = stores.front().second;
            for (auto j : direction) {
                int h = x + j[0];
                int l = y + j[1];
                if (h >= 0 && h <= m-1 && l >= 0 && l <= n-1) {
                    if ((h % 10 + (h - h % 10) / 10 + l % 10 + (l - l % 10) / 10 <= k) && !visited[h][l])
                        stores.push(make_pair(h, l));
                    visited[h][l] = 1;
                }
            }
            stores.pop();
            count++;
        }
    }
    return count;
}