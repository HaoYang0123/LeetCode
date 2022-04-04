// Leetcode 1448

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int res;
    int goodNodes(TreeNode* root) {
        res = 0;
        dfs(root, INT_MIN);
        return res;
    }
    
    void dfs(TreeNode* root, int cur_max) {
        if(root == NULL) return;
        if(root->val >= cur_max) ++res;
        cur_max = max(cur_max, root->val);
        dfs(root->left, cur_max);
        dfs(root->right, cur_max);
    }
};
