//Leetcode 1026

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
    int maxAncestorDiff(TreeNode* root) {
        res = INT_MIN;
        dfs(root);
        return res;
    }
    
    pair<int, int> dfs(TreeNode* root) {
        pair<int, int> rr;
        int minv=root->val, maxv=root->val;
        if(root->left != NULL) {
            pair<int, int> left = dfs(root->left);
            minv=min(left.first, minv);
            maxv=max(left.second, maxv);
            res=max(res, abs(left.first-root->val));
            res=max(res, abs(left.second-root->val));
        }
        if(root->right != NULL) {
            pair<int, int> right = dfs(root->right);
            minv=min(right.first, minv);
            maxv=max(right.second, maxv);
            res=max(res, abs(right.first-root->val));
            res=max(res, abs(right.second-root->val));
        }
        rr.first = minv;
        rr.second = maxv;
        return rr;
    }
};
