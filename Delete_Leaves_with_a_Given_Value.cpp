//Leetcode 1325

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
	TreeNode* removeLeafNodes(TreeNode* root, int target) {
		return dfs(root, target);
	}
  
	TreeNode * dfs(TreeNode * root, int target) { //如果root被删除完，则返回NULL
		if (root == NULL) return NULL;
		if (root->val != target) {
			root->left = dfs(root->left, target);
			root->right = dfs(root->right, target);
			return root;
		}
		TreeNode * left_flag = dfs(root->left, target);
		TreeNode * right_flag = dfs(root->right, target);
		root->left = left_flag;
		root->right = right_flag;
		if (left_flag == NULL && right_flag == NULL) {
			return NULL;
		}
		return root;
	}
};
