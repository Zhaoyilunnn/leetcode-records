//
// Created by zyl on 2020/3/16.
//

#include "include/algorithms_data_structures.h"


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
 * Solution 1:  use a vector (size 26) to store the list of words that end of index = end - 'a',
 * then find if current word is covered
 * Solution 2:  Trie (字典树) */
/***********************************************************************************************/

struct TrieNode {
    vector<TrieNode*> children;
    bool isEndOfWord;
    TrieNode() : isEndOfWord(false), children(26, nullptr) {}
};

int Solution::minimumLengthEncoding(vector<string> &words) {
    auto* root = new TrieNode();
    int length = 0;
    for (auto word : words) {
        int temp_length = 0;
        TrieNode* p = root;
        for (int i = word.size()-1; i >= 0; i--) {
            temp_length++;
            int pos = word[i] - 'a';
            if (!(p->children[pos])) {
                p->children[pos] = new TrieNode();
                if (i == 0) {
                    length += temp_length + 1;
                    p->isEndOfWord = true;
                }
            } else if (p->isEndOfWord && i != 0) {
                length -= temp_length + 1;
                p->isEndOfWord = false;
            }
            p = p->children[pos];
        }
    }
    delete root;
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
 *              Then the minimum depth is determined and split */
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

/****************************************************************************************/
/* Description: Implement atoi which converts a string to an integer.
 * The function first discards as many whitespace characters as necessary until
 * the first non-whitespace character is found. Then, starting from this character,
 * takes an optional initial plus or minus sign followed by as many numerical digits as
 * possible, and interprets them as a numerical value.
 *
 * The string can contain additional characters after those that form the integral number,
 * which are ignored and have no effect on the behavior of this function.
 *
 * If the first sequence of non-whitespace characters in str is not a valid integral
 * number, or if no such sequence exists because either str is empty or it contains only
 * whitespace characters, no conversion is performed. If no valid conversion could be
 * performed, a zero value is returned.*/
/****************************************************************************************/
int Solution::myAtoi(const string& str) {
    int start = 0;
    while (start < str.size()) {
        if (str[start] != ' ')
            break;
        start++;
    }
    bool negative = false;
    if (str[start] == '-') {
        negative = true;
        start++;
    } else if (str[start] == '+')
        start++;
    int end = start;
    int new_start = -1;
    long result = 0;
    while (end < str.size()) {
        int digit = str[end] - '0';
        if (new_start < 0 && digit != 0)
            new_start = end;
        if (digit < 0 || digit > 9)
            break;
        else
            result = result * 10 + digit;
        if (new_start >= 0 && end - new_start > 9)
            return negative ? -2147483648 : 2147483647;
        end++;
    }
    if (result) {
        if (negative) {
            if (result <= 2147483648)
                return 0 - result;
            else
                return -2147483648;
        } else {
            if (result <= 2147483647)
                return result;
            else
                return 2147483647;
        }
    }
    else
        return 0;
}


/********************************************************************************/
/* Description: Given an input string, reverse the string word by word. */
/********************************************************************************/
string Solution::reverseWords(const string& s) {
    if (s.empty()) return "";
    string res;
    int start = 0;
    int end = (int)s.size() - 1;
    while (start <= end) {
        if (s[start] == ' ') start++;
        if (s[end] == ' ') end--;
        if (end < 0) return "";
        if (s[start] != ' ' && s[end] != ' ') break;
    }
    if (start > end) return "";
    int begin = s.size();
    for (int i = end; i >= start; i--) {
        if (s[i] == ' ' && begin > end) {
            begin = i + 1;
            res += s.substr(begin, end - begin + 1) + ' ';
        }
        if (s[i] != ' ' && begin <= end) end = i;
        if (i == start) res += s.substr(i, end - i + 1);
    }
    return res;
}


/*****************************************************************************/
/*
 * Description
 * */
/*****************************************************************************/
string Solution::decodeString(const string &s) {
    string num_repeat_str;
    string str_repeat;
    string res;
    stack<pair<int, string>> store;
    for (char c : s) {
        if (c - '0' >= 0 && c - '0' <= 9) num_repeat_str.push_back(c);
        else if (c == '[') {
            store.emplace(stoi(num_repeat_str), "");
            num_repeat_str.clear();
        } else if (c == ']') {
            str_repeat = store.top().second;
            int num_repeat = store.top().first;
            store.pop();
            if (store.empty()) {
                for (int i = 0; i < num_repeat; i++)
                    res += str_repeat;
            } else {
                for (int i = 0; i < num_repeat; i++)
                    store.top().second += str_repeat;
            }
        } else {
            if (store.empty()) res.push_back(c);
            else store.top().second.push_back(c);
        }
    }
    return res;
}


/*****************************************************************/
/*
 * Description:
 * */
/*****************************************************************/
bool Solution::isPalindrome(const string& s) {
    int i = 0, j = s.size() - 1;
    int first = -1, second = -1;
    while (i <= j) {
        if (first < 0) {
            if (s[i] - 'a' >= 0 && s[i] - 'a' <= 25) first = s[i] - 'a';
            else if (s[i] - 'A' >= 0 && s[i] - 'A' <= 25) first = s[i] - 'A';
            else if (s[i] - '0' >= 0 && s[i] - '0' <= 9) first = s[i] - '0' + 100;
        }
        if (second < 0) {
            if (s[j] - 'a' >= 0 && s[j] - 'a' <= 25) second = s[j] - 'a';
            else if (s[j] - 'A' >= 0 && s[j] - 'A' <= 25) second = s[j] - 'A';
            else if (s[j] - '0' >= 0 && s[j] - '0' <= 9) second = s[j] - '0' + 100;
        }
        if (first < 0) {
            i++;
            if (second < 0) j--;
        } else if (second < 0) j--;
        else if (first != second) return false;
        else {
            i++;
            j--;
            first = -1;
            second = -1;
        }
    }
    return true;
}


/**
 * https://leetcode-cn.com/problems/add-strings/
 */
string Solution::addString(const string &num1, const string &num2) {
    int i = num1.size() - 1, j = num2.size() - 1;
    int flag = 0;
    string res;
    while (i >= 0 || j >= 0) {
        int digit1 = 0, digit2 = 0;
        if (i >= 0) digit1 = num1[i] - '0';
        if (j >= 0) digit2 = num2[j] - '0';
        int cur_sum = digit1 + digit2 + flag;
        flag = cur_sum / 10;
        res.insert(res.begin(), cur_sum % 10 + '0');
        i--;
        j--;
    }
    if (flag) res.insert(res.begin(), flag + '0');
    return res;
}


/**
 * https://leetcode-cn.com/problems/restore-ip-addresses/
 * Current solution is dfs
 * TODO: Any optimization??
 */

vector<string> restoreIpPart(const string& s, int start, int k) {
    if (k == 0) return {};
    vector<string> res;
    int curr_digit = 0;
    string curr_res;
    for (int i = start; i < start + 3 && i < s.size(); i++) {
        curr_digit = s[i] - '0' + 10 * curr_digit;
        if (curr_digit >= 0 && curr_digit <= 255) curr_res.push_back(s[i]);
        else break;
        if (s[start] == '0' && i > start) break;
        if (s.size() - i - 1 >= (k - 1) * 1 && s.size() - i - 1 <= (k - 1) * 3) {
            vector<string> curr_res_part = restoreIpPart(s, i + 1, k - 1);
            if (!curr_res_part.empty()) {
                for (const auto &rem : curr_res_part) {
                    string temp = curr_res;
                    if (!rem.empty()) {
                        temp.push_back('.');
                        temp += rem;
                    }
                    if (temp.size() == s.size() - start + k - 1) res.push_back(temp);
                }
            } else if (curr_res.size() == s.size() - start + k - 1) res.push_back(curr_res);
        }
    }
    return res;
}

vector<string> Solution::restoreIpAddress(const string& s) {
    vector<string> res;
    int curr_digit = 0;
    string curr_res;
    for (int i = 0; i < 3 && i < s.size(); i++) {
        curr_digit = s[i] - '0' + 10 * curr_digit;
        if (curr_digit >= 0 && curr_digit <= 255) curr_res.push_back(s[i]);
        else break;
        if (s[0] == '0' && i > 0) break;
        if (s.size() - i - 1 >= 3 && s.size() - i - 1 <= 9) {
            vector<string> curr_res_part = restoreIpPart(s, i + 1, 3);
            for (const auto& rem : curr_res_part) {
                string temp = curr_res;
                if (!rem.empty()) {
                    temp.push_back('.');
                    temp += rem;
                }
                if (temp.size() == s.size() + 3) res.push_back(temp);
            }
        }
    }
    return res;
}


/**
 * https://leetcode-cn.com/problems/multiply-strings/
 * Solution 1: 从右向左遍历num2，对于num2的每一位，都需要和num1的每一位计算乘积
 *             addStr --> 字符串相加
 *             multiplyOne --> num2中的某一位和num1相乘的结果
 * Solution 2: 用一个数组存储结果，最后再处理进位，相比于方法1，省去了字符串相加的过程，方法1中有n次字符串相加，而方法二只会在最后遍历一次
 * Solution 3: 方法二实际上可以看成卷积，可以用fft加速
 *             fft_naive --> O(n^2)版本的dft
 * @param num1
 * @param num2
 * @return
 */
vector<CP> dsp::dftNaive(vector<CP>& x) {
    // ref: https://en.wikipedia.org/wiki/Cooley%E2%80%93Tukey_FFT_algorithm
    int N = (int) x.size();  // N should be power of two
    vector<CP> X(N, 0);
    for (int k = 0; k < N; k++) {
        for (int n = 0; n < N; n++) {
            X[k] += x[n] * CP(cos(2*PI*n*k/N), sin(-2*PI*n*k/N));
        }
    }
    return X;
}

/**
 * ref: https://en.wikipedia.org/wiki/Cooley%E2%80%93Tukey_FFT_algorithm
 * @param x --> input sequence of time domain signal
 * @param N --> length of x, should be power of two
 * @param s --> step
 * @param X --> output sequence of frequency domain signal
 * @return
 */
int dsp::reverseBit(int num, int count) {
    // ref: https://www.youtube.com/watch?v=KE5Axm7uzok
    //      https://www.geeksforgeeks.org/write-an-efficient-c-program-to-reverse-bits-of-a-number/
    int reverse_num = 0;
    for (int i = 0; i < count; i++) {
        reverse_num <<= 1;
        reverse_num |= num & 1;
        num >>= 1;
    }
    return reverse_num;
}

void dsp::bitReverseCopy(vector<CP>& x, vector<CP>& X) {
    // ref: Introduction to Algorithm - third edition
    int n = x.size();  // n should be the power of two
    int m = log2(n);
    for (int i = 0; i < n; i++) {
        X[this->reverseBit(i, m)] = x[i];
    }
}

vector<CP> dsp::fftCooleyTukey(vector<CP> &x) {
    vector<CP> X(x.size(), 0);
    bitReverseCopy(x, X);
    int n = x.size();
    for (int s = 1; s <= (int) log2(n); s++) {
        int m = pow(2, s);
        CP w_m = CP(cos(-2 * PI / m), sin(-2 * PI / m));
        for (int k = 0; k < n; k += m) {
            CP w = 1;
            for (int j = 0; j < m / 2; j++) {
                CP t = w * X[k + j + m / 2];
                CP u = X[k + j];
                X[k + j] = u + t;
                X[k + j + m / 2] = u - t;
                w = w * w_m;
            }
        }
    }
    return X;
}

string addStr(const string& num1, const string& num2) {
    if (num1.empty()) return num2;
    else if (num2.empty()) return num1;
    int i = (int) num1.size() - 1;
    int j = (int) num2.size() - 1;
    string res;
    int flag = 0, d1 = 0, d2 = 0;
    while (i >= 0 || j >= 0) {
        d1 = 0;
        d2 = 0;
        if (i >= 0) d1 = num1[i] - '0';
        if (j >= 0) d2 = num2[j] - '0';
        int s = d1 + d2 + flag;
        flag = s / 10;
        res.insert(res.begin(), '0' + s % 10);
        i--;
        j--;
    }
    if (flag) res.insert(res.begin(), '1');
    return res;
}

string multiplyOne(const string& num1, const char& num2) {
    int i = (int) num1.size() - 1, d2 = num2 - '0', d1 = 0, flag = 0;
    string res;
    while (i >= 0) {
        d1 = num1[i] - '0';
        int s = d1 * d2 + flag;
        flag = s / 10;
        res.insert(res.begin(), s % 10 + '0');
        i--;
    }
    if (flag) res.insert(res.begin(), flag + '0');
    return res;
}

string Solution::multiply(const string &num1, const string &num2) {
    // Solution 1
    /*if (num1 == "0" || num2 == "0") return "0";
    int i = (int) num2.size() - 1;
    string zeros;
    string last_res, cur_res;
    while (i >= 0) {
        char d2 = num2[i];
        cur_res = multiplyOne(num1, d2);
        cur_res.insert(cur_res.end(), zeros.begin(), zeros.end());
        cur_res = addStr(cur_res, last_res);
        last_res = cur_res;
        i--;
        zeros += '0';
    }
    return cur_res;*/

    // Solution 2
    /*if (num1 == "0" || num2 == "0") return "0";
    int m = num1.size(), n = num2.size();
    vector<int> store(m + n, 0);
    for (int i = 0; i < m; i++) {
        int x = num1[i] - '0';
        for (int j = 0; j < n; j++) {
            int y = num2[j] - '0';
            int temp_product = x * y;
            store[i + j + 1] += temp_product;
        }
    }
    for (int i = m + n - 1; i > 0; i--) {
        store[i - 1] += store[i] / 10;
        store[i] %= 10;
    }
    string res;
    for (int i = 0; i < m + n; i++) {
        if (i == 0 && store[i] == 0) continue;
        else res.push_back(store[i] + '0');
    }
    return res;*/

    // Solution 3

}


/**
 * https://leetcode-cn.com/problems/valid-parentheses/
 * @param s
 * @return
 */
bool Solution::isValid(const string &s) {
    stack<char> store;
    for (auto c : s) {
        if (!store.empty()) {
            switch (c) {
                case '}':
                    if (store.top() != '{') return false;
                    else store.pop();
                    break;
                case ']':
                    if (store.top() != '[') return false;
                    else store.pop();
                    break;
                case ')':
                    if (store.top() != '(') return false;
                    else store.pop();
                    break;
                default:
                    store.push(c);
            }
        } else store.push(c);
    }
    if (!store.empty()) return false;
    else return true;
}


/**
 * https://leetcode-cn.com/problems/palindromic-substrings/
 * @param s
 * @return
 */
int Solution::countSubstrings(const string &s) {
    if (s.empty()) return 0;
    int res = 1;
    vector<int> indexes;
    indexes.push_back(0);
    vector<int> pre = indexes;
    for (int i = 1; i < s.size(); i++) {
        indexes.clear();
        for (int j : pre) {
            if (j > 0 && s[i] == s[j - 1]) {
                indexes.push_back(j - 1);
                res++;
            }
        }
        if (s[i] == s[i - 1]) {
            indexes.push_back(i - 1);
            res++;
        }
        indexes.push_back(i);
        res++;
        pre = indexes;
    }
    return res;
}


/**
 * https://leetcode-cn.com/problems/repeated-substring-pattern/
 * @param s
 * @return
 */
bool Solution::repeatedSubstring(const string &s) {
    if (s.size() == 1 || s.empty()) return false;
    vector<string> subs;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == s[0]) {
            if (s.substr(0, i) == s.substr(i, i)) {
                string sub = s.substr(0, i);
                subs.push_back(sub);
            }
        }
    }
    if (subs.empty()) return false;
    bool res = true;
    for (const auto& sub : subs) {
        res = true;
        for (int i = 2 * sub.size(); i < s.size(); i += sub.size()) {
            if (s.substr(i, sub.size()) != sub) {
                res = false;
                break;
            }
        }
        if (res) return res;
    }
    return res;
}