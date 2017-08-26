//在树中找求和最大的路径（路径可以是任意的，不需要经过根结点，也不需要到达叶子结点）
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
    int maxValue;
    
    int maxPathSum(TreeNode* root) {
        maxValue = INT_MIN;
        maxPathSumDown(root);
        return maxValue;
    }
    
    int maxPathSumDown(TreeNode* root) { //返回值是左子树和右子树中最大者再加root结点，因为需要继续往上回溯，所以不能将左和右求和返回，否则不是一条路径
        if(root == NULL) return 0;
        int left = max(0, maxPathSumDown(root->left));
        int right = max(0, maxPathSumDown(root->right));
        maxValue = max(maxValue, left + right + root->val); //maxValue是答案，需要考虑经过root的一条路径
        return max(left, right) + root->val;
    }
};
