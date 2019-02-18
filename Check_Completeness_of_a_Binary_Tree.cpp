//Leetcode 958

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
    bool isCompleteTree(TreeNode* root) {
        if(root == NULL) return true;
        vector<TreeNode*> cur_floor;
        cur_floor.push_back(root);
        bool floor_flag = true; //floor_flag表示当前一层是否包含全部的结点数目，比如：第一层一个结点，第二层两个结点，..第i层2^i个结点
        int floor_num = 2;
        while(!cur_floor.empty()) {
            bool flag = true;
            vector<TreeNode*> new_floor;
            for(int i=0;i<cur_floor.size();++i) {
                TreeNode* a = cur_floor[i];
                if(a->left != NULL) {
                    //cout<<flag<<"\t"<<floor_flag<<endl;
                    if(!flag || !floor_flag) return false; //如果上一层没满或者当前层的前面有NULL的情况，则返回false
                    new_floor.push_back(a->left);
                }
                else flag = false;
                if(a->right != NULL) {
                    //cout<<flag<<"\t"<<floor_flag<<endl;
                    if(!flag || !floor_flag) return false; //同上
                    new_floor.push_back(a->right);
                }
                else flag = false;
            }
            if(new_floor.size() < floor_num) floor_flag = false; //当前层的结点数目如果低于应该全部拥有的数目，则floor_flag设置false
            floor_num *= 2;
            cur_floor = new_floor;
        }
        return true;
    }
};
