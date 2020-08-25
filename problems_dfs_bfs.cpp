//
// Created by zyl on 2020/3/14.
//

#include "include/algorithms_data_structures.h"

void BFS(vector<vector<char>>& grid, int m, int n) {
    int nr = grid.size();
    int nc = grid[0].size();
    queue<pair<int, int>> q;
    vector<vector<int>> dirs = {{1, 0}, {0, 1},
                                {-1, 0}, {0, -1}};
    q.emplace(m, n);
    grid[m][n] = '0';
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            int x = q.front().first;
            int y = q.front().second;
            for (int j = 0; j < 4; j++) {
                int r = x + dirs[j][0];
                int c = y + dirs[j][1];
                if (r >= 0 && r <= nr - 1 && c >= 0 && c <= nc - 1 && grid[r][c] == '1') {
                    q.emplace(r, c);
                    grid[r][c] = '0';
                }
            }
            q.pop();
        }
    }
}

bool findNewNode(vector<vector<char> > &grid, vector<vector<int> > &visited, pair<int, int> &p, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
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
    int result = 0;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            if (grid[i][j] == '1') {
                BFS(grid, i, j);
                result++;
            }
        }
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


/***********************************************************************************************/
/* Description: Given a matrix consists of 0 and 1, find the distance of the nearest 0 for each
 * cell */
/***********************************************************************************************/
vector<vector<int>> Solution::updateMatrix(vector<vector<int> > &matrix) {
    vector<vector<int>> result = matrix;
    queue<pair<int, int>> distances;
    vector<vector<int>> direction = {{0, 1}, {1, 0},
                                     {-1, 0}, {0, -1}};
    int m = matrix.size();
    int n = matrix[0].size();

    // find 0 elements and initialize queue
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!matrix[i][j]) {
                distances.emplace(i, j);
                matrix[i][j] = -1;
            }
        }
    }

    // BFS
    while (!distances.empty()) {
        auto [a, b] = distances.front();
        distances.pop();
        int ref = result[a][b];
        for (auto direct: direction) {
            int c = a + direct[0];
            int d = b + direct[1];
            if (c >= 0 && c <= m - 1 && d >= 0 && d <= n-1 && matrix[c][d] > 0) {
                result[c][d] = ref + 1;
                matrix[c][d] = -1;
                distances.emplace(c, d);
            }
        }
    }

    return result;
}


/**
 * https://leetcode-cn.com/problems/surrounded-regions/
 * TODO: optimization
 *       1. find the 'O' that is on the border
 *       2. dfs/bfs the 'O' in the border and denote the path you traverse as "cannot be transformed to 'X' "
 *       3. traverse the matrix, change 'O' to 'X'
 * @param board
 */
void Solution::solve(vector<vector<char>> &board) {
    int m = board.size();
    int n = board[0].size();
    queue<pair<int, int>> store;
    vector<pair<int, int>> temp;
    vector<vector<int>> direct = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    vector<vector<int>> visited(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 'O' && !visited[i][j]) {
                temp.clear();
                store.emplace(i, j);
                visited[i][j] = 1;
                bool flag = false;
                while (!store.empty()) {
                    int size = store.size();
                    for (int k = 0; k < size; k++) {
                        int p = store.front().first;
                        int q = store.front().second;
                        if (p == 0 || p == m - 1 || q == 0 || q == n - 1) flag = true;
                        temp.emplace_back(p, q);
                        for (auto d : direct) {
                            int x = p + d[0], y = q + d[1];
                            if (x >= 0 && x < m && y >= 0 && y < n && board[x][y] == 'O' && !visited[x][y]) {
                                store.emplace(x, y);
                                visited[x][y] = 1;
                            }
                        }
                        store.pop();
                    }
                }
                if (!flag) {
                    for (auto t : temp) {
                        board[t.first][t.second] = 'X';
                    }
                }
            }
        }
    }
}


/**
 * https://leetcode-cn.com/problems/clone-graph/
 * TODO: implement DFS
 * @param node
 * @return
 */
Node* Solution::cloneGraph(Node *node) {
    if (!node) return nullptr;
    // BFS
    Node* new_node = new Node(node->val);
    queue<Node*> org_store;
    queue<Node*> new_store;
    org_store.push(node);
    unordered_map<Node*, Node*> correspond;
    new_store.push(new_node);
    correspond.emplace(node, new_node);
    while (!org_store.empty()) {
        int size = org_store.size();
        for (int i = 0; i < size; i++) {
            Node* org_node = org_store.front();
            Node* cur_node = new_store.front();
            for (int j = 0; j < org_node->neighbors.size(); j++) {
                auto it = correspond.find(org_node->neighbors[j]);
                if (it == correspond.end()) {
                    cur_node->neighbors.push_back(new Node(org_node->neighbors[j]->val));
                    org_store.push(org_node->neighbors[j]);
                    new_store.push(cur_node->neighbors[j]);
                    correspond.emplace(org_node->neighbors[j], cur_node->neighbors[j]);
                } else cur_node->neighbors.push_back(it->second);
            }
            org_store.pop();
            new_store.pop();
        }
    }
    return new_node;
}


/**
 * https://leetcode-cn.com/problems/remove-boxes/
 * TODO: Implement
 * @param boxes
 * @return
 */
int Solution::removeBoxes(vector<int> &boxes) {

}


/**
 * https://leetcode-cn.com/problems/flood-fill/
 * @param image
 * @param sr
 * @param sc
 * @param newColor
 * @return
 */

void dfs(vector<vector<int>>& image, int x, int y, int cur_color, int new_color) {
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int m = image.size(), n = image[0].size();
    for (auto d : directions) {
        int xx = x + d[0], yy = y + d[1];
        if (xx >= 0 && xx < m && yy >= 0 && yy < n && image[xx][yy] == cur_color) {
            image[xx][yy] = new_color;
            dfs(image, xx, yy, cur_color, new_color);
        }
    }
}

vector<vector<int>> Solution::floodFill(vector<vector<int>> &image, int sr, int sc, int newColor) {
    // BFS
    /*int init_pixel = image[sr][sc];
    if (init_pixel == newColor) return image;
    queue<pair<int, int>> store;
    store.emplace(sr, sc);
    vector<vector<int>> directs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    int m = image.size(), n = image[0].size();
    vector<vector<int>> visited(m, vector<int>(n, 0));
    image[sr][sc] = newColor;
    while (!store.empty()) {
        int size = store.size();
        for (int i = 0; i < size; i++) {
            int x = store.front().first, y = store.front().second;
            for (auto direct : directs) {
                int x_ = x + direct[0];
                int y_ = y + direct[1];
                if (x_ >= 0 && x_ < m && y_ >= 0 && y_ < n && image[x_][y_] == init_pixel) {
                    store.emplace(x_, y_);
                    image[x_][y_] = newColor;
                }
            }
            store.pop();
        }
    }
    return image;*/

    // DFS
    int cur_color = image[sr][sc];
    if (cur_color == newColor) return image;
    image[sr][sc] = newColor;
    dfs(image, sr, sc, cur_color, newColor);
    return image;
}


/**
 * https://leetcode-cn.com/problems/minesweeper/
 * @param board
 * @param click
 * @return
 */
vector<vector<char>> Solution::updateBoard(vector<vector<char>> &board, vector<int> &click) {
    if (board[click[0]][click[1]] == 'M') {
        board[click[0]][click[1]] = 'X';
        return board;
    }
    queue<pair<int, int>> store;
    store.emplace(click[0], click[1]);
    vector<vector<int>> directs = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}, {1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int m = board.size(), n = board[0].size();
    board[click[0]][click[1]] = '-';
    while (!store.empty()) {
        int size = store.size();
        for (int i = 0; i < size; i++) {
            int a = store.front().first, b = store.front().second;
            int num_mines = 0;
            vector<pair<int, int>> temp;
            for (auto d : directs) {
                int x = a + d[0], y = b + d[1];
                if (x >= 0 && x < m && y >= 0 && y < n) {
                    if (board[x][y] == 'M') {
                        num_mines++;
                    }
                    else if (board[x][y] == 'E' && num_mines == 0) temp.emplace_back(x, y);
                }
            }
            if (num_mines == 0) {
                board[a][b] = 'B';
                for (auto e : temp) {
                    store.emplace(e.first, e.second);
                    board[e.first][e.second] = '-';
                }
            } else board[a][b] = num_mines + '0';
            store.pop();
            temp.clear();
        }
    }
    return board;
}