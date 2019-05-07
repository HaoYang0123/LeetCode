//Leetcode 1038
//后序遍历，从大到小遍历树，记录结点是否访问

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
    TreeNode* bstToGst(TreeNode* root) {
        if(root==NULL) return NULL;
        stack<TreeNode*> sta;
        unordered_map<int, bool> is_vis;
		sta.push(root);
		int cur = 0;
		while(!sta.empty()) {
			TreeNode* cur_node = sta.top();
            bool has_right = false;
			if(cur_node->right != NULL) {
                if(is_vis.find(cur_node->right->val) == is_vis.end()) {
                    sta.push(cur_node->right); //有右子树，则加入栈中
                    has_right = true;
                }
            }
			if(!has_right) { //无右子树，则弹出并更新当前结点的值
				cur += cur_node->val;
                //cout<<cur<<endl;
				cur_node->val = cur;
				sta.pop();
                is_vis[cur_node->val] = true;
				if(cur_node->left != NULL) {
                    if(is_vis.find(cur_node->left->val) == is_vis.end()) {
                        sta.push(cur_node->left); //有左子树，则加入栈中
                    }
                }
			}
		}
		return root;
    }
};
