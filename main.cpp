//
// Created by zyl on 2020/1/13.
//
#include "include/algorithms_data_structures.h"
#include "include/objects_oriented.h"

extern ListNode* mergeTwoList(ListNode* head1, ListNode* head2);

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution solution;

    vector<int> test = {1,4,5,55,6,7,2,2,3,1};
    int res = solution.wiggleMaxLength(test);

    return 0;
}
