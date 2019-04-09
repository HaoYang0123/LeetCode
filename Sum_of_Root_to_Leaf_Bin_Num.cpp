//Leetcode 1022

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
    int res;
    int sumRootToLeaf(TreeNode* root) {
        res = 0;
        if(root == NULL) return 0;
        dfs(root, root->val);
        return res;
    }
    
    void dfs(TreeNode* root, int prev_value) { //prev_value表示从树的根结点到当前结点root的路径的和 
        //int new_value = (prev_value<<1);
        //cout<<"\t"<<root->val<<"\t"<<prev_value<<"\t"<<new_value<<endl;
        if(root->left == NULL && root->right == NULL) {
            res += prev_value; //如果root是叶结点，直接将和加入到res中
            //cout<<root->val<<"\t"<<new_value<<"\t"<<res<<endl;
            return;
        }
        if(root->left != NULL) {
            dfs(root->left, (prev_value<<1) + root->left->val); //如果有左子树，那么需要将prev_value*2，并加上左子树的结点的val
        }
        if(root->right != NULL) {
            dfs(root->right, (prev_value<<1) + root->right->val); //同左子树
        }
    }
};
