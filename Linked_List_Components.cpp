//Leetcode 817

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
    int numComponents(ListNode* head, vector<int>& G) {
        set<int> ss;
        for(int i=0;i<G.size();++i) ss.insert(G[i]);
        ListNode* cur = head;
        int res = 0;
        while(cur != NULL) {
            if(ss.find(cur->val) != ss.end() && (cur->next == NULL || ss.find(cur->next->val) == ss.end()))
            //判断条件是：如果列表当前结点包含在G中，并且下一个元素不存在，或者下一个元素不在当前列表中，那么则加1
                ++res;
            cur = cur->next;
        }
        return res;
    }
};
