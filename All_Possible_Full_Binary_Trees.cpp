//Leetcode 894
//动态规划 dp[n]=((dp[1],dp[n-2]), (dp[3],dp[n-4]), ..., (dp[n-2], dp[1]))

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
    vector<vector<TreeNode*>> dp;
    vector<TreeNode*> allPossibleFBT(int N) {
        dp.resize(N+1);
        dp[1].push_back(new TreeNode(0));
        return dfs(N);
    }
    vector<TreeNode*> dfs(int N) {
        if(dp[N].size() > 0) return dp[N];
        vector<TreeNode*> res;
        for(int i=1; i<N-1; i+=2) {
            vector<TreeNode*> left = dfs(i), right = dfs(N-1-i);
            for(int j=0;j<left.size();++j) {
                for(int k=0;k<right.size();++k) {
                    TreeNode* root=new TreeNode(0);
                    root->left = left[j];
                    root->right = right[k];
                    res.push_back(root);
                }
            }
        }
        dp[N] = res;
        return res;
    }
};
