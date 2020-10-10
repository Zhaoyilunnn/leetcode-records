//
// Created by zyl on 2020/4/10.
//

#include "include/algorithms_data_structures.h"

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


/****************************************************************/
/*
 * Description: Given a non-empty string s, you may delete at
 * most one character. Judge whether you can make it a palindrome.
 * */
/****************************************************************/
bool flag = false;

bool Solution::validPalindrome(const string& s) {
    int last_pos = (int)s.size() - 1;
    int i = 0;
    while (i < last_pos - i) {
        if (s[i] != s[last_pos - i]) {
            if (flag) return false;
            flag = true;
            if (s[i + 1] == s[last_pos - i] && validPalindrome(s.substr(i + 1, last_pos - 2 * i)))
                return true;
            else if (s[i] == s[last_pos - i - 1]) {
                return validPalindrome(s.substr(i, last_pos - 2 * i));
            }
        }
        i++;
    }
    return true;
}


/**
 * https://leetcode-cn.com/problems/n-queens/
 * @param n
 * @return
 */
bool isValid(int n, int rowIndex, int colIndex, vector<string>& cur_res) {
    for (int i = 0; i < rowIndex; i++) {
        if (cur_res[i][colIndex] == 'Q') return false;
    }
    for (int i = rowIndex - 1, j = colIndex - 1; i >= 0 && j >= 0; i--, j--) {
        if (cur_res[i][j] == 'Q') return false;
    }
    for (int i = rowIndex - 1, j = colIndex + 1; i >= 0 && j < n; i--, j++) {
        if (cur_res[i][j] == 'Q') return false;
    }
    return true;
}


void helper(int n, int rowIndex, vector<string>& cur_res, vector<vector<string>>& res) {
    if (rowIndex == n) {
        res.push_back(cur_res);
        return;
    }
    for (int i = 0; i < n; i++) {
        if (isValid(n, rowIndex, i, cur_res)) {
            cur_res[rowIndex][i] = 'Q';
            helper(n, rowIndex + 1, cur_res, res);
            cur_res[rowIndex][i] = '.';
        }
    }
}

vector<vector<string>> Solution::solveNQueens(int n) {
    vector<vector<string>> res;
    vector<string> cur_res(n, string(n, '.'));
    helper(n, 0, cur_res, res);
    return res;
}

