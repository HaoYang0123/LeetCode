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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mm;
        for(int i = 0; i < inorder.size(); ++i) {
            mm[inorder[i]] = i;
        }
        return buildTree(preorder, 0, preorder.size(), inorder, 0, mm);
    }
    TreeNode* buildTree(vector<int> & preorder, int index1, int len1, vector<int> & inorder, int index2, unordered_map<int, int> & mm)     {
        if(len1 <= 0) return NULL;
        int rootVal = preorder[index1];
        TreeNode* res = new TreeNode(rootVal);
        int inoIndex = mm[rootVal];
        int leftLen = inoIndex - index2;
        int rightLen = len1 - leftLen - 1;
        res->left = buildTree(preorder, index1 + 1, leftLen, inorder, index2, mm);
        res->right = buildTree(preorder, index1 + 1 + leftLen, rightLen, inorder, index2 + 1 + leftLen, mm);
        return res;
    }
};
