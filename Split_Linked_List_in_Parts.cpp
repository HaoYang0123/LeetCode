//Leetcode 725

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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        int n = 0;
        ListNode* cur0 = root;
        while(cur0 != NULL) {
            ++n;
            cur0 = cur0->next;
        }
        if(n == 0) return vector<ListNode*>(k, NULL);
        int mean = n / k; //平均每个part的数量是mean
        int more = n % k; //前面more个part的数量是mean+1
        //cout<<mean<<"\t"<<more<<endl;
        vector<ListNode*> res(k, NULL);
        int c_num = 1, r_ind = 0;
        res[0] = root;
        ListNode* cur = root->next, * pre = root;
        if(n <= k) {
            r_ind = 1;
            res[1] = root->next;
            res[0]->next = NULL;
            c_num = 0;
        }
        while(cur != NULL) {
            ++c_num;
            int new_mean = mean;
            if(r_ind < more) {
                ++new_mean;
            }
            //cout<<"---\t"<<new_mean<<endl;
            if(c_num > new_mean) {
                c_num = 1;
                pre->next = NULL;
                ListNode* lll = res[r_ind-1];
                ++r_ind;
                res[r_ind] = cur;
            }
            pre = cur;
            cur = cur->next;
        }
        return res;
    }
};
