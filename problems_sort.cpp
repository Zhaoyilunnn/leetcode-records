//
// Created by zyl on 2020/6/29.
//

#include "include/algorithms_data_structures.h"

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


/**
 * https://leetcode-cn.com/problems/top-k-frequent-elements/
 * TODO: review priority queue
 * @param nums
 * @return
 */
class mycompare {
public:
    bool operator() (const pair<int, int>& lhs, const pair<int, int>& rhs) const {
        return lhs.second < rhs.second;
    }
};


vector<int> Solution::topKFrequent(vector<int> &nums, int k) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, mycompare> store;
    unordered_map<int, int> occurrence;
    for (int i : nums) {
        occurrence[i]++;
    }
    for (auto o : occurrence) {
        store.emplace(o.first, o.second);
    }
    vector<int> res;
    for (int i = 0; i < k; i++) {
        res.push_back(store.top().first);
        store.pop();
    }
    return res;
}


/**
 * https://leetcode-cn.com/problems/4sum/
 * @param nums
 * @param target
 * @return
 */
vector<vector<int>> Solution::fourSum(vector<int> &nums, int target) {
    if(nums.size() < 4)
        return {};
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    for(int first = 0; first < nums.size()-3; first++){
        if(first > 0 && nums[first] == nums[first-1])
            continue;
        for(int second = first+1; second < nums.size() - 2; second++){
            if(second > first+1 && nums[second] == nums[second-1])
                continue;
            int third = second+1;
            int forth = nums.size()-1;
            while(third<forth){
                int temp = nums[first] + nums[second] + nums[third] + nums[forth];
                if(temp == target){
                    ans.push_back({nums[first], nums[second], nums[third], nums[forth]});
                    while(third+1<forth && nums[third] == nums[third+1])
                        third++;
                    while(forth-1>third && nums[forth] == nums[forth-1])
                        forth--;
                    third++;
                    forth--;
                }
                else if(temp<target)
                    third++;
                else
                    forth--;
            }
        }
    }
    return ans;
}


/**
 * https://leetcode-cn.com/problems/sort-colors/
 * Solution: 1. Sort
 *           2. single pointer
 *           3. double pointer
 * @param nums
 */
void sortColorFast(vector<int>& nums, int l, int r) {
    if (l >= r) return;
    int i = l, j = r, key = nums[l];
    while (i < j) {
        while (nums[j] > key && i < j) {
            j--;
        }
        if (i < j) {
            nums[i] = nums[j];
            i++;
        }
        while (nums[i] <= key && i < j) {
            i++;
        }
        if (i < j) {
            nums[j] = nums[i];
            j--;
        }
    }
    nums[i] = key;
    sortColorFast(nums, l, i - 1);
    sortColorFast(nums, i + 1, r);
}

void Solution::sortColors(vector<int> &nums) {
    /* Fast sort */
    /*int l = 0, r = (int) nums.size() - 1;
    sortColorFast(nums, l, r);*/

    /* single pointers */
    /*int i = 0, j = (int) nums.size() - 1;
    while (i < j) {
        while (nums[j] == 2 && i < j) j--;
        while (nums[i] != 2 && i < j) i++;
        if (i < j) {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
    }
    i = 0, j = (int) nums.size() - 1;
    while (i < j) {
        while (nums[j] >= 1 && i < j) j--;
        while (nums[i] != 1 && i < j) i++;
        if (i < j) {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
    }*/

    /* double pointer (three-way partition) */
    int i = 0, j = 0, k = (int) nums.size() - 1;
    while (j < k + 1) {
        if (nums[j] < 1) {
            swap(nums[j], nums[i]);
            i++;
            j++;
        } else if (nums[j] > 1) {
            swap(nums[j], nums[k]);
            k--;
        } else j++;
    }
}


/**
 * https://leetcode-cn.com/problems/squares-of-a-sorted-array/
 * @param A
 * @return
 */
vector<int> Solution::sortedSquares(vector<int> &A) {
    int n = A.size();
    vector<int> ans(n);
    for (int i = 0, j = n - 1, pos = n - 1; i <= j;) {
        if (A[i] * A[i] > A[j] * A[j]) {
            ans[pos] = A[i] * A[i];
            ++i;
        }
        else {
            ans[pos] = A[j] * A[j];
            --j;
        }
        --pos;
    }
    return ans;
}

/**
 * https://leetcode-cn.com/problems/sort-array-by-parity-ii/
 * @param A
 * @return
 */
vector<int> Solution::sortArrayByParityII(vector<int> &A) {
    int n = A.size();
    int j = 1;
    for (int i = 0; i < n; i += 2) {
        if (A[i] % 2 == 1) {
            while (A[j] % 2 == 1) {
                j += 2;
            }
            swap(A[i], A[j]);
        }
    }
    return A;
}