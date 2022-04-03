// Leetcode 2218

class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n=piles.size();
        vector<vector<long long>> dp(n+1, vector<long long>(k+1, 0));
        //dp[i][j]表示在第i个piles下，选择j个coins的最大值
        for(int i=1; i<=n; ++i) {  //枚举所有的piles桶
            vector<long long> prefix_sum(piles[i-1].size()+1, 0);  //prefix_sum[j]表示piles[i]的前j缀和
            for(int j=0; j<piles[i-1].size(); ++j) prefix_sum[j+1] = prefix_sum[j] + piles[i-1][j];  //计算前缀和
            for(int j=0; j<=k; ++j) {   //计算所有dp[i][...],
                //dp[i][j]表示第i个桶中获取j个coins中的最大值，该最大值需要枚举所有前i-1个桶中的(0-j)个coins
                for(int p=0; p<prefix_sum.size() && p<=j; ++p) {  //p>j的时候，那么就不用计算了，因为超过了j个coines
                    dp[i][j] = max(dp[i][j], dp[i-1][j-p]+prefix_sum[p]);
                }
            }
        }
        return dp[n][k];
    }
};
