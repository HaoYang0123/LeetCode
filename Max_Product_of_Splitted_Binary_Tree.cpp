//Leetcode 1339

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
    unordered_map<TreeNode*, int> root2sum;
    int maxProduct(TreeNode* root) {
        int all_sum = get_value(root);
        long long res = 0;
        for(auto ind = root2sum.begin(); ind != root2sum.end(); ++ind) {
            long long tmp = (long long)(ind->second) * (long long)(all_sum - ind->second);
            res = max(res, tmp);
        }
        return (int)(res % 1000000007);
    }
    
    int get_value(TreeNode* root) {
        if(root == NULL) return 0;
        int res = root->val + get_value(root->left) + get_value(root->right);
        root2sum[root] = res;
        return res;
    }
};
