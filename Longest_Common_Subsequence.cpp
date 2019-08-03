//Leetcode 1143
//动态规划，O(N*M)的时间复杂度

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.length();
        int m=text2.length();
        
        vector<vector<int>> dp(n+1, vector<int>(m+1,0));
        for(int i=0;i<n;++i) {
            for(int j=0;j<m;++j) {
                if(text1[i]!=text2[j])
                    dp[i+1][j+1]=max(dp[i][j],max(dp[i+1][j],dp[i][j+1]));
                else
                    dp[i+1][j+1]=max(dp[i][j]+1,max(dp[i+1][j],dp[i][j+1]));
            }
        }
        return dp[n][m];
    }
};
