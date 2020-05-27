//Leetcode 1457

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int res;
    int pseudoPalindromicPaths (TreeNode* root) {
        res = 0;
        if(root == NULL) return res;
        unordered_map<int,int> v2c;
        dfs(root, v2c);
        return res;
    }
    
    void dfs(TreeNode* root, unordered_map<int,int> & v2c) {
        v2c[root->val]++;
        if(root->left == NULL && root->right == NULL) { //叶子结点
            if(is_ok(v2c)) ++res;
            v2c[root->val]--;
            return ;
        }
        //unordered_map<int,int> new_v2c = v2c;
        if(root->left != NULL) dfs(root->left, v2c);
        //unordered_map<int,int> new_v2c2 = v2c;
        if(root->right != NULL) dfs(root->right, v2c);
        v2c[root->val]--;
    }
    
    inline bool is_ok(unordered_map<int,int> & v2c) {
        int odd_num = 0;
        for(auto ind = v2c.begin(); ind != v2c.end(); ++ind) {
            //cout<<ind->first<<":"<<ind->second<<"\t";
            if(ind->second % 2 != 0) {
                ++odd_num;
                if(odd_num>1) {
                    //cout<<endl;
                    return false;
                }
            }
        }
        //cout<<endl;
        return true;
    }
};
