//
// Created by zyl on 2020/3/22.
//

#include "function_defs.h"

void fastSort(vector<int>& A) {
    if (A.size() == 1 || A.empty())
        return;
    vector<int> left;
    vector<int> right;
    for (int i = 1; i < A.size(); i++) {
        if (A[i] < A[0])
            left.push_back(A[i]);
        else
            right.push_back(A[i]);
    }
    fastSort(left);
    fastSort(right);
    left.push_back(A[0]);
    left.insert(left.end(), right.begin(), right.end());
    A = left;
}

int sum_num(vector<int>& A) {
    if (A.empty())
        return 0;
    int res = 0;
    for (int a : A) {
        res += a;
    }
    return res;
}

/*****************************************************************************/
/* Naive solution:  The result should be N*(N+1)/2 - sum of vector
 *          Steps:  First sort the group,
 *                  for a : A
 *                      if a > expected; then
 *                          delta <-- delta + a - expected
 *                          sum <-- sum + expected_sum - current_sum
 *                      end if
 *                  end for
 *
 * Optimization 1:  Store the next number of current number
 *          Steps:  use a vector of big length, store next element
 *                  for a : A
 *                      if vector[a] == 0; then
 *                          vector[a] = a + 1
 *                      else
 *                          while (next != 0)
 *                              find next;
 *                          move <-- next - a;
 *                          vector[a] = next + 1
 *                          vector[next] = next + 1*
 *                      end if
 *                  end for
 * Optimization 2:  Store the count of each number
 *          Steps:  use a vector to store count,
 *                  in the meantime, store min and max
 *                  use a flag to denote if count > 1 exist
 *                  while (flag)
 *                      for a = min : max + A.length
 *                          if vector[a] > 1
 *                              push forward
 *                          end if
 *                      end for
 *                  end while */
/*****************************************************************************/
int Solution::minIncrementForUnique(vector<int> &A) {
    if (A.size() == 1 || A.empty())
        return 0;
    vector<int> slots(80001, 0);
    int min = A[0];
    int max = A[0];
    for (int a : A) {
        if (a <= min)
            min = a;
        if (a >= max)
            max = a;
        slots[a]++;
    }
    int move = 0;
    while (true) {
        int i = min;
        while (slots[i]) {
            if (slots[i] > 1) {
                for (int j = 1; j < slots[i]; j++)
                    slots[i + j]++;
                move += slots[i] * (slots[i] - 1) / 2;
                slots[i] = 1;
            }
            i++;
        }
        if (i > max)
            break;
        while (!slots[i])
            i++;
        min = i;
    }
    return move;
}