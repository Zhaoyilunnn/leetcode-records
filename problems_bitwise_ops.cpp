//
// Created by zyl on 2020/4/28.
//

#include "algorithms_data_structures.h"


/*********************************************************/
/* Description: two number appear once, others appear twice
 * */
/*********************************************************/
vector<int> Solution::singleNumbers(vector<int> &nums) {
    int ret = 0;
    for (int i : nums) ret ^= i;
    int div = 1;
    while (!(div & ret)) div <<= 1;
    int a = 0, b = 0;
    for (int i : nums) {
        if (div & i) a ^= i;
        else b ^= i;
    }
    return vector<int>{a, b};
}