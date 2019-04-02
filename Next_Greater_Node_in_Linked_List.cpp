//Leetcode 1019
//O(N)的时间复杂度，使用stack来记录数组中降序的索引号，一旦当前元素的值比stack中的栈顶元素大，则将stack中的所有<=当前值的索引号弹出
//并将这些弹出的索引号结果为当前元素

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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> data;
        while(head!=NULL) {
            data.push_back(head->val);
            head = head->next;
        }
        vector<int> res(data.size(), 0);
        stack<int> sta; //保存数组data中降序的索引号
        for(int i=0;i<data.size();++i) {
            if(sta.empty() || data[i]<=data[sta.top()]) {
                sta.push(i);
                continue;
            }
            while(!sta.empty() && data[i]>data[sta.top()]) {
                res[sta.top()] = data[i];
                sta.pop();
            }
            sta.push(i);
        }
        return res;
    }
};
