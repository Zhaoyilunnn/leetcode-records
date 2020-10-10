//
// Created by zyl on 2020/2/22.
//
#include "include/algorithms_data_structures.h"


TreeNode* Solution::buildTree(vector<int>& inOrder, vector<int>& postOrder) {
    TreeNode* root = new TreeNode(postOrder[postOrder.size() - 1]);
    if (inOrder.size() == 1)
        return root;
    vector<int> new_inOrder;
    vector<int> new_postOrder;
    for (int i = 0; i < inOrder.size(); i++) {
        if (inOrder[i] == postOrder[postOrder.size() - 1]) {
            if (i > 0) {
                new_inOrder.assign(inOrder.begin(), inOrder.begin()+i);
                new_postOrder.assign(postOrder.begin(), postOrder.begin()+i);
                root->left = buildTree(new_inOrder, new_postOrder);
            }
            if (!new_inOrder.empty())
                new_inOrder.clear();
            if (!new_postOrder.empty())
                new_postOrder.clear();
            if (i < postOrder.size()-1) {
                new_inOrder.assign(inOrder.begin()+i+1, inOrder.end());
                new_postOrder.assign(postOrder.begin()+i, postOrder.end()-1);
                root->right = buildTree(new_inOrder, new_postOrder);
            }
        }
    }
    return root;
}


vector<vector<int>> Solution::zigzagLevelOrder(TreeNode* root) {
    if (!root)
        return {};
    vector<TreeNode*> vctStack1;
    vector<TreeNode*> vctStack2;
    vctStack1.push_back(root);
    vector<int> temp;
    vector<vector<int>> result;
    TreeNode* top = NULL;
    bool Flag = false;
    while (!vctStack1.empty() || !vctStack2.empty()) {
        if (vctStack2.empty() && Flag) {
            Flag = false;
            if (!temp.empty()) {
                result.push_back(temp);
                temp.clear();
            }
        }
        if (vctStack1.empty() && !Flag) {
            Flag = true;
            if (!temp.empty()) {
                result.push_back(temp);
                temp.clear();
            }
        }
        if (Flag) {
            top = vctStack2[vctStack2.size()-1];
            vctStack2.pop_back();
            temp.push_back(top->val);
            if (top->right)
                vctStack1.push_back(top->right);
            if (top->left)
                vctStack1.push_back(top->left);
        }
        else {
            top = vctStack1[vctStack1.size()-1];
            vctStack1.pop_back();
            temp.push_back(top->val);
            if (top->left)
                vctStack2.push_back(top->left);
            if (top->right)
                vctStack2.push_back(top->right);
        }
    }
    if (!temp.empty())
        result.push_back(temp);
    return result;
}


void inOrder(TreeNode* root, vector<int>& vctRes) {
    if (root->left)
        inOrder(root->left, vctRes);
    vctRes.push_back(root->val);
    if (root->right)
        inOrder(root->right, vctRes);
}


vector<int> getVecTree(TreeNode* root) {
    if (!root)
        return {};
    vector<int> vctRes;
    inOrder(root, vctRes);
    return vctRes;
}

vector<int> Solution::getAllElements(TreeNode *root1, TreeNode *root2) {
    vector<int> vctTree1 = getVecTree(root1);
    vector<int> vctTree2 = getVecTree(root2);
    if (vctTree1.empty())
        return vctTree2;
    if (vctTree2.empty())
        return vctTree1;
    vector<int> vctRes;
    int i, j;
    i = 0;
    j = 0;
    while (i < vctTree1.size() || j < vctTree2.size()) {
        if (j == vctTree2.size())
            vctRes.push_back(vctTree1[i++]);
        else if (i == vctTree1.size())
            vctRes.push_back(vctTree2[j++]);
        else if (vctTree1[i] < vctTree2[j])
            vctRes.push_back(vctTree1[i++]);
        else
            vctRes.push_back(vctTree2[j++]);
    }
    return vctRes;
}


int depth(TreeNode* root) {
    if (root) {
        cout << root->val << " ";
        int depth_left = depth(root->left);
        int depth_right = depth(root->right);
        if (depth_left >= depth_right)
            return ++depth_left;
        else
            return ++depth_right;
    }
    return 0;
}

/*****************************************************************/
/* Solution: 1. Compute depth of left and depth of right         */
/*           2. Compute the sum of depths of left and right      */
/*           3. Compare the sum and the depth_left and depth_right
 *              and return the minimum                           */
/*****************************************************************/
int Solution::diameterOfBinaryTree(TreeNode* root) {
    if (!root)
        return 0;
    int d = 0;
    int dl = 0;
    int dr = 0;
    d += depth(root->left);
    dl = diameterOfBinaryTree(root->left);
    d += depth(root->right);
    dr = diameterOfBinaryTree(root->right);
    if (d <= 2)
        return d;
    if (d <= dl)
        d = dl;
    if (d <= dr)
        d = dr;
    return d;
}



/**
 * https://leetcode-cn.com/problems/unique-binary-search-trees/
 * TODO: Optimize 不同搜索二叉树II (generateTrees)
 * @param n
 * @return
 */
int Solution::numTrees(int n) {
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            dp[i] += dp[j] * dp[i - j - 1];
        }
    }
    return dp[n];
}


// 不同搜索二叉树||
/**
 * https://leetcode-cn.com/problems/unique-binary-search-trees-ii/
 * @param n
 * @return
 */
vector<TreeNode*> Solution::generateTrees(int n) {

}


/*****************************************************************/
/* Description: Given a binary tree, find its maximum depth
 * Solution 1:  recurrence
 * Solution 2:  level traverse
 * follow up: how to print the route of max depth? */
/*****************************************************************/
int Solution::maxDepth(TreeNode *root) {
    if (!root)
        return 0;
    queue<TreeNode*> level_nodes;
    int depth = 0;

    level_nodes.push(root);
    while (!level_nodes.empty()) {
        int size = level_nodes.size();
        for (int i = 0; i < size; i++) {
            TreeNode* node = level_nodes.front();
            if (node->left)
                level_nodes.push(node->left);
            if (node->right)
                level_nodes.push(node->right);
            level_nodes.pop();
        }
        depth++;
    }
    return depth;
}


/*****************************************************************************/
/* Description: Given a binary tree, imagine yourself standing on the right
 * side, return the values of the nodes that you can see ordered from top to
 * bottom
 * Solution: Level order traverse and store the last value of each layer */
/*****************************************************************************/
vector<int> Solution::rightSideView(TreeNode *root) {
    if (!root) return {};
    queue<TreeNode*> q;
    q.push(root);
    vector<int> result;
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            TreeNode* p = q.front();
            if (p->left) q.push(p->left);
            if (p->right) q.push(p->right);
            q.pop();
            if (i == size - 1) result.push_back(p->val);
        }
    }
    return result;
}


/************************************************************************************/
/* Description: determine is a tree valid binary search tree */
/************************************************************************************/
bool Solution::isValidBST(TreeNode *root) {
    if (!root) return true;
    vector<int> val_list;

    /* first inorder traverse */
    stack<TreeNode*> nodes_store;
    nodes_store.push(root);
    TreeNode* curr_node = root;
    while (curr_node->left) {
        nodes_store.push(curr_node->left);
        curr_node = curr_node->left;
    }
    while (!nodes_store.empty()) {
        curr_node = nodes_store.top();
        if (!val_list.empty() && curr_node->val <= *(val_list.end() - 1))
            return false;
        val_list.push_back(curr_node->val);
        nodes_store.pop();
        if (curr_node->right) {
            nodes_store.push(curr_node->right);
            curr_node = curr_node->right;
            while (curr_node->left) {
                nodes_store.push(curr_node->left);
                curr_node = curr_node->left;
            }
        }
    }

    return true;
}


/*************************************************************************/
/* Description: Given two non-empty tree s and t, check whether t has
 * exactly the same structure and node values with a subtree of s */
/*************************************************************************/
bool isSameTree(TreeNode* s, TreeNode* t) {
    if (!s && !t) return true;
    if (!s || !t) return false;
    if (s->val == t->val)
        return isSameTree(s->left, t->left) ? isSameTree(s->right, t->right) : false;
    else return false;
}

bool Solution::isSubtree(TreeNode *s, TreeNode *t) {
    queue<TreeNode*> nodes;
    nodes.push(s);
    while (!nodes.empty()) {
        int size = nodes.size();
        for (int i = 0; i < size; i++) {
            TreeNode* p = nodes.front();
            if (isSameTree(p, t)) return true;
            if (p->left) nodes.push(p->left);
            if (p->right) nodes.push(p->right);
            nodes.pop();
        }
    }
    return false;
}


/*****************************************************************************/
/*
 * Description: Given a binary tree, find the lowest common ancestor (LCA) of
 * two given nodes in the tree.
 * */
/*****************************************************************************/
vector<TreeNode*> inOrder(TreeNode* root) {
    stack<TreeNode*> nodes;
    vector<TreeNode*> in_order_vals;
    TreeNode* p = root;
    while (p) {
        nodes.push(p);
        p = p->left;
    }
    while (!nodes.empty()) {
        p = nodes.top();
        in_order_vals.push_back(p);
        nodes.pop();
        if (p->right) {
            p = p->right;
            while (p) {
                nodes.push(p);
                p = p->left;
            }
        }
    }
    return in_order_vals;
}

vector<TreeNode*> level(TreeNode* root) {
    queue<TreeNode*> nodes;
    vector<TreeNode*> level_vals;
    nodes.push(root);
    while (!nodes.empty()) {
        int size = nodes.size();
        for (int i = 0; i < size; i++) {
            TreeNode* p = nodes.front();
            if (p->left) nodes.push(p->left);
            if (p->right) nodes.push(p->right);
            level_vals.push_back(p);
            nodes.pop();
        }
    }
    return level_vals;
}

TreeNode* Solution::lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    vector<TreeNode*> in_order = inOrder(root);
    vector<TreeNode*> level_order = level(root);
    int start = 0;
    while (start < in_order.size()) {
        if (in_order[start]->val == p->val || in_order[start]->val == q->val) break;
        else start++;
    }
    unordered_set<TreeNode*> candidates;
    candidates.insert(in_order[start]);
    int end = start + 1;
    while (end < in_order.size()) {
        if (in_order[end]->val == p->val || in_order[end]->val == q->val) break;
        else {
            candidates.insert(in_order[end]);
            end++;
        }
    }
    candidates.insert(in_order[end]);
    for (auto* i : level_order)
        if (candidates.find(i) != candidates.end()) return i;
    return nullptr;
}

/***************************************************************************/
/*
 * Description: Given a binary tree, check whether it is a mirror of itself
 * */
/***************************************************************************/
bool isTwoTreeSymm(TreeNode* root1, TreeNode* root2) {
    if ((!root1 && root2) || (root1 && !root2)) return false;
    if (!root1 && !root2) return true;
    if (root1->val == root2->val) {
        return isTwoTreeSymm(root1->left, root2->right) && isTwoTreeSymm(root1->right, root2->left);
    } else return false;
}

bool Solution::isSymmetric(TreeNode *root) {
    if (!root) return true;
    return isTwoTreeSymm(root->left, root->right);
}


/***************************************************************************/
/*
 * Description: Input: "1-2--3--4-5--6--7" Output: [1,2,5,3,4,6,7]
 * If a node has only one child, that child is guaranteed to be the left child.
 * */
/***************************************************************************/
TreeNode* Solution::recoverFromPreorder(const string &S) {
    stack<pair<TreeNode*, int>> store;
    int d_prev = 0;
    int d_curr = 0;
    int value = 0;
    int i = 0;
    while (i < S.size()) {
        if (S[i] == '-') break;
        value = value * 10 + S[i] - '0';
        i++;
    }
    auto* root = new TreeNode(value);
    store.emplace(root, 0);
    while (i < S.size()) {
        d_curr = 0;
        value = 0;
        TreeNode* node = store.top().first;
        while (S[i] == '-') {
            d_curr++;
            i++;
        }
        while (S[i] != '-') {
            value = value * 10 + S[i] - '0';
            i++;
            if (i == S.size())
                break;
        }
        if (d_curr > d_prev) {
            node->left = new TreeNode(value);
            store.emplace(node->left, d_curr);
        } else if (d_curr == d_prev) {
            store.pop();
            node = store.top().first;
            node->right = new TreeNode(value);
            store.pop();
            store.emplace(node->right, d_curr);
        } else {
            while (store.top().second >= d_curr) {
                store.pop();
            }
            node = store.top().first;
            node->right = new TreeNode(value);
            store.pop();
            store.emplace(node->right, d_curr);
        }
        d_prev = d_curr;
    }
    return root;
}


/********************************************************************************/
/*
 * Description: Given an array where elements are sorted in ascending order,
 * convert it to a height balanced BST. For this problem, a height-balanced
 * binary tree is defined as a binary tree in which the depth of the two
 * subtrees of every node never differ by more than 1.
 * */
/********************************************************************************/
TreeNode* toBST(vector<int>& nums, int l, int r) {
    if (l > r) return nullptr;
    int mid = (l + r) / 2;
    auto* node = new TreeNode(nums[mid]);
    node->left = toBST(nums, l, mid - 1);
    node->right = toBST(nums, mid + 1, r);
    return node;
}

TreeNode* Solution::sortedArrayToBST(vector<int> &nums) {
    if (nums.empty()) return nullptr;
    int l = 0, r = nums.size() - 1;
    return toBST(nums, l, r);
}


/**
 * Given a binary tree and a sum, determine if the tree has a path, that the sum equals the sum
 * @param root: the tree's root
 * @param sum: the target sum
 * @return
 */
bool Solution::hasPathSum(TreeNode *root, int sum) {
    if (!root) return false;
    int sub_sum = sum - root->val;
    if (sub_sum == 0 && !root->left && !root->right) return true;
    return hasPathSum(root->left, sub_sum) || hasPathSum(root->right, sub_sum);
}


/**
 * https://leetcode-cn.com/problems/recover-binary-search-tree/
 * TODO: optimize the space complexity, O(N) -> O(1)
 * @param root
 */
void Solution::recoverTree(TreeNode *root) {
    /* First inorder traverse and get a vector than contains nodes in increasing order of value */
    vector<TreeNode*> inorder;
    stack<TreeNode*> store;
    store.push(root);
    TreeNode* node = root;
    while (node->left) {
        store.push(node->left);
        node = node->left;
    }
    while (!store.empty()) {
        node = store.top();
        inorder.push_back(node);
        store.pop();
        if (node->right) {
            store.push(node->right);
            node = node->right;
            while (node->left) {
                store.push(node->left);
                node = node->left;
            }
        }
    }

    // Then swap the wrong value
    for (int i = (int) inorder.size() - 1; i > 0; i--) {
        int target = 0;
        if (inorder[i]->val < inorder[i - 1]->val) {
            target = inorder[i]->val;
            for (int j = 0; j < i; j++) {
                if (inorder[j]->val > target) {
                    inorder[i]->val = inorder[j]->val;
                    inorder[j]->val = target;
                    break;
                }
            }
            break;
        }
    }
}


/**
 * https://leetcode-cn.com/problems/balanced-binary-tree/
 * Solution: 1. 自顶向下递归
 *           2. 自底向上递归
 * @param root
 * @return
 */
int Depth(TreeNode* root) {
    if (!root) return 0;
    int depth = 0;
    queue<TreeNode*> store;
    store.push(root);
    while (!store.empty()) {
        int size = store.size();
        for (int i = 0; i < size; i++) {
            TreeNode* p = store.front();
            cout << p->val << " ";
            if (p->left) store.push(p->left);
            if (p->right) store.push(p->right);
            store.pop();
        }
        depth++;
    }
    return depth;
}

int Height(TreeNode* root) {
    if (!root) return 0;
    int h_l = 0, h_r = 0;
    if (root->left) h_l = Height(root->left);
    if (root->right) h_r = Height(root->right);
    if (abs(h_l - h_r) > 1 || h_l == -1 || h_r == -1) return -1;
    else return max(h_r, h_l);
}

bool Solution::isBalanced(TreeNode *root) {
    // O(n^2) 方法
    /*if (!root) return true;
    int delta = Depth(root->left) - Depth(root->right);
    if (abs(delta) > 1) return false;
    else return isBalanced(root->left) && isBalanced(root->right);*/

    // O(n) 方法
    return Height(root) >= 0;
}


/**
 * https://leetcode-cn.com/problems/convert-sorted-list-to-binary-search-tree/
 * @param head
 * @return
 */
TreeNode* sortedListToBSTLength(ListNode* head, int length) {
    if (length == 0) return nullptr;
    if (length == 1) return new TreeNode(head->val);
    if (length == 2) {
        auto root = new TreeNode(head->val);
        root->right = new TreeNode(head->next->val);
        return root;
    }
    int mid = length / 2;
    ListNode* p = head;
    for (int i = 0; i < mid; i++) {
        p = p->next;
    }
    auto* root = new TreeNode(p->val);
    root->left = sortedListToBSTLength(head, mid);
    root->right = sortedListToBSTLength(p->next, length - mid - 1);
    return root;
}

// 通过快慢指针来找到链表中间的节点，并把中间节点前的节点的下一下节点指向null
ListNode* middle(ListNode* head) {
    ListNode* fast = head, *slow = head;
    ListNode* pre = nullptr;
    while (fast && fast->next) {
        fast = fast->next->next;
        pre = slow;
        slow = slow->next;
    }
    if (pre) pre->next = nullptr;
    return slow;
}

TreeNode* Solution::sortedListToBST(ListNode *head) {
    ListNode* p1 = head;
    ListNode* p2 = head;
    TreeNode* root;
    int length = 0, l = 0;
    while (p2) {
        if (p2->next) {
            p2 = p2->next->next;
            length += 2;
        } else {
            length++;
            break;
        }
        p1 = p1->next;
        l++;
    }
    l++;
    root = new TreeNode(p1->val);
    root->left = sortedListToBSTLength(head, l - 1);
    root->right = sortedListToBSTLength(p1->next, length - l);
    return root;
}


/**
 * https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/
 * @param root
 * @return
 */
int Solution::minDepth(TreeNode *root) {
    queue<TreeNode*> store;
    store.push(root);
    int depth = 1;
    while (!store.empty()) {
        int size = store.size();
        for (int i = 0; i < size; i++) {
            TreeNode* p = store.front();
            bool flag = true;
            if (p->left) {
                store.push(p->left);
                flag = false;
            }
            if (p->right) {
                store.push(p->right);
                flag = false;
            }
            if (flag) return depth;
            store.pop();
        }
        depth++;
    }
    return depth;
}

void dfs(TreeNode* root, string& curr_path, vector<string>& paths) {
    if (!root->right && !root->left) {
        paths.push_back(curr_path);
        return;
    }
    string next_path;
    if (root->right) {
        next_path = curr_path;
        next_path += "->";
        next_path += to_string(root->right->val);
        dfs(root->right, next_path, paths);
    }
    if (root->left) {
        next_path = curr_path;
        next_path += "->";
        next_path += to_string(root->left->val);
        dfs(root->left, next_path, paths);
    }
}

/**
 * https://leetcode-cn.com/problems/binary-tree-paths/
 * @param root
 * @return
 */
vector<string> Solution::binaryTreePaths(TreeNode *root) {
    if (!root) return {};
    vector<string> paths;
    string curr_path;
    curr_path += to_string(root->val);
    dfs(root, curr_path, paths);
    return paths;
}


/**
 * https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii/
 * @param root
 * @return
 */
vector<vector<int>> Solution::levelOrderBottom(TreeNode *root) {
    queue<TreeNode*> store;
    if (!root) return {};
    store.push(root);
    vector<vector<int>> res;
    while (!store.empty()) {
        int size = store.size();
        vector<int> temp;
        for (int i = 0; i < size; i++) {
            auto cur = store.front();
            temp.push_back(cur->val);
            if (cur->left) store.push(cur->left);
            if (cur->right) store.push(cur->right);
            store.pop();
        }
        res.push_back(temp);
    }
    reverse(res.begin(), res.end());
    return res;
}


/**
 * https://leetcode-cn.com/problems/average-of-levels-in-binary-tree/
 * @param root
 * @return
 */
vector<double> Solution::averageOfLevels(TreeNode *root) {
    if (!root) return {};
    queue<TreeNode*> store;
    store.push(root);
    vector<double> res;
    while (!store.empty()) {
        int size = store.size();
        double cur_sum = 0;
        for (int i = 0; i < size; i++) {
            cur_sum += store.front()->val;
            if (store.front()->left) store.push(store.front()->left);
            if (store.front()->right) store.push(store.front()->right);
            store.pop();
        }
        res.push_back(cur_sum / size);
    }
    return res;
}


/**
 * https://leetcode-cn.com/problems/sum-of-left-leaves/
 * @param root
 * @return
 */
void dfs(TreeNode* root, int& res) {
    if (!root) return;
    if (root->left) {
        if (!root->left->left && !root->left->right) {
            res += root->left->val;
        } else dfs(root->left, res);
    }
    if (root->right) {
        dfs(root->right, res);
    }
}

int Solution::sumOfLeftLeaves(TreeNode *root) {
    if (!root) return 0;
    int res = 0;
    dfs(root, res);
    return res;
}


/**
 * https://leetcode-cn.com/problems/convert-bst-to-greater-tree/
 */
TreeNode* Solution::convertBST(TreeNode *root) {
    if (!root) return nullptr;
    stack<TreeNode*> store;
    auto p = root;
    while (p) {
        store.push(p);
        p = p->right;
    }
    int sum = 0;
    while (!store.empty()) {
        p = store.top();
        sum += p->val;
        p->val = sum;
        store.pop();
        if (p->left) {
            p = p->left;
            while (p) {
                store.push(p);
                p = p->right;
            }
        }
    }
    return root;
}


/**
 * https://leetcode-cn.com/problems/path-sum-ii/
 * @param root
 * @param sum
 * @return
 */
void traverse(TreeNode* node, int cur_sum, int sum, vector<int>& cur_res, vector<vector<int>>& res) {
    if (cur_sum == sum && !node->left && !node->right) {
        res.push_back(cur_res);
        return;
    }
    if (node->left) {
        cur_sum += node->left->val;
        cur_res.push_back(node->left->val);
        traverse(node->left, cur_sum, sum, cur_res, res);
        cur_res.pop_back();
        cur_sum -= node->left->val;
    }
    if (node->right) {
        cur_sum += node->right->val;
        cur_res.push_back(node->right->val);
        traverse(node->right, cur_sum, sum, cur_res, res);
        cur_res.pop_back();
        cur_sum -= node->right->val;
    }

}

vector<vector<int>> Solution::pathSum(TreeNode *root, int sum) {
    if (!root) return {};
    int cur_sum = root->val;
    vector<int> cur_res = {root->val};
    vector<vector<int>> res;
    traverse(root, cur_sum, sum, cur_res, res);
    return res;
}


/**
 * https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
 * @param root
 * @param p
 * @param q
 * @return
 */
TreeNode* Solution::lowestCommonAncestorBST(TreeNode *root, TreeNode *p, TreeNode *q) {
    auto cur = root;
    TreeNode* small = nullptr, *large = nullptr;
    if (p->val > q->val) {
        small = q;
        large = p;
    } else {
        large = q;
        small = p;
    }
    while (cur) {
        if (cur->val >= small->val && cur->val <= large->val) return cur;
        if (cur->val > large->val) cur = cur->left;
        else if (cur->val < small->val) cur = cur->right;
    }
    return nullptr;
}


/**
 * https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/
 * @param root
 * @return
 */
int maxGain(TreeNode* node, int& res) {
    if (!node) return 0;
    int left_gain = max(maxGain(node->left, res), 0);
    int right_gain = max(maxGain(node->right, res), 0);
    int price_new_path = node->val + left_gain + right_gain;
    res = max(res, price_new_path);
    return node->val + max(left_gain, right_gain);
}

int Solution::maxPathSum(TreeNode *root) {
    int res = INT32_MIN;
    maxGain(root, res);
    return res;
}