//将一个链表组成的数组转化成如下形式：
//1->2->3->4->5->6转化为1->6->2->5->3->4
//1->2->3->4->5->6->7转化为1->7->2->6->3->5->4
//可以有如下思路：
//将后半段反转，比如将1->2->3->4->5->6，变为两半：1->2->3和6->5->4(后半段已经反转）
//然后再将两半进行合并：1->6->2->5->3->4
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
    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL) return;
        ListNode* slow = head, * slowPre = slow, * fast = head;
        while(fast != NULL && fast->next != NULL) {
            slowPre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        slowPre->next = NULL;
        //先将后半端反转，比如1->2->3->4->5->6,得到1->2->3, 6->5->4
        ListNode* a = slow, * b = slow->next;
        slow->next = NULL;
        while(b != NULL) {
            ListNode* oldA = a;
            a = b;
            b = b->next;
            a->next = oldA;
        }
        //然后将两端1->2->3,6->5->4接上，得到结果1->6->2->5->3->4
        ListNode* cur = head, * left = head->next, * right = a;
        if(right != NULL) {
            cur->next = right;
            cur = cur->next;
            right = right->next;
        }
        while(left != NULL) {
            cur->next = left;
            left = left->next;
            cur->next->next = right;
            cur = cur->next->next;
            right = right->next;
        }
        if(right != NULL) cur->next = right;
    }
};
