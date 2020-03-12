//
// Created by zyl on 2020/3/12.
//

#include "function_defs.h"

string Solution::gcdOfStrings(string str1, string str2) {
    int L = 0;
    int L1 = str1.size();
    int L2 = str2.size();
    if (L1 > L2)
        L = L2;
    else
        L = L1;
    string result;
    string strNow;
    int now_L = 0;
    while (L > 0) {
        if (L1 % L == 0 && L2 % L == 0) {
            if (!strNow.empty())
                strNow.clear();
            result = str1.substr(0, L);
            now_L = L;
            while (now_L <= L1 || now_L <= L2) {
                strNow += result;
                if (now_L <= L1 && strNow != str1.substr(0, now_L))
                    break;
                if (now_L <= L2 && strNow != str2.substr(0, now_L))
                    break;
                now_L += L;
            }
            if (now_L > L1 && now_L > L2)
                return result;
        }
        L--;
    }
    return "";
}
