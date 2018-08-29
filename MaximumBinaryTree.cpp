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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return dfs(nums, 0, nums.size()-1);
    }
    
    TreeNode* dfs(vector<int>& nums, int start, int end) {
        if (start > end) {return NULL;}
        if (start == end) {
            return new TreeNode(nums[start]);
        }
        int max_index = start;
        int max_value = nums[start];
        for (int i = start + 1; i <= end; ++i) {
            if (nums[i] > max_value) {
                max_value = nums[i];
                max_index = i;
            }
        }
        TreeNode* res = new TreeNode(max_value);
        res->left = dfs(nums, start, max_index-1);
        res->right = dfs(nums, max_index+1, end);
        return res;
    }
};
