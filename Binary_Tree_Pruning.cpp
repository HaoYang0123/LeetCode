//Leetcode 814
//dfs搜索，如果当前结点是NULL，则删除；再访问左结点和右结点，如果左结点需要删除，则root->left=NULL，右结点也是如此
//如果当前结点值为1，那么当前结点肯定需要保留；否则，只有当左结点和右结点都需要删除时，当前结点才会被删除，否则保留当前结点

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
    TreeNode* pruneTree(TreeNode* root) {
        bool flag = need_delete(root);
        if(flag) return NULL;
        return root;
    }
    
    bool need_delete(TreeNode* root) { //如果root没有包含1，则删除
        if(root == NULL) return true;
        bool left = need_delete(root->left), right = need_delete(root->right);
        if (left) root->left = NULL;
        if (right) root->right = NULL;
        if (root->val==1) return false;
        return left && right;
    }
};
