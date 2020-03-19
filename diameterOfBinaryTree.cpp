//
// Created by zyl on 2020/3/10.
//

#include "function_defs.h"

int depth(TreeNode* root) {
    if (root) {
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
