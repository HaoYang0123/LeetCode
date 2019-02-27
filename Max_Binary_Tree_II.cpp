//Leetcode 998

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
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        TreeNode* pre = root, * cur = root;
        while(cur != NULL) {
            if(cur->val < val) break;
            pre = cur;
            cur = cur->right;
        }
        if(cur == root) { //如果A中最大的值（即root结点）均比val小，那么val作为根结点，之前的根结点作为新根结点的左子树
            TreeNode* new_node = new TreeNode(val);
            new_node->left = root;
            return new_node;
        }
        if(cur == NULL) { //如果cur是空指针，说明根结点往右走，所有的右子树的值均比val大，那么val只能作为pre的右子树
            TreeNode* new_node = new TreeNode(val);
            pre->right = new_node;
            return root;
        }
        //否则，将val作为pre的右子树，之前的右子树作为val的左子树
        TreeNode* new_node = new TreeNode(val);
        pre->right = new_node;
        new_node->left = cur;
        return root;
    }
};
