//Leetcode 72
//计算两个字符串的编辑距离，动态规划：dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1])+1 if s[i] != t[j]; 
//dp[i][j] = dp[i-1][j-1] else if s[i] == t[j]

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.length(), n2 = word2.length();
        vector<vector<int>> dp(n1+2, vector<int>(n2+2, 0));
        for(int i=1;i<=n1;++i) dp[i][0] = i;
        for(int i=1;i<=n2;++i) dp[0][i] = i;
        for(int i=1;i<=n1;++i) {
            for(int j=1;j<=n2;++j) {
                if(word1[i-1] == word2[j-1]) dp[i][j] = dp[i-1][j-1];
                else {
                    dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])) + 1;
                }
            }
        }
        return dp[n1][n2];
    }
};
