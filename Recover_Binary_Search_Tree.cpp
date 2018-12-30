//Leetcode 99
//出现乱序的两个数字，如果按照左中右顺序（中序遍历），那么两个数字一定是相邻的
//比如：题目中的第二个例子：1，3，2，4
//那么先从左、中、右的顺序，可以找到结点2违反了规则（因为：2的左边中最大的值是3，当前值2<3）
//然后从右、中、左的顺序，又可以找到结点3违反了规则（因为：3的右边中最小的值是2，当前值3>2）
//最后，将找到的两个值交换顺序

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *loc1=NULL,*loc2=NULL;
    void recoverTree(TreeNode* root) {
        long long max=2147483648,min=-2147483649;
        leftInOrderSearch(root,min);
        rightInOrderSearch(root,max);
        int value;
        value=loc1->val;
        loc1->val=loc2->val;
        loc2->val=value;  
    }
    void leftInOrderSearch(TreeNode* node, long long &lastValue)
    {
        if(!node)
            return;
        leftInOrderSearch(node->left,lastValue);
        if(lastValue<(long long)node->val)
            lastValue=node->val;
        else
            loc1=node;
        leftInOrderSearch(node->right,lastValue);
    }
    void rightInOrderSearch(TreeNode* node, long long &lastValue)
    {
        if(!node)
            return;
        rightInOrderSearch(node->right,lastValue);
        if(lastValue>(long long)node->val)
            lastValue=node->val;
        else
            loc2=node;
        rightInOrderSearch(node->left,lastValue);
    }
};
