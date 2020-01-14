//
// Created by zyl on 2020/1/13.
//

#include "function_defs.h"

int Solution::minimumTotal(vector<vector<int>>& triangle) {
   vector<vector<int>> results;
   vector<int> temp;
   int length = triangle.size();
   if (length == 1)
       return triangle[0][0];
   for (int i = 0; i < length-1; i++) {
       if (!temp.empty())
           temp.clear();
       for (int j = 0; j < length-1-i; j++) {
           if (i == 0) {
               if (triangle[length-1-i][j] < triangle[length-1-i][j+1])
                   temp.push_back(triangle[length-1-i][j] + triangle[length-2-i][j]);
               else
                   temp.push_back(triangle[length-1-i][j+1] + triangle[length-2-i][j]);
           }
           else {
               if (results[i - 1][j] < results[i - 1][j + 1])
                   temp.push_back(results[i - 1][j] + triangle[length - 2 - i][j]);
               else
                   temp.push_back(results[i - 1][j + 1] + triangle[length - 2 - i][j]);
           }
       }
       results.push_back(temp);
   }
   return results[length-2][0];
}

