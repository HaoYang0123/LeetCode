//Leetcode 1290

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
    int getDecimalValue(ListNode* head) {
        int res = 0;
        int mul = 1;
        ListNode* ori = head;
        while(head != NULL) {
            mul *= 2;
            head = head->next;
        }
        mul /= 2;
        while(ori != NULL) {
            res += mul * ori->val;
            mul /= 2;
            ori = ori->next;
        }
        return res;
    }
};
