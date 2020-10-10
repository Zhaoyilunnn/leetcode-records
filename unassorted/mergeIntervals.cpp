//
// Created by zyl on 2020/4/16.
//

#include "include/algorithms_data_structures.h"

/*****************************************************************************/
/* Description: Given a collection of intervals, merge all overlapping
 * intervals */
/*****************************************************************************/
vector<vector<int>> Solution::merge(vector<vector<int> > &intervals) {
    if (intervals.empty()) return {};
    vector<vector<int>> merged;
    sort(intervals.begin(), intervals.end());
    int start = intervals[0][0];
    int end = intervals[0][0];
    for (auto & interval : intervals) {
        if (interval[0] <= end) {
            end = interval[1] > end ? interval[1] : end;
        } else {
            merged.push_back({start, end});
            start = interval[0];
            end = interval[1];
        }
    }
    merged.push_back({start, end});
    return merged;
}