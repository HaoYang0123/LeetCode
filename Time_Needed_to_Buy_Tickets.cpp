// Leetcode 2073

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int need = tickets[k];
        int res = 0;
        for(int i=0;i<tickets.size();++i) {
            if(i<=k) res += min(tickets[i], need);
            else res += min(tickets[i], need-1);
        }
        return res;
    }
};
