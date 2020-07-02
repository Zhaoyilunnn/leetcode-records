//
// Created by zyl on 2020/6/25.
//

#include "function_defs.h"


/**********************************************************************/
/*
 * Description: Given a non-empty string s and a dictionary wordDict
 * containing a list of non-empty words, determine if s can be
 * segmented into a space-separated sequence of one or more dictionary words.
 * */
/**********************************************************************/

bool isWordsMatch(string s, unordered_set<string>& words) {
    string first;
    for (int i = 0; i < s.size(); i++) {
        first.push_back(s[i]);
        if (words.find(first) != words.end()) {
            if (i < s.size() - 1) {
                if (isWordsMatch(s.substr(i + 1), words)) return true;
            } else return true;
        }
    }
    return false;
}

bool Solution::wordBreak(string s, vector<string> &wordDict) {
    unordered_set<string> words;
    for (string& word : wordDict) {
        words.insert(word);
    }
    return isWordsMatch(s, words);
}