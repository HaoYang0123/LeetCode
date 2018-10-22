//Leetcode 863
//给定一颗树，以及树中某个目标结点target，找出与target结点距离为K的所有结点

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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        vector<TreeNode*> path;
		    get_path(root, target->val, path);
        //for(int i=0;i<path.size();++i) cout<<path[i]->val<<endl;
        vector<int> res;
		  for(int i=0;i<path.size();++i) {
			  if(K-i < 0) break;
			  if(i==0)
				  get_res(path[i], NULL, K, res);
			  else
				  get_res(path[i], path[i-1], K-i, res);
		  }
        return res;
    }
	
	void get_res(TreeNode* root, TreeNode* notNeed, int K, vector<int> & res) {
		if(root == NULL) return;
		if(K == 0) {
			res.push_back(root->val);
			return;
		}
		if(root->left != NULL && (notNeed == NULL || root->left->val != notNeed->val)) {
			get_res(root->left, NULL, K - 1, res);
		}
		if(root->right != NULL && (notNeed == NULL || root->right->val != notNeed->val)) {
			get_res(root->right, NULL, K - 1, res);
		}
	}
	
	bool get_path(TreeNode* root, int target_val, vector<TreeNode*> & path) {
        if(root == NULL) return false;
        if(root->val == target_val) {
          path.push_back(root);
          return true;
        }
        bool left_flag = get_path(root->left, target_val, path);
        if(left_flag) {
          path.push_back(root);
          return true;
        }
        bool right_flag = get_path(root->right, target_val, path);
        if(right_flag) {	
          path.push_back(root);
          return true;
        }
        return false;
	  }
};
