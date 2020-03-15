//Leetcode 1379

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
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        return dfs(original, cloned, target);
    }
    
    TreeNode* dfs(TreeNode* ori, TreeNode* clo, TreeNode* target) {
        if(ori == target) return clo;
        if(ori->left == NULL && ori->right == NULL) return NULL;
        if(ori->left != NULL) {
            TreeNode* left_flag = dfs(ori->left, clo->left, target);
            if(left_flag != NULL) return left_flag;
        }
        if(ori->right != NULL) {
            TreeNode* right_flag = dfs(ori->right, clo->right, target);
            if(right_flag != NULL) return right_flag;
        }
        return NULL;
    }
};
