//Leetcode 1367

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    bool isSubPath(ListNode* head, TreeNode* root) {
        unordered_map<int, vector<TreeNode*>> val2nodes;
        queue<TreeNode*> qs;
        qs.push(root);
        while(!qs.empty()) {
            TreeNode* r = qs.front();
            qs.pop();
            val2nodes[r->val].push_back(r);
            if(r->left != NULL) {
                qs.push(r->left);
            }
            if(r->right != NULL) {
                qs.push(r->right);
            }
        }
        auto ind = val2nodes.find(head->val);
        if(ind == val2nodes.end()) return false;
        vector<TreeNode*> & start_nodes = ind->second;
        //cout<<"\t"<<head->val<<"\t"<<start_nodes.size();
        //write(start_nodes);
        while(head->next != NULL) {
            vector<TreeNode*> next_nodes = find_next(start_nodes, head->next->val);
            //cout<<"\t"<<head->next->val<<"\t"<<next_nodes.size();
            //write(next_nodes);
            if(next_nodes.size() == 0) return false;
            start_nodes = next_nodes;
            head = head->next;
        }
        return true;
    }
    
    void write(vector<TreeNode*> & r) {
        for(int i=0;i<r.size();++i) {
            cout<<"\t"<<r[i]->val<<":";
            if(r[i]->left != NULL) cout<<r[i]->left->val<<":";
            else cout<<":";
            if(r[i]->right != NULL) cout<<r[i]->right->val;
        }
        cout<<endl;
    }
    
    inline vector<TreeNode*> find_next(vector<TreeNode*> nodes, int v) {
        //cout<<"Find:\t"<<v;
        //write(nodes);
        vector<TreeNode*> res;
        for(int i=0;i<nodes.size();++i) {
            if(nodes[i]->left != NULL && nodes[i]->left->val == v) res.push_back(nodes[i]->left);
            if(nodes[i]->right != NULL && nodes[i]->right->val == v) res.push_back(nodes[i]->right);
        }
        return res;
    }
};
