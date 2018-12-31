//Leetcode 951

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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        return dfs(root1, root2);
    }
    
    bool dfs(TreeNode* r1, TreeNode* r2) {
        if(r1 == NULL && r2 == NULL) return true;
        if(r1 == NULL) return false;
        if(r2 == NULL) return false;
        if(r1->val != r2->val) return false;
        if(dfs(r1->left, r2->left) && dfs(r1->right, r2->right)) return true;
        if(dfs(r1->left, r2->right) && dfs(r1->right, r2->left)) return true;
        return false;
    }
};
