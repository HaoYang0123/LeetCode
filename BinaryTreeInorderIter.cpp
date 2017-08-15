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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> sta;
        TreeNode* pCurrent = root;
        while(!sta.empty() || pCurrent != NULL) {
            while(pCurrent != NULL) {
                sta.push(pCurrent);
                pCurrent = pCurrent->left;
            }
            pCurrent = sta.top();
            sta.pop();
            res.push_back(pCurrent->val);
            pCurrent = pCurrent->right;
        }
        return res;
    }
};
