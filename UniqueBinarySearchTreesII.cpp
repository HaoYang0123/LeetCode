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
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0){
            vector<TreeNode*> res;
            return res;
        }
        return dfs(1, n);
    }
    
    vector<TreeNode*> dfs(int start, int end) {
        vector<TreeNode*> res;
        if(start > end) { 
            res.push_back(NULL);
            return res;
        }
        for(int i = start; i <= end; ++i) {
            vector<TreeNode*> left = dfs(start, i - 1), right = dfs(i + 1, end);
            for(int j = 0; j < left.size(); ++j) {
                for(int k = 0; k < right.size(); ++k) {
                    TreeNode* tmp = new TreeNode(i);
                    tmp->left = left[j];
                    tmp->right = right[k];
                    res.push_back(tmp);
                }
            }
        }
        return res;
    }
};
