//
// Created by zyl on 2020/6/10.
//

#include "include/algorithms_data_structures.h"


/*************************************************************************/
/*
 * Description: Determine whether an integer is a palindrome
 * */
/*************************************************************************/
bool Solution::isPalindrome(int x) {
    if (x < 0) return false;
    if (x / 10 == 0) return true;
    int div = 10;
    while (x / div >= 10) {
        div *= 10;
    }
    while (div >= 10) {
        int first = x / div;
        int second = x % 10;
        if (first != second) return false;
        x -= (first * div + second);
        x /= 10;
        div /= 100;
    }
    return true;
}