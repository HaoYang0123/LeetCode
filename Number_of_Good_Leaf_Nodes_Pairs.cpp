//Leetcode 1530

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
    int res;
    int countPairs(TreeNode* root, int distance) {
        res = 0;
        vector<int> left_dist, right_dist;
        dfs(root, left_dist, right_dist, distance);
        return res;
    }
    
    void dfs(TreeNode* root, vector<int> & left_dist, vector<int> & right_dist, int distance) {
        //记录当前root为根结点的树，left_dist记录左子树中所有叶子结点到达root的距离
        //right_dist记录右子树中所有叶子结点到达root的距离
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL) { //叶子结点
            left_dist.push_back(0);
            return;
        }
        if(root->left != NULL) {
            vector<int> ld, rd;
            dfs(root->left, ld, rd, distance);
            for(int i = 0; i < ld.size(); ++i) {
                if(ld[i] + 1 < distance) left_dist.push_back(ld[i]+1);
            }
            for(int i = 0; i < rd.size(); ++i) {
                if(rd[i] + 1 < distance) left_dist.push_back(rd[i]+1);
            }
        }
        if(root->right != NULL) {
            vector<int> ld, rd;
            dfs(root->right, ld, rd, distance);
            for(int i = 0; i < ld.size(); ++i) {
                if(ld[i] < distance) right_dist.push_back(ld[i]+1);
            }
            for(int i = 0; i < rd.size(); ++i) {
                if(rd[i] < distance) right_dist.push_back(rd[i]+1);
            }
        }
        //计算左子树中各节点与右子树中各节点之间的距离，如果<=distance，则加入至res结果中
        for(int i=0;i<left_dist.size();++i) {
            for(int j=0;j<right_dist.size();++j) {
                if(left_dist[i] + right_dist[j] <= distance) ++res;
            }
        }
    }
};
