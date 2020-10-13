//
// Created by zyl on 2020/3/23.
//

#include "include/algorithms_data_structures.h"

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


/**
 * https://leetcode-cn.com/problems/swap-nodes-in-pairs/solution/liang-liang-jiao-huan-lian-biao-zhong-de-jie-di-91/
 * @param head
 * @return
 */
ListNode* Solution::swapPairs(ListNode *head) {
    /*if (!head)
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
    return res;*/

    /* recurrent */
    if (!head || !head->next) return head;
    auto new_head = head->next;
    head->next = swapPairs(head->next->next);
    new_head->next = head;
    return new_head;
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


/**
 * https://leetcode-cn.com/problems/linked-list-cycle-ii/
 * 1. HashSet
 * 2. O(1) space complexity
 *    Also double pointer
 *    f(2n - m) = f(n)
 *    --> m = n
 *    --> m is the length from cycle start to cycle end
 * @param head
 * @return
 */
ListNode* Solution::detectCycle(ListNode *head) {
    if (!head) return nullptr;

    /* Hash Set */
    /*unordered_set<ListNode*> visited;
    auto p = head;
    while (p) {
        if (visited.find(p) != visited.end()) return p;
        visited.insert(p);
        p = p->next;
    }*/

    /* Double Pointer */
    ListNode *slow = head, *fast = head;
    while (fast != nullptr) {
        slow = slow->next;
        if (fast->next == nullptr) {
            return nullptr;
        }
        fast = fast->next->next;
        if (fast == slow) {
            ListNode *ptr = head;
            while (ptr != slow) {
                ptr = ptr->next;
                slow = slow->next;
            }
            return ptr;
        }
    }
    return nullptr;
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


/*******************************************************************************/
/*
 * Description: Given a linked list, reverse the nodes of a linked list k at
 * a time and return its modified list
 * */
/*******************************************************************************/
ListNode* reverseListRecursive(ListNode* head) {
    ListNode* new_head = nullptr;
    if (head->next) {
        new_head = reverseListRecursive(head->next);
        head->next->next = head;
        head->next = nullptr;
    } else new_head = head;
    return new_head;
}

ListNode* Solution::reverseKGroup(ListNode *head, int k) {
    ListNode* p = head;
    ListNode* new_head = nullptr;
    ListNode* next_node = nullptr;
    ListNode* part_head = nullptr;
    ListNode* prev_part_head = nullptr;
    ListNode* whole_new_head = nullptr;
    bool flag = false;  // 是否找到新的整个链表的头结点
    while (p) {
        if (part_head) prev_part_head = part_head;
        part_head = p;
        for (int i = 0; i < k - 1; i++) {
            p = p->next;
            if (!p) break;
        }
        if (p) {
            next_node = p->next;
            p->next = nullptr;
            p = next_node;
            new_head = reverseListRecursive(part_head);
        } else new_head = part_head;
        if (!flag) {
            flag = true;
            whole_new_head = new_head;
        }
        if (prev_part_head) prev_part_head->next = new_head;
    }
    return whole_new_head;
}


/*****************************************************************************/
/*
 * Write code to remove duplicates from a unsorted linked list
 * */
/*****************************************************************************/
ListNode* Solution::removeDuplicateNodes(ListNode *head) {
    if (!head) return nullptr;
    unordered_set<int> store;
    ListNode* prev  = head;
    store.insert(prev->val);
    ListNode* p = head->next;
    while (p) {
        if (store.end() != store.find(p->val)) {
            prev->next = p->next;
            p->next = nullptr;
            p = prev->next;
        } else {
            store.insert(p->val);
            prev = p;
            p = p->next;
        }
    }
    return head;
}


/**
 * https://leetcode-cn.com/problems/add-two-numbers/
 * @param l1
 * @param l2
 * @return
 */
ListNode* Solution::addTwoNumbersII(ListNode *l1, ListNode *l2) {
    ListNode vHead(0), *p = &vHead;
    int flag = 0;
    while (l1 || l2 || flag) {
        int tmp = 0;
        if (l1 != nullptr) tmp += l1->val;
        if (l2 != nullptr) tmp += l2->val;
        tmp += flag;

        flag = tmp / 10;
        tmp %= 10;

        ListNode *next = l1 ? l1 : l2;
        if (next == nullptr) next = new ListNode(tmp);
        next->val = tmp;

        p->next = next;
        p = p->next;
        l1 = l1 ? l1->next : nullptr;
        l2 = l2 ? l2->next : nullptr;
    }
    return vHead.next;
}