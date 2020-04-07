    //
// Created by zyl on 2020/1/13.
//
#include "function_defs.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution solution;


    string test = "赵逸伦";
    cout << test.length() << endl;
    cout << test.size() << endl;
    cout << test.max_size() << endl;

    string str1 = "horse";
    string str2 = "ros";
    int res = solution.minDistance(str1, str2);


    return 0;
}
