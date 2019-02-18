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
        bool floor_flag = true; //floor_flag表示当前一层是否
        int floor_num = 2;
        while(!cur_floor.empty()) {
            bool flag = true;
            vector<TreeNode*> new_floor;
            for(int i=0;i<cur_floor.size();++i) {
                TreeNode* a = cur_floor[i];
                if(a->left != NULL) {
                    //cout<<flag<<"\t"<<floor_flag<<endl;
                    if(!flag || !floor_flag) return false;
                    new_floor.push_back(a->left);
                }
                else flag = false;
                if(a->right != NULL) {
                    //cout<<flag<<"\t"<<floor_flag<<endl;
                    if(!flag || !floor_flag) return false;
                    new_floor.push_back(a->right);
                }
                else flag = false;
            }
            if(new_floor.size() < floor_num) floor_flag = false;
            floor_num *= 2;
            cur_floor = new_floor;
        }
        return true;
    }
};
