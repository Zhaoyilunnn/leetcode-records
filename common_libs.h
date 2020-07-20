//
// Created by zyl on 2020/7/19.
//

#ifndef LEETCODE_RECORD_COMMON_LIBS_H
#define LEETCODE_RECORD_COMMON_LIBS_H

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <queue>
#include <map>
#include <stack>
#include <numeric>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <cmath>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

#endif //LEETCODE_RECORD_COMMON_LIBS_H
