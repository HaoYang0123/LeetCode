//Leetcode 1382

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
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> res;
        dfs(root, res);
        return dfs(res, 0, res.size()-1);
    }
    
    TreeNode* dfs(vector<int> & res, int start, int end) {
        if(start > end) return NULL;
        int mid = (start+end) / 2;
        TreeNode* root = new TreeNode(res[mid]);
        root->left = dfs(res, start, mid-1);
        root->right = dfs(res, mid+1, end);
        return root;
    }
    
    void dfs(TreeNode* root, vector<int> & res) {
        if(root == NULL) return;
        vector<int> left, right;
        dfs(root->left, left);
        dfs(root->right, right);
        res = left;
        res.push_back(root->val);
        res.insert(res.end(), right.begin(), right.end());
    }
};
