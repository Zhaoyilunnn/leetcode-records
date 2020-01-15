//
// Created by zyl on 2020/1/15.
//

#include "function_defs.h"

bool checkPal(string s) {
    int i = 0;
    while (i <= s.size()-i-1) {
        if (s[i] != s[s.size()-i-1])
            return false;
        i++;
    }
    return true;
}

string Solution::longestPalindrome(string s) {
    if (s.empty())
        return "";
    vector<string> res;
    int temp = 0;
    for (int i = 0; i < s.size(); i++) {
        if (i == 0)
            res.push_back(s.substr(0, 1));
        else if (i == 1) {
            if (s[i] == s[0])
                res.push_back(s.substr(0, 2));
            else
                res.push_back(s.substr(1, 1));
        }
        else if (i == 2) {
            if (res[1].size() == 1) {
                if (checkPal(s.substr(0, 3)))
                    res.push_back(s.substr(0, 3));
                else if (s[2] == s[1])
                    res.push_back(s.substr(1, 2));
                else
                    res.push_back(s.substr(2, 1));
            }
            else if (s[2] == s[1])
                res.push_back(s.substr(0, 3));
            else
                res.push_back(s.substr(0, 2));
        }
        else {
            temp = res[i-1].size();
            if (temp <= i-1) {
                if (checkPal(s.substr(i-temp-1, temp+2)))
                    res.push_back(s.substr(i-temp-1, temp+2));
                else if (checkPal(s.substr(i-temp, temp+1)))
                    res.push_back(s.substr(i-temp, temp+1));
                else if (checkPal(s.substr(i-temp+1, temp)))
                    res.push_back(s.substr(i-temp+1, temp));
                else {
                    if (temp != 1)
                        res.push_back(res[i-1]);
                    else
                        res.push_back(s.substr(i, 1));
                }
            }
            else {
                if (checkPal(s.substr(i-temp, temp+1)))
                    res.push_back(s.substr(i-temp, temp+1));
                else if (checkPal(s.substr(i-temp+1, temp)))
                    res.push_back(s.substr(i-temp+1, temp));
                else
                    res.push_back(res[i-1]);
            }
        }
    }
    return res[res.size()-1];
}