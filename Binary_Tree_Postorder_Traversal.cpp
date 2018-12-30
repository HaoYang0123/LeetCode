//Leetcode 145
//使用非递归方式去计算树的后序遍历：

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
        stack<TreeNode*> sta;
        vector<int> res;
        sta.push(root);
        while(!sta.empty()) {
            TreeNode* cur = sta.top();
            sta.pop();
            if(cur==NULL) continue;
            res.push_back(cur->val);
            sta.push(cur->left);
            sta.push(cur->right);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

//当然，用递归方式更加容易理解。

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        return dfs(root);
    }
    
    vector<int> dfs(TreeNode* root) {
        if(root == NULL) return vector<int>();
        vector<int> left = dfs(root->left), right = dfs(root->right);
        vector<int> res;
        res.insert(res.end(), left.begin(), left.end());
        res.insert(res.end(), right.begin(), right.end());
        res.push_back(root->val);
        return res;
    }
};
