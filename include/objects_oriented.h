//
// Created by zyl on 2020/7/19.
//

#ifndef LEETCODE_RECORD_OBJECTS_ORIENTED_H
#define LEETCODE_RECORD_OBJECTS_ORIENTED_H

#include "include/common_libs.h"

// 队列的最大值
class MaxQueue {
public:
    vector<int> queue;
    vector<pair<int, int>> queue_max;  // first store value, second store push
    int push = 0;
    int pop = 0;

    MaxQueue() {

    }

    int max_value() {
        if (queue.empty())
            return -1;
        return queue_max[0].first;
    }

    void push_back(int value) {
        pair<int, int> temp;
        if (queue.empty()) {
            queue.push_back(value);
            push++;
            temp = make_pair(value, push);
            queue_max.push_back(temp);
            return;
        }
        queue.push_back(value);
        push++;
        for (int i = 0; i < queue_max.size(); i++) {
            if (value >= queue_max[i].first) {
                temp = make_pair(value, push);
                queue_max.erase(queue_max.begin()+i, queue_max.end());
                queue_max.push_back(temp);
                break;
            }
            else if (i == queue_max.size()-1) {
                temp = make_pair(value, push);
                queue_max.push_back(temp);
            }
        }
    }

    int pop_front() {
        if (queue.empty())
            return -1;
        int res = queue[0];
        queue.erase(queue.begin());
        pop++;
        if (pop >= queue_max[0].second)
            queue_max.erase(queue_max.begin());
        return res;
    }
};

/*********************************************************************************/
/* Description: Design and implement a data structure for Least Frequently Used
 * (LFU) cache. It should support the following operations: get and put get(key)
 * - Get the value (will always be positive) of the key if the key exists in the
 * cache, otherwise return -1. put(key, value) - Set or insert the value if the
 * key is not already present. When the cache reaches its capacity, it should
 * invalidate the least frequently used item before inserting a new item.
 *
 * For the purpose of this problem, when there is a tie (i.e., two or more
 * keys that have the same frequency), the least recently used key would be
 * evicted.Note that the number of times an item is used is the number of
 * calls to the get and put functions for that item since it was inserted.
 * This number is set to zero when the item is removed.
 *
 * Solution 1: use map<int, vector<int>> to store the frequency and the
 * TODO: Optimization
 * corresponding keys */
/*********************************************************************************/
// LFU Cache
class LFUCache {
    struct keyInfo {
        int frequency; // record the times of usage
        int value; // record the value of key
        int time; // most recently used time
    };
    map<int, keyInfo> m_key_info;    // connect key with its information
    map<int, map<int, int>> m_count_key;       // connect frequency with key (least recently used),
    // the first element of vector stores the least recently used key
    int m_current_num = 0;  // record the number of keys currently
    int m_capacity = 0;  // the capacity of Cache
    int m_least_count = 0;  // the least count of current keys
    int m_time = 0;  // store the time of current operation
public:
    LFUCache(int capacity) {
        m_capacity = capacity;
    }

    void insertCountKey(int key, keyInfo& information) {
        auto count_pos = m_count_key.find(information.frequency);
        if (count_pos != m_count_key.end()) count_pos->second.insert(make_pair(information.time, key));
        else {
            map<int, int> temp;
            temp.insert(make_pair(information.time, key));
            m_count_key.insert(make_pair(information.frequency, temp));
        }
    }

    void deleteCountKey(int key, keyInfo& information) {
        auto count_pos = m_count_key.find(information.frequency);
        auto time_pos = count_pos->second.find(information.time);
        count_pos->second.erase(time_pos);
        if (count_pos->second.empty()) {
            m_count_key.erase(count_pos);
            if (information.frequency == m_least_count) m_least_count++;
        }
    }

    int get(int key) {
        auto key_pos = m_key_info.find(key);
        if (m_key_info.end() != key_pos) {
            /* 从原来的使用次数对应的数组中删除当前的key */
            deleteCountKey(key, key_pos->second);

            /* 使用次数加一并更新使用次数-key表的信息 */
            key_pos->second.frequency++;
            key_pos->second.time = m_time;
            insertCountKey(key, key_pos->second);
            m_time++;
            return key_pos->second.value;
        } else return -1;
    }

    void put(int key, int value) {
        if (m_capacity == 0)
            return;
        auto key_pos = m_key_info.find(key);
        if (m_key_info.end() == key_pos) {
            keyInfo temp = {1, value, m_time};
            if (m_current_num == m_capacity) {
                m_current_num--;  // 为了和最后的++兼容

                /* remove least recently used key */
                auto count_pos = m_count_key.find(m_least_count);
                m_key_info.erase(count_pos->second.begin()->second);
                count_pos->second.erase(count_pos->second.begin());
                if (count_pos->second.empty()) m_count_key.erase(count_pos);
            }

            /* 插入新的key并使当前key数量加一 */
            m_key_info.insert(make_pair(key, temp));
            m_current_num++;
            insertCountKey(key, temp);
            m_least_count = 1;
        } else {
            /* 从原来的使用次数对应的数组中删除当前的key */
            deleteCountKey(key, key_pos->second);

            /* 使用次数加一，并更新次数-key表中的信息 */
            key_pos->second.frequency++;
            key_pos->second.value = value;
            key_pos->second.time = m_time;
            insertCountKey(key, key_pos->second);
        }
        m_time++;
    }
};


struct biLinkedList {
    pair<int, int> val = make_pair(0, 0);
    biLinkedList* prev = nullptr;
    biLinkedList* next = nullptr;
    biLinkedList(int key, int value) : val(make_pair(key, value)) {}
};


/**
 * https://leetcode-cn.com/problems/lru-cache/
 * LRU cache
 * Data structures: 1. Queue which is implemented using a doubly linked list. The maximum size of the queue will be
 *                     equal to the total number of frames available
 */
class LRUCache {
public:
    int m_capacity = 0;
    int m_num_nodes = 0;
    biLinkedList* head = nullptr;
    biLinkedList* tail = nullptr;
    unordered_map<int, biLinkedList*> addresses;  // stores the key and its address of node in list

    LRUCache(int capacity) {
        m_capacity = capacity;
    }

    int get(int key) {
        auto it = addresses.find(key);
        if (it == addresses.end()) return -1;
        else {
            if (it->second != tail) move_to_tail(it->second);  // move current key to most recently used position
            return it->second->val.second;
        }
    }

    void put(int key, int value) {
        auto it = addresses.find(key);
        if (m_num_nodes < m_capacity) {
            if (it == addresses.end()) {
                // if current key is not in list, append it to the tail of list
                auto node = new biLinkedList(key, value);
                add_to_tail(node);
                addresses.emplace(key, tail);
                m_num_nodes++;
            } else {
                if (it->second != tail) move_to_tail(it->second);
                it->second->val.second = value;
            }
        } else {
            if (it == addresses.end()) {
                // delete the head node
                addresses.erase(addresses.find(head->val.first));
                if (head->next) {
                    head->next->prev = nullptr;
                    head = head->next;
                    tail->next = new biLinkedList(key, value);
                    tail->next->prev = tail;
                    tail = tail->next;
                } else {
                    head = new biLinkedList(key, value);
                    tail = head;
                }
                addresses.emplace(key, tail);
            } else {
                if (it->second != tail) move_to_tail(it->second);
                it->second->val.second = value;
            }
        }
    }

    void move_to_tail(biLinkedList* node) {
        if (node->prev) node->prev->next = node->next;
        else head = node->next;
        node->next->prev = node->prev;
        node->prev = tail;
        tail->next = node;
        node->next = nullptr;
        tail = node;
    }

    void add_to_tail(biLinkedList* node) {
        if (tail) {
            tail->next = node;
            node->prev = tail;
            tail = node;
        } else {
            head = node;
            tail = head;
        }
    }
};


class MyStack {
public:
    queue<int> queue_first;
    queue<int> queue_second;

    /** Initialize your data structure here. */
    MyStack() {

    }

    /** Push element x onto stack. */
    void push(int x) {
        queue_first.empty() ? queue_second.push(x) : queue_first.push(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int res = 0;
        int size = queue_first.empty() ? queue_second.size() : queue_first.size();
        if (queue_first.empty()) {
            for (int i = 0; i < size - 1; i++) {
                queue_first.push(queue_second.front());
                queue_second.pop();
            }
            res = queue_second.front();
            queue_second.pop();
            return res;
        } else {
            for (int i = 0; i < size - 1; i++) {
                queue_second.push(queue_first.front());
                queue_first.pop();
            }
            res = queue_first.front();
            queue_first.pop();
            return res;
        }
    }

    /** Get the top element. */
    int top() {
        return queue_first.empty() ? queue_second.back() : queue_first.back();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return queue_first.empty() && queue_second.empty();
    }
};


// Serialize and deserialize binary tree
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res = "[";
        queue<TreeNode*> store;
        store.push(root);
        res += to_string(root->val);
        res += ",";
        while (!store.empty()) {
            int size = store.size();
            string temp;
            for (int i = 0; i < size; i++) {
                TreeNode* node = store.front();
                store.pop();
                if (node->left) {
                    store.push(node->left);
                    temp += to_string(node->left->val);
                    temp += ",";
                } else temp += "null,";
                if (node->right) {
                    store.push(node->right);
                    temp += to_string(node->right->val);
                    temp += ",";
                } else temp += "null,";
            }
            if (!store.empty()) res += temp;
        }
        res += "]";
        return res;
    }

    // get a string
    string get_string(string data, int& start) {
        string res;
        int i = 0;
        for (i = start; i < data.size(); i++) {
            if (data[i] != '[' && data[i] != ',' && data[i] != ']') res.push_back(data[i]);
            else break;
        }
        start = i + 1;
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode* root = NULL;
        queue<TreeNode*> store;
        int i = 1;
        root = new TreeNode(stoi(get_string(data, i)));
        store.push(root);
        while (i < data.size()) {
            int size = store.size();
            for (int j = 0; j < size; j++) {
                TreeNode* node = store.front();
                string new_val = get_string(data, i);
                if (new_val != "null" && !new_val.empty()) {
                    node->left = new TreeNode(stoi(new_val));
                    store.push(node->left);
                }
                new_val = get_string(data, i);
                if (new_val != "null" && !new_val.empty()) {
                    node->right = new TreeNode(stoi(new_val));
                    store.push(node->right);
                }
                store.pop();
            }
        }
        return root;
    }
};

/**
 * https://leetcode-cn.com/problems/yong-liang-ge-zhan-shi-xian-dui-lie-lcof/
 * Stack using two queues
 */
class CQueue {
public:
    stack<int> heads;
    stack<int> tails;

    CQueue() {

    }

    void appendTail(int value) {
        if (heads.empty()) tails.push(value);
        else {
            while (!heads.empty()) {
                tails.push(heads.top());
                heads.pop();
            }
            tails.push(value);
        }
    }

    int deleteHead() {
        while (!tails.empty()) {
            heads.push(tails.top());
            tails.pop();
        }
        int res = -1;
        if (!heads.empty()) {
            res = heads.top();
            heads.pop();
        }
        return res;
    }
};

#endif //LEETCODE_RECORD_OBJECTS_ORIENTED_H
