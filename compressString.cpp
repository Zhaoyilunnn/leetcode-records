//
// Created by zyl on 2020/3/16.
//

#include "function_defs.h"

string Solution::compressString(string S) {
    if (S.empty())
        return "";
    string result;
    int num = 1;
    for (int i = 1; i < S.size(); i++) {
        if (S[i] == S[i-1])
            num++;
        else {
            result.push_back(S[i - 1]);
            string strNum = to_string(num);
            for (auto str: strNum)
                result.push_back(str);
            num = 1;
        }
    }
    result.push_back(S[S.size()-1]);
    string strNum = to_string(num);
    for (auto str: strNum)
        result.push_back(str);
    if (result.size() >= S.size())
        return S;
    else
        return result;
}