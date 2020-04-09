//
// Created by zyl on 2020/4/10.
//

#include "function_defs.h"

/***********************************************************************************************/
/* Description: Given n pairs of parentheses, write a function to generate all combinations
 * of well-formed parentheses
 *
 * */
/***********************************************************************************************/

void generate(vector<string>& result, string& curr_str, int& count1, int& count2, int n) {
    string str = curr_str;
    if (count1 > 0) {
        str += '(';
        int new_count1 = count1 - 1;
        generate(result, str, new_count1, count2, n);
    }
    str = curr_str;
    if (count2 > 0) {
        str += ')';
        int new_count2 = count2 - 1;
        if (count1 > new_count2)
            return;
        if (count1 == 0 && new_count2 == 0) {
            result.push_back(str);
            return;
        }
        generate(result, str, count1, new_count2, n);
    }
}

vector<string> Solution::generateParenthesis(int n) {
    vector<string> result;
    string curr_str;
    int count1 = n;
    int count2 = n;
    count1--;
    curr_str.push_back('(');
    generate(result, curr_str, count1, count2, n);
    return result;
}
