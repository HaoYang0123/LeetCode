// Leetcode 1721

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        int n = get_count(head);
        ListNode* one = get_index_value(head, k);
        ListNode* two = get_index_value(head, n-k+1);
        int tmp = one->val;
        one->val = two->val;
        two->val = tmp;
        return head;
    }
    
    inline int get_count(ListNode* head) {
        int res = 0;
        ListNode* cur = head;
        while(cur != NULL) {
            ++res;
            cur = cur->next;
        }
        return res;
    }
    
    inline ListNode* get_index_value(ListNode* head, int k) {
        ListNode* cur = head;
        --k;
        while(k > 0) {
            cur = cur->next;
            --k;
        }
        return cur;
    }
};
