//Leetcode 1261
//深度搜索将tree中值存入set中

#include <iostream>
#include <unordered_set>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class FindElements {
public:
	unordered_set<int> val;
	FindElements(TreeNode * root) {
		dfs(root, 0);
	}

	void dfs(TreeNode * cur_root, int v) {
		if(cur_root == NULL) return;
		val.insert(v);
		dfs(cur_root->left, v*2+1);
		dfs(cur_root->right, v*2+2);
	}

	bool find(int target) {
		return val.find(target) != val.end();
	}
};
