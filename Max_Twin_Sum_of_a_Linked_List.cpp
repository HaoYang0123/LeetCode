// Leetcode 2130

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
    int pairSum(ListNode* head) {
        vector<int> hh;
        while(head != NULL) {
            hh.push_back(head->val);
            head = head->next;
        }
        int res = 0;
        for(int i=0; i<hh.size(); ++i) {
            int tmp = hh[i] + hh[hh.size()-1-i];
            res = max(res, tmp);
        }
        return res;
    }
};
