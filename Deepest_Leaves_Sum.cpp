//Leetcode 1302

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
    int deepestLeavesSum(TreeNode* root) {
        if(root == NULL) return 0;
        return get_deep_value(root).second;
    }
    pair<int,int> get_deep_value(TreeNode* root) { //pair<int,int>中第1个表示root为根的树高度，第2个表示最深的叶子值求和
        pair<int,int> res(1,root->val);
        int child_deep = 0;
        int left_deep = 0, right_deep = 0;
        int left_value = 0, right_value = 0;
        if(root->left != NULL) {
            pair<int,int> left = get_deep_value(root->left);
            child_deep = max(child_deep, left.first);
            left_value = left.second;
            left_deep = left.first;
        }
        if(root->right != NULL) {
            pair<int,int> right = get_deep_value(root->right);
            child_deep = max(child_deep, right.first);
            right_value = right.second;
            right_deep = right.first;
        }
        if(child_deep == 0) return res;
        int value = 0;
        if(child_deep == left_deep) value += left_value; //左子树的高度与树高度一致，则value加上左子树的最深叶子值求和
        if(child_deep == right_deep) value += right_value; //同理，对于右子树也是如此
        return pair<int,int>(child_deep + 1, value); //child_deep+1表示当前root为根的树高度
    }
};
