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


/***************************************************************************/
/* Description: Add two non-empty lists */
/***************************************************************************/
void addTwoLists(ListNode* &l1, ListNode* &l2, int& flag) {
    if (l1->next && l2->next)
        addTwoLists(l1->next, l2->next, flag);
    int sum = l1->val + l2->val + flag;
    if (sum >= 10) {
        l1->val = sum - 10;
        flag = 1;
    } else {
        l1->val = sum;
        flag = 0;
    }
}

ListNode* Solution::addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode* h1 = l1;
    ListNode* h2 = l2;
    while (h1 && h2) {
        h1 = h1->next;
        h2 = h2->next;
    }
    int delta = 0;
    while (h1) {
        h1 = h1->next;
        delta++;
    }
    if (delta) {
        int flag = 0;
        ListNode* new_node = nullptr;
        ListNode* temp = l2;
        for (int i = 0; i < delta; i++) {
            new_node = new ListNode(0);
            new_node->next = temp;
            temp = new_node;
        }
        addTwoLists(l1, new_node, flag);
        if (flag) {
            auto node = new ListNode(1);
            node->next = l1;
            return node;
        }
        return l1;
    }
    while (h2) {
        h2 = h2->next;
        delta++;
    }
    if (delta) {
        int flag = 0;
        ListNode* new_node = nullptr;
        ListNode* temp = l1;
        for (int i = 0; i < delta; i++) {
            new_node = new ListNode(0);
            new_node->next = temp;
            temp = new_node;
        }
        addTwoLists(new_node, l2, flag);
        if (flag) {
            auto node = new ListNode(1);
            node->next = new_node;
            return node;
        }
        return new_node;
    }
    int flag = 0;
    addTwoLists(l1, l2, flag);
    if (flag) {
        auto node = new ListNode(1);
        node->next = l1;
        return node;
    }
    return l1;
}


/*************************************************************************************/
/* Description: Merge K lists */
/*************************************************************************************/
ListNode* Solution::mergeKLists(vector<ListNode *> &lists) {

}


/************************************************************************************/
/* Given a linked list, determine if it has a cycle in it */
/************************************************************************************/
bool Solution::hasCycle(ListNode *head) {
    ListNode* pFast = head;
    ListNode* pSlow = head;
    while (pFast && pFast->next && pSlow) {
        pFast = pFast->next->next;
        pSlow = pSlow->next;
        if (pFast == pSlow) return true;
    }
    return false;
}


/********************************************************************************/
/* Description: Merge two sorted lists
 * Trick: use a previous node*/
/********************************************************************************/
ListNode* Solution::mergeTwoLists(ListNode *l1, ListNode *l2) {
    auto* preHead = new ListNode(-1);

    ListNode* prev = preHead;
    while (l1 != nullptr && l2 != nullptr) {
        if (l1->val < l2->val) {
            prev->next = l1;
            l1 = l1->next;
        } else {
            prev->next = l2;
            l2 = l2->next;
        }
        prev = prev->next;
    }

    // 合并后 l1 和 l2 最多只有一个还未被合并完，我们直接将链表末尾指向未合并完的链表即可
    prev->next = l1 == nullptr ? l2 : l1;

    return preHead->next;
}