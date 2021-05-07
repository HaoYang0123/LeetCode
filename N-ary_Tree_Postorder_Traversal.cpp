// Leetcode 590

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
    vector<int> postorder(Node* root) {
        vector<int> res;
        dfs(root, res);
        return res;
    }
    
    void dfs(Node* root, vector<int> & res) {
        if(root == NULL) return;
        vector<Node*> & c = root->children;
        for(int i=0; i<c.size(); ++i) {
            dfs(c[i], res);
        }
        res.push_back(root->val);
    }
};
