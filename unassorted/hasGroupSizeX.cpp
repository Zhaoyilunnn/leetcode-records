//
// Created by zyl on 2020/3/27.
//

#include "include/algorithms_data_structures.h"

/****************************************************************/
/* Description: In a deck of cards, each card has an
 * integer written on it, return true only if the
 * entire deck can be split into 1 or more groups of
 * cards where each group has exactly X cards and all
 * the cards in the same group has the same number
 *
 * Solution 1: count the number of each card, then find
 * all the possible group lengths and them find if any
 * group length can satisfy the requirements
 * Solution 2: to do --> how to find the greatest common
 * factor? --> use the gcd function from numeric library */
/***************************************************************/
bool Solution::hasGroupsSizeX(vector<int> &deck) {
    /*vector<int> num_cards(10000, 0);
    vector<int> index_cards;
    for (int i : deck) {
        if (num_cards[i] == 0)
            index_cards.push_back(i);
        num_cards[i]++;
    }
    int common = -1;
    int flag = true;
    while (flag) {
        flag = false;
        for (int i : index_cards) {
            if (common < 0)
                common = num_cards[i];
            else
                common = gcd(common, num_cards[i]);
        }
    }
    return common >= 2;*/

    return true;
}
