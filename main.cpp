//
// Created by zyl on 2020/1/13.
//
#include "include/algorithms_data_structures.h"
#include "include/objects_oriented.h"

string reverseStr(const string& str) {
    string res;
    int start = str.size() - 1, end = str.size() - 1;
    while (end >= 0) {
        if (str[end] != ' ') break;
        end--;
    }
    start = end;
    int i = end;
    while (i >= 0) {
        if (end >= start) {
            if (str[i] != ' ') start--;
            else {
                res.insert(res.end(), str.begin() + start + 1, str.begin() + end + 1);
                res.push_back(' ');
                end = start;
                start++;
                i++;
            }
        } else {
            if (str[i] != ' ') {
                start = end;
                i++;
            }
            else end--;
        }
        i--;
    }
    if (str[0] != ' ') res.insert(res.end(), str.begin() + start + 1, str.begin() + end + 1);
    return res;
}


pair<int, int> numGood(int num, vector<int>& nums) {
    vector<pair<int, int>> dp(num, make_pair(0, 0));
    for (int i = 0; i < nums.size(); i++) {
        if (i == 0) dp[0] = make_pair(nums[0], 1);
        else if (i == 1) dp[1] = make_pair(max(nums[0], nums[1]), 1);
        else {
            int temp = dp[i - 2].first + nums[i];
            if (temp > dp[i - 1].first) {
                dp[i].first = temp;
                dp[i].second = dp[i - 2].second + 1;
            } else if (temp == dp[i - 1].first) {
                dp[i].first = temp;
                dp[i].second = min(1 + dp[i - 2].second, dp[i - 1].second);
            } else {
                dp[i] = dp[i - 1];
            }
        }
    }
    return dp[num - 1];
}

int numMagic(int N, int T, int M, vector<int>& H) {


    return -1;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    Solution solution;

    vector<int> test = {-8};
    int res = solution.subarraysDivByK(test, 6);

    return 0;
}
