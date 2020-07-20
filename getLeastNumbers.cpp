//
// Created by zyl on 2020/3/20.
//

#include "algorithms_data_structures.h"

/*To summarize*/
vector<int> Solution::getLeastNumbers(vector<int> &arr, int k) {
    if (arr.empty() || k > arr.size() || k == 0)
        return {};
    // Build a heap, small on top
    int p = arr.size()/2 - 1;
    while (p >= 0) {
        int n = p;
        while (n < arr.size()-1) {
            if (2 * n + 2 <= arr.size() - 1) {
                if (arr[2 * n + 2] <= arr[2 * n + 1] && arr[2 * n + 2] <= arr[n]) {
                    int temp = arr[2 * n + 2];
                    arr[2 * n + 2] = arr[n];
                    arr[n] = temp;
                    n = 2*n+2;
                } else if (arr[2 * n + 1] <= arr[n]) {
                    int temp = arr[2 * n + 1];
                    arr[2 * n + 1] = arr[n];
                    arr[n] = temp;
                    n = 2*n+1;
                } else
                    break;
            } else if (2*n+1 < arr.size() && arr[2 * n + 1] <= arr[n]) {
                int temp = arr[2 * n + 1];
                arr[2 * n + 1] = arr[n];
                arr[n] = temp;
                n = 2 * n + 1;
            } else
                break;
        }
        p--;
    }
    int count = 0;
    vector<int> res;
    while (count < k) {
        res.push_back(arr[0]);
        arr[0] = arr[arr.size()-1];
        arr.pop_back();
        p = 0;
        while (true) {
            bool flag = false;
            int temp = 0;
            if (2*p + 2 < arr.size()) {
                if (arr[2*p+2] <= arr[2*p+1]) {
                    if (arr[2*p+2] <= arr[p]) {
                        flag = true;
                        temp = arr[2*p+2];
                        arr[2*p+2] = arr[p];
                        arr[p] = temp;
                        p = 2*p+2;
                    }
                } else {
                    if (arr[2*p+1] <= arr[p]) {
                        flag = true;
                        temp = arr[2*p+1];
                        arr[2*p+1] = arr[p];
                        arr[p] = temp;
                        p = 2*p+1;
                    }
                }
            } else if (2*p+1 < arr.size() && arr[2*p+1] <= arr[p]) {
                flag = true;
                temp = arr[2*p+1];
                arr[2*p+1] = arr[p];
                arr[p] = temp;
                p = 2*p+1;
            }
            if (!flag)
                break;
        }
        count++;
    }
    return res;
}
