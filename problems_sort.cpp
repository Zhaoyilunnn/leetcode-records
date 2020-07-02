//
// Created by zyl on 2020/6/29.
//

#include "function_defs.h"

void fastSort(vector<int>& nums, int low, int high) {
    if (low >= high)
        return;
    int i = low;
    int j = high;
    int key = nums[low];
    while (i < j) {
        while (i < j && nums[j] >= key)
            j--;
        nums[i] = nums[j];
        while (i < j && nums[i] < key)
            i++;
        nums[j] = nums[i];
    }
    nums[i] = key;
    fastSort(nums, low, i-1);
    fastSort(nums, i+1, high);
}

vector<int> Solution::sortArray(vector<int> &nums) {
    if (nums.empty())
        return {};
    if (nums.size() == 1)
        return nums;
    fastSort(nums, 0, (int)nums.size()-1);
    return nums;
}


/*******************************************************************/
/*
 * Kth Largest Element in an Array
 * --> heap sort!!
 * */
/*******************************************************************/
int Solution::findKthLargest(vector<int> &nums, int k) {
    // first build a heap, start from the last parent node, i.e nums[k / 2 - 1]
    int p = k / 2 - 1;
    while (p >= 0) {
        int i = p;
        // float down the node
        while (true) {
            int smallest = i;
            if (2 * i + 1 < k && nums[2 * i + 1] < nums[i]) smallest = 2 * i + 1;
            if (2 * i + 2 < k && nums[2 * i + 2] < nums[smallest]) smallest = 2 * i + 2;
            if (smallest != i) {
                int temp = nums[i];
                nums[i] = nums[smallest];
                nums[smallest] = temp;
                i = smallest;
            } else break;
            if (i >= k - 2) break;
        }
        p--;
    }

    // update the heap from nums[k]
    for (int j = k; j < nums.size(); j++) {
        if (nums[j] > nums[0]) {
            // found element larger than the top of small heap
            nums[0] = nums[j];
            int i = 0;
            while (true) {
                int smallest = i;
                if (2 * i + 1 < k && nums[2 * i + 1] < nums[i]) smallest = 2 * i + 1;
                if (2 * i + 2 < k && nums[2 * i + 2] < nums[smallest]) smallest = 2 * i + 2;
                if (smallest != i) {
                    int temp = nums[i];
                    nums[i] = nums[smallest];
                    nums[smallest] = temp;
                    i = smallest;
                } else break;
                if (i >= k - 2) break;
            }
        }
    }
    return nums[0];
}


/************************************************************************************/
/*
 * Description: Given a n x n matrix where each of the rows and columns are sorted
 * in ascending order, find the kth smallest element in the matrix. Note that it is
 * the kth smallest element in the sorted order, not the kth distinct element.
 *
 * Solutions: 1. Just like heap sort
 *            2. TODO: binary search
 *            3. priority queue
 * */
/************************************************************************************/
struct point {
    int val;  // element value
    int x;  // row position
    int y;  // column position
    point(int val, int x, int y) : val(val), x(x), y(y) {}
    bool operator> (const point& a) const { return this->val > a.val; }
};

int Solution::kthSmallest(vector<vector<int> > &matrix, int k) {
    int n = matrix.size();
    priority_queue<point, vector<point>, greater<point>> que;
    for (int i = 0; i < n; i++) {
        que.emplace(matrix[i][0], i, 0);
    }
    for (int i = 0; i < k - 1; i++) {
        int x = que.top().x;
        int y = que.top().y;
        que.pop();
        if (y < n - 1) {
            que.emplace(matrix[x][y + 1], x, y + 1);
        }
    }
    return que.top().val;
}
