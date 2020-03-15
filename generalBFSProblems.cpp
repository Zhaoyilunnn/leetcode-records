//
// Created by zyl on 2020/3/14.
//

#include "function_defs.h"

bool findNewNode(vector<vector<char> > &grid, vector<vector<int> > &visited, pair<int, int> &p) {
    pair<int, int> result;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            if (grid[i][j] == '1' && visited[i][j] == 0) {
                p = make_pair(i, j);
                visited[i][j] = 1;
                return true;
            }
        }
    }
    return false;
}

int Solution::numIsLands(vector<vector<char> > &grid) {
    if (grid.empty())
        return 0;
    queue<pair<int, int>> q;
    vector<int> zeros(grid[0].size(), 0);
    vector<vector<int>> visited(grid.size(), zeros);
    int result = 0;
    while (true) {
        if (q.empty()) {
            pair<int, int> p;
            if (findNewNode(grid, visited, p))
                q.push(p);
            else
                break;
        }
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int m = q.front().first;
                int n = q.front().second;
                pair<int, int> p;
                if (m > 0) {
                    if (grid[m-1][n] == '1' && visited[m-1][n] == 0) {
                        p = make_pair(m-1, n);
                        q.push(p);
                        visited[m-1][n] = 1;
                    }
                }
                if (m < grid.size()-1) {
                    if (grid[m+1][n] == '1' && visited[m+1][n] == 0) {
                        p = make_pair(m+1, n);
                        q.push(p);
                        visited[m+1][n] = 1;
                    }
                }
                if (n > 0) {
                    if (grid[m][n-1] == '1' && visited[m][n-1] == 0) {
                        p = make_pair(m, n-1);
                        q.push(p);
                        visited[m][n-1] = 1;
                    }
                }
                if (n < grid[0].size()-1) {
                    if (grid[m][n+1] == '1' && visited[m][n+1] == 0) {
                        p = make_pair(m, n+1);
                        q.push(p);
                        visited[m][n+1] = 1;
                    }
                }
                q.pop();
            }
        }
        result++;
    }
    return result;
}


bool findNewNodePro(vector<vector<int> > &grid, vector<vector<int> > &visited, pair<int, int> &p) {
    pair<int, int> result;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            if (grid[i][j] == 1 && visited[i][j] == 0) {
                p = make_pair(i, j);
                visited[i][j] = 1;
                return true;
            }
        }
    }
    return false;
}

int Solution::maxAreaOfIsland(vector<vector<int> > &grid) {
    if (grid.empty())
        return 0;
    queue<pair<int, int>> q;
    vector<int> zeros(grid[0].size(), 0);
    vector<vector<int>> visited(grid.size(), zeros);
    int result = 0;
    int temp_result = 0;
    while (true) {
        temp_result = 0;
        if (q.empty()) {
            pair<int, int> p;
            if (findNewNodePro(grid, visited, p))
                q.push(p);
            else
                break;
        }
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int m = q.front().first;
                int n = q.front().second;
                pair<int, int> p;
                if (m > 0) {
                    if (grid[m-1][n] == 1 && visited[m-1][n] == 0) {
                        p = make_pair(m-1, n);
                        q.push(p);
                        visited[m-1][n] = 1;
                    }
                }
                if (m < grid.size()-1) {
                    if (grid[m+1][n] == 1 && visited[m+1][n] == 0) {
                        p = make_pair(m+1, n);
                        q.push(p);
                        visited[m+1][n] = 1;
                    }
                }
                if (n > 0) {
                    if (grid[m][n-1] == 1 && visited[m][n-1] == 0) {
                        p = make_pair(m, n-1);
                        q.push(p);
                        visited[m][n-1] = 1;
                    }
                }
                if (n < grid[0].size()-1) {
                    if (grid[m][n+1] == 1 && visited[m][n+1] == 0) {
                        p = make_pair(m, n+1);
                        q.push(p);
                        visited[m][n+1] = 1;
                    }
                }
                q.pop();
                temp_result++;
            }
        }
        if (temp_result > result)
            result = temp_result;
    }
    return result;
}


int Solution::islandPerimeter(vector<vector<int> > &grid) {
    queue<pair<int, int>> q;
    vector<int> zeros(grid[0].size(), 0);
    vector<vector<int>> visited(grid.size(), zeros);
    pair<int, int> p;
    int result = 4;
    if (findNewNodePro(grid, visited, p))
        q.push(p);
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            int m = q.front().first;
            int n = q.front().second;
            if (m > 0) {
                if (grid[m-1][n] == 1 && visited[m-1][n] == 0) {
                    p = make_pair(m-1, n);
                    q.push(p);
                    visited[m-1][n] = 1;
                    result += 2;
                }
            }
            if (m < grid.size()-1) {
                if (grid[m+1][n] == 1 && visited[m+1][n] == 0) {
                    p = make_pair(m+1, n);
                    q.push(p);
                    visited[m+1][n] = 1;
                    result += 2;
                }
            }
            if (n > 0) {
                if (grid[m][n-1] == 1 && visited[m][n-1] == 0) {
                    p = make_pair(m, n-1);
                    q.push(p);
                    visited[m][n-1] = 1;
                    result += 2;
                }
            }
            if (n < grid[0].size()-1) {
                if (grid[m][n+1] == 1 && visited[m][n+1] == 0) {
                    p = make_pair(m, n+1);
                    q.push(p);
                    visited[m][n+1] = 1;
                    result += 2;
                }
            }
            q.pop();
        }
    }
    return result;
}


int Solution::orangesRotting(vector<vector<int>>& grid) {
    vector<vector<int>> temp = grid;
    bool flag = true;
    int m = grid.size();
    int n = grid[0].size();
    int time = 0;
    while (flag) {
        time++;
        flag = false;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (temp[i][j] == 2) {
                    if (i > 0) {
                        if (temp[i-1][j] == 1) {
                            grid[i-1][j] = 2;
                            flag = true;
                        }
                    }
                    if (i < m-1) {
                        if (temp[i+1][j] == 1) {
                            grid[i+1][j] = 2;
                            flag = true;
                        }
                    }
                    if (j > 0) {
                        if (temp[i][j-1] == 1) {
                            grid[i][j-1] = 2;
                            flag = true;
                        }
                    }
                    if (j < n-1) {
                        if (temp[i][j+1] == 1) {
                            grid[i][j+1] = 2;
                            flag = true;
                        }
                    }
                    grid[i][j] = -1;
                }
            }
        }
        temp = grid;
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1)
                return -1;
        }
    }
    return --time;
}
