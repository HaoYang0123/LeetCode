//Leetcode 993

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
    bool isCousins(TreeNode* root, int x, int y) {
        if(root == NULL) return false;
        unordered_map<int, int> val_to_dep; //值为val的结点（树中各结点的值不相同）对应的树深度
        unordered_map<int, int> val_to_parent; //值为val的结点对应的父结点
        queue<pair<TreeNode*, int>> qs;
        qs.push(pair<TreeNode*, int>(root, 0));
        val_to_dep[root->val] = 0;
        int find_num = 0;
        while(!qs.empty()) {
            pair<TreeNode*, int> t = qs.front();
            qs.pop();
            TreeNode* c = t.first;
            int dep = t.second;
            if(c->left != NULL) {
                val_to_dep[c->left->val] = dep+1;
                val_to_parent[c->left->val] = c->val;
                qs.push(pair<TreeNode*, int>(c->left, dep+1));
                if(c->left->val == x || c->left->val == y) {
                    ++find_num;
                    if(find_num == 2) break;
                }
            }
            if(c->right != NULL) {
                val_to_dep[c->right->val] = dep+1;
                val_to_parent[c->right->val] = c->val;
                qs.push(pair<TreeNode*, int>(c->right, dep+1));
                if(c->right->val == x || c->right->val == y) {
                    ++find_num;
                    if(find_num == 2) break;
                }
            }
        }
        //如果x和y对应的深度一致，且x和y来自于两个不同的父结点，才返回true
        return (val_to_dep[x] == val_to_dep[y] && val_to_parent[x] != val_to_parent[y]);
    }
};
