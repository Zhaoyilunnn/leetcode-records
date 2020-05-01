    //
// Created by zyl on 2020/1/13.
//
#include "function_defs.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution solution;

    auto* l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(4);
    auto* l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);
    ListNode* l3 = solution.mergeTwoLists(l1, l2);

    return 0;
}
