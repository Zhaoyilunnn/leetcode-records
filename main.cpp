//
//  main.cpp
//  leetcode
//
//  Created by zyl on 2019/11/1.
//  Copyright © 2019 zyl. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void Sort(vector<int>& nums) {
        if (nums.size() == 1)
            return;
        int end = int(nums.size() - 1);
        int temp = 0;
        while (end > 0) {
            for (int i = 1; i <= end; i++) {
                if (nums[i] <= nums[i-1]) {
                    temp = nums[i];
                    nums[i] = nums[i-1];
                    nums[i-1] = temp;
                }
            }
            end--;
        }
    }
    
    vector<int> FastSort(vector<int>& nums) {
        if (nums.size() <= 1) {
            return nums;
        }
        vector<int> pivot_list;
        vector<int> less;
        vector<int> greater;
        int pivot = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < pivot)
                less.push_back(nums[i]);
            else
                greater.push_back(nums[i]);
        }
        vector<int> sorted_less = FastSort(less);
        vector<int> sorted_greater = FastSort(greater);
        sorted_less.push_back(pivot);
        sorted_less.insert(sorted_less.end(), sorted_greater.begin(), sorted_greater.end());
        return sorted_less;
    }
    
    int findContentChildren(vector<int>& g, vector<int>& s) {
//        Sort(g);
//        Sort(s);
        g = FastSort(g);
        s = FastSort(s);
        int i = 0, j = 0;
        int result = 0;
        while (i < g.size() && j < s.size()) {
            if (g[i] <= s[j]) {
                result += 1;
                i++;
                j++;
            }
            else
                j++;
        }
        return result;
    }
    
    // 不同搜索二叉树|
    int numTrees(int n) {
        vector<int> vctRes;
        int j = 0;
        int k = 0;
        int iTemp = 0;
        for (int i = 0; i < n; i++) {
            if (i == 0)
                vctRes.push_back(1);
            else {
                j = 1;
                k = i+1;
                iTemp = 0;
                while (j <= k) {
                    if (j == 1)
                        iTemp += 2 * vctRes[i-1];
                    else if (j == k)
                        iTemp += vctRes[j-1-1] * vctRes[i-j];
                    else
                        iTemp += 2 * vctRes[j-1-1] * vctRes[i-j-1];
                    j++;
                    k--;
                }
                vctRes.push_back(iTemp);
            }
        }
        return vctRes[n-1];
    }
    
    // 不同搜索二叉树||
    vector<TreeNode*> generateTrees(int n) {
        vector<vector<TreeNode*> > vctRes;
        vector<TreeNode*> vctTmpRes;
        if (n == 1) {
            TreeNode* pNode = new TreeNode(1);
            vctTmpRes.push_back(pNode);
            return vctTmpRes;
        }
        TreeNode* pNode = NULL;
        for (int i = 0; i < n; i++) {
            if (!vctTmpRes.empty())
                vctTmpRes.clear();
            if (i == 0) {
                pNode = new TreeNode(1);
                vctTmpRes.push_back(pNode);
            }
            else {
                for (int j = 1; j <= i+1; j++) {
                    if (j == 1) {
                        for (int k = 0; k < vctRes[i-j].size(); k++) {
                            pNode = new TreeNode(j);
                            pNode->right = addTreevalue(j, vctRes[i-j][k]);
                            vctTmpRes.push_back(pNode);
                        }
                    }
                    else if (j == i+1) {
                        for (int k = 0; k < vctRes[i-1].size(); k++) {
                            pNode = new TreeNode(j);
                            pNode->left = addTreevalue(0, vctRes[i-1][k]);
                            vctTmpRes.push_back(pNode);
                        }
                    }
                    else {
                        for (int k = 0; k < vctRes[j-1-1].size(); k++) {
                            for (int m = 0; m < vctRes[i-j].size(); m++) {
                                pNode = new TreeNode(j);
                                pNode->left = addTreevalue(0, vctRes[j-1-1][k]);
                                pNode->right = addTreevalue(j, vctRes[i-j][m]);
                                vctTmpRes.push_back(pNode);
                            }
                        }
                    }
                }
            }
            vctRes.push_back(vctTmpRes);
        }
        return vctRes[n-1];
    }

    TreeNode* addTreevalue(int m, TreeNode* treeNode) {
        TreeNode* pRes = NULL;
        if (NULL != treeNode) {
            pRes = new TreeNode(treeNode->val + m);
            if (treeNode->left)
                pRes->left = addTreevalue(m, treeNode->left);
            if (treeNode->right)
                pRes->right = addTreevalue(m, treeNode->right);
        }
        return pRes;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> g = {10, 9, 8, 7};
    vector<int> s = {5, 6, 7, 8};
    Solution slt;
//    int result = slt.findContentChildren(g, s);
//    int result = slt.numTrees(3);
    vector<TreeNode*> result = slt.generateTrees(3);
    
//    std::cout << "Content children number is: " << result << endl;
    return 0;
}
