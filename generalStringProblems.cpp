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

/********************************************************************************************************************/
/****************************************************** Solution: ***************************************************/
/* Solution 1: Use a map to store the char in chars and its count --need optimize                                   */
/* Solution 2: Use a vector to store and then find it directly because they are all a-z -- optimization 03//17/2020 */
/********************************************************************************************************************/
int Solution::countCharacters(vector<string> &words, string chars) {
   vector<int> char_num(26, 0);
   for (auto ch: chars)
       char_num[ch-'a']++;
   vector<int> temp;
   int count;
   int result = 0;
   for (auto word: words) {
       temp = char_num;
       count = 0;
       for (auto ch: word) {
           temp[ch-'a']--;
           if (temp[ch-'a'] < 0)
               break;
           else
               count++;
       }
       if (count == word.size())
           result += count;
   }
    return result;
}