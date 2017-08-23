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
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL) return NULL;
        ListNode* slow = head, * fast = head;
        ListNode* slowPre = NULL;
        while(fast != NULL && fast->next != NULL) {
            slowPre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        TreeNode* res = new TreeNode(slow->val);
        if(slowPre == NULL) return res;
        slowPre->next = NULL;
        res->left = sortedListToBST(head);
        res->right = sortedListToBST(slow->next);
        return res;
    }
};
