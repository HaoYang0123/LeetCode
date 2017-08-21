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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> mm;
        for(int i = 0; i < inorder.size(); ++i) {
            mm[inorder[i]] = i;
        }
        return buildTree(inorder, inorder.size() - 1, inorder.size(), postorder, postorder.size() - 1, mm);
    }
    
    TreeNode* buildTree(vector<int> & inorder, int index1, int len1, vector<int> & postorder, int index2, unordered_map<int, int> & mm) {
        if(len1 <= 0) return NULL;
        int rootVal = postorder[index2];
        TreeNode* res = new TreeNode(rootVal);
        int inoIndex = mm[rootVal];
        int rightLen = index1 - inoIndex;
        int leftLen = len1 - rightLen - 1;
        res->right = buildTree(inorder, index1, rightLen, postorder, index2 - 1, mm);
        res->left = buildTree(inorder, index1 - 1 - rightLen, leftLen, postorder, index2 - 1 - rightLen, mm);
        return res;
    }
};
