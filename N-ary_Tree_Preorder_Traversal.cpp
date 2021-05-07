// Leetcode 589

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> res;
        dfs(root, res);
        return res;
    }
    
    void dfs(Node* root, vector<int> & res) {
        if(root == NULL) return ;
        res.push_back(root->val);
        vector<Node*> & c = root->children;
        for(int i=0; i<c.size(); ++i) {
            dfs(c[i], res);
        }
    }
};
