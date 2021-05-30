//
// Created by zyl on 2020/1/13.
//
#include "include/algorithms_data_structures.h"
#include "include/objects_oriented.h"

extern ListNode* mergeTwoList(ListNode* head1, ListNode* head2);

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution solution;

    vector<vector<int>> grid = {{1,0,1}, {1,1,1}};
    vector<vector<int>> hits = {{0,0},{0,2},{1,1}};
    vector<int> res = solution.hitBricks(grid, hits);

    return 0;
}
