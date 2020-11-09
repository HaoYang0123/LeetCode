//Leetcode 1641
//动态规划，时间复杂度为O(n*5*5)

class Solution {
public:
    int countVowelStrings(int n) {
        vector<vector<int>> dp(5, vector<int>(52,0));
        for(int i=0;i<5;++i) {
            dp[i][1] = 1;
        }
        for(int i=2;i<=n;++i) {
            for(int j=0;j<5;++j) {
                for(int k=j;k<5;++k) {
                    dp[j][i] += dp[k][i-1];
                }
            }
        }
        int res = 0;
        for(int i=0;i<5;++i) res += dp[i][n];
        return res;
    }
};
