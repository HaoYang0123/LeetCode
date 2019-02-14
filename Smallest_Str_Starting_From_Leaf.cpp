//Leetcode 988

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
    string smallestFromLeaf(TreeNode* root) {
        return find_smallest(root);
    }
    
    string find_smallest(TreeNode* root) {
        if(root == NULL) return "";
        string l = find_smallest(root->left), r = find_smallest(root->right);
        string c = string(1,char(root->val+'a'));
        if(l==""&&r=="") return c;
        if(l=="") return r+c;
        if(r=="") return l+c;
        if(l<r) return l+c;
        return r+c;
    }
};
