// Leetcode 2196

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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, pair<int,int>> parent2child;
        unordered_set<int> indeg;
        unordered_set<int> nodes;
        for(int i=0; i<descriptions.size(); ++i) {
            vector<int> & des = descriptions[i];
            int p = des[0], c = des[1], f = des[2];
            indeg.insert(c);
            nodes.insert(p);
            nodes.insert(c);
            if(parent2child.find(p) == parent2child.end())
                parent2child[p] = {0, 0};
            if(f==1) parent2child[p].first = c;
            else parent2child[p].second = c;
        }
        //找到根结点
        int root = 0;
        for(auto idx=nodes.begin(); idx != nodes.end(); ++idx) {
            if(indeg.find(*idx) == indeg.end()) {
                root = *idx;
                break;
            }
        }
        TreeNode* res = new TreeNode(root);
        unordered_map<int, TreeNode*> val2node;
        val2node[root] = res;
        queue<int> qs;
        qs.push(root);
        //BFS搜索，从根结点出发
        while(!qs.empty()) {
            int cur = qs.front();
            TreeNode* cur_node = val2node[cur];
            qs.pop();
            pair<int,int> & child = parent2child[cur];
            if(child.first != 0) {
                cur_node->left = new TreeNode(child.first);
                qs.push(child.first);
                val2node[child.first] = cur_node->left;
            }
            if(child.second != 0) {
                cur_node->right = new TreeNode(child.second);
                qs.push(child.second);
                val2node[child.second] = cur_node->right;
            }
        }
        return res;
    }
};
