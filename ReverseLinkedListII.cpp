/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head == NULL) return NULL;
        ListNode* r = head, * preR = NULL, * r2 = NULL, * r3 = NULL, * r4 = NULL;
        int oldM = m;
        while(--m) {
            preR = r;
            r = r->next;
        }
        r3 = preR;
        r4 = r;
        n -= (oldM - 1);
        while(--n) {
            r2 = r->next;
            r->next = preR;
            preR = r;
            r = r2;
        }
        r2 = r->next;
        r->next = preR;
        //cout<<r3->val<<"\t"<<r->val<<endl;
        if(r3 == NULL) {
            head->next = r2;
            return r;
        } 
        else {
            r3->next = r;
            r4->next = r2;
        }
        return head;
    }
};
