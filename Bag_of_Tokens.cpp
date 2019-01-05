//Leetcode 948
//贪心策略，将数组从小到大排序，两个指针l和h，l表示买进（得分+1），h表示卖出。当手里的P不足以买进tokens[l]时，并且得分>0，那么则卖出tokens[h]。

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        sort(tokens.begin(), tokens.end());
        int n = tokens.size();
        int l = 0, h = n-1;
        int points = 0, ans = 0;
        while(l<=h && (P >= tokens[l] || points > 0)) {
            while(l <= h && P >= tokens[l]) {
                P -= tokens[l++];
                points++;
            }
            ans = max(ans, points);
            if(l <= h && points > 0) {
                P += tokens[h--];
                points--;
            }
        }
        return ans;
    }
};
