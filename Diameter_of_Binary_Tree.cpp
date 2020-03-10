//Leetcode 543

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
    int diameterOfBinaryTree(TreeNode* root) {
        res = INT_MIN;
        if(root == NULL) return 0;
        int leftHeight = 0, rightHeight = 0;
        dfs(root, leftHeight, rightHeight);
        return res;
    }
    
    int dfs(TreeNode* root, int & leftHeight, int & rightHeight) {
        if(root == NULL || (root->left == NULL && root->right == NULL)) {
            leftHeight = 0;
            rightHeight = 0;
        }
        else {
            int leftTree_leftHeight = 0, leftTree_rightHeight = 0;
            int rightTree_leftHeight = 0, rightTree_rightHeight = 0;
            dfs(root->left, leftTree_leftHeight, leftTree_rightHeight);
            dfs(root->right, rightTree_leftHeight, rightTree_rightHeight);
            leftHeight = (leftTree_leftHeight > leftTree_rightHeight ? leftTree_leftHeight : leftTree_rightHeight);
            rightHeight = (rightTree_leftHeight > rightTree_rightHeight ? rightTree_leftHeight : rightTree_rightHeight);
            if(root->left != NULL)
                ++leftHeight;
            if(root->right != NULL)
                ++rightHeight;
        }
        if(res < leftHeight + rightHeight) res = leftHeight + rightHeight;
        
        return leftHeight + rightHeight;
    }
};
