//
// Created by zyl on 2020/7/19.
//

#ifndef LEETCODE_RECORD_COMMON_LIBS_H
#define LEETCODE_RECORD_COMMON_LIBS_H

#include <iostream>
#include <utility>
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
#include <complex>

using namespace std;

#define PI acos(-1)
typedef complex<double> CP;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

struct ListNode {
    int val;
    ListNode* next;
    explicit ListNode(int x) : val(x), next(nullptr) {}
};


struct UnionFind {
    vector<int> ancestor;

    UnionFind(int n) {
        ancestor.resize(n);
        for (int i = 0; i < n; ++i) {
            ancestor[i] = i;
        }
    }

    int find(int index) {
        return index == ancestor[index] ? index : ancestor[index] = find(ancestor[index]);
    }

    void merge(int u, int v) {
        ancestor[find(u)] = find(v);
    }
};


class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }

    explicit Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = std::move(_neighbors);
    }
};

class dsp {
public:
    int reverseBit(int num, int count);

    void bitReverseCopy(vector<CP>& x, vector<CP>& X);

    vector<CP> dftNaive(vector<CP> &x);

    vector<CP> fftCooleyTukey(vector<CP> &x);
};
#endif //LEETCODE_RECORD_COMMON_LIBS_H
