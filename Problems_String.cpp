//
// Created by zyl on 2020/3/16.
//

#include "function_defs.h"


/******************************************************************************************/
/* Description: For strings S and T, we say "T divides S" if and only if S = T + ... + T 
 * (T concatenated with itself 1 or more times) Return the largest string X such that
 * X divides str1 and X divides str2.*/
/******************************************************************************************/
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

/******************************************************************************/
/* Description: Implement a method to perform basic string compression using
 * the counts of repeated characters. For example, the string aabcccccaaa would
 * become a2blc5a3. If the "compressed" string would not become smaller than
 * the original string, your method should return the original string.
 * You can assume the string has only uppercase and lowercase letters (a - z).*/
/******************************************************************************/
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

/***********************************************************************************************/
/* Description: Given a list of words, we may encode it by writing a reference string S and a
 * list of indexes A. For example, if the list of words is ["time", "me", "bell"], we can write
 * it as S = "time#bell#" and indexes = [0, 2, 5].
 *
 * Then for each index, we will recover the word by reading from the reference string from that
 * index until we reach a "#" character.
 * What is the length of the shortest reference string S possible that encodes the given words?
 *
 * Solution: use a vector (size 26) to store the list of words that end of index = end - 'a',
 * then find if current word is covered */
/***********************************************************************************************/
int Solution::minimumLengthEncoding(vector<string> &words) {
    vector<string> init;
    vector<vector<string>> results(26, init);
    int length = 0;
    for (string word : words) {
        int index = word[word.size() - 1] - 'a';
        if (results[index].empty()) {
            results[index].push_back(word);
            length += word.size() + 1;
            continue;
        }
        bool flag = true;  // whether add current length to total length
        for (int m = 0; m < results[index].size(); m++) {
            string a = results[index][m];
            int i = a.size() - 1;
            int j = word.size() - 1;
            flag = false;
            while (i >= 0 && j >= 0) {
                if (a[i] != word[j]) {
                    flag = true;
                    break;
                }
                i--;
                j--;
            }
            if (!flag) {
                if (word.size() > a.size()) {
                    length += word.size() - a.size();
                    results[index][m] = word;
                }
                break;
            }
        }
        if (flag) {
            length += word.size() + 1;
            results[index].push_back(word);
        }
    }
    return length;
}


/**************************************************************************************/
/* Description: Given a VPS seq, split it into two disjoint subsequences A and B,
 * such that A and B are VPS's (and A.length + B.length = seq.length).
 *
 * Now choose any such A and B such that max(depth(A), depth(B)) is the minimum
 * possible value.
 *
 * Return an answer array (of length seq.length) that encodes such a choice of A and B: 
 * answer[i] = 0 if seq[i] is part of A, else answer[i] = 1.  Note that even though
 * multiple answers may exist, you may return any of them.
 *
 * Solution:    naive method, two traverse,
 *              First determine the depth
 *              Then the minimum depth is dermined and split*/
/**************************************************************************************/
vector<int> Solution::maxDepthAfterSplit(string seq) {
    // first traverse, find the depth
    int count = 0;
    int depth = 0;
    for (auto a : seq) {
        if (a == '(') {
            count++;
            if (count > depth)
                depth = count;
        } else
            count--;
    }
    int max_split_depth = depth / 2;
    vector<int> result;
    count = 0;
    // second traverse, when go into depth deeper than max_depth, split it out
    for (auto a : seq) {
        if (a == '(') {
            count++;
            if (count <= max_split_depth)
                result.push_back(0);
            else
                result.push_back(1);
        } else {
            count--;
            if (count < max_split_depth)
                result.push_back(0);
            else
                result.push_back(1);
        }
    }
    return result;
}