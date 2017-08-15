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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> sta;
        TreeNode* current = root;
        if(current == NULL) return res;
        while(!sta.empty() || current != NULL) {
            while(current != NULL) {
                res.push_back(current->val);
                sta.push(current);
                current = current->left;
            }
            current = sta.top();
            sta.pop();
            current = current->right;
        }
        return res;
    }

};
