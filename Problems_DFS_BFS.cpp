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


/**************************************************************************************/
/* First solution:   BFS
 *                   1. Process special situation
 *                   2. Use a vector to store cases, cases[0] and cases[sum] is 1
 *                      Other is 2
 *                   3. Start BFS, use a queue to store results, queue element is
 *                      pair<int, int> that store current case
 *                   4. The branches of BFS search including several different
 *                      situations
 * Optimization:     solve a solution: a*x + b*y = z, in which a and b are integers and
 *                   a*x and b*y are less than common multiple of x,y*/
/**************************************************************************************/
bool Solution::canMeasureWater(int x, int y, int z) {
    if (z > x+y)
        return false;
    int large = 0;
    int small = 0;
    int b = 0;
    if (x > y) {
        large = x;
        small = y;
    } else {
        large = y;
        small = x;
    }
    while ((b*large-z) % small != 0) {
        b++;
        if (b*large % small == 0)
            return false;
    }
    return true;
}


/**************************************************************************/
/* Description: Given an N x N grid containing only values 0 and 1,
 * where 0 represents water and 1 represents land, find a water
 * cell such that its distance to the nearest land cell is maximized
 * and return the distance. The distance used in this problem is
 * the Manhattan distance: the distance between two cells
 * (x0, y0) and (x1, y1) is |x0 - x1| + |y0 - y1|.
 * If no land or water exists in the grid, return -1.
 *
 * Solution 1:  BFS,
 *              1. Find positions that contain 1 and push them into queue
 *              2. Find four directions, if any unvisited, push them
 * Solution 2:  How to optimize? */
/**************************************************************************/
int Solution::maxDistance(vector<vector<int> > &grid) {
    queue<pair<int, int>> positions;
    int N = grid.size();
    vector<int> init(N, 0);
    vector<vector<int>> visited(N, init);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j]) {
                positions.push(make_pair(i, j));
                visited[i][j] = 1;
            }
        }
    }
    int res = 0;
    while (!positions.empty()) {
        int size = positions.size();
        bool flag = false;
        for (int i = 0; i < size; i++) {
            pair<int, int> position = positions.front();
            int m = position.first;
            int n = position.second;
            if (m > 0 && !visited[m-1][n]) {
                flag = true;
                visited[m-1][n] = 1;
                positions.push(make_pair(m-1, n));
            }
            if (m < N-1 && !visited[m+1][n]) {
                flag = true;
                visited[m+1][n] = 1;
                positions.push(make_pair(m+1, n));
            }
            if (n > 0 && !visited[m][n-1]) {
                flag = true;
                visited[m][n-1] = 1;
                positions.push(make_pair(m, n-1));
            }
            if (n < N-1 && !visited[m][n+1]) {
                flag = true;
                visited[m][n+1] = 1;
                positions.push(make_pair(m, n+1));
            }
            positions.pop();
        }
        if (flag) res++;
    }
    if (!res)
        return -1;
    else
        return res;
}
