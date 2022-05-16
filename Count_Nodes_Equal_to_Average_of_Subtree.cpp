// Leetcode 2265

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
    int averageOfSubtree(TreeNode* root) {
        res = 0;
        dfs(root);
        return res;
    }
    
    pair<int, int> dfs(TreeNode* root) {
        if(root == NULL) return {0,0};
        pair<int, int> left = dfs(root->left);
        pair<int, int> right = dfs(root->right);
        int sum = root->val+left.first+right.first;
        int num = 1+left.second+right.second;
        if(sum / num == root->val) ++res;
        return {sum, num};
    }
};
