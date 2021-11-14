// Leetcode 2058

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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> res(2, -1);
        if(head == NULL || head->next == NULL || head->next->next == NULL) return res; //元素数量<=2，则直接返回
        ListNode* pre = head, * cur = head->next;
        int min_dis = INT_MAX, max_dis = 0;
        int first_pos = -1, pre_pos = -1, cur_pos = 0;
        while(cur->next != NULL) {
            if(is_min_max(pre, cur)) {
                if(first_pos == -1) { //如果是第1个极小、极大值位置
                    first_pos = cur_pos;
                }
                else {
                    int cur_dis = cur_pos - pre_pos;
                    min_dis = min(min_dis, cur_dis);
                    max_dis = max(max_dis, cur_pos - first_pos);
                }
                pre_pos = cur_pos;
            }
            ++cur_pos;
            pre = pre->next;
            cur = cur->next;
        }
        if(min_dis == INT_MAX) { //只有一个极小、极大值位置
            min_dis = -1;
            max_dis = -1;
        }
        res[0] = min_dis;
        res[1] = max_dis;
        return res;
    }
    
    inline bool is_min_max(ListNode* pre, ListNode* cur) {
        if(cur->val > pre->val && cur->val > cur->next->val) //极大值
            return true;
        if(cur->val < pre->val && cur->val < cur->next->val) //极小值
            return true;
        return false;
    }
};
