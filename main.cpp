//
// Created by zyl on 2020/1/13.
//
#include "include/algorithms_data_structures.h"
#include "include/objects_oriented.h"

extern ListNode* mergeTwoList(ListNode* head1, ListNode* head2);

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution solution;

    ListNode a(1);
    ListNode b(2);
    ListNode c(3);
    ListNode d(4);
    ListNode e(5);
    a.next = &c;
    c.next = &b;
    b.next = &e;
    e.next = &d;
    auto res = solution.sortList(&a);

    return 0;
}
