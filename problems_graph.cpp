//
// Created by zyl on 2020/3/26.
//

#include "include/algorithms_data_structures.h"

/************************************************/
/* Given the total number of course lists and
 * prerequisite course, is it possible to
 * finish all the courses */
/************************************************/
bool Solution::canFinish(int numCourses, vector<vector<int> > &prerequisites) {
    vector<int> init_vec;
    pair<int, vector<int>> init_pair = make_pair(0, init_vec);
    vector<pair<int, vector<int>>> pre_course(numCourses, init_pair);
    stack<int> non_pre; // store the courses that currently with no prerequisites
    for (auto prerequisite : prerequisites) {
        pre_course[prerequisite[1]].first++;
        pre_course[prerequisite[0]].second.push_back(prerequisite[1]);
    }
    for (int i = 0; i < pre_course.size(); i++) {
        if (pre_course[i].first == 0)
            non_pre.push(i);
    }
    int count = 0;
    while (!non_pre.empty()) {
        int top = non_pre.top();
        non_pre.pop();
        count++;
        for (int i : pre_course[top].second) {
            pre_course[i].first--;
            if (pre_course[i].first == 0)
                non_pre.push(i);
        }
    }
    return count == numCourses;
}


/******************************************************************************/
/*
 * Description: Given the total number of courses and a list of prerequisite
 * pairs, return the ordering of courses you should take to finish all courses.
 * */
/******************************************************************************/
vector<int> Solution::findOrder(int numCourses, vector<vector<int> > &prerequisites) {
    vector<int> order;

    /* first build graph */
    vector<pair<int, vector<int>>> graph(numCourses, make_pair(0, vector<int>()));  // first is input
    // number, second is courses that depend on it
    for (vector<int>& depend : prerequisites) {
        graph[depend[0]].first++;
        graph[depend[1]].second.push_back(depend[0]);
    }

    // Using a queue to store nodes whose input is zero
    queue<int> nodes;
    for (int i = 0; i < graph.size(); i++) {
        if (graph[i].first == 0) nodes.push(i);
    }
    while (!nodes.empty()) {
        int size = nodes.size();
        for (int i = 0; i < size; i++) {
            int node = nodes.front();
            order.push_back(node);
            for (int course : graph[node].second) {
                graph[course].first--;
                if (graph[course].first == 0) nodes.push(course);
            }
            nodes.pop();
        }
    }
    if (order.size() != numCourses) order.clear();
    return order;
}


/**
 * https://leetcode-cn.com/problems/redundant-connection-ii/
 * rooted tree -> 一个顶点入度为0，其余为1
 * @param edges
 * @return
 */
vector<int> Solution::findRedundantDirectedConnection(vector<vector<int>> &edges) {
    int nodesCount = edges.size();
    UnionFind uf = UnionFind(nodesCount + 1);
    auto parent = vector<int>(nodesCount + 1);
    for (int i = 1; i <= nodesCount; ++i) {
        parent[i] = i;
    }
    int conflict = -1;
    int cycle = -1;
    for (int i = 0; i < nodesCount; ++i) {
        auto edge = edges[i];
        int node1 = edge[0], node2 = edge[1];
        if (parent[node2] != node2) {
            conflict = i;
        } else {
            parent[node2] = node1;
            if (uf.find(node1) == uf.find(node2)) {
                cycle = i;
            } else {
                uf.merge(node1, node2);
            }
        }
    }
    if (conflict < 0) {
        auto redundant = vector<int> {edges[cycle][0], edges[cycle][1]};
        return redundant;
    } else {
        auto conflictEdge = edges[conflict];
        if (cycle >= 0) {
            auto redundant = vector<int> {parent[conflictEdge[1]], conflictEdge[1]};
            return redundant;
        } else {
            auto redundant = vector<int> {conflictEdge[0], conflictEdge[1]};
            return redundant;
        }
    }
}