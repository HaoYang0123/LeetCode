//Leetcode 1110

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
    unordered_map<int, TreeNode*> mm;
    unordered_map<int, int> child2parent;
    vector<TreeNode*> res;
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_map<int, bool> to_delete_map;
        for(int i=0;i<to_delete.size();++i) to_delete_map[to_delete[i]] = true;
        if(root == NULL) return res;
        if(to_delete_map.find(root->val) == to_delete_map.end()) res.push_back(root);
        dfs(root, to_delete_map);
        return res;
    }
    
    void dfs(TreeNode* root, unordered_map<int,bool> & to_delete) {
        if(root==NULL) return;
        auto ind=to_delete.find(root->val);
        if(root->left != NULL) child2parent[root->left->val] = root->val;
        if(root->right != NULL) child2parent[root->right->val] = root->val;
        mm[root->val] = root;
        if(ind==to_delete.end()) { //当前根结点不删除，那么递归调用
            dfs(root->left, to_delete);
            dfs(root->right, to_delete);
        }
        else { //当前根结点删除，则找到根结点的上一个结点
            auto parent_ind = child2parent.find(root->val);
            if(parent_ind != child2parent.end()) { //说明当前根结点不是全局树的根结点
                TreeNode* parent_node = mm[parent_ind->second];
                if(parent_node->left != NULL && parent_node->left->val == root->val)
                    parent_node->left = NULL;
                else parent_node->right = NULL;
            }
            if(root->left != NULL && to_delete.find(root->left->val) == to_delete.end()) res.push_back(root->left);
            if(root->right != NULL && to_delete.find(root->right->val) == to_delete.end()) res.push_back(root->right);
            dfs(root->left, to_delete);
            dfs(root->right, to_delete);
        }
    }
};
