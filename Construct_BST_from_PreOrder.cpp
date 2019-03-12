//Leetcode 1008

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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return dfs(preorder, 0, preorder.size()-1); 
    }
    
    TreeNode* dfs(vector<int> & preorder, int start, int end) {
        if(start>end) return NULL;
        if(start==end) return new TreeNode(preorder[start]);
        TreeNode* root = new TreeNode(preorder[start]);
        int i = start+1;
        for(;i<=end;++i) {
            if(preorder[i]>preorder[start]) break;
        }
        root->left = dfs(preorder, start+1, i-1);
        root->right = dfs(preorder, i, end);
        return root;
    }
};
