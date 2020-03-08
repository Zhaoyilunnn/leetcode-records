//
// Created by zyl on 2020/3/8.
//

#include "function_defs.h"

void fastSort(vector<int>& coins) {
    if (coins.size() == 1 || coins.empty())
        return;
    vector<int> large;
    vector<int> small;
    int ref = coins[0];
    for (int i = 1; i < coins.size(); i++) {
        if (coins[i] >= ref)
            large.push_back(coins[i]);
        else
            small.push_back(coins[i]);
    }
    fastSort(large);
    fastSort(small);
    small.push_back(ref);
    small.insert(small.end(), large.begin(), large.end());
    coins = small;
}

int Solution::coinChange(vector<int>& coins, int amount) {
    if (coins.empty())
        return -1;
    fastSort(coins);
    vector<int> results;
    int result = 0;
    int temp = 0;
    for (int  i = 0;  i < amount+1; ++ i) {
        result = 0;
        if (i == 0) {
            results.push_back(result);
            continue;
        }
        result = -1;
        temp = 0;
        for (int coin : coins) {
            if (i - coin >= 0 && results[i - coin] >= 0) {
                temp = results[i - coin] + 1;
                if (result <= 0 || temp < result)
                    result = temp;
            }
        }
        results.push_back(result);
    }
    return results[results.size()-1];
}
