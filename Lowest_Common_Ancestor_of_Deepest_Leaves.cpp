//Leetcode 1123

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
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if(root == NULL) return NULL;
        unordered_map<TreeNode*, TreeNode*> val2par; //当前结点对应的父结点
        vector<TreeNode*> cur_floor, pre_floor;
        cur_floor.push_back(root);
        while(cur_floor.size() > 0) {
            vector<TreeNode*> next_floor;
            for(int i=0;i<cur_floor.size();++i) {
                if(cur_floor[i]->left != NULL) {
                    next_floor.push_back(cur_floor[i]->left);
                    val2par[cur_floor[i]->left] = cur_floor[i];
                }
                if(cur_floor[i]->right != NULL) {
                    next_floor.push_back(cur_floor[i]->right);
                    val2par[cur_floor[i]->right] = cur_floor[i];
                }
            }
            pre_floor = cur_floor;
            cur_floor = next_floor;
        }
        //for(int i=0;i<pre_floor.size();++i) cout<<pre_floor[i]->val<<endl;
        //pre_floor是最深的叶子结点
        while(pre_floor.size() > 1) {
            unordered_set<TreeNode*> ss; //ss表示上一层的结点
            for(int i=0;i<pre_floor.size();++i) {
                ss.insert(val2par[pre_floor[i]]);
            }
            pre_floor.clear();
            for(auto ind = ss.begin(); ind != ss.end(); ++ind) {
                pre_floor.push_back(*ind);
            }
        }
        return pre_floor[0];
    }
};
