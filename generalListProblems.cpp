//
// Created by zyl on 2020/3/23.
//

#include "function_defs.h"

/*********************************************************/
/* Solution 1: 第一遍遍历获取节点数量, 然后取中间
 * Solution 2: 快慢指针, 快指针走两步, 慢指针走一步 */
/*********************************************************/
ListNode* Solution::middleNode(ListNode *head) {
    if (!head)
        return nullptr;
    ListNode* fast = head;
    ListNode* slow = head;
    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}


/*********************************************************/
/* Solution 1:  递归
 *      Steps:  temp <-- 下下个节点
 *              new head <-- 下个节点
 *              下个节点指向头结点
 *              头节点指向 F(temp)
 * Solution 2:  迭代
 *              first 指向 second->next->next
 *              second 指向 first*/
/*********************************************************/
ListNode* Solution::swapPairs(ListNode *head) {
    if (!head)
        return nullptr;
    if (!head->next)
        return head;
    ListNode* first = head;
    ListNode* second = head->next;
    ListNode* res = second;
    while (second && second->next) {
        ListNode* first_next_next = first->next->next;
        ListNode* second_next_next = second->next->next;
        if (second_next_next)
            first->next = second->next->next;
        else
            first->next = second->next;
        second->next = first;
        first = first_next_next;
        second = second_next_next;
    }
    if (second) {
        second->next = first;
        first->next = nullptr;
    }
    return res;
}