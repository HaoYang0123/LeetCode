//Leetcode 889

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
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        vector<int> map(32, -1);
        for(int i=0;i<post.size();++i) {
            map[post[i]] = i;
        }
        return dfs(pre, 0, pre.size()-1, post, 0, post.size()-1, map);
    }
    TreeNode* dfs(vector<int> & pre, int s1, int e1, vector<int> & post, int s2, int e2, vector<int>& map) {
        if(s1 > e1) return NULL;
        if(s1 == e1) return new TreeNode(pre[s1]);
        TreeNode* res = new TreeNode(pre[s1]);
        int left_val = pre[s1+1];
        int index_in_post = map[left_val];
        int left_num = index_in_post - s2 + 1;
        res->left = dfs(pre, s1 + 1, s1 + left_num, post, s2, s2 + left_num - 1, map);
        res->right = dfs(pre, s1 + left_num + 1, e1, post, s2 + left_num, e2 - 1, map);
        return res;
    }
};
