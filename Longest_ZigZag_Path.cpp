//Leetcode 1372

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
    int res;
    int longestZigZag(TreeNode* root) {
        res = 0;
        dfs(root, 0);
        return res;
    }
    
    void dfs(TreeNode* root, int depth) {
        if(root==NULL) return;
        //depth<0表示向左，>0表示向右
        res = max(res, abs(depth));
        dfs(root->left, depth>0?-depth-1:-1);
        dfs(root->right, depth<0?-depth+1:1);
    }
};
