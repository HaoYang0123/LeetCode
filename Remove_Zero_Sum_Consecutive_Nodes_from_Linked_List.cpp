// Leetcode 1171

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
    ListNode* removeZeroSumSublists(ListNode* head) {
        vector<int> arr;
        ListNode* cur = head;
        while(cur != NULL) {
            arr.push_back(cur->val);
            cur = cur->next;
        }
        for(int i=0; i<arr.size(); ++i) {
            int sum=0, e=-1;  //计算[i,j]求和=0，最大的j
            for(int j=i; j<arr.size(); ++j) {
                sum += arr[j];
                if(sum == 0) e = j;
            }
            if(e != -1) {
                for(int j=i; j<=e; ++j) arr[j] = INT_MAX;
                i=e;
            }
        }
        ListNode* res = NULL;
        cur = res;
        for(int i=0; i<arr.size(); ++i) {
            if(arr[i] != INT_MAX) {
                ListNode* tmp = new ListNode(arr[i]);
                if(res == NULL) {
                    res = tmp;
                    cur = res;
                }
                else {
                    cur->next = tmp;
                    cur = cur->next;
                }
            }
        }
        return res;
    }
};
