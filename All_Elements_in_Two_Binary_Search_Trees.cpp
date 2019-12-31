//Leetcode 1305

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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> arr1 = get_sorted_list(root1);
        vector<int> arr2 = get_sorted_list(root2);
        int i=0,j=0;
        vector<int> res;
        while(i<arr1.size() && j<arr2.size()) {
            if(arr1[i]<arr2[j]) {
                res.push_back(arr1[i++]);
            }
            else {
                res.push_back(arr2[j++]);
            }
        }
        while(i<arr1.size()) res.push_back(arr1[i++]);
        while(j<arr2.size()) res.push_back(arr2[j++]);
        return res;
    }
    
    vector<int> get_sorted_list(TreeNode* root) {
        if(root==NULL) return vector<int>();
        vector<int> left_sorted = get_sorted_list(root->left);
        left_sorted.push_back(root->val);
        vector<int> right_sorted = get_sorted_list(root->right);
        left_sorted.insert(left_sorted.end(), right_sorted.begin(), right_sorted.end());
        return left_sorted;
    }
};
