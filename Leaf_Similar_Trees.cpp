//Leetcode 872
//使用BFS宽搜（即栈的方式从右结点、左结点的顺序来计算），树中每个结点入栈出栈一次，只输出叶子结点的情况，叶子结点的顺序是从左到右输出

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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        stack<TreeNode*> s1, s2;
        s1.push(root1);
        s2.push(root2);
        while(!s1.empty() && !s2.empty()) {
            int a = next_leaf(s1), b = next_leaf(s2);
            if(a != b) return false;
        }
        return (s1.empty() && s2.empty());
    }
    
    int next_leaf(stack<TreeNode*> & s) {
        while(true) {
            TreeNode* a = s.top();
            s.pop();
            if(a->right != NULL) s.push(a->right);
            if(a->left != NULL) s.push(a->left);
            if(a->left == NULL && a->right == NULL) return a->val;
        }
    }
};
