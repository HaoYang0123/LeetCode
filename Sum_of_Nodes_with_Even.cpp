//Leetcode 1315

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
    int sumEvenGrandparent(TreeNode* root) {
        if(root == NULL) return 0;
        int res = 0;
        queue<TreeNode*> qs;
        qs.push(root); //宽度搜索整棵树
        while(!qs.empty()) {
            TreeNode* r = qs.front();
            res += get_res(r);
            qs.pop();
            if(r->left != NULL) qs.push(r->left);
            if(r->right != NULL) qs.push(r->right);
        }
        return res;
    }
    
    int get_res(TreeNode* root) { //以root为根的子树的结果
        if(root == NULL) return 0;
        if(root->val % 2 != 0) return 0; //如果root本身不是偶数，则以root为grandparent的孙子结点都不能考虑
        int res = 0; //否则，将以root为grandparent的所有孙子结点求和，返回结果
        if(root->left != NULL) {
            if(root->left->left != NULL) res += root->left->left->val;
            if(root->left->right != NULL) res += root->left->right->val;
        }
        if(root->right != NULL) {
            if(root->right->left != NULL) res += root->right->left->val;
            if(root->right->right != NULL) res += root->right->right->val;
        }
        return res;
    }
};
