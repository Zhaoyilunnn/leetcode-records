//
// Created by zyl on 2020/3/14.
//

#include "function_defs.h"

bool findNewNode(vector<vector<char> > &grid, vector<vector<int> > &visited, pair<int, int> &p) {
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
                } else if (visited[m-1][n] == 1)
                    result -= 2;
            }
            if (m < grid.size()-1) {
                if (grid[m+1][n] == 1 && visited[m+1][n] == 0) {
                    p = make_pair(m+1, n);
                    q.push(p);
                    visited[m+1][n] = 1;
                    result += 2;
                } else if (visited[m+1][n] == 1)
                    result -= 2;
            }
            if (n > 0) {
                if (grid[m][n-1] == 1 && visited[m][n-1] == 0) {
                    p = make_pair(m, n-1);
                    q.push(p);
                    visited[m][n-1] = 1;
                    result += 2;
                } else if (visited[m][n-1] == 1)
                    result -= 2;
            }
            if (n < grid[0].size()-1) {
                if (grid[m][n+1] == 1 && visited[m][n+1] == 0) {
                    p = make_pair(m, n+1);
                    q.push(p);
                    visited[m][n+1] = 1;
                    result += 2;
                } else if (visited[m][n+1] == 1)
                    result -= 2;
            }
            q.pop();
            visited[m][n] = -1;
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

int Solution::openLock(vector<string> &deadends, string target) {
    int rot_time = 0;
    string begin_num = "0000";
    int isvisit[10000] = {0};
    queue<string>num_path;
    num_path.push(begin_num);
    isvisit[0] = 1;
    //把deadends中的数设置成无法访问
    for(auto & deadend : deadends){
        int index = (deadend[0]-'0')*1000 + (deadend[1]-'0')*100 + (deadend[2]-'0')*10 + (deadend[3]-'0');
        isvisit[index] = 1;
    }
    string num_up;
    string num_down;
    while(!num_path.empty()){
        num_up = num_path.front();
        num_down = num_path.front();
        for(int i=0;i<4;i++){
            if(num_up[i]=='9'){
                num_up[i] = '0';
            }
            else
            {
                num_up[i] += 1;
            }
            if(num_down[i]=='0'){
                num_down[i] = '9';
            }
            else
            {
                num_down[i] -= 1;
            }
            if(num_up == target || num_down == target){
                rot_time++;
                return rot_time;
            }
            //转换成数字,num_up、num_down为字符串
            int num_upint = (num_up[0]-'0')*1000 + (num_up[1]-'0')*100 + (num_up[2]-'0')*10 + (num_up[3]-'0');
            int num_downint = (num_down[0]-'0')*1000 + (num_down[1]-'0')*100 + (num_down[2]-'0')*10 +(num_down[3]-'0');
            if(isvisit[num_upint]==0){
                num_path.push(num_up);
            }
            if(isvisit[num_downint]==0){
                num_path.push(num_down);
            }
            num_path.pop();
        }
        rot_time++;
    }
    return -1;
}
