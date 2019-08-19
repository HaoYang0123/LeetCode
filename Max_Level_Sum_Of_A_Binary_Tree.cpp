//Leetcode 1161

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
    int maxLevelSum(TreeNode* root) {
        int res=INT_MIN, level=0;
        vector<TreeNode*> cur_floor;
        int cur_level = 0;
        cur_floor.push_back(root);
        while(cur_floor.size()>0) {
            ++cur_level;
            int cur_value = get_val(cur_floor);
            if(cur_value > res) {
                res = cur_value;
                level = cur_level;
            }
            cur_floor = get_next_floor(cur_floor);
        }
        return level;
    }
    
    int get_val(vector<TreeNode*> & cur_floor) {
        int res=0;
        for(int i=0;i<cur_floor.size();++i) 
            res += cur_floor[i]->val;
        return res;
    }
    
    vector<TreeNode*> get_next_floor(vector<TreeNode*> & cur_floor) {
        vector<TreeNode*> res;
        for(int i=0;i<cur_floor.size();++i) {
            if(cur_floor[i]->left != NULL) res.push_back(cur_floor[i]->left);
            if(cur_floor[i]->right != NULL) res.push_back(cur_floor[i]->right);
        }
        return res;
    }
};
