//Leetcode 1145
//y的选择只有三种情况，x结点的父结点，x的左子树结点、x的右子树结点
//所以可以DFS计算各结点作为根的总结点数目
//三种情况最大的值，如果其比所有剩余结点数量大，那么y可以获胜，获胜选择的结点就是该情况对应的结点
//否则y不能获胜

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
 unordered_map<int, int> node2num; //记录以结点为根的树的总结点数量
 TreeNode* cur_x;
 bool btreeGameWinningMove(TreeNode* root, int n, int x) {
  if (root == NULL) return false;
  get_num(root, x);
  int all_num = node2num[root->val];
  int left_num = 0, right_num = 0, parent_num = 0;
  if (cur_x->left != NULL) left_num = node2num[cur_x->left->val];
  if (cur_x->right != NULL) right_num = node2num[cur_x->right->val];
  parent_num = all_num - 1 - left_num - right_num;
  int y_num = max(left_num, max(right_num, parent_num));
  return y_num > all_num - y_num;
 }

 int get_num(TreeNode* root, int x) {
  if (root == NULL) return 0;
  if (root->val == x) cur_x = root;
  if (node2num.find(root->val) != node2num.end()) return node2num[root->val];
  int v = 1 + get_num(root->left, x) + get_num(root->right, x);
  node2num[root->val] = v;
  return v;
 }
};
