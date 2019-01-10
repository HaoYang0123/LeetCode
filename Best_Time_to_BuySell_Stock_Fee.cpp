//Leetcode 714
//O(n)时间复杂度。记录两个数组，分别是当前持有/不持有，第i天时得到的最大收益

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<int> dp1(n+1,0), dp2(n+1,0); //dp1表示不持股时第i天时的最大收益，dp2表示持股时第i天时的最大收益
        dp2[0] = -1000000;
        for(int i=0;i<n;++i) {
            dp1[i+1] = max(dp2[i]+prices[i]-fee, dp1[i]);
            dp2[i+1] = max(dp1[i]-prices[i], dp2[i]);
        }
        return dp1[n];
    }
};
