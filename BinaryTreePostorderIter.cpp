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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> sta;
        int flag[100];
        TreeNode* pCurrent = root;
        if(pCurrent == NULL) return res;
        while(pCurrent != NULL) {
            sta.push(pCurrent);
            flag[sta.size()] = 0;
            pCurrent = pCurrent->left;
        }
        while(!sta.empty()) {
            pCurrent = sta.top();
            while(pCurrent->right != NULL && flag[sta.size()] == 0) {
                flag[sta.size()] = 1;
                pCurrent = pCurrent->right;
                while(pCurrent != NULL) {
                    sta.push(pCurrent);
                    flag[sta.size()] = 0;
                    pCurrent = pCurrent->left;
                }
            }
            pCurrent = sta.top();
            sta.pop();
            res.push_back(pCurrent->val);
        }
        return res;
    }

};
