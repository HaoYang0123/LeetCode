//Leetcode 897

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
    TreeNode* increasingBST(TreeNode* root) {
        return dfs(root)[0];
    }
    
    vector<TreeNode*> dfs(TreeNode* root) {
        vector<TreeNode*> res(2, NULL);
        if (root == NULL) return res;
        vector<TreeNode*> left = dfs(root->left), right = dfs(root->right);
        if(left[0] != NULL) { 
            res[0] = left[0];
            left[1]->right = root;
        }
        else {
            res[0] = root;
        }
        
        if(right[1] != NULL) { 
            res[1] = right[1];
            root->right = right[0];
        }
        else res[1] = root;
        root->left = NULL; //一定注意需要将root左边的置NULL，不然会出现环，导致死循环。
        //write(res[0]);
        return res;
    }
    void write(TreeNode* root) {
        TreeNode* cur=root;
        while(cur!=NULL) {
            cout<<cur->val<<endl;
            cur=cur->right;
        }
        cout<<"========="<<endl;
    }
};
