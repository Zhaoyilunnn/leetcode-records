//
// Created by zyl on 2020/4/12.
//

#include "include/algorithms_data_structures.h"

/****************************************************************/
/* Description: Given two straight lines, computer their
 * intersection */
/****************************************************************/
vector<double> Solution::intersection(const vector<int> &start1, const vector<int> &end1, const vector<int> &start2,
                                      const vector<int> &end2) {
    auto l1 = (double)min(end1[0], start1[0]);
    auto r1 = (double)max(end1[0], start1[0]);
    auto l2 = (double)min(end2[0], start2[0]);
    auto r2 = (double)max(end2[0], start2[0]);
    auto d1 = (double)min(end1[1], start1[1]);
    auto h1 = (double)max(end1[1], start1[1]);
    auto d2 = (double)min(end2[1], start2[1]);
    auto h2 = (double)max(end2[1], start2[1]);
    double k1 = 0;
    double k2 = 0;
    double b1 = 0;
    double b2 = 0;
    double x = 0;
    double y = 0;

    // Both segment are not vertical
    if (start1[0] != end1[0] && start2[0] != end2[0]) {
        k1 = ((double)end1[1] - (double)start1[1]) / ((double)end1[0] - (double)start1[0]);
        k2 = ((double)end2[1] - (double)start2[1]) / ((double)end2[0] - (double)start2[0]);
        b1 = (double) end1[1] - k1 * (double) end1[0];
        b2 = (double) end2[1] - k2 * (double) end2[0];
        if (k1 == k2) {
            if (l1 > r2 || l2 > r1 || b1 != b2) return {};
            return {max(l1, l2), k1 * max(l1, l2) + b1};
        };
        x = (b2 - b1) / (k1 - k2);
        y = k1 * x + b1;
    }

    // First is vertical
    if (start1[0] == end1[0] && start2[0] != end2[0]) {
        x = start1[0];
        k2 = ((double)end2[1] - (double)start2[1]) / ((double)end2[0] - (double)start2[0]);
        b2 = (double) end2[1] - k2 * (double) end2[0];
        y = k2 * x + b2;
    }

    // Second is vertical
    if (start1[0] != end1[0] && start2[0] == end2[0]) {
        x = start2[0];
        k1 = ((double)end1[1] - (double)start1[1]) / ((double)end1[0] - (double)start1[0]);
        b1 = (double) end1[1] - k1 * (double) end1[0];
        y = k1 * x + b1;
    }

    // Both are vertical
    if (start1[0] == end1[0] && start2[0] == end2[0]) {
        if (d1 > h2 || d2 > h1 || l1 != l2) return {};
        x = start1[0];
        y = max(d1, d2);
    }

    if (x < l1 || x > r1 || x < l2 || x > r2 || y < d1 || y > h1 || y < d2 || y > h2)
        return {};
    return {x, y};
}