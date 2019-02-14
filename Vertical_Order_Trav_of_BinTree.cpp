//Leetcode 987 
//先将树存储转化成两维矩阵存储，由于有位置冲突，需要将冲突的全部保存，所以最后是三维矩阵
//最后矩阵按列从小到大输出即可

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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        int height = get_height(root);
        int n = height, m = 1+2*(height-1);
        vector<vector<vector<int>>> data(n,vector<vector<int>>(m));
        vector<vector<int>> res;
        if(root == NULL) return res;
        int cur_i = 0, cur_j = height-1;
        vector<TreeNode*> cur_floor;
        vector<pair<int, int>> cur_pos;
        cur_floor.push_back(root);
        cur_pos.push_back(pair<int,int>(cur_i,cur_j));
        data[cur_i][cur_j].push_back(root->val);
        while(cur_floor.size()>0) {
            vector<TreeNode*> new_floor;
            vector<pair<int,int>> new_pos;
            for(int i=0;i<cur_floor.size();++i) {
                TreeNode* cur_node = cur_floor[i];
                pair<int,int> cur_np = cur_pos[i];
                if(cur_node->left != NULL) {
                    new_floor.push_back(cur_node->left);
                    int new_i = cur_np.first + 1, new_j = cur_np.second - 1;
                    new_pos.push_back(pair<int,int>(new_i, new_j));
                    data[new_i][new_j].push_back(cur_node->left->val);
                }
                if(cur_node->right != NULL) {
                    new_floor.push_back(cur_node->right);
                    int new_i = cur_np.first + 1, new_j = cur_np.second + 1;
                    new_pos.push_back(pair<int,int>(new_i, new_j));
                    data[new_i][new_j].push_back(cur_node->right->val);
                }
            }
            cur_floor = new_floor;
            cur_pos = new_pos;
        }
        for(int i=0;i<m;++i) {
            vector<int> vertical;
            for(int j=0;j<n;++j) {
                vector<int> pos = data[j][i];
                sort(pos.begin(), pos.end());
                vertical.insert(vertical.end(), pos.begin(), pos.end());
            }
            if(vertical.size() > 0)
                res.push_back(vertical);
        }
        return res;
    }
    
    int get_height(TreeNode* root) {
        if(root == NULL) return 0;
        int left_h = get_height(root->left), right_h = get_height(root->right);
        return 1+max(left_h, right_h);
    }
};
