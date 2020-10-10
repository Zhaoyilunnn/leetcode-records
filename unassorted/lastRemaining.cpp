//
// Created by zyl on 2020/3/30.
//

#include "include/algorithms_data_structures.h"

/**********************************************************************************/
/* Description: 0,1,,n-1这n个数字排成一个圆圈，从数字0开始，每次从这个圆圈里删除第m个数字。
 * 求出这个圆圈里剩下的最后一个数字。例如，0、1、2、3、4这5个数字组成一个圆圈，从
 * 数字0开始每次删除第3个数字，则删除的前4个数字依次是2、0、4、1，因此最后剩下的数字是3。
 *
 * Solution 1:  用一个vector存储，根据step每次删掉一个元素
 * Solution 2:  用循环单链表模拟整个过程 (约瑟夫环问题) 时间复杂度 O(n*m)
 *              如果只需要知道最后剩下的数字，可以直接套公式 */
/**********************************************************************************/

/*struct listNode {
    int val;
    listNode* next = nullptr;
    listNode(int x) : val(x) {};
};*/

int Solution::lastRemaining(int n, int m) {
    if (n == 1)
        return 1;
    return (lastRemaining(n-1, m) + m) % n;
}