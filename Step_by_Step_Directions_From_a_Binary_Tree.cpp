// Leetcode 2096


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
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* same_parent = get_lca(root, startValue, destValue);
        //cout<<same_parent->val<<endl;
        string leftpath = "", rightpath = "";
        dfs(same_parent, startValue, leftpath);
        dfs(same_parent, destValue, rightpath);
        for(int i=0; i<leftpath.length(); ++i) leftpath[i] = 'U';
        return leftpath + rightpath;
    }
    
    TreeNode* get_lca(TreeNode* root, int s, int e) {
        if(root == NULL) return NULL;
        if(root->val == s || root->val == e) return root;
        TreeNode* left_r = get_lca(root->left, s, e);
        TreeNode* right_r = get_lca(root->right, s, e);
        if(left_r != NULL && right_r != NULL) return root;
        if(left_r != NULL) return left_r;
        if(right_r != NULL) return right_r;
        return NULL;
    }
    
     bool dfs(TreeNode*root , int target , string &path)
    {
        if(!root )
            return false;
        //if target is reached return 
        if(root->val == target)
            return true;
        
        path += "L"; // move to left
        if(dfs(root->left, target , path))
            return true; // if path is found no need to traverse anymore
        path.pop_back(); // else backtrack
        
		//similarly for right nodes
        path+="R"; 
        if(dfs(root->right ,target , path))
            return true;
        path.pop_back();
        
        return false;
    }
    
    bool dfs_me(TreeNode* root, int s, string& path) {  //为何我这个会MLE呢？？？感觉和网上AC的dfs是一样的
        if(root == NULL) return false;
        if(root->val == s) return true;
        if(dfs(root->left, s, path)) {
            path = 'L' + path;
            return true;
        }
        if(dfs(root->right, s, path)) {
            path = 'R' + path;
            return true;
        }
        return false;
    }
};
