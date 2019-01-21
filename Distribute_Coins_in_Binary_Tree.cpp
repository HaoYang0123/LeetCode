//Leetcode 979

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
    int distributeCoins(TreeNode* root) {
        res = 0;
        dfs(root);
        return res;
    }
    
    int dfs(TreeNode* root) { //返回root为根结点的树，给上层节点的coin数目
        if(root == NULL) return 0;
        int left = dfs(root->left), right = dfs(root->right); //从左子树获得的coin数目，从右子树获得的coin数目
        res += abs(left) + abs(right); //移动数目就等于从左子树和右子树获得的coin数目，由于有可能有负数，所以取绝对值
        return root->val + left + right - 1; //从左、右子树获得的coin求和，加上自己当前的coin数目，-1表示最后给自己保留1个coin，其余的返回给上一层
    }
};
