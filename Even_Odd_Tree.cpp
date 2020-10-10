//Leetcode 1609

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        if(root == NULL) return true;
        int level = 0;
        vector<TreeNode*> cur({root});
        while(cur.size() > 0) {
            if(level % 2 == 0 && !is_increase(cur)) return false;
            if(level % 2 == 1 && !is_decrease(cur)) return false;
            vector<TreeNode*> new_floor;
            for(int i=0;i<cur.size();++i) {
                if(cur[i]->left != NULL) new_floor.push_back(cur[i]->left);
                if(cur[i]->right != NULL) new_floor.push_back(cur[i]->right);
            }
            cur = new_floor;
            ++level;
        }
        return true;
    }
    
    inline bool is_increase(vector<TreeNode*> & values) {
        for(int i=0;i<values.size()-1;++i) {
            if(values[i]->val % 2 == 0) return false;
            if(values[i]->val>=values[i+1]->val) return false;
        }
        return values.back()->val % 2 == 1;
    }
    
    inline bool is_decrease(vector<TreeNode*> & values) {
        for(int i=0;i<values.size()-1;++i) {
            if(values[i]->val % 2 == 1) return false;
            if(values[i]->val<=values[i+1]->val) return false;
        }
        return values.back()->val % 2 == 0;
    }
};
