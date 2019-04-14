//Leetcode 783

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
    int minDiffInBST(TreeNode* root) {
        res = INT_MAX;
        if(root == NULL) return res;
        pair<int, int> min_max;
        dfs(root, min_max);
        return res;
    }
    void dfs(TreeNode* root, pair<int, int> & min_max) {
        int min_val = root->val, max_val = root->val;
        if(root->left != NULL) {
            pair<int, int> left;
            dfs(root->left, left);
            min_val = left.first;
            res = min(res, root->val - left.second);
        }
        if(root->right != NULL) {
            pair<int, int> right;
            dfs(root->right, right);
            max_val = right.second;
            res = min(res, right.first - root->val);
        }
        min_max.first = min_val;
        min_max.second = max_val;
    }
};
